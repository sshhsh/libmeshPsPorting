/*****************************************************************************
 *
 * Copyright [2015] Qualcomm Technologies International, Ltd.
 *
 *****************************************************************************/
/* Note: this is an auto-generated file. */

#ifndef __PING_MODEL_H__
#define __PING_MODEL_H__

#include "csr_mesh_model_common.h"
#include "csr_types.h"
#include "csr_mesh_mcp_types.h"

/** \addtogroup Ping
 * @{
 * \JAVADOC_AUTOBRIEF <br>The Ping Model ensures that the MTL can provide reliable message delivery to a peer device. It does this by allowing a transmitting device to send a request that a device supporting the ping model will respond to. The ping model optimises the configuration of devices within the network. The mechanisms to optimise the network are out of scope of this specification.
 * \file 
 * \brief Defines the structures used by the Ping model.
 *
 * \details <br>The Ping Model ensures that the MTL can provide reliable message delivery to a peer device. It does this by allowing a transmitting device to send a request that a device supporting the ping model will respond to. The ping model optimises the configuration of devices within the network. The mechanisms to optimise the network are out of scope of this specification.
 */


/** \brief Structure used with  CSRMESH_PING_REQUEST event.
 */
typedef struct
{
    CsrUint8 arbitraryDataLen;        /*< \brief length for arbitrarydata array */
    CsrUint8 *arbitraryData;      /*!< \brief Arbitrary data */
    CsrUint8 rspTTl;      /*!< \brief Response packet time to live */
} CSRMESH_PING_REQUEST_T;

/** \brief Structure used with  CSRMESH_PING_RESPONSE event.
 */
typedef struct
{
    CsrUint8 arbitraryDataLen;        /*< \brief length for arbitrarydata array */
    CsrUint8 *arbitraryData;      /*!< \brief Arbitrary data */
    CsrUint8 tTLAtRx;      /*!< \brief Time to live when received */
    CsrUint8 rSSIAtRx;      /*!< \brief Receiver signal strength when received */
} CSRMESH_PING_RESPONSE_T;


/*!@} */
#endif /* __PING_MODEL_H__ */

