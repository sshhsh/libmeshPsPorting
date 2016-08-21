/*****************************************************************************
 *
 * Copyright [2015] Qualcomm Technologies International, Ltd.
 *
 *****************************************************************************/

/*! \file Csr_mesh_gateway_config.h
 * \brief Defines the macros for MESH Stack Specific Configurations
 * \addtogroup CSRmesh
 * @{
 *
 */
 
#ifndef __CSR_MESH_GW_CONFIG_H__
#define __CSR_MESH_GW_CONFIG_H__


#ifdef __cplusplus
extern "C" {
#endif

/*==================================MESH Stack Specific Configurations==========================================*/
/*! \brief Maximum number of networks supported*/
#define CSR_MESH_GW_MAX_NUM_OF_NETWORKS_ALLOWD     (5)

/*! \brief Maximum Duplicate Message Chache Size */
#define CSR_MESH_GW_MAX_DUPLICATE_MSG_CHACHE_SIZE  (255)

/*! \brief Random UUID Support */
#define CSR_MESH_GW_RANDOM_UUID                    (1)   /*0-- Not Supported 1--Supported*/

/*! \brief  enable/disable Authorization code for association*/
#define CSR_MESH_GW_USE_AUTHORIZATION_CODE         (0)   /*0-- Not Supported 1--Supported*/

/*! \brief Number of bearers supported by Gateway*/
#define CSR_MESH_NO_OF_SUPPORTED_BEARER            (1)
/*======================================================================================================*/

#ifdef __cplusplus
}
#endif

/*!@} */
#endif /*__CSR_MESH_GW_CONFIG_H__*/
