/*****************************************************************************
 *
 * Copyright [2015] Qualcomm Technologies International, Ltd.
 *
 *****************************************************************************/
/* Note: this is an auto-generated file. */

#ifndef __LIGHT_MODEL_H__
#define __LIGHT_MODEL_H__

#include "csr_mesh_model_common.h"
#include "csr_types.h"
#include "csr_mesh_mcp_types.h"

/** \addtogroup Light
 * @{
 * \JAVADOC_AUTOBRIEF <br>The Light Model controls devices that typically have dimmable and/or coloured lights. It is also possible to control the power of the lights and have lights change their level and colour slowly. The light model also allows the fine tuning of the colour temperature of the light over time. For example, the light can be set to be bluer in the morning and slowly becomes yellower by the time of the afternoon. Finally, the light model allows the intensity of the light to change based on the received signal strength of certain assets. <h4> Light State</h4>The light model has the following states:<ul style='list-style:square;list-style-position: inside;'><li style='list-style-type:square;'>CurrentLevel</li><li style='list-style-type:square;'> DeltaLevel</li><li style='list-style-type:square;'>RedLevel</li><li style='list-style-type:square;'>GreenLevel</li><li style='list-style-type:square;'>BlueLevel</li><li style='list-style-type:square;'> DeltaRedLevel</li><li style='list-style-type:square;'>DeltaGreenLevel</li><li style='list-style-type:square;'> DeltaBlueLevel </li><li style='list-style-type:square;'>TargetLevel</li><li style='list-style-type:square;'>TargetRed</li><li style='list-style-type:square;'>TargetGreen </li><li style='list-style-type:square;'>TargetBlue</li><li style='list-style-type:square;'>LevelSDState </li><li style='list-style-type:square;'>LevelDuration </li><li style='list-style-type:square;'>LevelSustain</li><li style='list-style-type:square;'> LevelDecay </li><li style='list-style-type:square;'>ColorTemperature</li><li style='list-style-type:square;'> DeltaColorTemperature </li><li style='list-style-type:square;'>TargetColorTemperature</li></ul><h5> Current Level </h5>CurrentLevel is an unsigned integer representing values from 0x00 to 0xFF. The value 0x00 represents fully off, and the value 0xFF represents fully on. Values between these two extremes represent a linear change in observed brightness from fully off to fully on. For example, the value 0x80 represents half observed brightness.<h5> DeltaLevel</h5>DeltaLevel represents the desired change in CurrentLevel to TargetLevel over a given period of time. <h5>LevelSDState</h5>LevelSDState is an enumeration that represents the following values:<ul style='list-style:square;list-style-position: inside;'><li style='list-style-type:square;'>Idle</li><li style='list-style-type:square;'>Attacking </li><li style='list-style-type:square;'>Sustaining</li><li style='list-style-type:square;'>Decaying </li></ul><h4>Background Behaviour</h4>If CurrentLevel is different from TargetLevel, then CurrentLevel should be changed by DeltaLevel. If CurrentLevel reaches TargetLevel, then a LIGHT_STATE_NO_ACK message may be sent.<br><br>  If CurrentRed is different from TargetRed, then CurrentRed should be changed by DeltaRed. If CurrentRed reaches TargetRed, then a LIGHT_STATE_NO_ACK message may be sent.<br><br> If CurrentGreen is different from TargetGreen, then CurrentGreen should be changed by DeltaGreen. If CurrentGreen reaches TargetGreen, then a LIGHT_STATE_NO_ACK message may be sent.<br><br> If CurrentBlue is different from TargetBlue, then CurrentBlue should be changed by DeltaBlue. If CurrentBlue reaches TargetBlue, then a LIGHT_STATE_NO_ACK message may be sent.<br><br> If LevelSDState is Attacking and CurrentLevel is TargetLevel, then LevelSDState should be set to Sustaining and a timer starts for LevelSustain seconds.<br><br> If LevelSDState is Sustaining and the timer expires, LevelSDState is set to Decaying, TargetLevel is set to zero, DeltaLevel is set to the difference between CurrentLevel and TargetLevel divided by LevelDecay seconds, and a LIGHT_STATE_NO_ACK message may be sent.<br><br> If LevelSDState is Decaying, and CurrentLevel is the same as TargetLevel, then LevelSDState is set to Idle.
 * \file 
 * \brief Defines the structures used by the Light model.
 *
 * \details <br>The Light Model controls devices that typically have dimmable and/or coloured lights. It is also possible to control the power of the lights and have lights change their level and colour slowly. The light model also allows the fine tuning of the colour temperature of the light over time. For example, the light can be set to be bluer in the morning and slowly becomes yellower by the time of the afternoon. Finally, the light model allows the intensity of the light to change based on the received signal strength of certain assets. <h4> Light State</h4>The light model has the following states:<ul style='list-style:square;list-style-position: inside;'><li style='list-style-type:square;'>CurrentLevel</li><li style='list-style-type:square;'> DeltaLevel</li><li style='list-style-type:square;'>RedLevel</li><li style='list-style-type:square;'>GreenLevel</li><li style='list-style-type:square;'>BlueLevel</li><li style='list-style-type:square;'> DeltaRedLevel</li><li style='list-style-type:square;'>DeltaGreenLevel</li><li style='list-style-type:square;'> DeltaBlueLevel </li><li style='list-style-type:square;'>TargetLevel</li><li style='list-style-type:square;'>TargetRed</li><li style='list-style-type:square;'>TargetGreen </li><li style='list-style-type:square;'>TargetBlue</li><li style='list-style-type:square;'>LevelSDState </li><li style='list-style-type:square;'>LevelDuration </li><li style='list-style-type:square;'>LevelSustain</li><li style='list-style-type:square;'> LevelDecay </li><li style='list-style-type:square;'>ColorTemperature</li><li style='list-style-type:square;'> DeltaColorTemperature </li><li style='list-style-type:square;'>TargetColorTemperature</li></ul><h5> Current Level </h5>CurrentLevel is an unsigned integer representing values from 0x00 to 0xFF. The value 0x00 represents fully off, and the value 0xFF represents fully on. Values between these two extremes represent a linear change in observed brightness from fully off to fully on. For example, the value 0x80 represents half observed brightness.<h5> DeltaLevel</h5>DeltaLevel represents the desired change in CurrentLevel to TargetLevel over a given period of time. <h5>LevelSDState</h5>LevelSDState is an enumeration that represents the following values:<ul style='list-style:square;list-style-position: inside;'><li style='list-style-type:square;'>Idle</li><li style='list-style-type:square;'>Attacking </li><li style='list-style-type:square;'>Sustaining</li><li style='list-style-type:square;'>Decaying </li></ul><h4>Background Behaviour</h4>If CurrentLevel is different from TargetLevel, then CurrentLevel should be changed by DeltaLevel. If CurrentLevel reaches TargetLevel, then a LIGHT_STATE_NO_ACK message may be sent.<br><br>  If CurrentRed is different from TargetRed, then CurrentRed should be changed by DeltaRed. If CurrentRed reaches TargetRed, then a LIGHT_STATE_NO_ACK message may be sent.<br><br> If CurrentGreen is different from TargetGreen, then CurrentGreen should be changed by DeltaGreen. If CurrentGreen reaches TargetGreen, then a LIGHT_STATE_NO_ACK message may be sent.<br><br> If CurrentBlue is different from TargetBlue, then CurrentBlue should be changed by DeltaBlue. If CurrentBlue reaches TargetBlue, then a LIGHT_STATE_NO_ACK message may be sent.<br><br> If LevelSDState is Attacking and CurrentLevel is TargetLevel, then LevelSDState should be set to Sustaining and a timer starts for LevelSustain seconds.<br><br> If LevelSDState is Sustaining and the timer expires, LevelSDState is set to Decaying, TargetLevel is set to zero, DeltaLevel is set to the difference between CurrentLevel and TargetLevel divided by LevelDecay seconds, and a LIGHT_STATE_NO_ACK message may be sent.<br><br> If LevelSDState is Decaying, and CurrentLevel is the same as TargetLevel, then LevelSDState is set to Idle.
 */


