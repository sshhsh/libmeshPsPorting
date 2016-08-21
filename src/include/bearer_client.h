/*****************************************************************************
 *
 * Copyright [2015] Qualcomm Technologies International, Ltd.
 *
 *****************************************************************************/
/* Note: this is an auto-generated file. */

#ifndef __BEARER_CLIENT_H__
#define __BEARER_CLIENT_H__

#include "csr_types.h"
#include "csr_mesh_model_common.h"
#include "csr_mesh_result.h"
#include "csr_mesh_mcp_types.h"
/** \addtogroup Bearer
 * @{
 * \JAVADOC_AUTOBRIEF <br>The Bearer Model controls which bearers are handled by a given device and which bearers are used to relay MTL messages. A device can be set in a promiscuous mode where the device forwards all CSRmesh packets, regardless of whether the network key is known or not. This mode enables the examination of network traffic in busy locations with many overlapping networks and permits simpler deployments so that multiple installations can use their common physical deployment to support their individual traffic.<h4>Bearer State</h4>The Bearer has the following states:<ul style='list-style:square;list-style-position: inside;'> <li style='list-style-type:square;'>BearerRelayActive</li> <li style='list-style-type:square;'>BearerEnabled</li> <li style='list-style-type:square;'> Promiscous</li> </ul><H5> BearerRelayActive</h5>BearerRelayActive is a 16-bit bit field. Each bit determines if the given bearer is used to relay MTL packets received on any bearer. <h6>Note:</h6>BearerRelayActive does not determine if a message received on a given bearer is relayed, but which bearers relay a message received on any active bearer.<br><br> The following bits are defined:<ul style='list-style:square;list-style-position: inside;'> <li style='list-style-type:square;'>BearerRelayActive</li> <li style='list-style-type:square;'>LE Advertising Bearer=0</li><li style='list-style-type:square;'>LE GATT Server Bearer=1 </li></ul> <h5>BearerEnabled</h5>BearerEnabled is a 16-bit bit field. Each bit determines if the given bearer is enabled. Enabled in this context means that the bearer can receive mesh messages, and/or the bearer can be used to transmit mesh messages originated by this device.The following bits are defined:<ul style='list-style:square;list-style-position: inside;'> <li style='list-style-type:square;'>LE Advertising Bearer=0</li><li style='list-style-type:square;'>LE GATT Server Bearer=1 </li></ul><h5>BearerPromiscous</h5>BearerPromiscous is a 16-bit bit field. Each bit determines if the given bearer promiscuity is enabled. Enabled in this context means that the bearer can relay all traffic it receives even if the bearer does not match any known network keys.<br><br> The following bits are defined:<ul style='list-style:square;list-style-position: inside;'><li style='list-style-type:square;'>LE Advertising Bearer=0</li> <li style='list-style-type:square;'>LE GATT Server Bearer=1</li></ul>
 * \file 
 * \brief Declares the messages supported by the Bearer model.
 *
 * \details <br>The Bearer Model controls which bearers are handled by a given device and which bearers are used to relay MTL messages. A device can be set in a promiscuous mode where the device forwards all CSRmesh packets, regardless of whether the network key is known or not. This mode enables the examination of network traffic in busy locations with many overlapping networks and permits simpler deployments so that multiple installations can use their common physical deployment to support their individual traffic.<h4>Bearer State</h4>The Bearer has the following states:<ul style='list-style:square;list-style-position: inside;'> <li style='list-style-type:square;'>BearerRelayActive</li> <li style='list-style-type:square;'>BearerEnabled</li> <li style='list-style-type:square;'> Promiscous</li> </ul><H5> BearerRelayActive</h5>BearerRelayActive is a 16-bit bit field. Each bit determines if the given bearer is used to relay MTL packets received on any bearer. <h6>Note:</h6>BearerRelayActive does not determine if a message received on a given bearer is relayed, but which bearers relay a message received on any active bearer.<br><br> The following bits are defined:<ul style='list-style:square;list-style-position: inside;'> <li style='list-style-type:square;'>BearerRelayActive</li> <li style='list-style-type:square;'>LE Advertising Bearer=0</li><li style='list-style-type:square;'>LE GATT Server Bearer=1 </li></ul> <h5>BearerEnabled</h5>BearerEnabled is a 16-bit bit field. Each bit determines if the given bearer is enabled. Enabled in this context means that the bearer can receive mesh messages, and/or the bearer can be used to transmit mesh messages originated by this device.The following bits are defined:<ul style='list-style:square;list-style-position: inside;'> <li style='list-style-type:square;'>LE Advertising Bearer=0</li><li style='list-style-type:square;'>LE GATT Server Bearer=1 </li></ul><h5>BearerPromiscous</h5>BearerPromiscous is a 16-bit bit field. Each bit determines if the given bearer promiscuity is enabled. Enabled in this context means that the bearer can relay all traffic it receives even if the bearer does not match any known network keys.<br><br> The following bits are defined:<ul style='list-style:square;list-style-position: inside;'><li style='list-style-type:square;'>LE Advertising Bearer=0</li> <li style='list-style-type:square;'>LE GATT Server Bearer=1</li></ul>
 */




/** Bearer Initializer.
 *
 *  Response for various messages will be provided in the supplied callback
 *  \param  bearerAppCallback  callback to receive response
 *  \returns CSR_MESH_RESULT_SUCCESS if the request was successful
 */

CSRmeshResult BearerModelClientInit(CSRMESH_MODEL_CALLBACK_T bearerAppCallback);



/** \JAVADOC_AUTOBRIEF Setting Bearer State: Upon receiving a BEARER_SET_STATE message, where the destination address is the device ID of this device, the device saves the BearerRelayActive, BearerEnabled, and BearerPromiscuous fields into the appropriate state value. Then the device responds with a BEARER_STATE message with the current state information.
 *
 *  \param  nwkId  Network ID
 *  \param  destDevId  device ID
 *  \param  repeat  Number of times the request should be repeated on the mesh node 
 *  \param  bearerRelayActive Bit field of active relay bearers that are used to relay messages to.
 *  \param  bearerEnabled Bit field of enabled bearers.
 *  \param  bearerPromiscuous Relay all messages, regardless of MAC
 *  \param  tid Transaction identifier. The TID, or transaction identifier field is an 8-bit integer that identifies a given message with a known transaction from a source device.
 *
 *  \returns CSR_MESH_RESULT_SUCCESS if the request was successful
 */

CSRmeshResult BearerSetState(CsrUint8 nwkId,CsrUint16 destDevId,CsrUint8 repeat,CsrUint16 bearerRelayActive,CsrUint16 bearerEnabled,CsrUint16 bearerPromiscuous,CsrUint8 tid);




/** \JAVADOC_AUTOBRIEF Getting Bearer State: Upon receiving a BEARER_GET_STATE message, where the destination address is the device ID of this device, the device responds with a BEARER_STATE message with the current state information.
 *
 *  \param  nwkId  Network ID
 *  \param  destDevId  device ID
 *  \param  repeat  Number of times the request should be repeated on the mesh node 
 *  \param  tid Transaction identifier
 *
 *  \returns CSR_MESH_RESULT_SUCCESS if the request was successful
 */

CSRmeshResult BearerGetState(CsrUint8 nwkId,CsrUint16 destDevId,CsrUint8 repeat,CsrUint8 tid);






/*!@} */
#endif /* __BEARER_CLIENT_H__ */
