/*****************************************************************************
 *
 * Copyright [2015] Qualcomm Technologies International, Ltd.
 *
 *****************************************************************************/
/* Note: this is an auto-generated file. */

#ifndef __LIGHT_CLIENT_H__
#define __LIGHT_CLIENT_H__

#include "csr_types.h"
#include "csr_mesh_model_common.h"
#include "csr_mesh_result.h"
#include "csr_mesh_mcp_types.h"
/** \addtogroup Light
 * @{
 * \JAVADOC_AUTOBRIEF <br>The Light Model controls devices that typically have dimmable and/or coloured lights. It is also possible to control the power of the lights and have lights change their level and colour slowly. The light model also allows the fine tuning of the colour temperature of the light over time. For example, the light can be set to be bluer in the morning and slowly becomes yellower by the time of the afternoon. Finally, the light model allows the intensity of the light to change based on the received signal strength of certain assets. <h4> Light State</h4>The light model has the following states:<ul style='list-style:square;list-style-position: inside;'><li style='list-style-type:square;'>CurrentLevel</li><li style='list-style-type:square;'> DeltaLevel</li><li style='list-style-type:square;'>RedLevel</li><li style='list-style-type:square;'>GreenLevel</li><li style='list-style-type:square;'>BlueLevel</li><li style='list-style-type:square;'> DeltaRedLevel</li><li style='list-style-type:square;'>DeltaGreenLevel</li><li style='list-style-type:square;'> DeltaBlueLevel </li><li style='list-style-type:square;'>TargetLevel</li><li style='list-style-type:square;'>TargetRed</li><li style='list-style-type:square;'>TargetGreen </li><li style='list-style-type:square;'>TargetBlue</li><li style='list-style-type:square;'>LevelSDState </li><li style='list-style-type:square;'>LevelDuration </li><li style='list-style-type:square;'>LevelSustain</li><li style='list-style-type:square;'> LevelDecay </li><li style='list-style-type:square;'>ColorTemperature</li><li style='list-style-type:square;'> DeltaColorTemperature </li><li style='list-style-type:square;'>TargetColorTemperature</li></ul><h5> Current Level </h5>CurrentLevel is an unsigned integer representing values from 0x00 to 0xFF. The value 0x00 represents fully off, and the value 0xFF represents fully on. Values between these two extremes represent a linear change in observed brightness from fully off to fully on. For example, the value 0x80 represents half observed brightness.<h5> DeltaLevel</h5>DeltaLevel represents the desired change in CurrentLevel to TargetLevel over a given period of time. <h5>LevelSDState</h5>LevelSDState is an enumeration that represents the following values:<ul style='list-style:square;list-style-position: inside;'><li style='list-style-type:square;'>Idle</li><li style='list-style-type:square;'>Attacking </li><li style='list-style-type:square;'>Sustaining</li><li style='list-style-type:square;'>Decaying </li></ul><h4>Background Behaviour</h4>If CurrentLevel is different from TargetLevel, then CurrentLevel should be changed by DeltaLevel. If CurrentLevel reaches TargetLevel, then a LIGHT_STATE_NO_ACK message may be sent.<br><br>  If CurrentRed is different from TargetRed, then CurrentRed should be changed by DeltaRed. If CurrentRed reaches TargetRed, then a LIGHT_STATE_NO_ACK message may be sent.<br><br> If CurrentGreen is different from TargetGreen, then CurrentGreen should be changed by DeltaGreen. If CurrentGreen reaches TargetGreen, then a LIGHT_STATE_NO_ACK message may be sent.<br><br> If CurrentBlue is different from TargetBlue, then CurrentBlue should be changed by DeltaBlue. If CurrentBlue reaches TargetBlue, then a LIGHT_STATE_NO_ACK message may be sent.<br><br> If LevelSDState is Attacking and CurrentLevel is TargetLevel, then LevelSDState should be set to Sustaining and a timer starts for LevelSustain seconds.<br><br> If LevelSDState is Sustaining and the timer expires, LevelSDState is set to Decaying, TargetLevel is set to zero, DeltaLevel is set to the difference between CurrentLevel and TargetLevel divided by LevelDecay seconds, and a LIGHT_STATE_NO_ACK message may be sent.<br><br> If LevelSDState is Decaying, and CurrentLevel is the same as TargetLevel, then LevelSDState is set to Idle.
 * \file 
 * \brief Declares the messages supported by the Light model.
 *
 * \details <br>The Light Model controls devices that typically have dimmable and/or coloured lights. It is also possible to control the power of the lights and have lights change their level and colour slowly. The light model also allows the fine tuning of the colour temperature of the light over time. For example, the light can be set to be bluer in the morning and slowly becomes yellower by the time of the afternoon. Finally, the light model allows the intensity of the light to change based on the received signal strength of certain assets. <h4> Light State</h4>The light model has the following states:<ul style='list-style:square;list-style-position: inside;'><li style='list-style-type:square;'>CurrentLevel</li><li style='list-style-type:square;'> DeltaLevel</li><li style='list-style-type:square;'>RedLevel</li><li style='list-style-type:square;'>GreenLevel</li><li style='list-style-type:square;'>BlueLevel</li><li style='list-style-type:square;'> DeltaRedLevel</li><li style='list-style-type:square;'>DeltaGreenLevel</li><li style='list-style-type:square;'> DeltaBlueLevel </li><li style='list-style-type:square;'>TargetLevel</li><li style='list-style-type:square;'>TargetRed</li><li style='list-style-type:square;'>TargetGreen </li><li style='list-style-type:square;'>TargetBlue</li><li style='list-style-type:square;'>LevelSDState </li><li style='list-style-type:square;'>LevelDuration </li><li style='list-style-type:square;'>LevelSustain</li><li style='list-style-type:square;'> LevelDecay </li><li style='list-style-type:square;'>ColorTemperature</li><li style='list-style-type:square;'> DeltaColorTemperature </li><li style='list-style-type:square;'>TargetColorTemperature</li></ul><h5> Current Level </h5>CurrentLevel is an unsigned integer representing values from 0x00 to 0xFF. The value 0x00 represents fully off, and the value 0xFF represents fully on. Values between these two extremes represent a linear change in observed brightness from fully off to fully on. For example, the value 0x80 represents half observed brightness.<h5> DeltaLevel</h5>DeltaLevel represents the desired change in CurrentLevel to TargetLevel over a given period of time. <h5>LevelSDState</h5>LevelSDState is an enumeration that represents the following values:<ul style='list-style:square;list-style-position: inside;'><li style='list-style-type:square;'>Idle</li><li style='list-style-type:square;'>Attacking </li><li style='list-style-type:square;'>Sustaining</li><li style='list-style-type:square;'>Decaying </li></ul><h4>Background Behaviour</h4>If CurrentLevel is different from TargetLevel, then CurrentLevel should be changed by DeltaLevel. If CurrentLevel reaches TargetLevel, then a LIGHT_STATE_NO_ACK message may be sent.<br><br>  If CurrentRed is different from TargetRed, then CurrentRed should be changed by DeltaRed. If CurrentRed reaches TargetRed, then a LIGHT_STATE_NO_ACK message may be sent.<br><br> If CurrentGreen is different from TargetGreen, then CurrentGreen should be changed by DeltaGreen. If CurrentGreen reaches TargetGreen, then a LIGHT_STATE_NO_ACK message may be sent.<br><br> If CurrentBlue is different from TargetBlue, then CurrentBlue should be changed by DeltaBlue. If CurrentBlue reaches TargetBlue, then a LIGHT_STATE_NO_ACK message may be sent.<br><br> If LevelSDState is Attacking and CurrentLevel is TargetLevel, then LevelSDState should be set to Sustaining and a timer starts for LevelSustain seconds.<br><br> If LevelSDState is Sustaining and the timer expires, LevelSDState is set to Decaying, TargetLevel is set to zero, DeltaLevel is set to the difference between CurrentLevel and TargetLevel divided by LevelDecay seconds, and a LIGHT_STATE_NO_ACK message may be sent.<br><br> If LevelSDState is Decaying, and CurrentLevel is the same as TargetLevel, then LevelSDState is set to Idle.
 */




