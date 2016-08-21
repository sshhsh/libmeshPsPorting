/*!   Copyright [2015] Qualcomm Technologies International, Ltd.
 */

#ifndef __CSR_MESH_GW_CORE_API_H__
#define __CSR_MESH_GW_CORE_API_H__

#include "csr_mesh_types.h"
#include "csr_mesh_model_common.h"
#include "csr_mesh_gateway_prim.h"

#define INVALID_DEVICE_ID        0xFFFF

/*! \file
 * \brief Declares the functions provided by CSRmesh Core module
 * \addtogroup CSRmesh
 * @{
 *  \brief Declares the functions provided by CSRmesh Core module
 *
 * \section generic_api_sec Generic API
 * The Generic APIs allow the gateway to perform association. Mesh Association Protocol (MASP) allows one device to authenticate and securely 
 * distribute a network key to another device for the Mesh Control Protocol. When a device has this network key, then the Mesh Control Protocol 
 * can be used to obtain a Device Identifier and perform configuration and/or use of the device and it becomes part of the mesh. 
 * For a new device to become part of the network, it must transmit device identification information that allows a Configuring Device to perform the association.
 * This is most useful when a device is first powered on or some user interaction has been performed on the Gateway, for example after a button 
 * on the device has been pressed when it is not associated with any network. If pre-configured network keys are used instead of following MASP, users can
 * exercise the setNetworkKey API. It should be noted that the protection of network keys are integral to the security of mesh network and it is expected
 * that users of this API are ensuring the security of the keys at the application level.
 * Following sections define the Core APIs in detail. All Core APIs return the CSRmeshResult (Refer toCSRmeshResult (Enum)) to the application. 
 * Please note that all APIs operate as non blocking calls over the socket. 
 */
/*! \brief Core API Callback function type */
typedef CSRmeshResult  (*CSRMESH_CORE_API_CALLBACK_T)(CSR_MESH_CORE_EVENT_T event, CSRmeshResult status, void *data);


/*============================================================================*
Public Function Implementations
*============================================================================*/


CSRmeshResult CsrMeshRegisterCallback(CSRMESH_CORE_API_CALLBACK_T app_callback);

/**************************CSRmesh Generic APIs*******************************/

/*----------------------------------------------------------------------------*
 * CsrMeshStart
 */
/*! \brief Start the CSRmesh system
 *
 * Calling this API ensures that the bearer layer is initialised and the CSRmesh stack is ready to do RX/TX. 
 * The API call returns CSR_MESH_RESULT_SUCCESS on successful execution of the API. Then the application 
 * receives the CSR_MESH_START_EVENT event with the CSR_MESH_RESULT_SUCCESS status asynchronously. 
 * For unsuccessful operation of this API, the application receives the CSR_MESH_START_EVENT event with the 
 * status other than CSR_MESH_RESULT_SUCCESS. See CSRmeshCoreAppCallback for the asynchronous callback
 *
 *  \returns CSRmeshResult. Refer to \ref CSRmeshResult.
 */
/*----------------------------------------------------------------------------*/
CSRmeshResult CsrMeshStart(void);

/*----------------------------------------------------------------------------*
 * CsrMeshStop
 */
/*! \brief Stop the CsrMesh system
 *
 * This API de-initialises the bearer layer and stops sending and receiving of CSRmesh messages. The API call returns 
 * CSR_MESH_RESULT_SUCCESS on successful execution of the API. After the successful operation of this API the 
 * application receives the CSR_MESH_STOP_EVENT event with the CSR_MESH_RESULT_SUCCESS status asynchronously. 
 * For unsuccessful operation of this API, the application receives the CSR_MESH_STOP_EVENT event with status other 
 *  than CSR_MESH_RESULT_SUCCESS. See CSRmeshCoreAppCallback for the asynchronous callback.
 *
 *  \returns CSRmeshResult. Refer to \ref CSRmeshResult.
 */
/*----------------------------------------------------------------------------*/
CSRmeshResult CsrMeshStop(void);

/*----------------------------------------------------------------------------*
 * CsrMeshReset
 */
