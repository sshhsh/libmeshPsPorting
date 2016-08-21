#ifndef __CSR_MESH_GW_PRIM_H__
#define __CSR_MESH_GW_PRIM_H__

/*****************************************************************************
 *
 * Copyright [2015] Qualcomm Technologies International, Ltd.
 *
 *****************************************************************************/

/*! \file csr_mesh_gateway_prim.h
 * \brief Declares the macros and structures  provided by CSRmesh Core module
 * \addtogroup CSRmesh
 * @{
 *  \brief  <br>  Declares  the macros and structures provided by CSRmesh Core module
 *
 */
 
#include "csr_types.h"
#include "csr_mesh_types.h"
#include "csr_mesh_gateway_config.h"
#include "csr_mesh_model_common.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CSR_INSTRUCTION_TYPE_CSRMESH                        (0)
#define CSR_INSTRUCTION_TYPE_INITIALIZE                     (10)
#define CSR_INSTRUCTION_TYPE_MESSAGE                        (11)

#define CSR_MESH_MSG_CLS_TYPE_CORE                          CSR_INSTRUCTION_TYPE_CSRMESH
#define CSR_MESH_MSG_CLS_TYPE_INIT                          CSR_INSTRUCTION_TYPE_INITIALIZE
#define CSR_MESH_MSG_CLS_TYPE_MODELS                        CSR_INSTRUCTION_TYPE_MESSAGE
#define CSR_MESH_MSG_CLS_TYPE_MODELS_CFM                    12

#define CSR_INSTRUCTION_INITIALIZE_PACKET_SIZE              5 /* 2 packet size + 1  instruction type + 2 opcode*/
#define CSR_INSTRUCTION_INITIALIZE_MESSAGE_SIZE             3 /* 1 instruction type + 2 opcode*/

#define CSR_INSTRUCTION_MESSAGE_HEADER_LEN                  5 /* packet size + instruction type + opcode + nwid + devid */

#define CSR_INSTRUCTION_MESSAGE_SB_TO_NB_HEADER_SIZE        15 /* 2 packet size + 1 instruction type + 2 opcode + 1 nwid + 2 srcdevid + 2destdevid + 4seqno + 1 is_sniffed */
#define CSR_INSTRUCTION_MESSAGE_NB_TO_SB_HEADER_SIZE        8 /* 2 packet size + 1 instruction type + 2 opcode + 1 nwid + 2destdevid */

#define CSR_MESH_RSP_CFM_HDR_LEN                            3
#define CSR_MESH_SNIFF_MASP_MSG_HDR_LEN                     3
#define CSR_MESH_SNIFF_MCP_MSG_HDR_LEN                      4

#define CSR_GW_UUID_LENGTH                                  (16)
#define CSR_MESH_ID_LENGTH                                  (16)
#define CSR_MESH_NETWORK_KEY_LENGTH                         (16)


/*! \brief CSRmesh primitive Type*/
typedef CsrUint16  CSRMeshPrim;



#define CSR_MESH_PRIM_BASE                                  (0x0000)

#define CSR_MESH_INIT_REQ                                   ((CSRMeshPrim) (0x0000 + CSR_MESH_PRIM_BASE))
#define CSR_MESH_START_REQ                                  ((CSRMeshPrim) (0x0001 + CSR_MESH_PRIM_BASE))
#define CSR_MESH_STOP_REQ                                   ((CSRMeshPrim) (0x0002 + CSR_MESH_PRIM_BASE))
#define CSR_MESH_RESET_REQ                                  ((CSRMeshPrim) (0x0003 + CSR_MESH_PRIM_BASE))
#define CSR_MESH_SET_NETWORK_KEY_REQ                        ((CSRMeshPrim) (0x0004 + CSR_MESH_PRIM_BASE))
#define CSR_MESH_SET_PASSPHRASE_REQ                         ((CSRMeshPrim) (0x0005 + CSR_MESH_PRIM_BASE))
#define CSR_MESH_REMOVE_NETWORK_REQ                         ((CSRMeshPrim) (0x0006 + CSR_MESH_PRIM_BASE))
#define CSR_MESH_GET_NETID_LIST_REQ                         ((CSRMeshPrim) (0x0007 + CSR_MESH_PRIM_BASE))
#define CSR_MESH_SET_MAX_NO_OF_NETWORK_REQ                  ((CSRMeshPrim) (0x0008 + CSR_MESH_PRIM_BASE))
#define CSR_MESH_GET_DEVICE_ID_REQ                          ((CSRMeshPrim) (0x0009 + CSR_MESH_PRIM_BASE))
#define CSR_MESH_GET_DEVICE_UUID_REQ                        ((CSRMeshPrim) (0x000A + CSR_MESH_PRIM_BASE))
#define CSR_MESH_SET_TRANSMIT_STATE_REQ                     ((CSRMeshPrim) (0x000B + CSR_MESH_PRIM_BASE))
#define CSR_MESH_GET_TRANSMIT_STATE_REQ                     ((CSRMeshPrim) (0x000C + CSR_MESH_PRIM_BASE))
#define CSR_MESH_RESET_DIAGNOSTIC_DATA_REQ                  ((CSRMeshPrim) (0x000D + CSR_MESH_PRIM_BASE))
#define CSR_MESH_GET_DIAGNOSTIC_DATA_REQ                    ((CSRMeshPrim) (0x000E + CSR_MESH_PRIM_BASE))

