/*****************************************************************************
 *
 * Copyright [2015] Qualcomm Technologies International, Ltd.
 *
 *****************************************************************************/
/* Note: this is an auto-generated file. */


#ifndef __POWER_APP_CALLBACK_H__

#define __POWER_APP_CALLBACK_H__
#include "csr_mesh_model_common.h"
#include "csr_types.h"
#include "csr_mesh_result.h"

/** \addtogroup Power
 * @{
 * \JAVADOC_AUTOBRIEF <br>The Power Model controls the turning on and off of power for a device. A device may have multiple power states: on, off, and optionally standby. In addition to these states, a device may also remember if it is on standby before it is turned on so that it returns to standby mode after it is toggled to other power states.<br><br> The device power can be commanded directly to a given state, or the power state can be toggled to an opposite state. This means when a device is on, it will be toggled to off; when a device is off, it will be toggled to on. If a device supports the standby state, then the device will be toggled from standby to on from standby, and will be toggled from on from standby to standby. <br><br> The power model can be used in an individual device and at a wall power socket. A wall power socket may have multiple outlets, each of which can be individually switchable. To allow each power socket to be individually switched, each socket is assigned a separate GroupID.<h4>Power State</h4>The power model has the following state:<ul style='list-style:square;list-style-position: inside;'><li style='list-style-type:square;'>PowerState</li></ul><h5>Power State</h5>PowerState is an enumerated value held in an 8-bit value. The following values are defined:<ul style='list-style:square;list-style-position: inside;'><li style='list-style-type:square;'>Off=0x00. The device is powered off.</li><li style='list-style-type:square;'>On=0x01. The device is powered on.</li><li style='list-style-type:square;'>Standby=0x02. The device appears to be powered off, but is in a standby state so that it can turn on quicker than if it is off.</li><li style='list-style-type:square;'>OnFromStandby=0x03. The device is powered on from the standby state.</li></ul><h4>Power Background Behaviour</h4>The device may be interacted with directly, for example somebody presses a physical power switch on a device. When the power state changes locally on a device, it may send a POWER_STATE_NO_ACK message with the current state information.
 * \file 
 * \brief Declares the callback used for Power model updates.
 *
 */




/** Power callback.
 *
 *  Callback for various messages to be delivered from the mesh for the Power model
 *  \param  eventCode  code specifying the type of event that has occurred in the mesh
 *  \param data pointer to the event specific data
 *  \param length
 *  \param stateData
 *  \returns CSR_MESH_RESULT_SUCCESS if the mesh update was processed successfully
 */


CSRmeshResult PowerAppCallback(CSRMESH_MODEL_EVENT_T eventCode, CSRMESH_EVENT_DATA_T* data,
                                               CsrUint16 length, void **stateData);


#endif