/*! \brief Reset the CsrMesh library
 *
 * This API re-initialises the CSRmesh protocol layers and associated data structures. Note that this API does not delete 
 * any network key. Therefore calling this API does not lead to disassociation of the device from any existing network. 
 * The API returns CSR_MESH_RESULT_SUCCESS on successful reset of the CSRmesh stack. After the successful operation 
 * of this API, the application receives the CSR_MESH_RESET_EVENT event with the CSR_MESH_RESULT_SUCCESS status 
 * asynchronously. For unsuccessful operation of this API, the application receives the CSR_MESH_RESET_EVENT event with 
 * status other than CSR_MESH_RESULT_SUCCESS. See CSRmeshCoreAppCallback for the asynchronous callback
 *
 *  \returns CSRmeshResult. Refer to \ref CSRmeshResult.
 */
/*----------------------------------------------------------------------------*/
CSRmeshResult CsrMeshReset(void);

/*----------------------------------------------------------------------------*
 * CsrMeshSetNetworkKey
 */
/*! \brief Set a 128 bit netowrk key
 *
 * This API sets a 128 bit network key and a 16 bit device ID for the local device. The API sets pre-configured network 
 * keys which allow the device to be a part of a CSRmesh network without going through MASP flow with controller. The 
 * API call returns CSR_MESH_RESULT_SUCCESS on successful execution of the API. After the successful operation of 
 * this API, the application asynchronously receives the CSR_MESH_SET_NETWORK_KEY_EVENT event containing a network 
 * ID issued by the CSRmesh stack with the CSR_MESH_OPERATION_SUCCESS status. For unsuccessful operation of this 
 * API, the application receives the CSR_MESH_SET_NETWORK_KEY_EVENT event with status other than 
 * CSR_MESH_OPERATION_SUCCESS. See CSRmeshCoreAppCallback for the asynchronous callback
 *
 *  \param deviceId    16 bit device id assigned to the local device
 *  \param networkKey  128 bit network key used to encrypt the outgoing MCP data and decrypt the incoming MCP data
 *
 *  \returns CSRmeshResult. Refer to \ref CSRmeshResult.
 */
/*----------------------------------------------------------------------------*/
CSRmeshResult CsrMeshSetNetworkKey(CsrUint16 deviceId, CsrUint8* networkKey);

/*----------------------------------------------------------------------------*
 * CsrMeshSetPassPhrase
 */
/*! \brief Set a passphrase to create a network and network key internally
 *
 * This API sets passphrase with the help of which CSRmesh stack derives a 128 bit network key and a 16 bit device ID is 
 * associated for the local device. The API sets network keys which allow the device to be a part of a CSRmesh network 
 * without going through MASP flow with controller. The API call returns CSR_MESH_RESULT_SUCCESS on successful 
 * execution of the API. After the successful operation of this API, the application asynchronously receives the 
 * CSRMESH_SET_PASSPHRASE_EVENT event containing a network ID issued by the CSRmesh stack with the 
 * CSR_MESH_RESULT_SUCCESS status. For unsuccessful operation of this API, the application receives the 
 * CSRMESH_SET_PASSPHRASE_EVENT event with status other than CSR_MESH_RESULT_SUCCESS. 
 * See CSRmeshCoreAppCallback for the asynchronous callback.
 *
 *  \param passPhrase    passphrase string which is used to create a network
 *  \param length           length of the passphrase string
 *  \param deviceId        ID to be assigned to the gateway
 *
 *  \returns CSRmeshResult. Refer to \ref CSRmeshResult.
 */
/*----------------------------------------------------------------------------*/

CSRmeshResult CsrMeshSetPassPhrase(CsrUint8* passPhrase, CsrUint8 length, 
                                     CsrUint16 deviceId);

/*----------------------------------------------------------------------------*
 * CsrMeshRemoveNetwork
 */
/*! \brief Remove netowrk  specified by netId
 *
 * Application calls this API to remove a network to which the CSRmesh gateway is associated to. The API call returns 
 * CSR_MESH_RESULT_SUCCESS on successful execution of the API. On successful operation of this API, the application 
 * receives the CSRMESH_REMOVE_NETWORK_EVENT event with a network ID list from the CSRmesh stack with the 
 * CSR_MESH_RESULT_SUCCESS status. For unsuccessful operation of this API, the application receives the 
 * CSRMESH_REMOVE_NETWORK_EVENT event with status other than CSR_MESH_RESULT_SUCCESS. 
 * See CSRmeshCoreAppCallback for the asynchronous callback
 *
 *  \param netId    8 bit network id assigned to the network
 *
 *  \returns CSRmeshResult. Refer to \ref CSRmeshResult.
 */
