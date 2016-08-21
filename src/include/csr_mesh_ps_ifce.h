/*****************************************************************************
 *
 * Copyright [2015] Qualcomm Technologies International, Ltd.
 *
 *****************************************************************************/

/*! \file Csr_mesh_ps_ifce.h
 * \brief Persistent storage interface related functions and types 
 * 
 *  This file contains the PS interface related function and type defines. These functions need to be 
 *  implemented while porting the CSRmesh Gateway SB
 * \addtogroup CSRmesh
 * @{
 *
 */
 
#ifndef __CSR_MESH_PS_IFCE_H__
#define __CSR_MESH_PS_IFCE_H__

#include "csr_types.h"
#include "csr_mesh_result.h"

/*! \brief CSRmesh device UUID size in words*/
#define CSR_MESH_DEVICE_UUID_SIZE_IN_WORDS           (8)
/*! \brief CSRmesh device UUID size in bytes*/
#define CSR_MESH_DEVICE_UUID_SIZE_IN_BYTES           (16)
/*! \brief CSRmesh device authentication code size in words*/
#define CSR_MESH_DEVICE_AUTH_CODE_SIZE_IN_WORDS      (4)
/*! \brief CSRmesh device authentication code size in bytes*/
#define CSR_MESH_DEVICE_AUTH_CODE_SIZE_IN_BYTES      (8)
#define CSR_MESH_GW_DB_FILE_PATH                      "/csrmesh/csrMesh.db"

/*! \brief CSR Mesh device Authorization Code Size in words  */
#define CSR_MESH_DEVICE_AUTHCODE_SIZE_IN_WORDS       (4)
/*! \brief CSR Mesh device Authorization Code Size in  bytes  */
#define CSR_MESH_DEVICE_AUTHCODE_SIZE_IN_BYTES       (2 * CSR_MESH_DEVICE_AUTHCODE_SIZE_IN_WORDS)

/*!\brief CSR Mesh Key Type Definittion */
typedef enum
{
    CSR_MESH_DEVICE_UUID_KEY            = 0x01,
    CSR_MESH_DEVICE_AUTHCODE_KEY        = 0x02,
    CSR_MESH_MTL_NW_KEY_AVL_KEY         = 0x03,
    CSR_MESH_MTL_MCP_NWKEY_KEY          = 0x04,
    CSR_MESH_MTL_PROMISCUOUS_STATUS_KEY = 0x05,
    CSR_MESH_MASP_RELAY_STATE_KEY       = 0x06,
    CSR_MESH_MCP_SEQ_NUM_KEY            = 0x07,
    CSR_MESH_CONFIG_LAST_ETAG_KEY       = 0x08,
    CSR_MESH_CONFIG_PARAMS_KEY          = 0x10,
    CSR_MESH_BEARER_STATE_KEY           = 0x11,
    CSR_MESH_CONFIG_APPEARANCE_KEY      = 0x12,
    CSR_MESH_INVALID_KEY                = 0xFF
} CSRmeshPsKeys;

/* Default UUID, if you choose to use RANDOM_UUID by enabling CSR_MESH_GW_RANDOM_UUID in csr_mesh_gateway_config.h
 * then do not change this value. 
 * If you choose to use Static UUID then you can update the UUID here as described below
 * CSRmesh Device UUID: 128-Bit Device UUID is stored in 8 Words(16-Bits each) in Little Endian Format in RAM and NVM. To 
 * set a particular UUID, change the uuid array as shown in example.
 * Example:
 * ............................MSB.................................LSB.
 * Device UUID in Hexadecimal: 0123-4567-89AB-CDEF-FEDC-BA98-7654-3210.
 * Array should be set as: {0x3210, 0x7654, 0xBA98, 0xFEDC,
 *                          0xCDEF, 0x89AB, 0x4567, 0x0123};
 * NOTE: The UUID in array below will be used only if, Bit-0 of
 * CSKEY_INDEX_USER_FLAGS is Cleared.
 */
#define default_uuid_init_val { \
                              0x0000, 0x0000, 0x0000, 0x0000, \
                              0x0000, 0x0000, 0x0000, 0x0000  \
                              }

/*----------------------------------------------------------------------------*
 * CSRmeshPsInit
 */
/*! \brief Initialise Persistent Store
 *
 * \returns CSRmeshResult. Refer to \ref CSRmeshResult.
 */
/*----------------------------------------------------------------------------*/
extern CSRmeshResult CSRmeshPsInit(void);

/*----------------------------------------------------------------------------*
 * CSRmeshIsPsReadyForAccess
 */
/*! \brief This function returns TRUE if the PS is ready for access
 * 
 * \returns CsrBool
 */
/*----------------------------------------------------------------------------*/
extern CsrBool CSRmeshIsPsReadyForAccess(void);

/*----------------------------------------------------------------------------*
 * CSRmeshPsRead
 */
/*! \brief Read from Persistent Store
 * 
 * \param key Holds key to be read from persistent-store
 * \param valueBuffer Pointer to the buffer into which the data to be read
 * \param length Length of the buffer
 * \returns CSRmeshResult. Refer to \ref CSRmeshResult.
 */
/*----------------------------------------------------------------------------*/
extern CSRmeshResult CSRmeshPsRead(CsrUint8 key, CsrUint16 *valueBuffer, CsrUint16 length);

/*----------------------------------------------------------------------------*
 * CSRmeshPsSecureRead
 */
/*! \brief Read from Persistent Store securely
 * 
 * \param key Holds key to be read from persistent-store
 * \param valueBuffer Pointer to the buffer into which the data to be read
 * \param length Length of the buffer
 * \returns CSRmeshResult. Refer to \ref CSRmeshResult.
 */
/*----------------------------------------------------------------------------*/
extern CSRmeshResult CSRmeshPsSecureRead(CsrUint8 key, CsrUint16 *valueBuffer, CsrUint16 length);

/*----------------------------------------------------------------------------*
 * CSRmeshPsWrite
 */
/*! \brief Write to Persistent Store
 * 
 * \param key Holds key to be read from persistent-store
 * \param valueBuffer Pointer to the buffer from which the data to be written to persistent store
 * \param length Length of the buffer
 * \returns CSRmeshResult. Refer to \ref CSRmeshResult.
 */
/*----------------------------------------------------------------------------*/
extern CSRmeshResult CSRmeshPsWrite(CsrUint8 key, CsrUint16 *valueBuffer, CsrUint16 length);

/*----------------------------------------------------------------------------*
 * DataBlockSend
 */
/*! \brief Securely Write to Persistent Store
 * 
 * \param key Holds key to be read from persistent-store
 * \param valueBuffer Pointer to the buffer from which the data to be written to persistent store
 * \param length Length of the buffer
 * \returns CSRmeshResult. Refer to \ref CSRmeshResult.
 */
/*----------------------------------------------------------------------------*/
extern CSRmeshResult CSRmeshPsSecureWrite(CsrUint8 key, CsrUint16 *valueBuffer, CsrUint16 length);


/*----------------------------------------------------------------------------*
 * CSRmeshPsDeInit
 */
/*! \brief De-Initialise Persistent Store
  *
 * \returns CSRmeshResult. Refer to \ref CSRmeshResult.
 */
/*----------------------------------------------------------------------------*/
extern void CSRmeshPsDeInit(void);
/*!@} */
#endif /* __CSR_MESH_PS_IFCE_H__ */
