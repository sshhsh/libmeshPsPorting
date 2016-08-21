/*****************************************************************************
 *
 * Copyright [2015] Qualcomm Technologies International, Ltd.
 *
 *****************************************************************************/
/* Note: this is an auto-generated file. */


#ifndef __ATTENTION_APP_CALLBACK_H__

#define __ATTENTION_APP_CALLBACK_H__
#include "csr_mesh_model_common.h"
#include "csr_types.h"
#include "csr_mesh_result.h"

/** \addtogroup Attention
 * @{
 * \JAVADOC_AUTOBRIEF <br>It is sometimes useful to identify devices that have been installed, especially when they need maintenance. The attention model allows a device to make itself noticeable so that a human can help pinpoint the physical device.<h6>Note:</h6> The definition of being noticeable is an implementation detail and may vary from one device to another. For example, a light may flash its light, another device may make a sound, and another may operate a motor.<H4>Attention State</H4>The attention model has the following states:<ul style='list-style:square;list-style-position: inside;'><li style='list-style-type:square;'> AttractAttention</li> <li style='list-style-type:square;'>AttentionDuration</li></ul><h5> AttractAttention</h5>AttractAttention is a boolean value held in an 8-bit field. A value of 0x00 means that the device is not attracting attention. A value of 0x01 means that the device is attracting attention. Attracting attention in this context means that the device may flash lights, make a sound, operate a motor, or something similar that allows a user to determine which device is attracting attention. All other values are reserved for future use.<h5> AttentionDuration</h5>AttentionDuration is a 16-bit unsigned integer in milliseconds. This value determines how long a device continues to attract attention. If this value is set to 0xFFFF, then the device attracts attention continuously until it is set not to attract attention. <h4> Attention Background Behaviour</h4> If a device has been attracting attention for the time set by AttentionDuration, when the attention timer expires, the device will stop attracting attention and may send an ATTENTION_STATE message with the current state information. The TID field can be set to any value.
 * \file 
 * \brief Declares the callback used for Attention model updates.
 *
 */




/** Attention callback.
 *
 *  Callback for various messages to be delivered from the mesh for the Attention model
 *  \param  eventCode  code specifying the type of event that has occurred in the mesh
 *  \param data pointer to the event specific data
 *  \param length
 *  \param stateData
 *  \returns CSR_MESH_RESULT_SUCCESS if the mesh update was processed successfully
 */


CSRmeshResult AttentionAppCallback(CSRMESH_MODEL_EVENT_T eventCode, CSRMESH_EVENT_DATA_T* data,
                                               CsrUint16 length, void **stateData);


#endif
