/*****************************************************************************
 *
 * Copyright [2015] Qualcomm Technologies International, Ltd.
 *
 *****************************************************************************/
/* Note: this is an auto-generated file. */

#ifndef __SENSOR_MODEL_H__
#define __SENSOR_MODEL_H__

#include "csr_mesh_model_common.h"
#include "csr_types.h"
#include "csr_mesh_mcp_types.h"

/** \addtogroup Sensor
 * @{
 * \JAVADOC_AUTOBRIEF <br>The Sensor Model broadcasts values to other devices in the CSRmesh network. These values are either based on the physical measurement of something, for example the current air temperature, or based on a desired value for such a physical measurement. These desired values can be used by devices locally so that a feedback loop is created. For example, a fan can receive both the current air temperature and the desired air temperature from other devices and will turn on when the current air temperature is higher than the desired air temperature.<br><br> The sensor model logically includes two separate types of devices: a source of sensor values, known as a sensor server, and user of sensor values, known as a client. A device may implement both the source and user of sensor values, known as a combined device. A device may also proxy sensor values from other devices even though it does not generate nor act upon those values itself.<br><br> The sensor model defines three roles:<ul style='list-style:square;list-style-position: inside;'><li style='list-style-type:square;'>Server</li><li style='list-style-type:square;'>Client</li><li style='list-style-type:square;'>Proxy </li></ul><br> When a source transmits a sensor value in the CSRmesh network, it transmits the value multiple times over an extended period of time. This allows low duty cycle clients and proxies with reasonable proximity to receive the messages.<br> <br>There are two types of sensor values:immediate values and shared state values. Immediate values typically represent a current physical measurement. While multiple devices in a single room or group may measure the same physical measurement, their different values are significant because the differences convey additional information. Shared state values typically represent an intention or desire. If there are multiple devices within a room or group that need to know these shared state values, they should all work together to use the same value, distributing these values between each other until every device has the same shared state value.<br><br> Sensor values are always sent within the context of a group. It is the group that has the sensor value, not the individual devices. For example, the desired air temperature may be known by multiple devices, a window, a vent, a fan, an extractor fan, a heater, an air-conditioning unit, or a light; sending a request to read the current desired air temperature can elicit a response from any of these devices. This allows fast replacement or repurposing of equipment by configuring just the group codes for devices.<br><br> Devices may act as a proxy for sensor data. For example, a device that is able to listen all the time may listen for sensor messages and store the latest values for each type of sensor data for one or more groups. As stated above, the sensor values are associated with a group of devices and proxies do not have to understand the meaning or types of these sensor values or which devices generate these values. The proxies only need to know that the sensor values are associated with a given group. This allows any device to easily help reduce the power consumption of other devices within a room by taking the burden of remembering sensor values and listening to requests and responding with these values, or updating other devices with the latest shared state values. This can be done by any device.<br><br> A device that needs to know the current state of some sensor data may request the current state of the value from any other device in the group. A device may also send out a message that it is missing the current state of a value. These messages can highlight missing functionality at the group or network levels.<br><br> This specification defines a set of sensor types that describe the format and meaning of the sensor values. Multiple sensor types can be sent in a single message, although there are limits to the practical number of sensor values that can fit into a single message.<br><br> Sensor types based on physical measurements are always in SI units. No derived units are used. For example, temperature is measured as an integer multiple of 0.03125 kelvin. This implies that the resultant temperature must be converted to represent the temperature using the Celsius or Fahrenheit temperature scales. For example, 0 degrees Centigrade would be represented by the value 8741. This also implies that the Celsius temperature can represent accurately a temperature down to 0.1 degrees Centigrade and also a range of values from -273.1 degrees Centigrade to 1774.8 degrees Centigrade. The Fahrenheit scale can also represent temperatures down to 0.1 degrees Fahrenheit accuracy with a range from -459.67 degrees Fahrenheit to 3226.7 degrees Fahrenheit. This enables all devices to be sold worldwide to work with each other and display the temperature in whatever the local unit or user preference is. <br><br> Additional examples of SI unit representations include: speed measured in centimetres per second, air pressure in hecto-Pascals. Some values such as compass direction are compressed to a single octet representation, yet are still measured in radians. For example, each increment in the value increases the direction by 2pi/256 radians.<br><br> Some sensor types are based on bit-fields or enumerated values. To allow future extensions of these types a very simple extensibility protocol is used: If a bit is not defined in this specification, it should be transmitted as a zero and ignored upon receipt; if an enumerated value is not defined in this specification, it should not be transmitted and should be ignored upon receipt.<br><br> A device may support zero or more sensor types. For a given sensor type, there can be only one instance of this sensor type in a device. The set of supported types can therefore be considered to be a set of types. Given that a typical device may only support a very small number of types and these types are sparsely distributed, the method to discover the types supported by a device should be by returning the types supported and not as a bit-field or similar representation.<br><br> The exact representation of sensor values and the assigned numbers are documented in the mcp.json file included with this specification.<h4> Sensor State</h4>The sensor model has the following states:<ul style='list-style:square;list-style-position: inside;'><li style='list-style-type:square;'>Types</li><li style='list-style-type:square;'>Shared State Value</li></ul><h5>Types</h5>The types that a device supports are a property of a device that must be able to be discovered by a configuring device. A device may support zero or more types; there is no limit to the number of types that a device supports except imposed by the number of defined types. The types supported should be considered an ordered set of types. The types are enumerated using a 16-bit unsigned integer. The meaning of these types is defined in the associated mcp.json file.<h5> Shared State Value</h5>The shared state value is a variable length value that a device should remember so that the state of the shared state sensor type can be distributed to other devices in the network. <h4> Sensor Client Behaviour</h4>When a device is writing a new sensor value to another device or a set of devices identified by a group, the duty cycle of the destination device(s) may restrict the probability that the message is received. The client should therefore retransmit the SENSOR_WRITE_VALUE and SENSOR_WRITE_VALUE_NO_ACK messages multiple times over a period of time to increase the probability of the message being received by all devices. If SENSOR_WRITE_VALUE is used, then the retransmission of messages may be terminated early if a SENSOR_VALUE message is received from all devices from which such a message is expected. <h6>Note:</h6> The value in the SENSOR_VALUE message may be different from the value in the SENSOR_WRITE_VALUE message because another device may also be writing this value at the same time; the value in the SENSOR_VALUE message is always the latest value from the sending device.<h4>Sensor Periodic Behaviour</h4> For each sensor type that a device supports and for which the period is a non-zero time, if the sensor type is an immediate sensor type, then the device should send SENSOR_VALUE every period of time, with the value in this message as the latest measured value.<br><br> If a device is expecting a value to be written to a sensor type and no value is written within a reasonable period of time, the sensor can send a SENSOR_MISSING message. This message can be used by a sensor client to start sending sensor values to this device.
 * \file 
 * \brief Defines the structures used by the Sensor model.
 *
 * \details <br>The Sensor Model broadcasts values to other devices in the CSRmesh network. These values are either based on the physical measurement of something, for example the current air temperature, or based on a desired value for such a physical measurement. These desired values can be used by devices locally so that a feedback loop is created. For example, a fan can receive both the current air temperature and the desired air temperature from other devices and will turn on when the current air temperature is higher than the desired air temperature.<br><br> The sensor model logically includes two separate types of devices: a source of sensor values, known as a sensor server, and user of sensor values, known as a client. A device may implement both the source and user of sensor values, known as a combined device. A device may also proxy sensor values from other devices even though it does not generate nor act upon those values itself.<br><br> The sensor model defines three roles:<ul style='list-style:square;list-style-position: inside;'><li style='list-style-type:square;'>Server</li><li style='list-style-type:square;'>Client</li><li style='list-style-type:square;'>Proxy </li></ul><br> When a source transmits a sensor value in the CSRmesh network, it transmits the value multiple times over an extended period of time. This allows low duty cycle clients and proxies with reasonable proximity to receive the messages.<br> <br>There are two types of sensor values:immediate values and shared state values. Immediate values typically represent a current physical measurement. While multiple devices in a single room or group may measure the same physical measurement, their different values are significant because the differences convey additional information. Shared state values typically represent an intention or desire. If there are multiple devices within a room or group that need to know these shared state values, they should all work together to use the same value, distributing these values between each other until every device has the same shared state value.<br><br> Sensor values are always sent within the context of a group. It is the group that has the sensor value, not the individual devices. For example, the desired air temperature may be known by multiple devices, a window, a vent, a fan, an extractor fan, a heater, an air-conditioning unit, or a light; sending a request to read the current desired air temperature can elicit a response from any of these devices. This allows fast replacement or repurposing of equipment by configuring just the group codes for devices.<br><br> Devices may act as a proxy for sensor data. For example, a device that is able to listen all the time may listen for sensor messages and store the latest values for each type of sensor data for one or more groups. As stated above, the sensor values are associated with a group of devices and proxies do not have to understand the meaning or types of these sensor values or which devices generate these values. The proxies only need to know that the sensor values are associated with a given group. This allows any device to easily help reduce the power consumption of other devices within a room by taking the burden of remembering sensor values and listening to requests and responding with these values, or updating other devices with the latest shared state values. This can be done by any device.<br><br> A device that needs to know the current state of some sensor data may request the current state of the value from any other device in the group. A device may also send out a message that it is missing the current state of a value. These messages can highlight missing functionality at the group or network levels.<br><br> This specification defines a set of sensor types that describe the format and meaning of the sensor values. Multiple sensor types can be sent in a single message, although there are limits to the practical number of sensor values that can fit into a single message.<br><br> Sensor types based on physical measurements are always in SI units. No derived units are used. For example, temperature is measured as an integer multiple of 0.03125 kelvin. This implies that the resultant temperature must be converted to represent the temperature using the Celsius or Fahrenheit temperature scales. For example, 0 degrees Centigrade would be represented by the value 8741. This also implies that the Celsius temperature can represent accurately a temperature down to 0.1 degrees Centigrade and also a range of values from -273.1 degrees Centigrade to 1774.8 degrees Centigrade. The Fahrenheit scale can also represent temperatures down to 0.1 degrees Fahrenheit accuracy with a range from -459.67 degrees Fahrenheit to 3226.7 degrees Fahrenheit. This enables all devices to be sold worldwide to work with each other and display the temperature in whatever the local unit or user preference is. <br><br> Additional examples of SI unit representations include: speed measured in centimetres per second, air pressure in hecto-Pascals. Some values such as compass direction are compressed to a single octet representation, yet are still measured in radians. For example, each increment in the value increases the direction by 2pi/256 radians.<br><br> Some sensor types are based on bit-fields or enumerated values. To allow future extensions of these types a very simple extensibility protocol is used: If a bit is not defined in this specification, it should be transmitted as a zero and ignored upon receipt; if an enumerated value is not defined in this specification, it should not be transmitted and should be ignored upon receipt.<br><br> A device may support zero or more sensor types. For a given sensor type, there can be only one instance of this sensor type in a device. The set of supported types can therefore be considered to be a set of types. Given that a typical device may only support a very small number of types and these types are sparsely distributed, the method to discover the types supported by a device should be by returning the types supported and not as a bit-field or similar representation.<br><br> The exact representation of sensor values and the assigned numbers are documented in the mcp.json file included with this specification.<h4> Sensor State</h4>The sensor model has the following states:<ul style='list-style:square;list-style-position: inside;'><li style='list-style-type:square;'>Types</li><li style='list-style-type:square;'>Shared State Value</li></ul><h5>Types</h5>The types that a device supports are a property of a device that must be able to be discovered by a configuring device. A device may support zero or more types; there is no limit to the number of types that a device supports except imposed by the number of defined types. The types supported should be considered an ordered set of types. The types are enumerated using a 16-bit unsigned integer. The meaning of these types is defined in the associated mcp.json file.<h5> Shared State Value</h5>The shared state value is a variable length value that a device should remember so that the state of the shared state sensor type can be distributed to other devices in the network. <h4> Sensor Client Behaviour</h4>When a device is writing a new sensor value to another device or a set of devices identified by a group, the duty cycle of the destination device(s) may restrict the probability that the message is received. The client should therefore retransmit the SENSOR_WRITE_VALUE and SENSOR_WRITE_VALUE_NO_ACK messages multiple times over a period of time to increase the probability of the message being received by all devices. If SENSOR_WRITE_VALUE is used, then the retransmission of messages may be terminated early if a SENSOR_VALUE message is received from all devices from which such a message is expected. <h6>Note:</h6> The value in the SENSOR_VALUE message may be different from the value in the SENSOR_WRITE_VALUE message because another device may also be writing this value at the same time; the value in the SENSOR_VALUE message is always the latest value from the sending device.<h4>Sensor Periodic Behaviour</h4> For each sensor type that a device supports and for which the period is a non-zero time, if the sensor type is an immediate sensor type, then the device should send SENSOR_VALUE every period of time, with the value in this message as the latest measured value.<br><br> If a device is expecting a value to be written to a sensor type and no value is written within a reasonable period of time, the sensor can send a SENSOR_MISSING message. This message can be used by a sensor client to start sending sensor values to this device.
 */