#define CSR_MESH_START_DEVICE_INQUIRY_REQ                   ((CSRMeshPrim) (0x000F + CSR_MESH_PRIM_BASE))
#define CSR_MESH_ASSOCIATE_TO_A_NETWORK_REQ                 ((CSRMeshPrim) (0x0010 + CSR_MESH_PRIM_BASE))
#define CSR_MESH_SEND_ASSOCIATION_REQUEST_REQ               ((CSRMeshPrim) (0x0011 + CSR_MESH_PRIM_BASE))

#define CSR_MESH_REGISTER_SNIFFER_REQ                       ((CSRMeshPrim) (0x0012 + CSR_MESH_PRIM_BASE))

#define CSR_MESH_FIND_MESHID_REQ                            ((CSRMeshPrim) (0x0013 + CSR_MESH_PRIM_BASE))
#define CSR_MESH_FIND_NETID_REQ                             ((CSRMeshPrim) (0x0014 + CSR_MESH_PRIM_BASE))

#define CSR_MESH_PRIM_BASE_HIGHEST                          ((CSRMeshPrim) (0x0014 + CSR_MESH_PRIM_BASE))

#define CSR_MESH_PRIM_RESPONSE_BASE                         (0x8000)

#define CSR_MESH_INIT_CFM                                   ((CSRMeshPrim) (0x0000 + CSR_MESH_PRIM_RESPONSE_BASE))
#define CSR_MESH_START_CFM                                  ((CSRMeshPrim) (0x0001 + CSR_MESH_PRIM_RESPONSE_BASE))
#define CSR_MESH_STOP_CFM                                   ((CSRMeshPrim) (0x0002 + CSR_MESH_PRIM_RESPONSE_BASE))
#define CSR_MESH_RESET_CFM                                  ((CSRMeshPrim) (0x0003 + CSR_MESH_PRIM_RESPONSE_BASE))
#define CSR_MESH_SET_NETWORK_KEY_CFM                        ((CSRMeshPrim) (0x0004 + CSR_MESH_PRIM_RESPONSE_BASE))
#define CSR_MESH_SET_PASSPHRASE_CFM                         ((CSRMeshPrim) (0x0005 + CSR_MESH_PRIM_RESPONSE_BASE))
#define CSR_MESH_REMOVE_NETWORK_CFM                         ((CSRMeshPrim) (0x0006 + CSR_MESH_PRIM_RESPONSE_BASE))
#define CSR_MESH_GET_NETID_LIST_CFM                         ((CSRMeshPrim) (0x0007 + CSR_MESH_PRIM_RESPONSE_BASE))
#define CSR_MESH_SET_MAX_NO_OF_NETWORK_CFM                  ((CSRMeshPrim) (0x0008 + CSR_MESH_PRIM_RESPONSE_BASE))
#define CSR_MESH_GET_DEVICE_ID_CFM                          ((CSRMeshPrim) (0x0009 + CSR_MESH_PRIM_RESPONSE_BASE))
#define CSR_MESH_GET_DEVICE_UUID_CFM                        ((CSRMeshPrim) (0x000A + CSR_MESH_PRIM_RESPONSE_BASE))
#define CSR_MESH_SET_TRANSMIT_STATE_CFM                     ((CSRMeshPrim) (0x000B + CSR_MESH_PRIM_RESPONSE_BASE))
#define CSR_MESH_GET_TRANSMIT_STATE_CFM                     ((CSRMeshPrim) (0x000C + CSR_MESH_PRIM_RESPONSE_BASE))
#define CSR_MESH_RESET_DIAGNOSTIC_DATA_CFM                  ((CSRMeshPrim) (0x000D + CSR_MESH_PRIM_RESPONSE_BASE))
#define CSR_MESH_GET_DIAGNOSTIC_DATA_CFM                    ((CSRMeshPrim) (0x000E + CSR_MESH_PRIM_RESPONSE_BASE))
#define CSR_MESH_START_DEVICE_INQUIRY_CFM                   ((CSRMeshPrim) (0x000F + CSR_MESH_PRIM_RESPONSE_BASE))
#define CSR_MESH_ASSOCIATE_TO_A_NETWORK_CFM                 ((CSRMeshPrim) (0x0010 + CSR_MESH_PRIM_RESPONSE_BASE))
#define CSR_MESH_SEND_ASSOCIATION_REQUEST_CFM               ((CSRMeshPrim) (0x0011 + CSR_MESH_PRIM_RESPONSE_BASE))
#define CSR_MESH_MASP_INQUIRY_DEVICE_IND                    ((CSRMeshPrim) (0x0012 + CSR_MESH_PRIM_RESPONSE_BASE))