/** Light Initializer.
 *
 *  Response for various messages will be provided in the supplied callback
 *  \param  lightAppCallback  callback to receive response
 *  \returns CSR_MESH_RESULT_SUCCESS if the request was successful
 */

CSRmeshResult LightModelClientInit(CSRMESH_MODEL_CALLBACK_T lightAppCallback);



/** \JAVADOC_AUTOBRIEF Setting Light Level: Upon receiving a LIGHT_SET_LEVEL_NO_ACK message, the device saves the Level field into the CurrentLevel model state. LevelSDState should be set to Idle. If ACK is requested, the device should respond with a LIGHT_STATE message.
 *
 *  \param  nwkId  Network ID
 *  \param  destDevId  device ID
 *  \param  repeat  Number of times the request should be repeated on the mesh node 
 *  \param  level Light level
 *  \param  tid Transaction identifier. The TID, or transaction identifier field is an 8-bit integer that identifies a given message with a known transaction from a source device.
 *  \param ack  true if acknowledgement is expected, false otherwise
 *  \returns CSR_MESH_RESULT_SUCCESS if the request was successful
 */

CSRmeshResult LightSetLevel(CsrUint8 nwkId,CsrUint16 destDevId,CsrUint8 repeat,CsrUint8 level,CsrUint8 tid,CsrBool ack);




