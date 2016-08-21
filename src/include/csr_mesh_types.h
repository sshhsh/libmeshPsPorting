 /******************************************************************************
 *  Copyright [2015] Qualcomm Technologies International, Ltd.
 *****************************************************************************/
/*! \file csr_mesh_types.h
 *  \brief CSRmesh library data types
 *
 *   This file contains the different data types used in CSRmesh library
 *
 *   NOTE: This library includes the Mesh Transport Layer, Mesh Control
 *   Layer and Mesh Association Layer functionality.
 */
 /*****************************************************************************/
#ifndef _CSR_MESH_TYPES_H_
#define _CSR_MESH_TYPES_H_

#include "csr_types.h"
#include "csr_mesh_gateway_config.h"
#include "csr_mesh_result.h"

#if defined(CSR101x) || defined(CSR101x_A05)
#include "ls_types.h"
#endif

/*! \addtogroup CSRmesh
 * @{
 */
 
/*============================================================================*
Public Definitions
*============================================================================*/
/*! \brief Invalid network id
 */
#define CSR_MESH_INVALID_NWK_ID         (0xFF)

/*! \brief short name for the device */
#define CSR_MESH_SHORT_NAME_LENGTH      (9)

/*! \brief 128-bit UUID type */
typedef struct
{
    CsrUint8 uuid[16]; /*!< \brief CSRmesh 128-bit UUID */
} CSR_MESH_UUID_T;

/*! \brief CSRmesh Model types */
typedef enum
{
    CSR_MESH_WATCHDOG_MODEL = 0,        /*!< \brief Type Watchdog model */
    CSR_MESH_CONFIG_MODEL = 1,          /*!< \brief Type Config model */
    CSR_MESH_GROUP_MODEL = 2,           /*!< \brief Type Group model */
    CSR_MESH_SENSOR_MODEL = 4,          /*!< \brief Type Sensor model */
    CSR_MESH_ACTUATOR_MODEL = 5,        /*!< \brief Type Actuator model */
    CSR_MESH_DATA_MODEL = 8,            /*!< \brief Type Data model */
    CSR_MESH_BEARER_MODEL = 11,         /*!< \brief Type Bearer model */
    CSR_MESH_PING_MODEL = 12,           /*!< \brief Type Ping model */
    CSR_MESH_BATTERY_MODEL = 13,        /*!< \brief Type Battery model */
    CSR_MESH_ATTENTION_MODEL = 14,      /*!< \brief Type Attention model */
    CSR_MESH_POWER_MODEL = 19,          /*!< \brief Type Power model */
    CSR_MESH_LIGHT_MODEL = 20,          /*!< \brief Type Light model */
    CSR_MESH_SWITCH_MODEL = 21,         /*!< \brief Type Switch model */
} CSR_MESH_MCP_MODEL_TYPE_T;

typedef enum
{
    CSR_MESH_DIAGNOSTIC_DUPLICATE_MSG_COUNT = 0x01, /* Duplicate message count mask. */
    CSR_MESH_DIAGNOSTIC_UNKNOWN_MSG_COUNT   = 0x02, /* Unknown message count mask.   */
    CSR_MESH_DIAGNOSTIC_KNOWN_MSG_COUNT     = 0x04, /* Known message count mask.     */
    CSR_MESH_DIAGNOSTIC_RELAYED_MSG_COUNT   = 0x08, /* Relayed message count mask.   */
    CSR_MESH_DIAGNOSTIC_BEARER_SPECIFIC_RX  = 0x10,  /* Bearer specific Rx. */
    CSR_MESH_DIAGNOSTIC_BEARER_SPECIFIC_TX  = 0x20,  /* Bearer specific Tx */
    CSR_MESH_DIAGNOSTIC_ALL                 = 0xFF, /* All message count mask.       */
} CSR_MESH_DIAGNOSTIC_CONFIG_MASK_T;

