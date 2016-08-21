/*****************************************************************************
 *
 * Copyright [2015] Qualcomm Technologies International, Ltd.
 *
 *****************************************************************************/
/* Note: this is an auto-generated file. */


#ifndef __BATTERY_APP_CALLBACK_H__

#define __BATTERY_APP_CALLBACK_H__
#include "csr_mesh_model_common.h"
#include "csr_types.h"
#include "csr_mesh_result.h"

/** \addtogroup Battery
 * @{
 * \JAVADOC_AUTOBRIEF <br>The Battery Model reports the current battery state of a device that is powered by a battery.<h4>Battery State</h4>The battery model has the following states:<ul style='list-style:square;list-style-position: inside;'> <li style='list-style-type:square;'>BatteryLevel</li><li style='list-style-type:square;'>BatteryState</li></ul> <h5> BatteryLevel</h5>BatteryLevel is an unsigned 8-bit value as a percentage. The values 0x00 to 0x64 are valid, and all other values are reserved for future use. The value 0x00 represents a battery that has no energy capacity. The value 0x64 represents a battery with full capacity. Values between these two extremes represent a linear scaling from empty to full capacity. <h5>BatteryState</h5>BatteryState is an 8-bit bit field. Each bit is a Boolean value that determines if a given state is true or false. The value of zero is false, and the value of one is true.<br><br> The following bits are defined:<ul style='list-style:square;list-style-position: inside;'> <li style='list-style-type:square;'>Battery is powering device=0</li><li style='list-style-type:square;'>Battery is charging=1</li><li style='list-style-type:square;'>Device is externally powered=2</li> <li style='list-style-type:square;'>Service is required for battery=3</li> <li style='list-style-type:square;'>Battery needs replacement=4</li></ul>All other bits are reserved. <h4>Battery Periodic Behaviour</h4>The device transmits a new BATTERY_STATE message with the current state information when the BatteryLevel changes significantly or the BatteryState changes. The TID field can be set to any value. <h6>Note:</h6> The definition of changing significantly is left to the implementation. It may mean when the battery level changes by 1% or 10% or 50% or some other value.
 * \file 
 * \brief Declares the callback used for Battery model updates.
 *
 */




/** Battery callback.
 *
 *  Callback for various messages to be delivered from the mesh for the Battery model
 *  \param  eventCode  code specifying the type of event that has occurred in the mesh
 *  \param data pointer to the event specific data
 *  \param length
 *  \param stateData
 *  \returns CSR_MESH_RESULT_SUCCESS if the mesh update was processed successfully
 */


CSRmeshResult BatteryAppCallback(CSRMESH_MODEL_EVENT_T eventCode, CSRMESH_EVENT_DATA_T* data,
                                               CsrUint16 length, void **stateData);


#endif
