/*****************************************************************************
 *
 * Copyright [2015] Qualcomm Technologies International, Ltd.
 *
 *
 ****************************************************************************/
/* Note: this is an auto-generated file. */


#ifndef __CSR_MESH_MODEL_COMMON__
#define __CSR_MESH_MODEL_COMMON__

#include "csr_types.h"
#include "csr_mesh_result.h"


#define  Mem_Alloc  CsrPmemAlloc
#define  Mem_Free     CsrPmemFree
#define  Mem_Set  CsrPmemSet
#define  Mem_Cpy     CsrPmemCpy
#define  sendToSB     CsrSendMesh


/*! \brief CSRmesh Model Event Code types */
typedef enum
{
    /*  model Messages */
    CSRMESH_WATCHDOG_MESSAGE = 0x00,
    CSRMESH_WATCHDOG_SET_INTERVAL = 0x01,
    CSRMESH_WATCHDOG_INTERVAL = 0x02,
    CSRMESH_CONFIG_LAST_SEQUENCE_NUMBER = 0x03,
    CSRMESH_CONFIG_RESET_DEVICE = 0x04,
    CSRMESH_CONFIG_SET_DEVICE_IDENTIFIER = 0x05,
    CSRMESH_CONFIG_SET_PARAMETERS = 0x06,
    CSRMESH_CONFIG_GET_PARAMETERS = 0x07,
    CSRMESH_CONFIG_PARAMETERS = 0x08,
    CSRMESH_CONFIG_DISCOVER_DEVICE = 0x09,
    CSRMESH_CONFIG_DEVICE_IDENTIFIER = 0x0A,
    CSRMESH_CONFIG_GET_INFO = 0x0B,
    CSRMESH_CONFIG_INFO = 0x0C,
    CSRMESH_GROUP_GET_NUMBER_OF_MODEL_GROUPIDS = 0x0D,
    CSRMESH_GROUP_NUMBER_OF_MODEL_GROUPIDS = 0x0E,
    CSRMESH_GROUP_SET_MODEL_GROUPID = 0x0F,
    CSRMESH_GROUP_GET_MODEL_GROUPID = 0x10,
    CSRMESH_GROUP_MODEL_GROUPID = 0x11,
    CSRMESH_SENSOR_GET_TYPES = 0x20,
    CSRMESH_SENSOR_TYPES = 0x21,
    CSRMESH_SENSOR_SET_STATE = 0x22,
    CSRMESH_SENSOR_GET_STATE = 0x23,
    CSRMESH_SENSOR_STATE = 0x24,
    CSRMESH_SENSOR_WRITE_VALUE_NO_ACK = 0x26,
    CSRMESH_SENSOR_WRITE_VALUE = 0x25,
    CSRMESH_SENSOR_READ_VALUE = 0x27,
    CSRMESH_SENSOR_VALUE = 0x28,
    CSRMESH_SENSOR_MISSING = 0x29,
    CSRMESH_ACTUATOR_GET_TYPES = 0x30,
    CSRMESH_ACTUATOR_TYPES = 0x31,
    CSRMESH_ACTUATOR_SET_VALUE_NO_ACK = 0x32,
    CSRMESH_ACTUATOR_SET_VALUE = 0x33,
    CSRMESH_ACTUATOR_VALUE_ACK = 0x34,
    CSRMESH_DATA_STREAM_FLUSH = 0x70,
    CSRMESH_DATA_STREAM_SEND = 0x71,
    CSRMESH_DATA_STREAM_RECEIVED = 0x72,
    CSRMESH_DATA_BLOCK_SEND = 0x73,
    CSRMESH_BEARER_SET_STATE = 0x8100,
    CSRMESH_BEARER_GET_STATE = 0x8101,
    CSRMESH_BEARER_STATE = 0x8102,
    CSRMESH_PING_REQUEST = 0x8200,
    CSRMESH_PING_RESPONSE = 0x8201,
    CSRMESH_BATTERY_GET_STATE = 0x8300,
    CSRMESH_BATTERY_STATE = 0x8301,
    CSRMESH_ATTENTION_SET_STATE = 0x8400,
    CSRMESH_ATTENTION_STATE = 0x8401,
    CSRMESH_POWER_SET_STATE_NO_ACK = 0x8900,
    CSRMESH_POWER_SET_STATE = 0x8901,
    CSRMESH_POWER_TOGGLE_STATE_NO_ACK = 0x8902,
    CSRMESH_POWER_TOGGLE_STATE = 0x8903,
    CSRMESH_POWER_GET_STATE = 0x8904,
    CSRMESH_POWER_STATE_NO_ACK = 0x8906,
    CSRMESH_POWER_STATE = 0x8905,
    CSRMESH_LIGHT_SET_LEVEL_NO_ACK = 0x8A00,
    CSRMESH_LIGHT_SET_LEVEL = 0x8A01,
    CSRMESH_LIGHT_SET_RGB_NO_ACK = 0x8A02,
    CSRMESH_LIGHT_SET_RGB = 0x8A03,
    CSRMESH_LIGHT_SET_POWER_LEVEL_NO_ACK = 0x8A04,
    CSRMESH_LIGHT_SET_POWER_LEVEL = 0x8A05,
    CSRMESH_LIGHT_SET_COLOR_TEMP = 0x8A06,
    CSRMESH_LIGHT_GET_STATE = 0x8A07,
    CSRMESH_LIGHT_STATE_NO_ACK = 0x8A09,
    CSRMESH_LIGHT_STATE = 0x8A08,
    CSRMESH_MODEL_CFM = 0xFFFF/*!< \brief Model Request Confirmation */

}CSRMESH_MODEL_EVENT_T;



/*! \brief CSRmesh device power state */
typedef enum
{
    POWER_STATE_OFF = 0,            /*!< \brief Device is in OFF state */
    POWER_STATE_ON = 1,             /*!< \brief Device is in ON state */
    POWER_STATE_STANDBY = 2,        /*!< \brief Device is in STANDBY state */
    POWER_STATE_ON_FROM_STANDBY = 3 /*!< \brief Device returned to ON state from STANDBY
                                     * state
                                     */
}POWER_STATE_T;

/*! \brief CSRmesh sniffed message data */
typedef struct
{
    CsrUint8 rx_ttl;  /*!< \brief CSRmesh  Rxd TTL  value*/
    CsrInt8 rx_rssi;  /*!< \brief CSRmesh  Rxd RSSI value */
}CSRMESH_EVENT_SNIFFED_DATA_T;

/*! \brief CSRmesh event data returned in the model callback */
typedef struct
{
    CsrUint8 nw_id; /*!<\brief CSRmesh network ID over which the message is received */
    CsrUint32 seq_num; /*!< \brief MCP sequence number of message */
    CsrUint16 src_id; /*!< \brief 16 bet ID of the device which sent the message */
    CsrUint16 dst_id; /*!< \brief 16 bit ID of the device/group to which the message was sent */
    void   *data; /*!< \brief Pointer to the event specific data structure */
    CSRMESH_EVENT_SNIFFED_DATA_T   *sniffed_data; /*!<\brief Pointer to CSRMESH_EVENT_SNIFFED_DATA_T, valid only for sniffed messages */
}CSRMESH_EVENT_DATA_T;

/*! \brief MCP Model handler function type */
typedef CSRmeshResult (*CSRMESH_MODEL_CALLBACK_T)(CSRMESH_MODEL_EVENT_T event_code, CSRMESH_EVENT_DATA_T* event_data,CsrUint16 length, void **state_data);


#endif /* __CSR_MESH_MODEL_COMMON__ */