#define CSR_MESH_ASSOC_STARTED_IND                          ((CSRMeshPrim) (0x0013 + CSR_MESH_PRIM_RESPONSE_BASE))
#define CSR_MESH_ASSOC_COMPLETE_IND                         ((CSRMeshPrim) (0x0014 + CSR_MESH_PRIM_RESPONSE_BASE))

#define CSR_MESH_REGISTER_SNIFFER_CFM                       ((CSRMeshPrim) (0x0015 + CSR_MESH_PRIM_RESPONSE_BASE))

#define CSR_MESH_FIND_MESHID_CFM                            ((CSRMeshPrim) (0x0016 + CSR_MESH_PRIM_RESPONSE_BASE))
#define CSR_MESH_FIND_NETID_CFM                             ((CSRMeshPrim) (0x0017 + CSR_MESH_PRIM_RESPONSE_BASE))
#define CSR_MESH_CONFIG_RESET_DEVICE_IND                    ((CSRMeshPrim) (0x0018 + CSR_MESH_PRIM_RESPONSE_BASE))

#define CSR_MESH_PRIM_RESPONSE_BASE_HIGHEST                 ((CSRMeshPrim) (0x0018 + CSR_MESH_PRIM_RESPONSE_BASE))

#define CSR_MESH_GW_NUMBER_OF_STATES 1
#define CSR_MESH_PRIM_DOWNSTREAM_COUNT (CSR_MESH_PRIM_BASE_HIGHEST + 1 - CSR_MESH_PRIM_BASE)
#define CSR_MESH_PRIM_UPSTREAM_COUNT (CSR_MESH_PRIM_RESPONSE_BASE_HIGHEST + 1 - CSR_MESH_PRIM_RESPONSE_BASE)