/** \JAVADOC_AUTOBRIEF Setting Light Colour:  Upon receiving a LIGHT_SET_RGB_NO_ACK message, the device saves the Level, Red, Green, and Blue fields into the TargetLevel, TargetRed, TargetGreen, and TargetBlue variables respectively. LevelSDState should be set to Attacking. If the Duration field is zero, then the device saves the Level, Red, Green, and Blue fields into the CurrentLevel, CurrentRed, CurrentGreen and CurrentBlue variables, and sets the DeltaLevel, DeltaRed, DeltaGreen, and DeltaBlue variables to zero. If the Duration field is greater than zero, then the device calculates the DeltaLevel, DeltaRed, DeltaGreen, and DeltaBlue levels from the differences between the Current values and the Target values divided by the Duration field, so that over Duration seconds, the CurrentLevel, CurrentRed, CurrentGreen, and CurrentBlue variables are changed smoothly to the TargetLevel, TargetRed, TargetGreen and TargetBlue values. If ACK is requested, the device responds with a LIGHT_STATE message.
 *
 *  \param  nwkId  Network ID
 *  \param  destDevId  device ID
 *  \param  repeat  Number of times the request should be repeated on the mesh node 
 *  \param  level Light level
 *  \param  red Red light level
 *  \param  green Green light level
 *  \param  blue Blue light level
 *  \param  colorDuration Time over which the colour will change
 *  \param  tid Transaction identifier. The TID, or transaction identifier field is an 8-bit integer that identifies a given message with a known transaction from a source device.
 *  \param ack  true if acknowledgement is expected, false otherwise
 *  \returns CSR_MESH_RESULT_SUCCESS if the request was successful
 */

CSRmeshResult LightSetRgb(CsrUint8 nwkId,CsrUint16 destDevId,CsrUint8 repeat,CsrUint8 level,CsrUint8 red,CsrUint8 green,CsrUint8 blue,CsrUint16 colorDuration,CsrUint8 tid,CsrBool ack);




/** \JAVADOC_AUTOBRIEF Setting Light Power and Light Level: Upon receiving a LIGHT_SET_POWER_LEVEL_NO_ACK message, the device sets the current PowerState to the Power field, the TargetLevel variable to the Level field, the DeltaLevel to the difference between TargetLevel and CurrentLevel divided by the LevelDuration field, saves the Sustain and Decay fields into the LevelSustain and LevelDecay variables, and sets LevelSDState to the Attacking state. If ACK is requested, the device should respond with a LIGHT_STATE message.
 *
 *  \param  nwkId  Network ID
 *  \param  destDevId  device ID
 *  \param  repeat  Number of times the request should be repeated on the mesh node 
 *  \param  power Power state
 *  \param  level Light level
 *  \param  levelDuration Time before light reaches desired level
 *  \param  sustain Time that light will stay at desired level
 *  \param  decay Time over which light will decay to zero light level
 *  \param  tid Transaction identifier. The TID, or transaction identifier field is an 8-bit integer that identifies a given message with a known transaction from a source device.
 *  \param ack  true if acknowledgement is expected, false otherwise
 *  \returns CSR_MESH_RESULT_SUCCESS if the request was successful
 */

CSRmeshResult LightSetPowerLevel(CsrUint8 nwkId,CsrUint16 destDevId,CsrUint8 repeat,CSR_MESH_POWER_STATE_T power,CsrUint8 level,CsrUint16 levelDuration,CsrUint16 sustain,CsrUint16 decay,CsrUint8 tid,CsrBool ack);




/** \JAVADOC_AUTOBRIEF Setting Light Colour Temperature: Upon receiving a LIGHT_SET_COLOR_TEMP message, the device saves the ColorTemperature field into the TargetColorTemperature state variable. If the TempDuration field is zero, the CurrentColorTemperature variable is set to TargetColorTemperature and DeltaColorTemperature is set to zero. If the TempDuration field is greater than zero, then the device calculates the difference between TargetColorTemperature and CurrentColorTemperature, over the TempDuration field and store this into a DeltaColorTemperature state variable, so that over TempDuration seconds, CurrentColorTemperature changes smoothly to TargetColorTemperature. The device then responds with a LIGHT_STATE message.
 *
 *  \param  nwkId  Network ID
 *  \param  destDevId  device ID
 *  \param  repeat  Number of times the request should be repeated on the mesh node 
 *  \param  colorTemperature Colour temperature
 *  \param  tempDuration Time over which colour temperature will change
 *  \param  tid Transaction identifier. The TID, or transaction identifier field is an 8-bit integer that identifies a given message with a known transaction from a source device.
 *
 *  \returns CSR_MESH_RESULT_SUCCESS if the request was successful
 */

CSRmeshResult LightSetColorTemp(CsrUint8 nwkId,CsrUint16 destDevId,CsrUint8 repeat,CsrUint16 colorTemperature,CsrUint16 tempDuration,CsrUint8 tid);




/** \JAVADOC_AUTOBRIEF Getting Light State: Upon receiving a LIGHT_GET_STATE message, the device responds with a LIGHT_STATE message.
 *
 *  \param  nwkId  Network ID
 *  \param  destDevId  device ID
 *  \param  repeat  Number of times the request should be repeated on the mesh node 
 *  \param  tid Transaction identifier. The TID, or transaction identifier field is an 8-bit integer that identifies a given message with a known transaction from a source device.
 *
 *  \returns CSR_MESH_RESULT_SUCCESS if the request was successful
 */

CSRmeshResult LightGetState(CsrUint8 nwkId,CsrUint16 destDevId,CsrUint8 repeat,CsrUint8 tid);






/*!@} */
#endif /* __LIGHT_CLIENT_H__ */
