/*****************************************************************************
 *
 * Copyright [2015] Qualcomm Technologies International, Ltd.
 *
 *****************************************************************************/
/* Note: this is an auto-generated file. */


#ifndef __WATCHDOG_APP_CALLBACK_H__

#define __WATCHDOG_APP_CALLBACK_H__
#include "csr_mesh_model_common.h"
#include "csr_types.h"
#include "csr_mesh_result.h"

/** \addtogroup Watchdog
 * @{
 * \JAVADOC_AUTOBRIEF <br>The Watchdog Model uses the concept of an interval that allows a device to send out a watchdog message at a known frequency. This message can be used by devices to determine whether the sending device is still connected to the network. For example, a window sensor that only transmits when it detects an alarm condition uses the watchdog message to inform other devices that it is still alive. The periodicity of these watchdog messages can be configured on each device, allowing devices that need shorter reporting intervals to be configured accordingly.<br><br> After these watchdog messages are sent, the devices can stay active for a short period of time for the capture of responses and for other devices to reconfigure these devices. This is most useful to allow devices that normally never listen for CSRmesh messages to be reconfigured or managed by devices. For example, a temperature sensor may only transmit the current room temperature, and send out a watchdog message once a day; when this single watchdog message is received, the sending device would stay active and another device could check the firmware version and possibly request the sending device to start to update its firmware. This enables the lowest possible power operation for the majority of the time whilst still allowing devices to be reconfigured within a known period of time.<br><br> Watchdog messages can also be used to ensure that a predetermined pattern of activity is maintained. This is done by issuing watchdog messages where the expected messages should be sent but for some reason are not sent, for example when a home owner is on vacation. This ensures that a similar traffic pattern is maintained and thus offers protection against traffic analysis and occupancy detection.<br><br> For example, a light switch may send out a few messages between 07:00 and 08:00 in the morning, and a few messages between 19:00 and 22:00. It can simulate this by sending watchdog messages that are sized similarly. It can even simulate the appropriate responses from devices by requesting a response with a similarly appropriate size. Devices can therefore protect against passive eavesdroppers monitoring the occupancy of a building from the quantity, size, or timing of messages.<h4>Client Behaviour</h4>If a device does not send any messages, but it should normally send some messages, for example because the building is currently unoccupied, the device may send one or more WATCHDOG_MESSAGE s to simulate the typical functionality of the device. The size of the WATCHDOG_MESSAGE s should be the same as the typical MCP messages that the device normally sends, and the RspSize should be set to the size of the typical responses to these messages. The MCP Dst field should also be set to the typical destination identifiers this device uses. <h6>Note:</h6> This behaviour prevents a passive eavesdropper from performing coarse traffic analysis to determine if a building is occupied and the coarse location of people in this building<h4> Background Behaviour</h4>The device should transmit a new random WATCHDOG_MESSAGE at least once every Interval state value seconds. A random message is defined as one that has the RspSize field set to the value zero, and the RandomData field set to a random number of random values, from 0 to 9 octets in length.<br><br> The ActiveAfterTime state value determines for how long a device should listen for the CSRmesh packets after transmitting a WATCHDOG_MESSAGE. This allows devices to be reconfigured at least once every Interval by waiting for a WATCHDOG_MESSAGE to be received from that device and then sending them another message at this time.<br><br>A device may transmit a new random WATCHDOG_MESSAGE at similar intervals to the normal operation of the device.
 * \file 
 * \brief Declares the callback used for Watchdog model updates.
 *
 */




/** Watchdog callback.
 *
 *  Callback for various messages to be delivered from the mesh for the Watchdog model
 *  \param  eventCode  code specifying the type of event that has occurred in the mesh
 *  \param data pointer to the event specific data
 *  \param length
 *  \param stateData
 *  \returns CSR_MESH_RESULT_SUCCESS if the mesh update was processed successfully
 */


CSRmeshResult WatchdogAppCallback(CSRMESH_MODEL_EVENT_T eventCode, CSRMESH_EVENT_DATA_T* data,
                                               CsrUint16 length, void **stateData);


#endif