/*! \brief CSRmesh core Event types */
typedef enum
{
    CSRMESH_START_EVENT = CSR_MESH_START_CFM,  /*!< \brief CSR Mesh Event for Mesh Start Request */ 
    CSRMESH_STOP_EVENT = CSR_MESH_STOP_CFM,  /*!< \brief CSR Mesh Event for Mesh Stop Request */
    CSRMESH_RESET_EVENT = CSR_MESH_RESET_CFM,  /*!< \brief CSR Mesh Event for Mesh Reset Request */
    CSRMESH_SET_NETWORK_KEY_EVENT = CSR_MESH_SET_NETWORK_KEY_CFM,  /*!< \brief CSR Mesh Event for Mesh Set Nw Key Request */ 
    CSRMESH_SET_PASSPHRASE_EVENT = CSR_MESH_SET_PASSPHRASE_CFM,  /*!< \brief CSR Mesh Event for Mesh Set PassPhrase Request */
    CSRMESH_REMOVE_NETWORK_EVENT = CSR_MESH_REMOVE_NETWORK_CFM,  /*!< \brief CSR Mesh Event for Mesh Remove Nw Request */
    CSRMESH_NETWORK_ID_LIST_EVENT = CSR_MESH_GET_NETID_LIST_CFM,  /*!< \brief CSR Mesh Event for Mesh Get Nw ID List Request */ 
    CSRMESH_SET_MAX_NO_OF_NETWORK_EVENT = CSR_MESH_SET_MAX_NO_OF_NETWORK_CFM,  /*!< \brief CSR Mesh Event for Mesh Set Max No of Nw Request */ 
    CSRMESH_GET_DEVICE_ID_EVENT = CSR_MESH_GET_DEVICE_ID_CFM,  /*!< \brief CSR Mesh Event for Mesh Get Device ID Request */ 
    CSRMESH_GET_DEVICE_UUID_EVENT = CSR_MESH_GET_DEVICE_UUID_CFM,  /*!< \brief CSR Mesh Event for Mesh Get Device UUID Request */ 
    CSRMESH_SET_TARNSMIT_STATE_EVENT = CSR_MESH_SET_TRANSMIT_STATE_CFM,  /*!< \brief CSR Mesh Event for Mesh Set Transmit State Request */ 
    CSRMESH_GET_TARNSMIT_STATE_EVENT = CSR_MESH_GET_TRANSMIT_STATE_CFM,  /*!< \brief CSR Mesh Event for Mesh Get Transmit State Request */ 
    CSRMESH_RESET_DIAG_DATA_EVENT = CSR_MESH_RESET_DIAGNOSTIC_DATA_CFM,  /*!< \brief CSR Mesh Event for Mesh Reset diag Data Request */ 
    CSRMESH_GET_DIAG_DATA_EVENT = CSR_MESH_GET_DIAGNOSTIC_DATA_CFM,  /*!< \brief CSR Mesh Event for Mesh get Diag Data Request */ 
    CSRMESH_START_DEVICE_INQUIRY_EVENT = CSR_MESH_START_DEVICE_INQUIRY_CFM,  /*!< \brief CSR Mesh Event for Mesh Start Device InquiryRequest */ 
    CSRMESH_ASSOC_TO_A_NETWORK_EVENT = CSR_MESH_ASSOCIATE_TO_A_NETWORK_CFM,  /*!< \brief CSR Mesh Event for Mesh Associate To Nw Request */ 
    CSRMESH_SEND_ASSOC_RESPONSE_EVENT = CSR_MESH_SEND_ASSOCIATION_REQUEST_CFM,  /*!< \brief CSR Mesh Event for Mesh Send Association Response Request */ 
    CSRMESH_START_DEVICE_DISCOVERED_EVENT = CSR_MESH_MASP_INQUIRY_DEVICE_IND,  /*!< \brief CSR Mesh Indication for Mesh Start Device discovered */ 
    CSRMESH_ASSOC_STARTED_EVENT = CSR_MESH_ASSOC_STARTED_IND,  /*!< \brief CSR Mesh Indication  for Mesh  Association Started  */ 
    CSRMESH_ASSOC_COMPLETE_EVENT = CSR_MESH_ASSOC_COMPLETE_IND,  /*!< \brief CSR Mesh Indication for Mesh Association completed */ 
    CSRMESH_REGISTER_SNIFFER_EVENT = CSR_MESH_REGISTER_SNIFFER_CFM,  /*!< \brief CSR Mesh Event for Mesh Register sniffer Request */ 
    CSRMESH_FIND_MESHID_EVENT = CSR_MESH_FIND_MESHID_CFM,  /*!< \brief CSR Mesh Event for Mesh Find Mesh Id Request */ 
    CSRMESH_FIND_NETID_EVENT = CSR_MESH_FIND_NETID_CFM,  /*!< \brief CSR Mesh Event for Mesh Find Net Id Request */ 
    CSRMESH_CONFIG_RESET_DEVICE_EVENT = CSR_MESH_CONFIG_RESET_DEVICE_IND  /*!< \brief CSR Mesh Reset Device Indication  */ 
} CSR_MESH_CORE_EVENT_T;

/*! \brief CSR Mesh  structure for Mesh Start request */ 
typedef struct
{
    CSRMeshPrim type;   /*!< \brief CSRmesh Gateway primitive */
}CSR_MESH_START_REQ_T;