typedef struct
{
    CsrUint32 numDuplicateMsg;      /*!< \brief Duplicate message count */
    CsrUint32 numUnknownMsg;        /*!< \brief Unknown message count */
    CsrUint32 numKnownMsg;          /*!< \brief Known message count */
    CsrUint32 numRelayedMsg;        /*!< \brief Relayed message count */
    CsrUint32 diagnosisDuration;    /*!< \brief Duration indicates the time interval
                                        in terms of milliseconds during which
                                        the diagnostic data is captured. */
    CsrUint32 totalNumOfMeshMsgRecvd;   /*!< \brief Total number of mesh messages received */
    CsrUint32 totalNumOfMeshMsgTrnsmtd; /*!< \brief Total number of mesh messages transmitted  */
} CSR_MESH_DIAG_DATA_T;

typedef struct
{
    CsrUint8  netId; /*!< \brief Network ID  */
    CsrUint8  meshId[16];  /*!< \brief Mesh ID  */
}CSR_MESH_MESHID_AND_NETID_T;

/*! \brief CSR Mesh Network Id List */
typedef struct
{
    /*!< \brief List of existing mesh network IDs. Each octet 
     * value identifies one distinguished mesh network. This is 
     * defined as a flexible array and a field of this type will 
     * be part of union CSR_MESH_APP_CB_DATA_T. The array netIdList
     * will have maximum number of array elements i.e. allowed by
     * the maximum size of the union. An invalid network id is 
     * defined as 0xFF.
     */
    CsrUint8 length; /*!< \brief length of netid list */
    CsrUint8 netIDList[CSR_MESH_GW_MAX_NUM_OF_NETWORKS_ALLOWD]; /*!< \brief Array of netid list with array size of maximum number of networks allowed*/
} CSR_MESH_NETID_LIST_T;

/*! \brief CSRmesh Device Appearance. The Appearance is a 24-bit value that is 
 *   composed of an "organization" and an "organization appearance". 
 */
typedef struct __attribute__((__packed__))
{
    CsrUint8  organization; /*!< \brief Identifies the organization which assigns
                               device appearance values */
    CsrUint16 value;        /*!< \brief Appearance value */
    CsrUint32 deviceHash;  /*!<\brief deviceHash of remote device */
}CSR_MESH_APPEARANCE_T;

/*! \brief CSR Mesh transmit state */
typedef struct __attribute__((__packed__))
{
    CsrUint16 bearerRelayActive; /*!< \brief Bit field of active relay bearers that are used to relay messages to. */
    CsrUint16 bearerEnabled; /*!< \brief Bit field of enabled bearers */
    CsrUint16 bearerPromiscuous; /*!< \brief Relay all messages, regardless of MAC */
    CsrBool maspRelayState; /*!< \brief MaspRelay state */
    CsrBool mcpRelayState; /*!< \brief MCP relay state */
    CsrBool promiscuousState; /*!< \brief promiscuous state */
} CSR_MESH_TRANSMIT_STATE_T;

/*! \brief CSRmesh Device Appearance. The Appearance  has short name and CSR_MESH_APPEARANCE_T structure */
typedef struct
{
    CsrUint8 shortName[CSR_MESH_SHORT_NAME_LENGTH]; /*!< \brief short name of the device */
    CSR_MESH_APPEARANCE_T apperance; /*!< \brief deviceApperance of the device */
}CSR_MESH_DEVICE_APPEARANCE_T;