/** \brief Structure used with  CSRMESH_LIGHT_SET_LEVEL_NO_ACK and  CSRMESH_LIGHT_SET_LEVEL events.
 */
typedef struct
{
    CsrUint8 level;      /*!< \brief Light level */
    CsrUint8 tid;      /*!< \brief Transaction identifier. The TID, or transaction identifier field is an 8-bit integer that identifies a given message with a known transaction from a source device. */
} CSRMESH_LIGHT_SET_LEVEL_T;

/** \brief Structure used with  CSRMESH_LIGHT_SET_RGB_NO_ACK and  CSRMESH_LIGHT_SET_RGB events.
 */
typedef struct
{
    CsrUint8 level;      /*!< \brief Light level */
    CsrUint8 red;      /*!< \brief Red light level */
    CsrUint8 green;      /*!< \brief Green light level */
    CsrUint8 blue;      /*!< \brief Blue light level */
    CsrUint16 colorDuration;      /*!< \brief Time over which the colour will change */
    CsrUint8 tid;      /*!< \brief Transaction identifier. The TID, or transaction identifier field is an 8-bit integer that identifies a given message with a known transaction from a source device. */
} CSRMESH_LIGHT_SET_RGB_T;

/** \brief Structure used with  CSRMESH_LIGHT_SET_POWER_LEVEL_NO_ACK and  CSRMESH_LIGHT_SET_POWER_LEVEL events.
 */
