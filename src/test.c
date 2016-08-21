#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#include "csr_mesh_ps_ifce.h"

#define SQLITE_CREATE_TABLE_QUERY "CREATE TABLE MESH(KEY, VAL);"

#define SQLITE_INSERT_QUERY "INSERT INTO MESH VALUES (CSR_MESH_DEVICE_UUID_KEY, NULL);" \
			    "INSERT INTO MESH VALUES (CSR_MESH_DEVICE_AUTHCODE_KEY, NULL);" \
			    "INSERT INTO MESH VALUES (CSR_MESH_MTL_NW_KEY_AVL_KEY, NULL);" \
			    "INSERT INTO MESH VALUES (CSR_MESH_MTL_MCP_NWKEY_KEY, NULL);" \
			    "INSERT INTO MESH VALUES (CSR_MESH_MTL_PROMISCUOUS_STATUS_KEY, NULL);" \
			    "INSERT INTO MESH VALUES (CSR_MESH_MASP_RELAY_STATE_KEY, NULL);" \
			    "INSERT INTO MESH VALUES (CSR_MESH_MCP_SEQ_NUM_KEY, NULL);" \
			    "INSERT INTO MESH VALUES (CSR_MESH_CONFIG_LAST_ETAG_KEY, NULL);" \
			    "INSERT INTO MESH VALUES (CSR_MESH_CONFIG_PARAMS_KEY, NULL);" \
			    "INSERT INTO MESH VALUES (CSR_MESH_BEARER_STATE_KEY, NULL);" \
			    "INSERT INTO MESH VALUES (CSR_MESH_CONFIG_APPEARANCE_KEY, NULL);" \
			    "INSERT INTO MESH VALUES (CSR_MESH_INVALID_KEY, NULL);"

#define SQLITE_READ_QUERY "SELECT * FROM MESH WHERE KEY=?;"

#define SQLITE_UPDATE_QUERY "UPDATE MESH SET VAL=? WHERE KEY=?;"

#define TABLE_ALREADY_EXISTS_STR "table MESH already exists"

static sqlite3 *db;
static CsrBool sqlDbDataInit;
static CsrUint16 default_uuid[] = default_uuid_init_val;
static CSRmeshResult CSRmeshSqlDbOpen(CsrUint8*, sqlite3**);
static CSRmeshResult CSRmeshSqlDbInit(sqlite3*);
static CSRmeshResult CSRmeshSqlDbRead(sqlite3*, CsrUint8, CsrUint16*, CsrUint16);
static CSRmeshResult CSRmeshSqlDbUpdate(sqlite3*, CsrUint8, CsrUint16*, CsrUint16);
static CSRmeshResult CSRmeshSqlDbClose(sqlite3*);

CSRmeshResult CSRmeshSqlDbOpen(CsrUint8 *dbName, sqlite3 **db)
{
	CSRmeshResult result = CSR_MESH_RESULT_SUCCESS;
	CsrUint8 *errMsg = NULL;
	CsrInt8 retVal;
	CsrUint8 *sqlCmd = SQLITE_CREATE_TABLE_QUERY;

	result = sqlite3_open(dbName, db);
	if (result){
		printf("Can't open database: %s\n", sqlite3_errmsg(*db));
		return CSR_MESH_RESULT_FAILURE;
	} else {
		printf("Successfully Open database\n");
	}
	/*Database has been Created. Create Table in the Database */
	retVal = sqlite3_exec(*db, sqlCmd, NULL, NULL, (char **)(&errMsg));
	if (retVal != SQLITE_OK) {
		printf("Can't create table : %d %s\n", retVal, errMsg);
		if(strcmp(TABLE_ALREADY_EXISTS_STR, errMsg) != 0){
			result = CSR_MESH_RESULT_FAILURE;
		}
		else {
			/* Setting the Flag which indicates SQL DB Data has been Initialized */
			sqlDbDataInit = TRUE;
		}
		sqlite3_free(errMsg);
	} else {
		printf("CsrMeshStackInfo Table created\n");
		printf("CSRmeshPsInit : Initializing SQLite DB : Only First Time\n");
		/* Initialize the database table with initial values */
		/* NOTE :- Only fixed no of keys-values are getting stored. So, It is good to
		   initalize the database table just after the creation*/
		CSRmeshSqlDbInit(*db);
		sqlDbDataInit = FALSE;
	}
	return result;
}

CSRmeshResult CSRmeshSqlDbInit(sqlite3* db)
{
	CSRmeshResult result = CSR_MESH_RESULT_SUCCESS;
	CsrInt8 retVal;
	CsrUint8 *errMsg = NULL;
	CsrUint8 *sqlCmd = SQLITE_INSERT_QUERY;
	/* Executing SQL Statement */
	retVal = sqlite3_exec(db, sqlCmd, NULL, NULL, (char **)(&errMsg));
	if (retVal != SQLITE_OK) {
		printf("Can't Initialize CsrMeshStackInfo table : %s\n", errMsg);
		sqlite3_free(errMsg);
		return CSR_MESH_RESULT_FAILURE;
	} else {
		printf("CsrMeshStackInfo Table Initialized \n");
	}
	/*Setting the default UUID*/
	result = CSRmeshSqlDbUpdate(db, CSR_MESH_DEVICE_UUID_KEY, default_uuid,
			CSR_MESH_DEVICE_UUID_SIZE_IN_WORDS);
	return result;
}

