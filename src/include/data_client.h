/*****************************************************************************
 *
 * Copyright [2015] Qualcomm Technologies International, Ltd.
 *
 *****************************************************************************/
/* Note: this is an auto-generated file. */

#ifndef __DATA_CLIENT_H__
#define __DATA_CLIENT_H__

#include "csr_types.h"
#include "csr_mesh_model_common.h"
#include "csr_mesh_result.h"
#include "csr_mesh_mcp_types.h"
/** \addtogroup Data
 * @{
 * \JAVADOC_AUTOBRIEF <br>The Data Model transmits either a stream or blocks of arbitrary data between two devices. For stream data, each octet within the stream has an octet number. This octet number provides the reliable delivery of the stream data as a sequence number. For block data, there is no reliable delivery of messages.<h4>Data State</h4>The data model has the following state:<ul style='list-style:square;list-style-position: inside;'> <li style='list-style-type:square;'>StreamSequenceNumber</li></ul><h5>StreamSequenceNumber</h5>StreamSequenceNumber is an unsigned 16-bit integer measured in octets. This value determines the octet number for the next message received.<h4> Data Client Behaviour</h4>Before sending a DATA_STREAM_SEND message, the client should send a DATA_STREAM_FLUSH message to set the current sequence number on the server to a known value.<br><br> When sending a number of octets, the client should split these octets into the minimum number of DATA_STREAM_SEND messages, and send each message in sequence with the appropriate sequence number. The client then awaits the DATA_STREAM_RECEIVED messages to determine if the data has been successfully received and acknowledged. If a DATA_STREAM_RECEIVED message is received and it has a next expected sequence number within the sent octets, then the DATA_STREAM_SEND message containing that octet number should be sent again.<br><br> If no DATA_STREAM_RECEIVED messages are received, then the client should resend the DATA_STREAM_SEND message until the device does acknowledge receipt.<br><br> The client may timeout the reliable delivery of these data stream octets. It should then send a DATA_STREAM_FLUSH message before sending additional stream octets to the server. The length of the time for the timeout is an implementation detail.<h6>Note:</h6> The timing of the DATA_STREAM_FLUSH message can be immediately after the timeout occurs, or it can be just before the delivery of the next sequence of octets. This is an implementation detail.
 * \file 
 * \brief Declares the messages supported by the Data model.
 *
 * \details <br>The Data Model transmits either a stream or blocks of arbitrary data between two devices. For stream data, each octet within the stream has an octet number. This octet number provides the reliable delivery of the stream data as a sequence number. For block data, there is no reliable delivery of messages.<h4>Data State</h4>The data model has the following state:<ul style='list-style:square;list-style-position: inside;'> <li style='list-style-type:square;'>StreamSequenceNumber</li></ul><h5>StreamSequenceNumber</h5>StreamSequenceNumber is an unsigned 16-bit integer measured in octets. This value determines the octet number for the next message received.<h4> Data Client Behaviour</h4>Before sending a DATA_STREAM_SEND message, the client should send a DATA_STREAM_FLUSH message to set the current sequence number on the server to a known value.<br><br> When sending a number of octets, the client should split these octets into the minimum number of DATA_STREAM_SEND messages, and send each message in sequence with the appropriate sequence number. The client then awaits the DATA_STREAM_RECEIVED messages to determine if the data has been successfully received and acknowledged. If a DATA_STREAM_RECEIVED message is received and it has a next expected sequence number within the sent octets, then the DATA_STREAM_SEND message containing that octet number should be sent again.<br><br> If no DATA_STREAM_RECEIVED messages are received, then the client should resend the DATA_STREAM_SEND message until the device does acknowledge receipt.<br><br> The client may timeout the reliable delivery of these data stream octets. It should then send a DATA_STREAM_FLUSH message before sending additional stream octets to the server. The length of the time for the timeout is an implementation detail.<h6>Note:</h6> The timing of the DATA_STREAM_FLUSH message can be immediately after the timeout occurs, or it can be just before the delivery of the next sequence of octets. This is an implementation detail.
 */




/** Data Initializer.
 *
 *  Response for various messages will be provided in the supplied callback
 *  \param  dataAppCallback  callback to receive response
 *  \returns CSR_MESH_RESULT_SUCCESS if the request was successful
 */

CSRmeshResult DataModelClientInit(CSRMESH_MODEL_CALLBACK_T dataAppCallback);



/** \JAVADOC_AUTOBRIEF Flushing Data: Upon receiving a DATA_STREAM_FLUSH message, the device saves the StreamSN field into the StreamSequenceNumber model state and responds with DATA_STREAM_RECEIVED with the StreamNESN field set to the value of the StreamSequenceNumber model state. The device also flushes all partially received stream data from this peer device.
 *
 *  \param  nwkId  Network ID
 *  \param  destDevId  device ID
 *  \param  repeat  Number of times the request should be repeated on the mesh node 
 *  \param  streamSn Stream sequence number
 *
 *  \returns CSR_MESH_RESULT_SUCCESS if the request was successful
 */

CSRmeshResult DataStreamFlush(CsrUint8 nwkId,CsrUint16 destDevId,CsrUint8 repeat,CsrUint16 streamSn);




/** \JAVADOC_AUTOBRIEF Sending Data: Upon receiving a DATA_STREAM_SEND message, the device first checks if the StreamSN field is the same as the StreamSequenceNumber model state. If these values are the same, the device passes the StreamOctets field up to the application for processing, and increments StreamSequenceNumber by the length of the StreamOctets field. It then responds with a DATA_STREAM_RECEIVED message with the current value of the StreamSequenceNumber. Note: The DATA_STREAM_RECEIVED message is sent even if the StreamSN received is different from the StreamSequenceNumber state. This allows missing packets to be detected and retransmitted by the sending device.
 *
 *  \param  nwkId  Network ID
 *  \param  destDevId  device ID
 *  \param  repeat  Number of times the request should be repeated on the mesh node 
 *  \param  streamSn Sequence number of the first octet in StreamOctets.
 *  \param  streamOctets Arbitrary stream of data.
 *  \param  streamOctetsLen length of streamOctets array
 *
 *  \returns CSR_MESH_RESULT_SUCCESS if the request was successful
 */

CSRmeshResult DataStreamSend(CsrUint8 nwkId,CsrUint16 destDevId,CsrUint8 repeat,CsrUint16 streamSn,CsrUint8* streamOctets, CsrUint8 streamOctetsLen );







/** \JAVADOC_AUTOBRIEF A block of data, no acknowledgement. Upon receiving a DATA_BLOCK_SEND message, the device passes the DatagramOctets field up to the application for processing.
 *
 *  \param  nwkId  Network ID
 *  \param  destDevId  device ID
 *  \param  repeat  Number of times the request should be repeated on the mesh node 
 *  \param  datagramOctets Datagram of octets
 *  \param  datagramOctetsLen length of datagramOctets array
 *
 *  \returns CSR_MESH_RESULT_SUCCESS if the request was successful
 */

CSRmeshResult DataBlockSend(CsrUint8 nwkId,CsrUint16 destDevId,CsrUint8 repeat,CsrUint8* datagramOctets, CsrUint8 datagramOctetsLen );



/*!@} */
#endif /* __DATA_CLIENT_H__ */