/** \brief Structure used with  CSRMESH_SENSOR_GET_TYPES event.
 */
typedef struct
{
    CSR_MESH_SENSOR_TYPE_T firstType; /*!< \brief The FirstType field is a 16-bit unsigned integer that determines the first Type that can be returned in the corresponding SENSOR_TYPES message. */
    CsrUint8 tid;      /*!< \brief Transaction identifier. The TID, or transaction identifier field is an 8-bit integer that identifies a given message with a known transaction from a source device. */
} CSRMESH_SENSOR_GET_TYPES_T;

/** \brief Structure used with  CSRMESH_SENSOR_TYPES event.
 */
typedef struct
{
    CsrUint8 typesLen;        /*< \brief length for types array */
    CSR_MESH_SENSOR_TYPE_T *types; /*!< \brief Array of sensor types supported (16 bits per type). The Types field is a variable length sequence of sensor types that the device sending this message supports. The sensor types included in this message shall be ordered by sensor type number and shall always be higher than the FirstType in the corresponding SENSOR_GET_TYPES message. Note: This field can be zero octets in length if a device does not support any sensor types greater than or equal to the FirstType in the corresponding SENSOR_GET_TYPES message. */
    CsrUint8 tid;      /*!< \brief Transaction identifier. The TID, or transaction identifier field is an 8-bit integer that identifies a given message with a known transaction from a source device. */
} CSRMESH_SENSOR_TYPES_T;

