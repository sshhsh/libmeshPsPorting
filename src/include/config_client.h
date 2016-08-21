/*****************************************************************************
 *
 * Copyright [2015] Qualcomm Technologies International, Ltd.
 *
 *****************************************************************************/
/* Note: this is an auto-generated file. */

#ifndef __CONFIG_CLIENT_H__
#define __CONFIG_CLIENT_H__

#include "csr_types.h"
#include "csr_mesh_model_common.h"
#include "csr_mesh_result.h"
#include "csr_mesh_mcp_types.h"
/** \addtogroup Config
 * @{
 * \JAVADOC_AUTOBRIEF <br>The Configuration Model configures the device within MCP. It sets the ability to discover devices within the CSRmesh network, configure the Device ID for a given device, and discover device information such as the set of models a device supports or a device UUID. It also sets the communication parameters for this device including the receive and transmit duty cycles and time-to-live values for transmitted packets. <h6>Note:</h6>Many devices implement the configuration model because it provides the primary method of inspecting a device and configuring the device. It has been considered that this model should be made mandatory, however at this time it is not a mandatory model as some devices may not need the configuration model; a device that only transmits asset broadcast messages using the asset model may not need the configuration model to work.<h4>Configuration State</h4>The configuration model has the following states:<ul style='list-style:square;list-style-position: inside;'><li style='list-style-type:square;'>DeviceUUID</li> <li style='list-style-type:square;'>SequenceNumber</li> <li style='list-style-type:square;'>DeviceID</li><li style='list-style-type:square;'> ModelsSupported</li><li style='list-style-type:square;'> TransmitInterval</li><li style='list-style-type:square;'>TransmitDuration<li style='list-style-type:square;'>ReceiverDutyCycle</li><li style='list-style-type:square;'>TransmitPower </li><li style='list-style-type:square;'>DefaultTimeToLive </li><li style='list-style-type:square;'>VendorIdentifier<li style='list-style-type:square;'>ProductIdentifier</li><li style='list-style-type:square;'>VersionNumber </li><li style='list-style-type:square;'>Appearance  </li><li style='list-style-type:square;'>LastETag </li></ul><h5> DeviceUUID</h5>DeviceUUID is the 128-bit UUID, the unique identifier for the device. This value is fixed and cannot be changed. DeviceUUID is used to generate DeviceHash in some configuration messages.<h5>SequenceNumber</h5>SequenceNumber is a 24-bit unsigned integer.<h5>DeviceID</h5>DeviceID is a 16-bit value. This value is used as the source address of the device when sending MCP messages and as the destination address when other devices send packets to this device. <h5> ModelsSupported </h5>ModelsSupported is a 128-bit bit field that has a single bit allocated for each model. If a bit is set, then the server behaviour of the set model should be supported, otherwise the server behaviour of the model is not supported.<h6>Note:</h6>It is not possible to determine if a device supports the client behaviour of a model, as this would be typically be determined by the functionality that the device exposes to the user.<h5>TransmitInterval</h5>The TransmitInterval is a 16-bit unsigned integer in milliseconds. This value determines how often a device retransmits a CSRmesh message.<h5>TransmitDuration</h5>TransmitDuration is a 16-bit unsigned integer in milliseconds. This value determines how long a device retransmits a CSRmesh message.<h5> ReceiverDutyCycle</h5>The ReceiverDutyCycle is an 8-bit unsigned integer that is 1/255th of a second. This value determines how frequently a device listens for CSRmesh messages from other devices.<h6>Note:</h6>The larger this value, the more reliably this device will receive CSRmesh messages, but the device will consume more energy. If this is value is zero, then the device will not listen for messages.<h5> TransmitPower</h5>TransmitPower is an 8-bit signed integer in dBm. This value determines how much energy is used when transmitting CSRmesh messages.<h6>Note:</h6>The larger this value, the more energy this device will consume but the greater the ranges in which this device will be able to transmit messages.<h5>DefaultTimeToLive</h5>DefaultTimeToLive is an 8-bit unsigned integer. <h5>VendorIdentifier</h5>VendorIdentifier is a 16-bit unsigned integer. This shall use the same enumerations as the existing Bluetooth SIG Company Identification assigned numbers.<h5>ProductIdentifier</h5>The ProductIdentifier is a 16-bit unsigned integer allocated by the Vendor.<h5>VersionNumber</h5>VersionNumber is a 32-bit unsigned integer allocated per product by the vendor. Each new version of the device shall have a different VersionNumber. A new version is defined as any change to the software, hardware or firmware of a device, even if this change has no material impact to the behaviour of the device.<h5>Appearance</h5>Appearance is a 24-bit unsigned integer using the same the Bluetooth SIG GAP Appearance characteristic values.<h5>LastETag</h5>LastETag is a 64-bit unsigned integer that should be set to a different value each time the device has a change in its configuration. This value is a read only value, and can be used to quickly determine if a device has changed its configuration without another device reading the full configuration. A configuration change is defined as any change to the device such that the device behaviour changes - for example, changing Groups or the interval for sending Sensor broadcast data.<h4>Config Background Behaviour</h4>If a device does not have a DeviceID, that is, the DeviceID is 0x0000, then it may periodically transmit a CONFIG_DEVICE_IDENTIFIER message to the destination address of 0x0000 with its DeviceHash.
 * \file 
 * \brief Declares the messages supported by the Config model.
 *
 * \details <br>The Configuration Model configures the device within MCP. It sets the ability to discover devices within the CSRmesh network, configure the Device ID for a given device, and discover device information such as the set of models a device supports or a device UUID. It also sets the communication parameters for this device including the receive and transmit duty cycles and time-to-live values for transmitted packets. <h6>Note:</h6>Many devices implement the configuration model because it provides the primary method of inspecting a device and configuring the device. It has been considered that this model should be made mandatory, however at this time it is not a mandatory model as some devices may not need the configuration model; a device that only transmits asset broadcast messages using the asset model may not need the configuration model to work.<h4>Configuration State</h4>The configuration model has the following states:<ul style='list-style:square;list-style-position: inside;'><li style='list-style-type:square;'>DeviceUUID</li> <li style='list-style-type:square;'>SequenceNumber</li> <li style='list-style-type:square;'>DeviceID</li><li style='list-style-type:square;'> ModelsSupported</li><li style='list-style-type:square;'> TransmitInterval</li><li style='list-style-type:square;'>TransmitDuration<li style='list-style-type:square;'>ReceiverDutyCycle</li><li style='list-style-type:square;'>TransmitPower </li><li style='list-style-type:square;'>DefaultTimeToLive </li><li style='list-style-type:square;'>VendorIdentifier<li style='list-style-type:square;'>ProductIdentifier</li><li style='list-style-type:square;'>VersionNumber </li><li style='list-style-type:square;'>Appearance  </li><li style='list-style-type:square;'>LastETag </li></ul><h5> DeviceUUID</h5>DeviceUUID is the 128-bit UUID, the unique identifier for the device. This value is fixed and cannot be changed. DeviceUUID is used to generate DeviceHash in some configuration messages.<h5>SequenceNumber</h5>SequenceNumber is a 24-bit unsigned integer.<h5>DeviceID</h5>DeviceID is a 16-bit value. This value is used as the source address of the device when sending MCP messages and as the destination address when other devices send packets to this device. <h5> ModelsSupported </h5>ModelsSupported is a 128-bit bit field that has a single bit allocated for each model. If a bit is set, then the server behaviour of the set model should be supported, otherwise the server behaviour of the model is not supported.<h6>Note:</h6>It is not possible to determine if a device supports the client behaviour of a model, as this would be typically be determined by the functionality that the device exposes to the user.<h5>TransmitInterval</h5>The TransmitInterval is a 16-bit unsigned integer in milliseconds. This value determines how often a device retransmits a CSRmesh message.<h5>TransmitDuration</h5>TransmitDuration is a 16-bit unsigned integer in milliseconds. This value determines how long a device retransmits a CSRmesh message.<h5> ReceiverDutyCycle</h5>The ReceiverDutyCycle is an 8-bit unsigned integer that is 1/255th of a second. This value determines how frequently a device listens for CSRmesh messages from other devices.<h6>Note:</h6>The larger this value, the more reliably this device will receive CSRmesh messages, but the device will consume more energy. If this is value is zero, then the device will not listen for messages.<h5> TransmitPower</h5>TransmitPower is an 8-bit signed integer in dBm. This value determines how much energy is used when transmitting CSRmesh messages.<h6>Note:</h6>The larger this value, the more energy this device will consume but the greater the ranges in which this device will be able to transmit messages.<h5>DefaultTimeToLive</h5>DefaultTimeToLive is an 8-bit unsigned integer. <h5>VendorIdentifier</h5>VendorIdentifier is a 16-bit unsigned integer. This shall use the same enumerations as the existing Bluetooth SIG Company Identification assigned numbers.<h5>ProductIdentifier</h5>The ProductIdentifier is a 16-bit unsigned integer allocated by the Vendor.<h5>VersionNumber</h5>VersionNumber is a 32-bit unsigned integer allocated per product by the vendor. Each new version of the device shall have a different VersionNumber. A new version is defined as any change to the software, hardware or firmware of a device, even if this change has no material impact to the behaviour of the device.<h5>Appearance</h5>Appearance is a 24-bit unsigned integer using the same the Bluetooth SIG GAP Appearance characteristic values.<h5>LastETag</h5>LastETag is a 64-bit unsigned integer that should be set to a different value each time the device has a change in its configuration. This value is a read only value, and can be used to quickly determine if a device has changed its configuration without another device reading the full configuration. A configuration change is defined as any change to the device such that the device behaviour changes - for example, changing Groups or the interval for sending Sensor broadcast data.<h4>Config Background Behaviour</h4>If a device does not have a DeviceID, that is, the DeviceID is 0x0000, then it may periodically transmit a CONFIG_DEVICE_IDENTIFIER message to the destination address of 0x0000 with its DeviceHash.
 */




