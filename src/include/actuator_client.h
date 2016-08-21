/*****************************************************************************
 *
 * Copyright [2015] Qualcomm Technologies International, Ltd.
 *
 *****************************************************************************/
/* Note: this is an auto-generated file. */

#ifndef __ACTUATOR_CLIENT_H__
#define __ACTUATOR_CLIENT_H__

#include "csr_types.h"
#include "csr_mesh_model_common.h"
#include "csr_mesh_result.h"
#include "csr_mesh_mcp_types.h"
/** \addtogroup Actuator
 * @{
 * \JAVADOC_AUTOBRIEF <br>The Actuator Model sets values on other devices in the CSRmesh network. These values are either based on the physical property of something, for example the current air temperature, or based on an abstract value for such a physical property.<br><br> There is one type of actuator values: control values. Control values are values that are immediately processed by a device and cannot be read. If the value should be readable, then the value would be better represented as a sensor desired value. This specification defines a set of actuator types that describe the format and meaning of the actuator values, logically from the same namespace as the sensor types.<br><br> Actuator types based around physical measurements are always in SI units. No derived units are used. For example, temperature is measured as an integer multiple of 0.03125 kelvin. This implies that the resultant temperature must be converted to represent the temperature using the Celsius or Fahrenheit temperature scales. For example, 0 degrees Centigrade would be represented by the value 8741. This also implies that the Celsius temperature scale can represent accurately a temperature down to 0.1 degrees Centigrade and also a range of values from -273.1 degrees Centigrade to 1774.8 degrees Centigrade. The Fahrenheit scale can also represent temperatures down to 0.1 degrees Fahrenheit accuracy with a range from -459.67 degrees Fahrenheit to 3226.7 degrees Fahrenheit. This enables all devices to be sold worldwide to work with each other and display the temperature in whatever the local unit or user preference is. Additional examples of SI unit representations include speed measured in centimetres per second and air pressure in hecto-Pascals. Some values such as compass direction are compressed to a single octet representation, yet are still measured in radians. For example, each increment in the value increases the direction by 2pi/256 radians.<br><br> Some actuator types are based on bit-fields or enumerated values. To allow for future extensions of these types a very simple extensibility protocol is used: if a bit is not defined in this specification, it shall be transmitted as a zero and ignored upon receipt; if an enumerated value is not defined in this specification, it shall not be transmitted and shall be ignored upon receipt. A device may support zero or more actuator types. For a given actuator type, there can be only one instance of this actuator type in a device. Therefore the collection of types supported is sufficient to describe the behaviour of a specific actuator and the number of instance is not needed. Given that a typical device may only support a very small number of types and these types are sparsely distributed, the method to discover the types supported by a device is by returning the types supported instead of using a bit-field or similar representation.<h4>Actuator State</h4>The actuator model has the following state:<ul style='list-style:square;list-style-position: inside;'><li style='list-style-type:square;'>Types</li></ul><h5>Types</h5>The types that a device supports are a property of the device that must be able to be discovered by a configuring device. A device may support one or more types; there is no limit to the number of types that a device supports except that imposed by the number of defined types. The types supported should be considered as an ordered set of types.
 * \file 
 * \brief Declares the messages supported by the Actuator model.
 *
 * \details <br>The Actuator Model sets values on other devices in the CSRmesh network. These values are either based on the physical property of something, for example the current air temperature, or based on an abstract value for such a physical property.<br><br> There is one type of actuator values: control values. Control values are values that are immediately processed by a device and cannot be read. If the value should be readable, then the value would be better represented as a sensor desired value. This specification defines a set of actuator types that describe the format and meaning of the actuator values, logically from the same namespace as the sensor types.<br><br> Actuator types based around physical measurements are always in SI units. No derived units are used. For example, temperature is measured as an integer multiple of 0.03125 kelvin. This implies that the resultant temperature must be converted to represent the temperature using the Celsius or Fahrenheit temperature scales. For example, 0 degrees Centigrade would be represented by the value 8741. This also implies that the Celsius temperature scale can represent accurately a temperature down to 0.1 degrees Centigrade and also a range of values from -273.1 degrees Centigrade to 1774.8 degrees Centigrade. The Fahrenheit scale can also represent temperatures down to 0.1 degrees Fahrenheit accuracy with a range from -459.67 degrees Fahrenheit to 3226.7 degrees Fahrenheit. This enables all devices to be sold worldwide to work with each other and display the temperature in whatever the local unit or user preference is. Additional examples of SI unit representations include speed measured in centimetres per second and air pressure in hecto-Pascals. Some values such as compass direction are compressed to a single octet representation, yet are still measured in radians. For example, each increment in the value increases the direction by 2pi/256 radians.<br><br> Some actuator types are based on bit-fields or enumerated values. To allow for future extensions of these types a very simple extensibility protocol is used: if a bit is not defined in this specification, it shall be transmitted as a zero and ignored upon receipt; if an enumerated value is not defined in this specification, it shall not be transmitted and shall be ignored upon receipt. A device may support zero or more actuator types. For a given actuator type, there can be only one instance of this actuator type in a device. Therefore the collection of types supported is sufficient to describe the behaviour of a specific actuator and the number of instance is not needed. Given that a typical device may only support a very small number of types and these types are sparsely distributed, the method to discover the types supported by a device is by returning the types supported instead of using a bit-field or similar representation.<h4>Actuator State</h4>The actuator model has the following state:<ul style='list-style:square;list-style-position: inside;'><li style='list-style-type:square;'>Types</li></ul><h5>Types</h5>The types that a device supports are a property of the device that must be able to be discovered by a configuring device. A device may support one or more types; there is no limit to the number of types that a device supports except that imposed by the number of defined types. The types supported should be considered as an ordered set of types.
 */




