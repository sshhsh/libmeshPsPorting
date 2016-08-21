/*****************************************************************************
 *
 * Copyright [2015] Qualcomm Technologies International, Ltd.
 *
 *****************************************************************************/
/* Note: this is an auto-generated file. */

#ifndef __PING_CLIENT_H__
#define __PING_CLIENT_H__

#include "csr_types.h"
#include "csr_mesh_model_common.h"
#include "csr_mesh_result.h"
#include "csr_mesh_mcp_types.h"
/** \addtogroup Ping
 * @{
 * \JAVADOC_AUTOBRIEF <br>The Ping Model ensures that the MTL can provide reliable message delivery to a peer device. It does this by allowing a transmitting device to send a request that a device supporting the ping model will respond to. The ping model optimises the configuration of devices within the network. The mechanisms to optimise the network are out of scope of this specification.
 * \file 
 * \brief Declares the messages supported by the Ping model.
 *
 * \details <br>The Ping Model ensures that the MTL can provide reliable message delivery to a peer device. It does this by allowing a transmitting device to send a request that a device supporting the ping model will respond to. The ping model optimises the configuration of devices within the network. The mechanisms to optimise the network are out of scope of this specification.
 */




/** Ping Initializer.
 *
 *  Response for various messages will be provided in the supplied callback
 *  \param  pingAppCallback  callback to receive response
 *  \returns CSR_MESH_RESULT_SUCCESS if the request was successful
 */

CSRmeshResult PingModelClientInit(CSRMESH_MODEL_CALLBACK_T pingAppCallback);



/** \JAVADOC_AUTOBRIEF Ping Request: Upon receiving a PING_REQUEST message, the device responds with a PING_RESPONSE message with the TTLAtRx field set to the TTL value from the PING_REQUEST message, and the RSSIAtRx field set to the RSSI value of the PING_REQUEST message. If the bearer used to receive the PING_REQUEST message does not have an RSSI value, then the value 0x00 is used.
 *
 *  \param  nwkId  Network ID
 *  \param  destDevId  device ID
 *  \param  repeat  Number of times the request should be repeated on the mesh node 
 *  \param  arbitraryData Arbitrary data
 *  \param  arbitraryDataLen length of arbitraryData array
 *  \param  rspTTl Response packet time to live
 *
 *  \returns CSR_MESH_RESULT_SUCCESS if the request was successful
 */

CSRmeshResult PingRequest(CsrUint8 nwkId,CsrUint16 destDevId,CsrUint8 repeat,CsrUint8* arbitraryData, CsrUint8 arbitraryDataLen ,CsrUint8 rspTTl);






/*!@} */
#endif /* __PING_CLIENT_H__ */