/*! \brief CSR Mesh  structure for Mesh Stop request */ 
typedef struct
{
    CSRMeshPrim type;   /*!< \brief CSRmesh Gateway primitive */
}CSR_MESH_STOP_REQ_T;

/*! \brief CSR Mesh  structure for Mesh Reset request */ 
typedef struct
{
    CSRMeshPrim type;   /*!< \brief CSRmesh Gateway primitive */
}CSR_MESH_RESET_REQ_T;

/*! \brief CSR Mesh  structure for Mesh set Nw Key request */ 
typedef struct
{
    CSRMeshPrim type;   /*!< \brief CSRmesh Gateway primitive */
    CsrUint16 deviceId;   /*!< \brief CSRmesh device ID */
    CsrUint8 networkKey[CSR_MESH_NETWORK_KEY_LENGTH];   /*!< \brief CSRmesh 8 octet size Network key */
}CSR_MESH_SET_NETWORK_KEY_REQ_T;

/*! \brief CSR Mesh  structure for Mesh Remove Nw request */ 
typedef struct
{
    CSRMeshPrim type;   /*!< \brief CSRmesh Gateway primitive */
    CsrUint8 netid;     /*!< \brief Network ID of the network to be removed */
}CSR_MESH_REMOVE_NETWORK_REQ_T;

/*! \brief CSR Mesh  structure for Mesh Get Nw Id list */ 
typedef struct
{
    CSRMeshPrim type;   /*!< \brief CSRmesh Gateway primitive */
}CSR_MESH_GET_NETID_LIST_REQ_T;

/*! \brief CSR Mesh  structure for Mesh Set PassPhrase Request */ 
typedef struct
{
    CSRMeshPrim type;           /*!< \brief CSRmesh Gateway primitive */
    CsrUint8  passPhraseLength; /*!< \brief Length of the passPhrase */
    CsrUint8* passPhrase;       /*!< \brief The string passphrase using which a NW key will be generated */
    CsrUint16 deviceId;         /*!< \brief 16 bit device ID assigned to the local device */
} CSR_MESH_SET_PASSPHRASE_REQ_T;

/*! \brief CSR Mesh  structure for Mesh Get Device Id request */ 
typedef struct
{
    CSRMeshPrim type;   /*!< \brief CSRmesh Gateway primitive */
    CsrUint8 netId;   /*!< \brief CSRmesh Mesh network ID  for  the requested device ID */
}CSR_MESH_GET_DEVICE_ID_REQ_T;

/*! \brief CSR Mesh  structure for Mesh Get Device UUID request */ 
typedef struct
{
    CSRMeshPrim type;   /*!< \brief CSRmesh Gateway primitive */
}CSR_MESH_GET_DEVICE_UUID_REQ_T;

/*! \brief CSR Mesh  structure for Mesh Set Transmit State request */ 
typedef struct __attribute__((__packed__))
{
    CSRMeshPrim type;   /*!< \brief CSRmesh Gateway primitive */
    CsrUint8 netId;   /*!< \brief CSRmesh Mesh Network ID for the requested Transmit state */
    CSR_MESH_TRANSMIT_STATE_T transmitState;
}CSR_MESH_SET_TRANSMIT_STATE_REQ_T;

/*! \brief CSR Mesh  structure for Mesh Get Transmit State request */ 
typedef struct
{
    CSRMeshPrim type;   /*!< \brief CSRmesh Gateway primitive */
    CsrUint8 netId;   /*!< \brief CSRmesh Mesh ID  */
}CSR_MESH_GET_TRANSMIT_STATE_REQ_T;

/*! \brief CSR Mesh  structure for Reset Diagnostic Data */ 
typedef struct
{
    CSRMeshPrim type;   /*!< \brief CSRmesh Gateway primitive */
}CSR_MESH_RESET_DIAGNOSTIC_DATA_REQ_T;

/*! \brief CSR Mesh  structure for Get Diagnostic Data */ 
typedef struct __attribute__((__packed__))
{
    CSRMeshPrim type;   /*!< \brief CSRmesh Gateway primitive */
    CSR_MESH_DIAGNOSTIC_CONFIG_MASK_T diagnosticMask; /*!< \brief  config mask required */
}CSR_MESH_GET_DIAGNOSTIC_DATA_REQ_T;