typedef struct
{
    CSR_MESH_POWER_STATE_T power; /*!< \brief Power state */
    CsrUint8 level;      /*!< \brief Light level */
    CsrUint16 levelDuration;      /*!< \brief Time before light reaches desired level */
    CsrUint16 sustain;      /*!< \brief Time that light will stay at desired level */
    CsrUint16 decay;      /*!< \brief Time over which light will decay to zero light level */
    CsrUint8 tid;      /*!< \brief Transaction identifier. The TID, or transaction identifier field is an 8-bit integer that identifies a given message with a known transaction from a source device. */
} CSRMESH_LIGHT_SET_POWER_LEVEL_T;

/** \brief Structure used with  CSRMESH_LIGHT_SET_COLOR_TEMP event.
 */
typedef struct
{
    CsrUint16 colorTemperature;      /*!< \brief Colour temperature */
    CsrUint16 tempDuration;      /*!< \brief Time over which colour temperature will change */
    CsrUint8 tid;      /*!< \brief Transaction identifier. The TID, or transaction identifier field is an 8-bit integer that identifies a given message with a known transaction from a source device. */
} CSRMESH_LIGHT_SET_COLOR_TEMP_T;

/** \brief Structure used with  CSRMESH_LIGHT_GET_STATE event.
 */
typedef struct
{
    CsrUint8 tid;      /*!< \brief Transaction identifier. The TID, or transaction identifier field is an 8-bit integer that identifies a given message with a known transaction from a source device. */
} CSRMESH_LIGHT_GET_STATE_T;

/** \brief Structure used with  CSRMESH_LIGHT_STATE_NO_ACK and  CSRMESH_LIGHT_STATE events.
 */
typedef struct
{
    CSR_MESH_POWER_STATE_T power; /*!< \brief Power state */
    CsrUint8 level;      /*!< \brief Light level */
    CsrUint8 red;      /*!< \brief Red light level */
    CsrUint8 green;      /*!< \brief Green light level */
    CsrUint8 blue;      /*!< \brief Blue light level */
    CsrUint16 colorTemperature;      /*!< \brief Colour temperature */
    CsrUint8 supports;      /*!< \brief Bit field of supported light behaviour */
    CsrUint8 tid;      /*!< \brief Transaction identifier. The TID, or transaction identifier field is an 8-bit integer that identifies a given message with a known transaction from a source device. */
} CSRMESH_LIGHT_STATE_T;


/*!@} */
#endif /* __LIGHT_MODEL_H__ */

