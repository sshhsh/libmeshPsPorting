/*****************************************************************************
 *
 * Copyright [2015] Qualcomm Technologies International, Ltd.
 *
 *****************************************************************************/
/* Note: this is an auto-generated file. */


#ifndef __SWITCH_APP_CALLBACK_H__

#define __SWITCH_APP_CALLBACK_H__
#include "csr_mesh_model_common.h"
#include "csr_types.h"
#include "csr_mesh_result.h"

/** \addtogroup Switch
 * @{
 * \JAVADOC_AUTOBRIEF <br>The switch model does not define any messages. The switch model is configured using the group model. <br> Switch Client Behaviour: If the user presses the on switch with a given switch_number, then the client sends a POWER_SET_STATE message to the appropriate GroupID as identified by the Instance value from the group model. If the user rotates a dimmer switch, then the client may send a LIGHT_LEVEL_NO_ACK message to the appropriate GroupID as configured in the group model. If the user finishes rotating a dimmer switch, then the client may send a LIGHT_LEVEL, and await an acknowledgement from the lights that this dimmer controls.
 * \file 
 * \brief Declares the callback used for Switch model updates.
 *
 */




/** Switch callback.
 *
 *  Callback for various messages to be delivered from the mesh for the Switch model
 *  \param  eventCode  code specifying the type of event that has occurred in the mesh
 *  \param data pointer to the event specific data
 *  \param length
 *  \param stateData
 *  \returns CSR_MESH_RESULT_SUCCESS if the mesh update was processed successfully
 */


CSRmeshResult SwitchAppCallback(CSRMESH_MODEL_EVENT_T eventCode, CSRMESH_EVENT_DATA_T* data,
                                               CsrUint16 length, void **stateData);


#endif