/*! \brief CSR Mesh  structure for Mesh associate to Nw request */
typedef struct __attribute__((__packed__))
{
    CSRMeshPrim  type;   /*!< \brief CSRmesh Gateway primitive */
    CSR_MESH_DEVICE_APPEARANCE_T  devApper;  /*!< \brief device appearance  */
    CsrUint8  ttl;       /*!< \brief Time-To-Live  */
}CSR_MESH_ASSOCIATE_TO_A_NETWORK_REQ_T;

/*! \brief CSR Mesh  structure for  Mesh Register Sniffer Request*/
typedef struct
{
    CSRMeshPrim type;   /*!< \brief CSRmesh Gateway primitive */
    CsrBool    enable;  /*!< \brief IF True receive sniffer messages otherwise stop receiving sniffer messages */
}CSR_MESH_REGISTER_SNIFFER_REQ_T;

/*! \brief CSR Mesh  structure for Mesh Find Mesh Id request */
typedef struct
{
    CSRMeshPrim type;   /*!< \brief CSRmesh Gateway primitive */
    CsrUint8   netId;   /*!< \brief Network ID of the network for which Mesh ID is required */
}CSR_MESH_FIND_MESHID_REQ_T;

/*! \brief CSR Mesh  structure for Mesh find Nw Id request */
typedef struct
{
    CSRMeshPrim type;   /*!< \brief CSRmesh Gateway primitive */
    CsrUint8   meshId[CSR_MESH_ID_LENGTH];   /*!< \brief CSRmesh Mesh ID  */
}CSR_MESH_FIND_NETID_REQ_T;

/*! \brief CSR Mesh  structure for Mesh Model Confirm Info*/
typedef struct __attribute__((__packed__))
{
    CSRMESH_MODEL_EVENT_T    modelEvent;    /*!< \brief Request CSRmesh Gateway primitive */
    CSRmeshResult            status;        /*!< \brief Request Status */
    CsrUint16                destDevId;     /*!< \brief Destination Device Id */
    CsrUint8                 nwkId;         /*!< \brief Network Id */
    CsrUint8                 tid;           /*!< \brief Request tid  */
}CSR_MESH_MODEL_CFM_INFO_T;

/*! \brief CSR Mesh  structure for Mesh Model Confirm event*/
typedef struct __attribute__((__packed__))
{
    CSRMESH_MODEL_EVENT_T      event;      /*!<\brief CSRMESH_MODEL_EVENT_T  : CSRMESH_MODEL_CFM (0xFFFF) */
    CSR_MESH_MODEL_CFM_INFO_T    data;       /*!<\brief  Request Failure Info */
}CSR_MESH_MODEL_CFM_EVT_T;

/* Core APIs confirmations */
/*! \brief CSR Mesh  structure for Mesh Start confirm */
typedef struct __attribute__((__packed__))
{
    CSRMeshPrim type;   /*!< \brief CSRmesh Gateway primitive */
    CSRmeshResult status;   /*!< \brief Message status */
}CSR_MESH_START_CFM_T;

/*! \brief CSR Mesh  structure for Mesh Stop confirm */
typedef struct __attribute__((__packed__))
{
    CSRMeshPrim type;   /*!< \brief CSRmesh Gateway primitive */
    CSRmeshResult status;   /*!< \brief Message status */
}CSR_MESH_STOP_CFM_T;

/*! \brief CSR Mesh  structure for Mesh Reset confirm*/
typedef struct __attribute__((__packed__))
{
    CSRMeshPrim type;   /*!< \brief CSRmesh Gateway primitive */
    CSRmeshResult status;   /*!< \brief Message status */
}CSR_MESH_RESET_CFM_T;

/*! \brief CSR Mesh  structure for Mesh Set Nw Key confirm*/
typedef struct __attribute__((__packed__))
{
    CSRMeshPrim type;   /*!< \brief CSRmesh Gateway primitive */
    CSRmeshResult status;   /*!< \brief Message status */
    CsrUint8 netId;   /*!< \brief CSRmesh  Network Id  */
}CSR_MESH_SET_NETWORK_KEY_CFM_T;

/*! \brief CSR Mesh  structure for Mesh Set PassPhrase confirm */
typedef struct __attribute__((__packed__))
{
    CSRMeshPrim type;   /*!< \brief CSRmesh Gateway primitive */
    CSRmeshResult status; /*!< \brief Message status */
    CsrUint8 netId;     /*!< \brief Network ID of the network */
}CSR_MESH_SET_PASSPHRASE_CFM_T;