/** \brief Structure used with  CSRMESH_SENSOR_SET_STATE event.
 */
typedef struct
{
    CSR_MESH_SENSOR_TYPE_T type; /*!< \brief Sensor type.The Type field is a 16-bit unsigned integer that determines the sensor type for the associated state. */
    CsrUint8 repeatInterval;      /*!< \brief How often the sensor value is repeated. The RepeatInterval is an 8-bit unsigned integer representing the interval in seconds between repeated transmissions of sensor values by this device. */
    CsrUint8 tid;      /*!< \brief Transaction identifier. The TID, or transaction identifier field is an 8-bit integer that identifies a given message with a known transaction from a source device. */
} CSRMESH_SENSOR_SET_STATE_T;

/** \brief Structure used with  CSRMESH_SENSOR_GET_STATE event.
 */
typedef struct
{
    CSR_MESH_SENSOR_TYPE_T type; /*!< \brief Sensor type. The Type field is a 16-bit unsigned integer that determines the sensor types being configured. */
    CsrUint8 tid;      /*!< \brief Transaction identifier. The TID, or transaction identifier field is an 8-bit integer that identifies a given message with a known transaction from a source device. */
} CSRMESH_SENSOR_GET_STATE_T;

/** \brief Structure used with  CSRMESH_SENSOR_STATE event.
 */