/*----------------------------------------------------------------------------*/
CSRmeshResult CsrMeshRemoveNetwork(CsrUint8 netId);


/*----------------------------------------------------------------------------*
 * CsrMeshGetNetIDList
 */
/*! \brief Gets a list of network IDs supported
 *
 * Application calls this API to get the list of network ID's to which the CSRmesh gateway is associated to. The API call returns 
 * CSR_MESH_RESULT_SUCCESS on successful execution of the API. On successful operation of this API, the application receives 
 * the CSRMESH_NETWORK_ID_LIST_EVENT event with a network ID list from the CSRmesh stack with the CSR_MESH_RESULT_SUCCESS 
 * status. For unsuccessful operation of this API, the application receives the CSRMESH_NETWORK_ID_LIST_EVENT event with status 
 * other than CSR_MESH_RESULT_SUCCESS. See CSRmeshCoreAppCallback for the asynchronous callback.
 *
 *  \returns CSRmeshResult. Refer to \ref CSRmeshResult.
 */
/*----------------------------------------------------------------------------*/
CSRmeshResult CsrMeshGetNetIDList(void);

/*----------------------------------------------------------------------------*
 * CsrMeshGetDeviceID
 */
/*! \brief Gets the Unique 16-bit Device Identifier of the CsrMesh device
 *
 * Application calls this API to get the ID of the local device configured for the network specified by the netId parameter. The API call 
 * returns CSR_MESH_RESULT_SUCCESS on successful execution of the API. On successful operation of this API, the application receives 
 * the CSR_MESH_GET_DEVICE_ID_EVENT event with a device ID from the CSRmesh stack with the CSR_MESH_RESULT_SUCCESS status. 
 * For unsuccessful operation of this API, the application receives the CSR_MESH_GET_DEVICE_ID_EVENT event with status other than 
 * CSR_MESH_RESULT_SUCCESS. See CSRmeshCoreAppCallback for the asynchronous callback.
 *
 *  \param netId
 *
 *  \returns CSRmeshResult. Refer to CSRmeshResult.
 */
/*----------------------------------------------------------------------------*/
CSRmeshResult CsrMeshGetDeviceID( CsrUint8 netId);

/*----------------------------------------------------------------------------*
 * CsrMeshGetDeviceUUID
 */
/*! \brief Gets the CsrMesh library 128 bit UUID (also referred to as device identification information).
 *
 * Application uses this API to get the UUID of the device. The API call returns CSR_MESH_RESULT_SUCCESS on successful execution of the 
 * API. On completion of the operation, the application receives the CSR_MESH_GET_DEVICE_UUID_EVENT event with a 128 bit device UUID 
 * from the CSRmesh stack in Little Endian order with the CSR_MESH_RESULT_SUCCESS status. For unsuccessful operation of this API, the 
 * application receives the CSR_MESH_GET_DEVICE_UUID_EVENT event with status other than CSR_MESH_RESULT_SUCCESS. 
 * See CSRmeshCoreAppCallback for the asynchronous callback.
 *
 *  \returns CSRmeshResult. Refer to \ref CSRmeshResult.
 */
/*----------------------------------------------------------------------------*/
CSRmeshResult CsrMeshGetDeviceUUID(void);

/*----------------------------------------------------------------------------*
 * CsrMeshSetTransmitState
 */
/*! \brief Enable or disable relaying of CsrMesh messages.
 *
 * 
 * This function enables/disables relaying of CSRmesh messages.
 * If the CSRmesh relay or promiscuous is enabled, the device retransmits the received messages after decrementing the TTL (time to live) field of 
 * message. The relay is enabled when messages need to be transmitted in the CSRmesh network where devices are located beyond the radio range 
 * of individual devices.
 * The API call returns CSR_MESH_RESULT_SUCCESS on successful execution of the API. On successful operation of this API, the application receives 
 * the CSRMESH_SET_TARNSMIT_STATE_EVENT event with a relay and promiscuous state from the CSRmesh stack and bearer with the 
 * CSR_MESH_RESULT_SUCCESS status. For unsuccessful operation of this API, the application receives the CSR_MESH_RELAY_STATE_EVENT event 
 * with status other than CSR_MESH_RESULT_SUCCESS. See CSRmeshCoreAppCallback for the asynchronous callback.
 * 
 *  \param netId       Network id of the network for which the relay is required to be enabled/disabled
 *  \param trsmitState      Holds relay/promiscuous related info for both mesh-stack and bearer
 *
 *  \returns CSRmeshResult. Refer to \ref CSRmeshResult.
 */