/** Config Initializer.
 *
 *  Response for various messages will be provided in the supplied callback
 *  \param  configAppCallback  callback to receive response
 *  \returns CSR_MESH_RESULT_SUCCESS if the request was successful
 */

CSRmeshResult ConfigModelClientInit(CSRMESH_MODEL_CALLBACK_T configAppCallback);



/** \JAVADOC_AUTOBRIEF Upon receiving a CONFIG_LAST_SEQUENCE_NUMBER message from a trusted device, the local device updates the SequenceNumber to at least one higher than the LastSequenceNumber in the message. Note: A trusted device means a device that is not only on the same CSRmesh network, having the same network key, but also interacted with in the past. This message is most useful to check if a device has been reset, for example when the batteries of the device are changed, but it does not remember its last sequence number in non-volatile memory.
 *
 *  \param  nwkId  Network ID
 *  \param  destDevId  device ID
 *  \param  repeat  Number of times the request should be repeated on the mesh node 
 *  \param  lastSequenceNumber The last sequence number seen by the source device from the destination device.
 *
 *  \returns CSR_MESH_RESULT_SUCCESS if the request was successful
 */

CSRmeshResult ConfigLastSequenceNumber(CsrUint8 nwkId,CsrUint16 destDevId,CsrUint8 repeat,CsrUint32 lastSequenceNumber);




