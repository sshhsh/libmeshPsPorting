/*****************************************************************************
 *
 * Copyright [2015] Qualcomm Technologies International, Ltd.
 *
 *****************************************************************************/
/* Note: this is an auto-generated file. */


#ifndef __PING_APP_CALLBACK_H__

#define __PING_APP_CALLBACK_H__
#include "csr_mesh_model_common.h"
#include "csr_types.h"
#include "csr_mesh_result.h"

/** \addtogroup Ping
 * @{
 * \JAVADOC_AUTOBRIEF <br>The Ping Model ensures that the MTL can provide reliable message delivery to a peer device. It does this by allowing a transmitting device to send a request that a device supporting the ping model will respond to. The ping model optimises the configuration of devices within the network. The mechanisms to optimise the network are out of scope of this specification.
 * \file 
 * \brief Declares the callback used for Ping model updates.
 *
 */




/** Ping callback.
 *
 *  Callback for various messages to be delivered from the mesh for the Ping model
 *  \param  eventCode  code specifying the type of event that has occurred in the mesh
 *  \param data pointer to the event specific data
 *  \param length
 *  \param stateData
 *  \returns CSR_MESH_RESULT_SUCCESS if the mesh update was processed successfully
 */


CSRmeshResult PingAppCallback(CSRMESH_MODEL_EVENT_T eventCode, CSRMESH_EVENT_DATA_T* data,
                                               CsrUint16 length, void **stateData);


#endif
