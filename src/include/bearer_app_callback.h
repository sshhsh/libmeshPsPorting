/*****************************************************************************
 *
 * Copyright [2015] Qualcomm Technologies International, Ltd.
 *
 *****************************************************************************/
/* Note: this is an auto-generated file. */


#ifndef __BEARER_APP_CALLBACK_H__

#define __BEARER_APP_CALLBACK_H__
#include "csr_mesh_model_common.h"
#include "csr_types.h"
#include "csr_mesh_result.h"

/** \addtogroup Bearer
 * @{
 * \JAVADOC_AUTOBRIEF <br>The Bearer Model controls which bearers are handled by a given device and which bearers are used to relay MTL messages. A device can be set in a promiscuous mode where the device forwards all CSRmesh packets, regardless of whether the network key is known or not. This mode enables the examination of network traffic in busy locations with many overlapping networks and permits simpler deployments so that multiple installations can use their common physical deployment to support their individual traffic.<h4>Bearer State</h4>The Bearer has the following states:<ul style='list-style:square;list-style-position: inside;'> <li style='list-style-type:square;'>BearerRelayActive</li> <li style='list-style-type:square;'>BearerEnabled</li> <li style='list-style-type:square;'> Promiscous</li> </ul><H5> BearerRelayActive</h5>BearerRelayActive is a 16-bit bit field. Each bit determines if the given bearer is used to relay MTL packets received on any bearer. <h6>Note:</h6>BearerRelayActive does not determine if a message received on a given bearer is relayed, but which bearers relay a message received on any active bearer.<br><br> The following bits are defined:<ul style='list-style:square;list-style-position: inside;'> <li style='list-style-type:square;'>BearerRelayActive</li> <li style='list-style-type:square;'>LE Advertising Bearer=0</li><li style='list-style-type:square;'>LE GATT Server Bearer=1 </li></ul> <h5>BearerEnabled</h5>BearerEnabled is a 16-bit bit field. Each bit determines if the given bearer is enabled. Enabled in this context means that the bearer can receive mesh messages, and/or the bearer can be used to transmit mesh messages originated by this device.The following bits are defined:<ul style='list-style:square;list-style-position: inside;'> <li style='list-style-type:square;'>LE Advertising Bearer=0</li><li style='list-style-type:square;'>LE GATT Server Bearer=1 </li></ul><h5>BearerPromiscous</h5>BearerPromiscous is a 16-bit bit field. Each bit determines if the given bearer promiscuity is enabled. Enabled in this context means that the bearer can relay all traffic it receives even if the bearer does not match any known network keys.<br><br> The following bits are defined:<ul style='list-style:square;list-style-position: inside;'><li style='list-style-type:square;'>LE Advertising Bearer=0</li> <li style='list-style-type:square;'>LE GATT Server Bearer=1</li></ul>
 * \file 
 * \brief Declares the callback used for Bearer model updates.
 *
 */




/** Bearer callback.
 *
 *  Callback for various messages to be delivered from the mesh for the Bearer model
 *  \param  eventCode  code specifying the type of event that has occurred in the mesh
 *  \param data pointer to the event specific data
 *  \param length
 *  \param stateData
 *  \returns CSR_MESH_RESULT_SUCCESS if the mesh update was processed successfully
 */


CSRmeshResult BearerAppCallback(CSRMESH_MODEL_EVENT_T eventCode, CSRMESH_EVENT_DATA_T* data,
                                               CsrUint16 length, void **stateData);


#endif
