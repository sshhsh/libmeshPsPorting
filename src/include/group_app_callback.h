/*****************************************************************************
 *
 * Copyright [2015] Qualcomm Technologies International, Ltd.
 *
 *****************************************************************************/
/* Note: this is an auto-generated file. */


#ifndef __GROUP_APP_CALLBACK_H__

#define __GROUP_APP_CALLBACK_H__
#include "csr_mesh_model_common.h"
#include "csr_types.h"
#include "csr_mesh_result.h"

/** \addtogroup Group
 * @{
 * \JAVADOC_AUTOBRIEF <br>The Group Model configures the set of groups that a device transmits or processes. The groups are configured for a particular model. Each model can have one or more groups associated with; the groups are organized by an index value per model. For example, a device can support 4 group identifiers for one model, and 2 group identifiers for another model.<br><br> Some models have no specific operation codes. The support of these models (for example the switch model) implies the support of the group model.It is possible to set the group identifiers for all models in a device using the model identifier 0xFF. <h4>Group State</h4>The group model has the following states:<ul style='list-style:square;list-style-position: inside;'><li style='list-style-type:square;'>NumberOfGroups</li><li style='list-style-type:square;'>NumberOfInstances</li> <li style='list-style-type:square;'>GroupIDs</li></ul> <h5> NumberOfGroups</h5>NumberOfGroups is an array of 8-bit unsigned integers, with one entry per model. The value of each entry is the number of group identifiers that the device supports for a given model.<h5>NumberOfInstances</h5> NumberOfInstances is an array of arrays of 8-bit unsigned integers. The top level array holds an array of instances for each model. The second level array holds the NumberOfInstances values for each GroupID that a device exposes in the NumberOfGroups state value<h5>GroupIDs</h5>GroupIDs is an array of arrays of 16-bit unsigned integers. The top level array holds an array of instances for each model. The second level array holds the GroupID values for that model, sized at least as big as the NumberOfGroups state value for that model.
 * \file 
 * \brief Declares the callback used for Group model updates.
 *
 */




/** Group callback.
 *
 *  Callback for various messages to be delivered from the mesh for the Group model
 *  \param  eventCode  code specifying the type of event that has occurred in the mesh
 *  \param data pointer to the event specific data
 *  \param length
 *  \param stateData
 *  \returns CSR_MESH_RESULT_SUCCESS if the mesh update was processed successfully
 */


CSRmeshResult GroupAppCallback(CSRMESH_MODEL_EVENT_T eventCode, CSRMESH_EVENT_DATA_T* data,
                                               CsrUint16 length, void **stateData);


#endif
