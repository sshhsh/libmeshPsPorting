/*! \file csr_mesh_result_ex.h
 *  \brief CSRmesh library result type
 *
 *   This file contains the different result types the application will receive
 *   as a result of invoking the Mesh APIs.
 *
 *   NOTE: This library includes the Mesh Transport Layer, Mesh Control
 *   Layer and Mesh Association Layer functionality.
 *
 *   Copyright [2015] Qualcomm Technologies International, Ltd.
 */
#ifndef __CSR_MESH_RESULT_EX_H__
#define __CSR_MESH_RESULT_EX_H__

#include "csr_mesh_result.h"


#ifdef __cplusplus
extern "C" {
#endif

#define CSR_MESH_RESULT_NB_ERROR					((CSRmeshResult) 0x1100)
#define CSR_MESH_RESULT_FAILED_COMM_ERROR          (CSR_MESH_RESULT_NB_ERROR + 1)
#define CSR_MESH_RESULT_API_FAILURE_BASE					(CSR_MESH_RESULT_NB_ERROR + 2)
#define CSR_MESH_RESULT_API_FAILURE_INVALID_PARAMS 			(CSR_MESH_RESULT_NB_ERROR + 3)


#ifdef __cplusplus
}
#endif

#endif
