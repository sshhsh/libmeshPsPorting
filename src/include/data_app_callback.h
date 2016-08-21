/*****************************************************************************
 *
 * Copyright [2015] Qualcomm Technologies International, Ltd.
 *
 *****************************************************************************/
/* Note: this is an auto-generated file. */


#ifndef __DATA_APP_CALLBACK_H__

#define __DATA_APP_CALLBACK_H__
#include "csr_mesh_model_common.h"
#include "csr_types.h"
#include "csr_mesh_result.h"

/** \addtogroup Data
 * @{
 * \JAVADOC_AUTOBRIEF <br>The Data Model transmits either a stream or blocks of arbitrary data between two devices. For stream data, each octet within the stream has an octet number. This octet number provides the reliable delivery of the stream data as a sequence number. For block data, there is no reliable delivery of messages.<h4>Data State</h4>The data model has the following state:<ul style='list-style:square;list-style-position: inside;'> <li style='list-style-type:square;'>StreamSequenceNumber</li></ul><h5>StreamSequenceNumber</h5>StreamSequenceNumber is an unsigned 16-bit integer measured in octets. This value determines the octet number for the next message received.<h4> Data Client Behaviour</h4>Before sending a DATA_STREAM_SEND message, the client should send a DATA_STREAM_FLUSH message to set the current sequence number on the server to a known value.<br><br> When sending a number of octets, the client should split these octets into the minimum number of DATA_STREAM_SEND messages, and send each message in sequence with the appropriate sequence number. The client then awaits the DATA_STREAM_RECEIVED messages to determine if the data has been successfully received and acknowledged. If a DATA_STREAM_RECEIVED message is received and it has a next expected sequence number within the sent octets, then the DATA_STREAM_SEND message containing that octet number should be sent again.<br><br> If no DATA_STREAM_RECEIVED messages are received, then the client should resend the DATA_STREAM_SEND message until the device does acknowledge receipt.<br><br> The client may timeout the reliable delivery of these data stream octets. It should then send a DATA_STREAM_FLUSH message before sending additional stream octets to the server. The length of the time for the timeout is an implementation detail.<h6>Note:</h6> The timing of the DATA_STREAM_FLUSH message can be immediately after the timeout occurs, or it can be just before the delivery of the next sequence of octets. This is an implementation detail.
 * \file 
 * \brief Declares the callback used for Data model updates.
 *
 */




/** Data callback.
 *
 *  Callback for various messages to be delivered from the mesh for the Data model
 *  \param  eventCode  code specifying the type of event that has occurred in the mesh
 *  \param data pointer to the event specific data
 *  \param length
 *  \param stateData
 *  \returns CSR_MESH_RESULT_SUCCESS if the mesh update was processed successfully
 */


CSRmeshResult DataAppCallback(CSRMESH_MODEL_EVENT_T eventCode, CSRMESH_EVENT_DATA_T* data,
                                               CsrUint16 length, void **stateData);


#endif