/** Actuator Initializer.
 *
 *  Response for various messages will be provided in the supplied callback
 *  \param  actuatorAppCallback  callback to receive response
 *  \returns CSR_MESH_RESULT_SUCCESS if the request was successful
 */

CSRmeshResult ActuatorModelClientInit(CSRMESH_MODEL_CALLBACK_T actuatorAppCallback);



/** \JAVADOC_AUTOBRIEF Upon receiving an ACTUATOR_GET_TYPES message, the device responds with an ACTUATOR_TYPES message with a list of supported types greater than or equal to the FirstType field. If the device does not support any types greater than or equal to FirstType, it sends an ACTUATOR_TYPES message with a zero length Types field.
 *
 *  \param  nwkId  Network ID
 *  \param  destDevId  device ID
 *  \param  repeat  Number of times the request should be repeated on the mesh node 
 *  \param  firstType First type to fetch. The FirstType field is a 16-bit unsigned integer that determines the first Type that can be returned in the corresponding ACTUATOR_TYPES message.
 *  \param  tid Transaction identifier. The TID, or transaction identifier field is an 8-bit integer that identifies a given message with a known transaction from a source device.
 *
 *  \returns CSR_MESH_RESULT_SUCCESS if the request was successful
 */

CSRmeshResult ActuatorGetTypes(CsrUint8 nwkId,CsrUint16 destDevId,CsrUint8 repeat,CSR_MESH_SENSOR_TYPE_T firstType,CsrUint8 tid);







/** \JAVADOC_AUTOBRIEF Get sensor state. Upon receiving an ACTUATOR_SET_VALUE_NO_ACK message, where the destination address is the device ID of this device and the Type field is a supported actuator type, the device shall immediately use the Value field for the given Type field. The meaning of this actuator value is not defined in this specification. Upon receiving an ACTUATOR_SET_VALUE_NO_ACK message, where the destination address is is the device ID of this device but the Type field is not a supported actuator type, the device shall ignore the message.
 *
 *  \param  nwkId  Network ID
 *  \param  destDevId  device ID
 *  \param  repeat  Number of times the request should be repeated on the mesh node 
 *  \param  type Actuator type. The Type field is the actuator type value being set.
 *  \param  value Actuator value. The Value field is the value that the actuator type.
 *  \param  valueLen length of value array
 *  \param  tid Transaction identifier. The TID, or transaction identifier field is an 8-bit integer that identifies a given message with a known transaction from a source device.
 *  \param ack  true if acknowledgement is expected, false otherwise
 *  \returns CSR_MESH_RESULT_SUCCESS if the request was successful
 */

CSRmeshResult ActuatorSetValue(CsrUint8 nwkId,CsrUint16 destDevId,CsrUint8 repeat,CSR_MESH_SENSOR_TYPE_T type,CsrUint8* value, CsrUint8 valueLen ,CsrUint8 tid,CsrBool ack);






/*!@} */
#endif /* __ACTUATOR_CLIENT_H__ */
