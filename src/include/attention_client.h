/*****************************************************************************
 *
 * Copyright [2015] Qualcomm Technologies International, Ltd.
 *
 *****************************************************************************/
/* Note: this is an auto-generated file. */

#ifndef __ATTENTION_CLIENT_H__
#define __ATTENTION_CLIENT_H__

#include "csr_types.h"
#include "csr_mesh_model_common.h"
#include "csr_mesh_result.h"
#include "csr_mesh_mcp_types.h"
/** \addtogroup Attention
 * @{
 * \JAVADOC_AUTOBRIEF <br>It is sometimes useful to identify devices that have been installed, especially when they need maintenance. The attention model allows a device to make itself noticeable so that a human can help pinpoint the physical device.<h6>Note:</h6> The definition of being noticeable is an implementation detail and may vary from one device to another. For example, a light may flash its light, another device may make a sound, and another may operate a motor.<H4>Attention State</H4>The attention model has the following states:<ul style='list-style:square;list-style-position: inside;'><li style='list-style-type:square;'> AttractAttention</li> <li style='list-style-type:square;'>AttentionDuration</li></ul><h5> AttractAttention</h5>AttractAttention is a boolean value held in an 8-bit field. A value of 0x00 means that the device is not attracting attention. A value of 0x01 means that the device is attracting attention. Attracting attention in this context means that the device may flash lights, make a sound, operate a motor, or something similar that allows a user to determine which device is attracting attention. All other values are reserved for future use.<h5> AttentionDuration</h5>AttentionDuration is a 16-bit unsigned integer in milliseconds. This value determines how long a device continues to attract attention. If this value is set to 0xFFFF, then the device attracts attention continuously until it is set not to attract attention. <h4> Attention Background Behaviour</h4> If a device has been attracting attention for the time set by AttentionDuration, when the attention timer expires, the device will stop attracting attention and may send an ATTENTION_STATE message with the current state information. The TID field can be set to any value.
 * \file 
 * \brief Declares the messages supported by the Attention model.
 *
 * \details <br>It is sometimes useful to identify devices that have been installed, especially when they need maintenance. The attention model allows a device to make itself noticeable so that a human can help pinpoint the physical device.<h6>Note:</h6> The definition of being noticeable is an implementation detail and may vary from one device to another. For example, a light may flash its light, another device may make a sound, and another may operate a motor.<H4>Attention State</H4>The attention model has the following states:<ul style='list-style:square;list-style-position: inside;'><li style='list-style-type:square;'> AttractAttention</li> <li style='list-style-type:square;'>AttentionDuration</li></ul><h5> AttractAttention</h5>AttractAttention is a boolean value held in an 8-bit field. A value of 0x00 means that the device is not attracting attention. A value of 0x01 means that the device is attracting attention. Attracting attention in this context means that the device may flash lights, make a sound, operate a motor, or something similar that allows a user to determine which device is attracting attention. All other values are reserved for future use.<h5> AttentionDuration</h5>AttentionDuration is a 16-bit unsigned integer in milliseconds. This value determines how long a device continues to attract attention. If this value is set to 0xFFFF, then the device attracts attention continuously until it is set not to attract attention. <h4> Attention Background Behaviour</h4> If a device has been attracting attention for the time set by AttentionDuration, when the attention timer expires, the device will stop attracting attention and may send an ATTENTION_STATE message with the current state information. The TID field can be set to any value.
 */




/** Attention Initializer.
 *
 *  Response for various messages will be provided in the supplied callback
 *  \param  attentionAppCallback  callback to receive response
 *  \returns CSR_MESH_RESULT_SUCCESS if the request was successful
 */

CSRmeshResult AttentionModelClientInit(CSRMESH_MODEL_CALLBACK_T attentionAppCallback);



/** \JAVADOC_AUTOBRIEF Setting Flashing State: Upon receiving an ATTENTION_SET_STATE message, the device saves the AttractAttention and AttentionDuration fields into the appropriate state value. It then responds with an ATTENTION_STATE message with the current state information. If the AttractAttention field is set to 0x01 and the AttentionDuration is not 0xFFFF, then any existing attention timer is cancelled and a new attention timer is started that will expire after AttentionDuration milliseconds. If the AttractAttention field is set to 0x01 and the AttentionDuration field is 0xFFFF, then the attention timer is ignored. If the AttractAttention field is set to 0x00, then the attention timer is cancelled if it is already running.
 *
 *  \param  nwkId  Network ID
 *  \param  destDevId  device ID
 *  \param  repeat  Number of times the request should be repeated on the mesh node 
 *  \param  attractAttention Attract attention
 *  \param  duration Duration for attracting attention
 *  \param  tid Transaction identifier. The TID, or transaction identifier field is an 8-bit integer that identifies a given message with a known transaction from a source device.
 *
 *  \returns CSR_MESH_RESULT_SUCCESS if the request was successful
 */

CSRmeshResult AttentionSetState(CsrUint8 nwkId,CsrUint16 destDevId,CsrUint8 repeat,CSR_MESH_BOOLEAN_T attractAttention,CsrUint16 duration,CsrUint8 tid);






/*!@} */
#endif /* __ATTENTION_CLIENT_H__ */
