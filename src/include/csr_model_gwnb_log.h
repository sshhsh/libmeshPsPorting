/*****************************************************************************
 *
 * Copyright [2015] Qualcomm Technologies International, Ltd.
 *
 *****************************************************************************/
#ifndef __CSR_MODEL_GWNB_LOG_H__
#define __CSR_MODEL_GWNB_LOG_H__

#ifdef ENABLE_MODEL_API_LOGS
#define MAX_LOG_WIDTH 256
#include "csr_model_gwnb.h"
void model_log(int level, const char *format, ...)
__attribute__((format(printf, 2, 3)));

#define GLOGD(...) model_log(CSR_GW_LOG_LEVEL_DEBUG, __VA_ARGS__)
#define GLOGI(...) model_log(CSR_GW_LOG_LEVEL_INFO, __VA_ARGS__)
#define GLOGE(...) model_log(CSR_GW_LOG_LEVEL_ERROR, __VA_ARGS__)

#else

#define GLOGD(...) 
#define GLOGI(...) 
#define GLOGE(...) 

#endif


#endif