/** \JAVADOC_AUTOBRIEF Upon receiving a CONFIG_RESET_DEVICE message from a trusted device directed at only this device, the local device sets the DeviceID to zero, and forgets all network keys, associated NetworkIVs and other configuration information. The device may act as if it is not associated and use MASP to re-associate with a network. Note: If the CONFIG_RESET_DEVICE message is received on any other destination address than the DeviceID of the local device, it is ignored. This is typically used when selling a device, to remove the device from the network of the seller so that the purchaser can associate the device with their network.
 *
 *  \param  nwkId  Network ID
 *  \param  destDevId  device ID
 *  \param  repeat  Number of times the request should be repeated on the mesh node 
 *
 *  \returns CSR_MESH_RESULT_SUCCESS if the request was successful
 */

CSRmeshResult ConfigResetDevice(CsrUint8 nwkId,CsrUint16 destDevId,CsrUint8 repeat);




/** \JAVADOC_AUTOBRIEF When the device with a DeviceID of 0x0000 receives a CONFIG_SET_DEVICE_IDENTIFIER message and the DeviceHash of the message matches the DeviceHash of this device, the DeviceID of this device is set to the DeviceID field of this message. Then the device responds with the DEVICE_CONFIG_IDENTIFIER message using the new DeviceID as the source address. Note: This function is not necessary in normal operation of a CSRmesh network as DeviceID is distributed as part of the MASP protocol in the MASP_ID_DISTRIBUTION message.
 *
 *  \param  nwkId  Network ID
 *  \param  destDevId  device ID
 *  \param  repeat  Number of times the request should be repeated on the mesh node 
 *  \param  deviceHash The DeviceHash for the device that will have a new DeviceID.
 *  \param  deviceHashLen length of deviceHash array
 *  \param  deviceId The new DeviceID for the device identified by DeviceHash.
 *
 *  \returns CSR_MESH_RESULT_SUCCESS if the request was successful
 */

CSRmeshResult ConfigSetDeviceIdentifier(CsrUint8 nwkId,CsrUint16 destDevId,CsrUint8 repeat,CsrUint8* deviceHash, CsrUint8 deviceHashLen ,CsrUint16 deviceId);