CSRmeshResult CSRmeshSqlDbRead(sqlite3 *db, CsrUint8 key, CsrUint16 *valueBuffer,
		CsrUint16 length)
{
	CSRmeshResult result = CSR_MESH_RESULT_SUCCESS;
	sqlite3_stmt *sqlStmt = NULL;
	CsrUint8 *sqlCmd = NULL;
	CsrInt8 retVal;
	CsrUint16 *dataPtr;
	printf("CSRmeshSqlDbRead: key : %d, length : %d \n",key, length);
	/* Preparing SQL Statement */
	sqlCmd = SQLITE_READ_QUERY;
	retVal = sqlite3_prepare_v2(db, sqlCmd, -1, &sqlStmt, NULL);
	if (retVal == SQLITE_OK) {
		sqlite3_bind_int(sqlStmt, 1, key);
	} else {
		printf("Failed to preapre SQL statement : %s\n", sqlite3_errmsg(db));
		return CSR_MESH_RESULT_FAILURE;
	}
	/* Executing SQL Statement */
	retVal = sqlite3_step(sqlStmt);
	if (retVal == SQLITE_ROW) {
		sqlite3_column_int(sqlStmt, 0);
		dataPtr = (CsrUint16 *) sqlite3_column_blob(sqlStmt, 1);
		memcpy(valueBuffer,dataPtr,length*2);
		printf("CSRmeshSqlDbRead: Successful\n");
	} else {
		printf("CSRmeshSqlDbRead: key %d not found in database\n", key);
		result = CSR_MESH_RESULT_FAILURE;
	}
	sqlite3_finalize(sqlStmt);
	return result;
}

CSRmeshResult CSRmeshSqlDbUpdate(sqlite3 *db, CsrUint8 key, CsrUint16 *valueBuffer,
		CsrUint16 length)
{
	CSRmeshResult result = CSR_MESH_RESULT_SUCCESS;
	sqlite3_stmt *sqlStmt;
	CsrUint8 *sqlCmd = NULL;
	CsrInt8 retVal;
	printf("\n CSRmeshSqlDbUpdate: key: %d, length: %d\n",key, length);
	/* Forming the SQL Command */
	sqlCmd = SQLITE_UPDATE_QUERY;
	/* Preparing SQL Statement */
	retVal = sqlite3_prepare_v2(db, sqlCmd, -1, &sqlStmt, 0);
	if (retVal == SQLITE_OK) {
		sqlite3_bind_blob(sqlStmt, 1, valueBuffer, length*2, SQLITE_TRANSIENT);
		sqlite3_bind_int(sqlStmt, 2, key);
	} else {
		printf("Failed to prepare SQL statement : %s\n", sqlite3_errmsg(db));
		return CSR_MESH_RESULT_FAILURE;
	}
	/* Executing SQL Statement */
	retVal = sqlite3_step(sqlStmt);
	if (retVal != SQLITE_DONE) {
		printf("Failed to execute SQL statement : %s\n", sqlite3_errmsg(db));
		result = CSR_MESH_RESULT_FAILURE;
	} else {
		printf("CSRmeshSqlDbUpdate: Executed Successfully\n");
		/* Update SQL DB Initialized falg when NWKEY gets updated in SQLDB */
		if (CSR_MESH_MTL_MCP_NWKEY_KEY == key)
		{
			sqlDbDataInit = TRUE;
		}
	}
	sqlite3_finalize(sqlStmt);
	return result;
}

CSRmeshResult CSRmeshSqlDbClose(sqlite3 *db)
{
	CSRmeshResult result = CSR_MESH_RESULT_SUCCESS;
	CsrInt8 retVal;
	/*Close SQL Database*/
	retVal = sqlite3_close(db);
	if(retVal != SQLITE_OK){
		printf("Unable to close db error: %d\n", retVal);
		result = CSR_MESH_RESULT_FAILURE;
	}
	return result;
}

CSRmeshResult CSRmeshPsInit(void)
{
	CsrUint8 *dbName = CSR_MESH_GW_DB_FILE_PATH;
	return CSRmeshSqlDbOpen(dbName, &db);
}

CsrBool CSRmeshIsPsReadyForAccess(void)
{
	return TRUE;
}

CSRmeshResult CSRmeshPsRead(CsrUint8 key, CsrUint16 *valueBuffer, CsrUint16 length)
{
	return CSRmeshSqlDbRead(db, key, valueBuffer, length);
}

CSRmeshResult CSRmeshPsSecureRead(CsrUint8 key, CsrUint16 *valueBuffer, CsrUint16 length)
{
	return CSRmeshPsRead(key, valueBuffer, length);
}

CSRmeshResult CSRmeshPsWrite(CsrUint8 key, CsrUint16 *valueBuffer, CsrUint16 length)
{
	return CSRmeshSqlDbUpdate(db, key, valueBuffer, length);
}

CSRmeshResult CSRmeshPsSecureWrite(CsrUint8 key, CsrUint16 *valueBuffer, CsrUint16 length)
{
	return CSRmeshPsWrite(key, valueBuffer, length);
}

void CSRmeshPsDeInit(void)
{
	CSRmeshSqlDbClose(db);
}