typedef struct
{
    CSR_MESH_SENSOR_TYPE_T type; /*!< \brief Sensor type. The Type field is a 16-bit unsigned integer that determines the sensor type for the associated state. */
    CsrUint8 repeatInterval;      /*!< \brief How often the sensor value is repeated. */
    CsrUint8 tid;      /*!< \brief Transaction identifier. The TID, or transaction identifier field is an 8-bit integer that identifies a given message with a known transaction from a source device. */
} CSRMESH_SENSOR_STATE_T;

/** \brief Structure used with  CSRMESH_SENSOR_WRITE_VALUE_NO_ACK and  CSRMESH_SENSOR_WRITE_VALUE events.
 */
typedef struct
{
    CSR_MESH_SENSOR_TYPE_T type; /*!< \brief Sensor type. The Type field is a 16-bit unsigned integer that determines the sensor type of the value. */
    CsrUint8 valueLen;        /*< \brief length for value array */
    CsrUint8 *value;      /*!< \brief Sensor Value. The Value field is from 1 to 4 octets in length; the format of this field is determined by the Type field. */
    CSR_MESH_SENSOR_TYPE_T type2; /*!< \brief Sensor type. The Type field is a 16-bit unsigned integer that determines the second sensor type of the value. This field is optional, and can be zero octets in length. */
    CsrUint8 value2Len;        /*< \brief length for value2 array */
    CsrUint8 *value2;      /*!< \brief Sensor Value. The Value field is from 1 to 4 octets in length; the format of this field is determined by the Type2 field. This field is optional, and can be zero octets in length. */
    CsrUint8 tid;      /*!< \brief Transaction identifier. The TID, or transaction identifier field is an 8-bit integer that identifies a given message with a known transaction from a source device. */
} CSRMESH_SENSOR_WRITE_VALUE_T;