/*! \brief CSR Mesh  structure for Mesh Remove Nw confirm*/
typedef struct __attribute__((__packed__))
{
    CSRMeshPrim type;   /*!< \brief CSRmesh Gateway primitive */
    CSRmeshResult status; /*!< \brief Message status */
}CSR_MESH_REMOVE_NETWORK_CFM_T;

/*! \brief CSR Mesh  structure for MEsh Get NETID List confirm*/
typedef struct __attribute__((__packed__))
{
    CSRMeshPrim type;   /*!< \brief CSRmesh Gateway primitive */
    CSRmeshResult status; /*!< \brief Message status */
    CSR_MESH_NETID_LIST_T    netIdList;   /*!< \brief CSRmesh  NetId List */
}CSR_MESH_GET_NETID_LIST_CFM_T;

/*! \brief CSR Mesh  structure for Mesh Set Max No of Nw confirm*/
typedef struct __attribute__((__packed__))
{
    CSRMeshPrim type;   /*!< \brief CSRmesh Gateway primitive */
    CSRmeshResult status; /*!< \brief Message status */
}CSR_MESH_SET_MAX_NO_OF_NETWORK_CFM_T;

/*! \brief CSR Mesh  structure for Mesh Get Device Id Confirm*/
typedef struct __attribute__((__packed__))
{
    CSRMeshPrim type;   /*!< \brief CSRmesh Gateway primitive */
    CSRmeshResult status;   /*!< \brief CSRmesh Message status */
    CsrUint16 deviceId;   /*!< \brief CSRmesh  Device ID */
}CSR_MESH_GET_DEVICE_ID_CFM_T;

/*! \brief CSR Mesh  structure for Mesh Get Device UUID Confirm*/
typedef struct __attribute__((__packed__))
{
    CSRMeshPrim type;   /*!< \brief CSRmesh Gateway primitive */
    CSRmeshResult status;   /*!< \brief CSRmesh Message status */
    CSR_MESH_UUID_T uuid;   /*!< \brief CSRmesh Device UUID */
}CSR_MESH_GET_DEVICE_UUID_CFM_T;

/*! \brief CSR Mesh  structure for Mesh Set Transmit State Confirm*/
typedef struct __attribute__((__packed__))
{
    CSRMeshPrim type;   /*!< \brief CSRmesh Gateway primitive */
    CSRmeshResult status;   /*!< \brief CSRmesh Message status */
    CSR_MESH_TRANSMIT_STATE_T tranmitState;   /*!< \brief CSRmesh Transmit state */
}CSR_MESH_SET_TRANSMIT_STATE_CFM_T; 

/*! \brief CSR Mesh  structure for Mesh Get Transmit State Confirm*/
typedef struct __attribute__((__packed__))
{
    CSRMeshPrim type;   /*!< \brief CSRmesh Gateway primitive */
    CSRmeshResult status;   /*!< \brief CSRmesh Message status */
    CSR_MESH_TRANSMIT_STATE_T tranmitState;   /*!< \brief CSRmesh Transmit state */
}CSR_MESH_GET_TRANSMIT_STATE_CFM_T;

/*! \brief CSR Mesh  structure for Mesh enable Promiscuous  Confirm*/
typedef struct __attribute__((__packed__))
{
    CSRMeshPrim type;   /*!< \brief CSRmesh Gateway primitive */
    CSRmeshResult status; /*!< \brief Message status */
}CSR_MESH_ENABLE_PROMISCUOUS_CFM_T;

/*! \brief CSR Mesh  structure for Mesh Is Promiscuous  Mode EnabledConfirm*/
typedef struct __attribute__((__packed__))
{
    CSRMeshPrim type;   /*!< \brief CSRmesh Gateway primitive */
    CSRmeshResult status; /*!< \brief Message status */
    CsrBool state;                      /*!< \brief Promiscuous state */
}CSR_MESH_IS_PROMISCUOUS_MODE_ENABLED_CFM_T;

/*! \brief CSR Mesh  structure for Mesh Reset Diagnostic DataConfirm*/
typedef struct __attribute__((__packed__))
{
    CSRMeshPrim type;   /*!< \brief CSRmesh Gateway primitive */
    CSRmeshResult status; /*!< \brief Message status */
}CSR_MESH_RESET_DIAGNOSTIC_DATA_CFM_T;

