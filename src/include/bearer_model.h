/*****************************************************************************
 *
 * Copyright [2015] Qualcomm Technologies International, Ltd.
 *
 *****************************************************************************/
/* Note: this is an auto-generated file. */

#ifndef __BEARER_MODEL_H__
#define __BEARER_MODEL_H__

#include "csr_mesh_model_common.h"
#include "csr_types.h"
#include "csr_mesh_mcp_types.h"

/** \addtogroup Bearer
 * @{
 * \JAVADOC_AUTOBRIEF <br>The Bearer Model controls which bearers are handled by a given device and which bearers are used to relay MTL messages. A device can be set in a promiscuous mode where the device forwards all CSRmesh packets, regardless of whether the network key is known or not. This mode enables the examination of network traffic in busy locations with many overlapping networks and permits simpler deployments so that multiple installations can use their common physical deployment to support their individual traffic.<h4>Bearer State</h4>The Bearer has the following states:<ul style='list-style:square;list-style-position: inside;'> <li style='list-style-type:square;'>BearerRelayActive</li> <li style='list-style-type:square;'>BearerEnabled</li> <li style='list-style-type:square;'> Promiscous</li> </ul><H5> BearerRelayActive</h5>BearerRelayActive is a 16-bit bit field. Each bit determines if the given bearer is used to relay MTL packets received on any bearer. <h6>Note:</h6>BearerRelayActive does not determine if a message received on a given bearer is relayed, but which bearers relay a message received on any active bearer.<br><br> The following bits are defined:<ul style='list-style:square;list-style-position: inside;'> <li style='list-style-type:square;'>BearerRelayActive</li> <li style='list-style-type:square;'>LE Advertising Bearer=0</li><li style='list-style-type:square;'>LE GATT Server Bearer=1 </li></ul> <h5>BearerEnabled</h5>BearerEnabled is a 16-bit bit field. Each bit determines if the given bearer is enabled. Enabled in this context means that the bearer can receive mesh messages, and/or the bearer can be used to transmit mesh messages originated by this device.The following bits are defined:<ul style='list-style:square;list-style-position: inside;'> <li style='list-style-type:square;'>LE Advertising Bearer=0</li><li style='list-style-type:square;'>LE GATT Server Bearer=1 </li></ul><h5>BearerPromiscous</h5>BearerPromiscous is a 16-bit bit field. Each bit determines if the given bearer promiscuity is enabled. Enabled in this context means that the bearer can relay all traffic it receives even if the bearer does not match any known network keys.<br><br> The following bits are defined:<ul style='list-style:square;list-style-position: inside;'><li style='list-style-type:square;'>LE Advertising Bearer=0</li> <li style='list-style-type:square;'>LE GATT Server Bearer=1</li></ul>
 * \file 
 * \brief Defines the structures used by the Bearer model.
 *
 * \details <br>The Bearer Model controls which bearers are handled by a given device and which bearers are used to relay MTL messages. A device can be set in a promiscuous mode where the device forwards all CSRmesh packets, regardless of whether the network key is known or not. This mode enables the examination of network traffic in busy locations with many overlapping networks and permits simpler deployments so that multiple installations can use their common physical deployment to support their individual traffic.<h4>Bearer State</h4>The Bearer has the following states:<ul style='list-style:square;list-style-position: inside;'> <li style='list-style-type:square;'>BearerRelayActive</li> <li style='list-style-type:square;'>BearerEnabled</li> <li style='list-style-type:square;'> Promiscous</li> </ul><H5> BearerRelayActive</h5>BearerRelayActive is a 16-bit bit field. Each bit determines if the given bearer is used to relay MTL packets received on any bearer. <h6>Note:</h6>BearerRelayActive does not determine if a message received on a given bearer is relayed, but which bearers relay a message received on any active bearer.<br><br> The following bits are defined:<ul style='list-style:square;list-style-position: inside;'> <li style='list-style-type:square;'>BearerRelayActive</li> <li style='list-style-type:square;'>LE Advertising Bearer=0</li><li style='list-style-type:square;'>LE GATT Server Bearer=1 </li></ul> <h5>BearerEnabled</h5>BearerEnabled is a 16-bit bit field. Each bit determines if the given bearer is enabled. Enabled in this context means that the bearer can receive mesh messages, and/or the bearer can be used to transmit mesh messages originated by this device.The following bits are defined:<ul style='list-style:square;list-style-position: inside;'> <li style='list-style-type:square;'>LE Advertising Bearer=0</li><li style='list-style-type:square;'>LE GATT Server Bearer=1 </li></ul><h5>BearerPromiscous</h5>BearerPromiscous is a 16-bit bit field. Each bit determines if the given bearer promiscuity is enabled. Enabled in this context means that the bearer can relay all traffic it receives even if the bearer does not match any known network keys.<br><br> The following bits are defined:<ul style='list-style:square;list-style-position: inside;'><li style='list-style-type:square;'>LE Advertising Bearer=0</li> <li style='list-style-type:square;'>LE GATT Server Bearer=1</li></ul>
 */


/** \brief Structure used with  CSRMESH_BEARER_SET_STATE event.
 */
typedef struct
{
    CsrUint16 bearerRelayActive;      /*!< \brief Bit field of active relay bearers that are used to relay messages to. */
    CsrUint16 bearerEnabled;      /*!< \brief Bit field of enabled bearers. */
    CsrUint16 bearerPromiscuous;      /*!< \brief Relay all messages, regardless of MAC */
    CsrUint8 tid;      /*!< \brief Transaction identifier. The TID, or transaction identifier field is an 8-bit integer that identifies a given message with a known transaction from a source device. */
} CSRMESH_BEARER_SET_STATE_T;

/** \brief Structure used with  CSRMESH_BEARER_GET_STATE event.
 */
typedef struct
{
    CsrUint8 tid;      /*!< \brief Transaction identifier */
} CSRMESH_BEARER_GET_STATE_T;

/** \brief Structure used with  CSRMESH_BEARER_STATE event.
 */
typedef struct
{
    CsrUint16 bearerRelayActive;      /*!< \brief Bitfield of active relay bearers */
    CsrUint16 bearerEnabled;      /*!< \brief Bitfield of enabled bearers */
    CsrUint16 bearerPromiscuous;      /*!< \brief Relay all messages, regardless of MAC */
    CsrUint8 tid;      /*!< \brief Transaction identifier */
} CSRMESH_BEARER_STATE_T;


/*!@} */
#endif /* __BEARER_MODEL_H__ */