/** \JAVADOC_AUTOBRIEF Upon receiving a CONFIG_SET_PARAMETERS message, where the destination address is the DeviceID of this device, the device saves the TxInterval, TxDuration, RxDutyCycle, TxPower and TTL fields into the TransmitInterval, TransmitDuration, ReceiverDutyCycle, TransmitPower and DefaultTimeToLive state respectively. Then the device responds with a CONFIG_PARAMETERS message with the current configuration model state information.
 *
 *  \param  nwkId  Network ID
 *  \param  destDevId  device ID
 *  \param  repeat  Number of times the request should be repeated on the mesh node 
 *  \param  txInterval The transmit interval for this device. The TxInterval field is a 16-bit unsigned integer in milliseconds that determines the interval between transmitting messages.
 *  \param  txDuration How long a single transmission should occur for. The TxDuration, or transmit duration field is a 16-bit unsigned integer in milliseconds that determines the duration of transmission for a single message.
 *  \param  rxDutyCycle How much time this device listens for messages. The RxDutyCycle, or receiver duty cycle field is an 8-bit unsigned integer in 1/255ths of a second that determines how often the device listens for CSRmesh messages. Note: The value 0x00 implies that the device does not listen for messages. The value 0xFF implies that the device continuously listens for messages.
 *  \param  txPower How loud the device transmits messages. The TxPower, or transmit power field is an 8-bit signed integer in decibels that determines the radio transmit power for a device.
 *  \param  timeToLive The initial default time to live for messages. The TimeToLive field is an 8-bit unsigned integer that determines the default value for the TTL packet field in an MTL packet.
 *  \param  tid Transaction identifier. The TID, or transaction identifier field is an 8-bit integer that identifies a given message with a known transaction from a source device.
 *
 *  \returns CSR_MESH_RESULT_SUCCESS if the request was successful
 */

CSRmeshResult ConfigSetParameters(CsrUint8 nwkId,CsrUint16 destDevId,CsrUint8 repeat,CsrUint16 txInterval,CsrUint16 txDuration,CsrUint8 rxDutyCycle,CsrInt8 txPower,CsrUint8 timeToLive,CsrUint8 tid);




/** \JAVADOC_AUTOBRIEF Upon receiving a CONFIG_SET_PARAMETERS message, where the destination address is the DeviceID of this device, the device will respond with a CONFIG_PARAMETERS message with the current config model state information.
 *
 *  \param  nwkId  Network ID
 *  \param  destDevId  device ID
 *  \param  repeat  Number of times the request should be repeated on the mesh node 
 *  \param  tid Transaction identifier. The TID, or transaction identifier field is an 8-bit integer that identifies a given message with a known transaction from a source device.
 *
 *  \returns CSR_MESH_RESULT_SUCCESS if the request was successful
 */

CSRmeshResult ConfigGetParameters(CsrUint8 nwkId,CsrUint16 destDevId,CsrUint8 repeat,CsrUint8 tid);







/** \JAVADOC_AUTOBRIEF Upon receiving a CONFIG_DISCOVER_DEVICE message directed at the 0x0000 group identifier or to DeviceID of this device, the device responds with a CONFIG_DEVICE_IDENTIFIER message.
 *
 *  \param  nwkId  Network ID
 *  \param  destDevId  device ID
 *  \param  repeat  Number of times the request should be repeated on the mesh node 
 *  \param  tid Transaction identifier. The TID, or transaction identifier field is an 8-bit integer that identifies a given message with a known transaction from a source device.
 *
 *  \returns CSR_MESH_RESULT_SUCCESS if the request was successful
 */

CSRmeshResult ConfigDiscoverDevice(CsrUint8 nwkId,CsrUint16 destDevId,CsrUint8 repeat,CsrUint8 tid);







/** \JAVADOC_AUTOBRIEF Upon receiving a CONFIG_GET_INFO message, directed at the DeviceID of this device, the device responds with a CONFIG_INFO message. The Info field of the CONFIG_GET_INFO message determines the information to be included in the CONFIG_INFO message. The following information values are defined: DeviceUUIDLow (0x00) contains the least significant eight octets of the DeviceUUID state value. DeviceUUIDHigh (0x01) contains the most significant eight octets of the DeviceUUID state value. ModelsLow (0x02) contains the least significant eight octets of the ModelsSupported state value. ModelsHigh (0x03) contains the most significant eight octets of the ModelsSupported state value.
 *
 *  \param  nwkId  Network ID
 *  \param  destDevId  device ID
 *  \param  repeat  Number of times the request should be repeated on the mesh node 
 *  \param  info The type of information being requested. The Info field is an 8-bit unsigned integer that enumerates the information being requested. The following values are defined: 0x00 = UUID Low, 0x01 UUID High, 0x02 = Model Low, 0x03 = Model High, 0x04 = VID_PID_Version, 0x05 = Appearance, 0x06 = LastETag.
 *  \param  tid Transaction identifier. The TID, or transaction identifier field is an 8-bit integer that identifies a given message with a known transaction from a source device.
 *
 *  \returns CSR_MESH_RESULT_SUCCESS if the request was successful
 */

CSRmeshResult ConfigGetInfo(CsrUint8 nwkId,CsrUint16 destDevId,CsrUint8 repeat,CSR_MESH_DEVICE_INFORMATION_T info,CsrUint8 tid);






/*!@} */
#endif /* __CONFIG_CLIENT_H__ */