/*! \brief CSR Mesh  structure for Mesh Get diagnostic Data Confirm*/
typedef struct __attribute__((__packed__))
{
    CSRMeshPrim type;   /*!< \brief CSRmesh Gateway primitive */
    CSRmeshResult status; /*!< \brief Message status */
    CSR_MESH_DIAG_DATA_T diagData; /*< \brief diagnostic Data */
}CSR_MESH_GET_DIAGNOSTIC_DATA_CFM_T;

/*! \brief CSR Mesh  structure for Mesh Start Device Inquiry Confirm*/
typedef struct __attribute__((__packed__))
{
    CSRMeshPrim type;   /*!< \brief CSRmesh Gateway primitive */
    CSRmeshResult status; /*!< \brief Message status */
}CSR_MESH_START_DEVICE_INQUIRY_CFM_T;

/*! \brief CSR Mesh  structure for Mesh Associate to a Nw Confirm*/
typedef struct __attribute__((__packed__))
{
    CSRMeshPrim type;   /*!< \brief CSRmesh Gateway primitive */
    CSRmeshResult status; /*!< \brief Message status */
}CSR_MESH_ASSOCIATE_TO_A_NETWORK_CFM_T;
/*! \brief CSR Mesh  structure for Mesh Send Association Request Confirm*/
typedef struct __attribute__((__packed__))
{
    CSRMeshPrim type;   /*!< \brief CSRmesh Gateway primitive */
    CSRmeshResult status; /*!< \brief Message status */
}CSR_MESH_SEND_ASSOCIATION_REQUEST_CFM_T;

/*! \brief CSR Mesh  structure for  Mesh Masp Inquiry Device Indication*/
typedef struct __attribute__((__packed__))
{
    CSRMeshPrim type;   /*!< \brief CSRmesh Gateway primitive */
    CSRmeshResult status; /*!< \brief Message status */
    CSR_MESH_UUID_T uuid;               /*!< \brief UUID of the device */
}CSR_MESH_MASP_INQUIRY_DEVICE_IND_T;

/*! \brief CSR Mesh  structure for  Mesh Association StartedIndication*/
typedef struct  __attribute__((__packed__))
{
    CSRMeshPrim type;                   /*!< \brief CSRmesh Gateway primitive */
    CSRmeshResult status; /*!< \brief Message status */
}CSR_MESH_ASSOC_STARTED_IND_T;

/*! \brief CSR Mesh  structure for Mesh Association Completed Indication*/
typedef struct __attribute__((__packed__))
{
    CSRMeshPrim type;                   /*!< \brief CSRmesh Gateway primitive */
    CSRmeshResult status; /*!< \brief Message status */
    CsrUint8 netId;                     /*!< \brief Network ID of the network */
}CSR_MESH_ASSOC_COMPLETED_IND_T;
/*! \brief CSR Mesh  structure for Mesh config Reset Device Indication*/
typedef struct __attribute__((__packed__))
{
    CSRMeshPrim type;                   /*!< \brief CSRmesh Gateway primitive */
    CSRmeshResult status; /*!< \brief Message status */
}CSR_MESH_CONFIG_RESET_DEVICE_IND_T;

/*! \brief CSR Mesh  structure for Mesh Register Sniffer confirm*/
typedef struct __attribute__((__packed__))
{
    CSRMeshPrim type;                   /*!< \brief CSRmesh Gateway primitive */
    CSRmeshResult status; /*!< \brief Message status */
}CSR_MESH_REGISTER_SNIFFER_CFM_T;


/*! \brief CSR Mesh  structure for Mesh Find Meshid NetId  confirm */
typedef struct __attribute__((__packed__))
{
    CSRMeshPrim type;     /*!< \brief CSRmesh Gateway primitive */
    CSRmeshResult status; /*!< \brief Message status */
    CsrUint8  netId;   /*!< \brief Network ID  */
    CsrUint8  meshId[CSR_MESH_ID_LENGTH];  /*!< \brief Mesh ID  */
}CSR_MESH_FIND_NETID_MESHID_CFM_T;


#ifdef __cplusplus
}
#endif

/*!@} */
#endif /*__CSR_MESH_GW_PRIM_H__*/