typedef enum
{
    CSR_MESH_INIT_EVENT                    = 0x0001,
    CSR_MESH_REGISTER_APP_CB_EVENT         = 0x0002,
    CSR_MESH_RESET_EVENT                   = 0x0003,
    CSR_MESH_START_EVENT                   = 0x0004,
    CSR_MESH_STOP_EVENT                    = 0x0005,
    CSR_MESH_RELAY_STATE_EVENT             = 0x0006,
    CSR_MESH_START_DEVICE_INQUIRY_EVENT    = 0x0007,
    CSR_MESH_ASSOC_STARTED_EVENT           = 0x0008,
    CSR_MESH_ASSOC_COMPLETE_EVENT          = 0x0009,
    CSR_MESH_SEND_ASSOC_COMPLETE_EVENT     = 0x000A,
    CSR_MESH_GET_DEVICE_ID_EVENT           = 0x000B,
    CSR_MESH_GET_DEVICE_UUID_EVENT         = 0x000C,
    CSR_MESH_MASP_DEVICE_IND_EVENT         = 0x000D,
    CSR_MESH_MASP_DEVICE_APPEARANCE_EVENT  = 0x000E,
    CSR_MESH_NETWORK_ID_LIST_EVENT         = 0x000F,
    CSR_MESH_SET_MAX_NO_OF_NETWORK_EVENT   = 0x0010,
    CSR_MESH_SET_PASSPHRASE_EVENT          = 0x0011,
    CSR_MESH_SET_NETWORK_KEY_EVENT         = 0x0012,
    CSR_MESH_CONFIG_RESET_DEVICE_EVENT     = 0x0013,
    CSR_MESH_CONFIG_SET_PARAMS_EVENT       = 0x0014,
    CSR_MESH_CONFIG_GET_PARAMS_EVENT       = 0x0015,
    CSR_MESH_GET_VID_PID_VERSTION_EVENT    = 0x0016,
    CSR_MESH_GET_DEVICE_APPEARANCE_EVENT   = 0x0017,
    CSR_MESH_GROUP_SET_MODEL_GROUPID_EVENT = 0x0018,
    CSR_MESH_SEND_RAW_MCP_MSG_EVENT        = 0x0019,
    CSR_MESH_SEND_MCP_MSG_EVENT            = 0x001A,
    CSR_MESH_MCP_REGISTER_MODEL_EVENT      = 0x001B,
    CSR_MESH_MCP_REGISTER_MODEL_CLIENT_EVENT = 0x001C,
    CSR_MESH_REMOVE_NETWORK_EVENT          = 0x001D,
    CSR_MESH_PROMISCUOUS_MODE_EVENT        = 0x001E,
    CSR_MESH_GET_DIAG_DATA_EVENT           = 0x001F,
    CSR_MESH_RESET_DIAG_DATA_EVENT         = 0x0020,
    CSR_MESH_REGISTER_SNIFFER_APP_CB_EVENT = 0x0021,
    CSR_MESH_GET_MESH_ID_EVENT             = 0x0022,
    CSR_MESH_GET_NET_ID_FROM_MESH_ID_EVENT = 0x0023,
    CSR_MESH_INVALID_EVENT                 = 0xFFFF
} CSR_MESH_EVENT_T;

/*! \brief Operation status passed with App-Callback to indicate the result of an
 *  asynchronous operation or to inform the App that the callback is mader to request info
 */
typedef enum
{
    CSR_MESH_OPERATION_SUCCESS                = 0x00, /*!< \brief Operation status success  */
    CSR_MESH_OPERATION_STACK_NOT_INITIALIZED  = 0x01, /*!< \brief Operation status stack not initialized */
    CSR_MESH_OPERATION_NOT_PERMITTED          = 0x02, /*!< \brief Operation status operation not permited */
    CSR_MESH_OPERATION_MEMORY_FULL            = 0x03, /*!< \brief Operation status memory full */
    CSR_MESH_OPERATION_REQUEST_FOR_INFO       = 0x04, /*!< \brief Operation status request for info to app */
    CSR_MESH_OPERATION_GENERIC_FAIL           = 0xFF, /*!< \brief Operation status generic fail */
} CSR_MESH_OPERATION_STATUS_T;

/*! \brief CSR Mesh App Event Data - to provide event, status * app data to app */
typedef struct
{
    CSR_MESH_EVENT_T              event;  /*!< \brief CSR Mesh Event */
    CSR_MESH_OPERATION_STATUS_T  status;  /*!< \brief CSR Mesh Operation Status */
    void *appCallbackDataPtr;  /*!< \brief App Data */
}CSR_MESH_APP_EVENT_DATA_T;

typedef void (*CSR_MESH_APP_CB_T) (CSR_MESH_APP_EVENT_DATA_T eventDataCallback);
typedef void (*CSR_MESH_APP_MASP_CB_T) (const CsrUint8* message, 
                                        CsrUint8 length,
                                        CsrUint8 rx_ttl,
                                        CsrInt8 rx_rssi);
typedef void (*CSR_MESH_APP_MCP_CB_T) (CsrUint8 netId, 
                                       const CsrUint8* message, 
                                       CsrUint8 length,
                                       CsrUint8 rx_ttl,
                                       CsrInt8 rx_rssi);
//#endif
/*!@} */
#endif /* _CSR_MESH_TYPES_H_ */
