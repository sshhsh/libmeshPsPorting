/*****************************************************************************
 *
 * Copyright [2015] Qualcomm Technologies International, Ltd.
 *
 *****************************************************************************/
/* Note: this is an auto-generated file. */


#ifndef __CONFIG_APP_CALLBACK_H__

#define __CONFIG_APP_CALLBACK_H__
#include "csr_mesh_model_common.h"
#include "csr_types.h"
#include "csr_mesh_result.h"

/** \addtogroup Config
 * @{
 * \JAVADOC_AUTOBRIEF <br>The Configuration Model configures the device within MCP. It sets the ability to discover devices within the CSRmesh network, configure the Device ID for a given device, and discover device information such as the set of models a device supports or a device UUID. It also sets the communication parameters for this device including the receive and transmit duty cycles and time-to-live values for transmitted packets. <h6>Note:</h6>Many devices implement the configuration model because it provides the primary method of inspecting a device and configuring the device. It has been considered that this model should be made mandatory, however at this time it is not a mandatory model as some devices may not need the configuration model; a device that only transmits asset broadcast messages using the asset model may not need the configuration model to work.<h4>Configuration State</h4>The configuration model has the following states:<ul style='list-style:square;list-style-position: inside;'><li style='list-style-type:square;'>DeviceUUID</li> <li style='list-style-type:square;'>SequenceNumber</li> <li style='list-style-type:square;'>DeviceID</li><li style='list-style-type:square;'> ModelsSupported</li><li style='list-style-type:square;'> TransmitInterval</li><li style='list-style-type:square;'>TransmitDuration<li style='list-style-type:square;'>ReceiverDutyCycle</li><li style='list-style-type:square;'>TransmitPower </li><li style='list-style-type:square;'>DefaultTimeToLive </li><li style='list-style-type:square;'>VendorIdentifier<li style='list-style-type:square;'>ProductIdentifier</li><li style='list-style-type:square;'>VersionNumber </li><li style='list-style-type:square;'>Appearance  </li><li style='list-style-type:square;'>LastETag </li></ul><h5> DeviceUUID</h5>DeviceUUID is the 128-bit UUID, the unique identifier for the device. This value is fixed and cannot be changed. DeviceUUID is used to generate DeviceHash in some configuration messages.<h5>SequenceNumber</h5>SequenceNumber is a 24-bit unsigned integer.<h5>DeviceID</h5>DeviceID is a 16-bit value. This value is used as the source address of the device when sending MCP messages and as the destination address when other devices send packets to this device. <h5> ModelsSupported </h5>ModelsSupported is a 128-bit bit field that has a single bit allocated for each model. If a bit is set, then the server behaviour of the set model should be supported, otherwise the server behaviour of the model is not supported.<h6>Note:</h6>It is not possible to determine if a device supports the client behaviour of a model, as this would be typically be determined by the functionality that the device exposes to the user.<h5>TransmitInterval</h5>The TransmitInterval is a 16-bit unsigned integer in milliseconds. This value determines how often a device retransmits a CSRmesh message.<h5>TransmitDuration</h5>TransmitDuration is a 16-bit unsigned integer in milliseconds. This value determines how long a device retransmits a CSRmesh message.<h5> ReceiverDutyCycle</h5>The ReceiverDutyCycle is an 8-bit unsigned integer that is 1/255th of a second. This value determines how frequently a device listens for CSRmesh messages from other devices.<h6>Note:</h6>The larger this value, the more reliably this device will receive CSRmesh messages, but the device will consume more energy. If this is value is zero, then the device will not listen for messages.<h5> TransmitPower</h5>TransmitPower is an 8-bit signed integer in dBm. This value determines how much energy is used when transmitting CSRmesh messages.<h6>Note:</h6>The larger this value, the more energy this device will consume but the greater the ranges in which this device will be able to transmit messages.<h5>DefaultTimeToLive</h5>DefaultTimeToLive is an 8-bit unsigned integer. <h5>VendorIdentifier</h5>VendorIdentifier is a 16-bit unsigned integer. This shall use the same enumerations as the existing Bluetooth SIG Company Identification assigned numbers.<h5>ProductIdentifier</h5>The ProductIdentifier is a 16-bit unsigned integer allocated by the Vendor.<h5>VersionNumber</h5>VersionNumber is a 32-bit unsigned integer allocated per product by the vendor. Each new version of the device shall have a different VersionNumber. A new version is defined as any change to the software, hardware or firmware of a device, even if this change has no material impact to the behaviour of the device.<h5>Appearance</h5>Appearance is a 24-bit unsigned integer using the same the Bluetooth SIG GAP Appearance characteristic values.<h5>LastETag</h5>LastETag is a 64-bit unsigned integer that should be set to a different value each time the device has a change in its configuration. This value is a read only value, and can be used to quickly determine if a device has changed its configuration without another device reading the full configuration. A configuration change is defined as any change to the device such that the device behaviour changes - for example, changing Groups or the interval for sending Sensor broadcast data.<h4>Config Background Behaviour</h4>If a device does not have a DeviceID, that is, the DeviceID is 0x0000, then it may periodically transmit a CONFIG_DEVICE_IDENTIFIER message to the destination address of 0x0000 with its DeviceHash.
 * \file 
 * \brief Declares the callback used for Config model updates.
 *
 */




/** Config callback.
 *
 *  Callback for various messages to be delivered from the mesh for the Config model
 *  \param  eventCode  code specifying the type of event that has occurred in the mesh
 *  \param data pointer to the event specific data
 *  \param length
 *  \param stateData
 *  \returns CSR_MESH_RESULT_SUCCESS if the mesh update was processed successfully
 */


CSRmeshResult ConfigAppCallback(CSRMESH_MODEL_EVENT_T eventCode, CSRMESH_EVENT_DATA_T* data,
                                               CsrUint16 length, void **stateData);


#endif