/** \brief Structure used with  CSRMESH_SENSOR_READ_VALUE event.
 */
typedef struct
{
    CSR_MESH_SENSOR_TYPE_T type; /*!< \brief Sensor type. The Type field is a 16-bit unsigned integer that determines the sensor type being read. */
    CSR_MESH_SENSOR_TYPE_T type2; /*!< \brief Sensor type. The Type field is a 16-bit unsigned integer that determines the second sensor type being read. This field is optional. */
    CsrUint8 tid;      /*!< \brief Transaction identifier. The TID, or transaction identifier field is an 8-bit integer that identifies a given message with a known transaction from a source device. */
} CSRMESH_SENSOR_READ_VALUE_T;

/** \brief Structure used with  CSRMESH_SENSOR_VALUE event.
 */
typedef struct
{
    CSR_MESH_SENSOR_TYPE_T type; /*!< \brief Sensor type. The Type field is a 16-bit unsigned integer that determines the sensor type of the value. */
    CsrUint8 valueLen;        /*< \brief length for value array */
    CsrUint8 *value;      /*!< \brief Sensor value. The Value field is from 1 to 4 octets in length; the format of this field is determined by the Type field. */
    CSR_MESH_SENSOR_TYPE_T type2; /*!< \brief Sensor type. The Type field is a 16-bit unsigned integer that determines the second sensor type of the value. This field is optional, and can be zero octets in length. */
    CsrUint8 value2Len;        /*< \brief length for value2 array */
    CsrUint8 *value2;      /*!< \brief Sensor value. The Value field is from 1 to 4 octets in length; the format of this field is determined by the Type2 field. This field shall only be included if the Type2 field exists. */
    CsrUint8 tid;      /*!< \brief Transaction identifier. The TID, or transaction identifier field is an 8-bit integer that identifies a given message with a known transaction from a source device. */
} CSRMESH_SENSOR_VALUE_T;

/** \brief Structure used with  CSRMESH_SENSOR_MISSING event.
 */
typedef struct
{
    CsrUint8 typesLen;        /*< \brief length for types array */
    CSR_MESH_SENSOR_TYPE_T *types; /*!< \brief A Types field is an array of one, two, three or four sensor types, with each value being a 16-bit unsigned integer that determines one of the sensor type that is missing. */
} CSRMESH_SENSOR_MISSING_T;


/*!@} */
#endif /* __SENSOR_MODEL_H__ */

