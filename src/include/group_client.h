/*****************************************************************************
 *
 * Copyright [2015] Qualcomm Technologies International, Ltd.
 *
 *****************************************************************************/
/* Note: this is an auto-generated file. */

#ifndef __GROUP_CLIENT_H__
#define __GROUP_CLIENT_H__

#include "csr_types.h"
#include "csr_mesh_model_common.h"
#include "csr_mesh_result.h"
#include "csr_mesh_mcp_types.h"
/** \addtogroup Group
 * @{
 * \JAVADOC_AUTOBRIEF <br>The Group Model configures the set of groups that a device transmits or processes. The groups are configured for a particular model. Each model can have one or more groups associated with; the groups are organized by an index value per model. For example, a device can support 4 group identifiers for one model, and 2 group identifiers for another model.<br><br> Some models have no specific operation codes. The support of these models (for example the switch model) implies the support of the group model.It is possible to set the group identifiers for all models in a device using the model identifier 0xFF. <h4>Group State</h4>The group model has the following states:<ul style='list-style:square;list-style-position: inside;'><li style='list-style-type:square;'>NumberOfGroups</li><li style='list-style-type:square;'>NumberOfInstances</li> <li style='list-style-type:square;'>GroupIDs</li></ul> <h5> NumberOfGroups</h5>NumberOfGroups is an array of 8-bit unsigned integers, with one entry per model. The value of each entry is the number of group identifiers that the device supports for a given model.<h5>NumberOfInstances</h5> NumberOfInstances is an array of arrays of 8-bit unsigned integers. The top level array holds an array of instances for each model. The second level array holds the NumberOfInstances values for each GroupID that a device exposes in the NumberOfGroups state value<h5>GroupIDs</h5>GroupIDs is an array of arrays of 16-bit unsigned integers. The top level array holds an array of instances for each model. The second level array holds the GroupID values for that model, sized at least as big as the NumberOfGroups state value for that model.
 * \file 
 * \brief Declares the messages supported by the Group model.
 *
 * \details <br>The Group Model configures the set of groups that a device transmits or processes. The groups are configured for a particular model. Each model can have one or more groups associated with; the groups are organized by an index value per model. For example, a device can support 4 group identifiers for one model, and 2 group identifiers for another model.<br><br> Some models have no specific operation codes. The support of these models (for example the switch model) implies the support of the group model.It is possible to set the group identifiers for all models in a device using the model identifier 0xFF. <h4>Group State</h4>The group model has the following states:<ul style='list-style:square;list-style-position: inside;'><li style='list-style-type:square;'>NumberOfGroups</li><li style='list-style-type:square;'>NumberOfInstances</li> <li style='list-style-type:square;'>GroupIDs</li></ul> <h5> NumberOfGroups</h5>NumberOfGroups is an array of 8-bit unsigned integers, with one entry per model. The value of each entry is the number of group identifiers that the device supports for a given model.<h5>NumberOfInstances</h5> NumberOfInstances is an array of arrays of 8-bit unsigned integers. The top level array holds an array of instances for each model. The second level array holds the NumberOfInstances values for each GroupID that a device exposes in the NumberOfGroups state value<h5>GroupIDs</h5>GroupIDs is an array of arrays of 16-bit unsigned integers. The top level array holds an array of instances for each model. The second level array holds the GroupID values for that model, sized at least as big as the NumberOfGroups state value for that model.
 */




/** Group Initializer.
 *
 *  Response for various messages will be provided in the supplied callback
 *  \param  groupAppCallback  callback to receive response
 *  \returns CSR_MESH_RESULT_SUCCESS if the request was successful
 */

CSRmeshResult GroupModelClientInit(CSRMESH_MODEL_CALLBACK_T groupAppCallback);



/** \JAVADOC_AUTOBRIEF Getting Number of Group IDs: Upon receiving a GROUP_GET_NUMBER_OF_MODEL_GROUPS message, where the destination address is the DeviceID of this device, the device responds with a GROUP_NUMBER_OF_MODEL_GROUPS message with the number of Group IDs that the given model supports on this device.
 *
 *  \param  nwkId  Network ID
 *  \param  destDevId  device ID
 *  \param  repeat  Number of times the request should be repeated on the mesh node 
 *  \param  model Model number
 *  \param  tid Transaction identifier. The TID, or transaction identifier field is an 8-bit integer that identifies a given message with a known transaction from a source device.
 *
 *  \returns CSR_MESH_RESULT_SUCCESS if the request was successful
 */

CSRmeshResult GroupGetNumberOfModelGroupids(CsrUint8 nwkId,CsrUint16 destDevId,CsrUint8 repeat,CsrUint8 model,CsrUint8 tid);







/** \JAVADOC_AUTOBRIEF Setting Model Group ID: Upon receiving a GROUP_SET_MODEL_GROUPID message, where the destination address is the DeviceID of this device, the device saves the Instance and GroupID fields into the appropriate state value determined by the Model and GroupIndex fields. It then responds with a GROUP_MODEL_GROUPID message with the current state information held for the given model and the GroupIndex values.
 *
 *  \param  nwkId  Network ID
 *  \param  destDevId  device ID
 *  \param  repeat  Number of times the request should be repeated on the mesh node 
 *  \param  model Model number
 *  \param  groupIndex Index of the group
 *  \param  instance Instance of the group
 *  \param  groupId Group identifier
 *  \param  tid Transaction identifier. The TID, or transaction identifier field is an 8-bit integer that identifies a given message with a known transaction from a source device.
 *
 *  \returns CSR_MESH_RESULT_SUCCESS if the request was successful
 */

CSRmeshResult GroupSetModelGroupid(CsrUint8 nwkId,CsrUint16 destDevId,CsrUint8 repeat,CsrUint8 model,CsrUint8 groupIndex,CsrUint8 instance,CsrUint16 groupId,CsrUint8 tid);




/** \JAVADOC_AUTOBRIEF Getting Model Group ID: Upon receiving a GROUP_GET_MODEL_GROUPID message, where the destination address is the DeviceID of this device, the device responds with a GROUP_MODEL_GROUPID message with the current state information held for the given Model and GroupIndex values.
 *
 *  \param  nwkId  Network ID
 *  \param  destDevId  device ID
 *  \param  repeat  Number of times the request should be repeated on the mesh node 
 *  \param  model Model number
 *  \param  groupIndex Index of the group
 *  \param  tid Transaction identifier. The TID, or transaction identifier field is an 8-bit integer that identifies a given message with a known transaction from a source device.
 *
 *  \returns CSR_MESH_RESULT_SUCCESS if the request was successful
 */

CSRmeshResult GroupGetModelGroupid(CsrUint8 nwkId,CsrUint16 destDevId,CsrUint8 repeat,CsrUint8 model,CsrUint8 groupIndex,CsrUint8 tid);






/*!@} */
#endif /* __GROUP_CLIENT_H__ */