/*-----------------------------------------------------------------------------*/
CSRmeshResult CsrMeshSetTransmitState(CsrUint8 netId, CSR_MESH_TRANSMIT_STATE_T trsmitState);

/*----------------------------------------------------------------------------*
 * CsrMeshGetTransmitState
 */
/*! \brief Called to check whether CsrMesh relay is enabled or not at mesh-stack as well at bearer level.
 *
 * This API provides the current relay state of the device for the network identified by netId. The API call returns CSR_MESH_RESULT_SUCCESS on 
 * successful execution of the API. After the successful operation of this API, the application receives the CSRMESH_GET_TARNSMIT_STATE_EVENT 
 * event with a relay and promiscuous state from the CSRmesh stack and bearer with the CSR_MESH_RESULT_SUCCESS status. For unsuccessful 
 * operation of this API, the application receives the CSR_MESH_RELAY_STATE_EVENT event with status other than CSR_MESH_RESULT_SUCCESS. 
 * See CSRmeshCoreAppCallback for the asynchronous callback.
 *
 *  \param netId       Network id of the network for which the relay status is required
 *
 *  \returns CSRmeshResult. Refer to \ref CSRmeshResult.
 */
/*-----------------------------------------------------------------------------*/
CSRmeshResult CsrMeshGetTransmitState(CsrUint8 netId);

/*----------------------------------------------------------------------------*
 * CsrMeshResetDiagnosticData
 */
/*! \brief Reset the diagnostic data
 *
 * This API resets diagnostics information of CSRmesh stack and bearer. The API call returns CSR_MESH_RESULT_SUCCESS on successful execution of 
 * the API. After the successful operation of this API, the application receives the CSRMESH_RESET_DIAG_DATA_EVENT event with the 
 * CSR_MESH_RESULT_SUCCESS status. For unsuccessful operation of this API, the application receives the CSRMESH_RESET_DIAG_DATA_EVENT event 
 * with status other than CSR_MESH_RESULT_SUCCESS. See CSRmeshCoreAppCallback for the asynchronous callback.
 *
 *  \returns CSRmeshResult. Refer to \ref CSRmeshResult.
 */
/*-----------------------------------------------------------------------------*/
CSRmeshResult CsrMeshResetDiagnosticData(void);

/*----------------------------------------------------------------------------*
 * CsrMeshGetDiagnosticData
 */
/*! \brief Get diagnostic data.
 *
 *  This API provides diagnostics information such as number of mesh packets received, number of packets transmitted over the bearer etc., The API call 
 * returns CSR_MESH_RESULT_SUCCESS on successful execution of the API. After the successful operation of this API, the application receives the 
 * CSRMESH_GET_DIAG_DATA_EVENT event with diagnostics information from the CSRmesh stack and bearer with the CSR_MESH_RESULT_SUCCESS status. 
 * For unsuccessful operation of this API, the application receives the CSRMESH_GET_DIAG_DATA_EVENT event with status other than 
 * CSR_MESH_RESULT_SUCCESS. See CSRmeshCoreAppCallback for the asynchronous callback.
 *
 *  \param diagnosticMask    The diagnostic mask identifies the type of the diagnostic data
 *
 *  \returns CSRmeshResult. Refer to \ref CSRmeshResult.
 */
/*-----------------------------------------------------------------------------*/
CSRmeshResult CsrMeshGetDiagnosticData(CSR_MESH_DIAGNOSTIC_CONFIG_MASK_T diagnosticMask);

/*----------------------------------------------------------------------------*
 * CsrMeshRegisterSniffer
 */
/*! \brief Register for sniffer data.
 *
 * This API registers for receiving the model messages sniffed over the CSRmesh network. The API call returns CSR_MESH_RESULT_SUCCESS 
 * on successful execution of the API. After the successful operation of this API, the application starts receiving the sniffed data in the
 * corresponding model callback registered.
 * 
 * For unsuccessful operation of this API, the application receives the CSRMESH_REGISTER_SNIFFER_EVENT event with status other than 
 * CSR_MESH_RESULT_SUCCESS.
 *
 * Note: Currently only one Application can register.
 *
 * See CSRmeshCoreAppCallback for the asynchronous callback.
 *
 *  \param enable       TRUE - To register for sniffer data. FALSE - To unregister for the sniffed data.
 *
 *  \returns CSRmeshResult. Refer to \ref CSRmeshResult.
 */
/*-----------------------------------------------------------------------------*/
CSRmeshResult CsrMeshRegisterSniffer(CsrBool enable);

/*----------------------------------------------------------------------------*
 * CsrMeshFindMeshId
 */
/*! \brief Find a MeshId for a given Network Id
 *
 * Application uses this API to get the mesh-ID from network-ID to which the CSRmesh Gateway is associated to. The API call returns CSR_MESH_RESULT_SUCCESS 
 * on successful execution of the API. On completion of the operation, the application receives the CSRMESH_FIND_MESHID_EVENT event with a 128 bit mesh ID from 
 * the CSRmesh stack with the CSR_MESH_RESULT_SUCCESS status. For unsuccessful operation of this API, the application receives the CSRMESH_FIND_MESHID_EVENT 
 * event with status other than CSR_MESH_RESULT_SUCCESS. See CSRmeshCoreAppCallback for the asynchronous callback.
 *
 *  \param netId         Network id of the network for which MeshId is required
 *
 *  \returns CSRmeshResult. Refer to \ref CSRmeshResult.
 */
/*----------------------------------------------------------------------------*/
CSRmeshResult CsrMeshFindMeshId(CsrUint8 netId);

/*----------------------------------------------------------------------------*
 * CsrMeshFindNetId
 */
/*! \brief Find the network id for a given MeshId
 *
 *  Application uses this API to get the network ID from mesh-ID to which the CSRmesh Gateway is associated to. The API call returns CSR_MESH_RESULT_SUCCESS 
 * on successful execution of the API. On completion of the operation, the application receives the CSRMESH_FIND_NETID_EVENT event with a network ID from the 
 * CSRmesh stack with the CSR_MESH_RESULT_SUCCESS status. For unsuccessful operation of this API, the application receives the CSRMESH_FIND_NETID_EVENT 
 * event with status other than CSR_MESH_RESULT_SUCCESS. See CSRmeshCoreAppCallback for the asynchronous callback.
 *
 *  \param meshId      Received MeshId required to find the associated network id
 *
 *  \returns CSRmeshResult. Refer to \ref CSRmeshResult.
 */
/*----------------------------------------------------------------------------*/
CSRmeshResult CsrMeshFindNetId(CsrUint8* meshId);


/**************************CSRmesh MASP APIs*******************************/

/*----------------------------------------------------------------------------*
 * CsrMeshAssociateToANetwork
 */
/*! \brief Advertises a CSRmesh device identification message.
 *
 * Only a non-config device can call this API. Application uses this API to appear as a new device. The API call returns CSR_MESH_RESULT_SUCCESS on successful 
 * execution of the API. On execution of this API the device sends the MASP_DEVICE_IDENTIFICATION message with its 128bit UUID and the MASP_DEVICE_APPEARANCE_NAME 
 * message with the device hash, appearance and short name. Only after this API is called, the CSRmesh stack will be in a state to respond to MASP_DEVICE_ASSOCIATION_REQUEST.
 * After the stack receives MASP_DEVICE_ASSOCIATION_REQ from the configuring device, it will send the CSR_MESH_ASSOC_STARTED_EVENT event to the application to notify the 
 * start of the procedure asynchronously. The application receives CSR_MESH_ASSOC_COMPLETE_EVENT with a network ID (network identifier of which the device is part of as a result 
 * of the association procedure) from the stack on successful completion of the procedure. The MASP_DEVICE_IDENTIFICATION message is advertised for 30 seconds before returning a 
 * failure or success. If association fails at the first attempt, subsequent calls to this API increase the advertisement duration by 5 seconds. When the advertisement period reaches 60 
 * seconds, no further increments are made. See CSRmeshCoreAppCallback for the asynchronous callback
 *
 *  \param deviceAppearance   The deviceAppearance of the device.Refer to \ref CSR_MESH_DEVICE_APPEARANCE_T structure.
 *  \param ttl        Time to live value used for MASP.
 *
 *  \returns CSRmeshResult. Refer to \ref CSRmeshResult.
 */
/*----------------------------------------------------------------------------*/
CSRmeshResult CsrMeshAssociateToANetwork(CSR_MESH_DEVICE_APPEARANCE_T *deviceAppearance, CsrUint8 ttl);


/*!@} */
#endif /* __CSR_MESH_GW_CORE_API_H__ */

