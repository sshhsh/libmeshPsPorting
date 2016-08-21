/*!   Copyright [2015] Qualcomm Technologies International, Ltd.
 */

#ifndef __CSR_MODEL_GWNB_H__
#define __CSR_MODEL_GWNB_H__

#include <stdbool.h>
/* log levels*/


#define CSR_GW_LOG_LEVEL_DEBUG 1
#define CSR_GW_LOG_LEVEL_INFO  2
#define CSR_GW_LOG_LEVEL_ERROR  3

/* mesh init callback handler */
typedef void (*MESH_INIT_CALLBACK_T) (bool success);

/*This API is used to set the server and port for the southbound daemon */
int csr_model_gwnb_set_server(const char* ip, int port);

/* This API is used to initialize the gateway northbound model API. Once initialized the
 * application is notified of the status using the callback supplied. On successful notification,
 * the application must initialize all the models it intends to use.
 */
int csr_model_gwnb_init(MESH_INIT_CALLBACK_T callback);

/* This API is used to de-initialize the gateway northbound model API.
 */
int csr_model_gwnb_deinit(void);

/* This API returns true is the Gateway NB Model API has been initialized.
 */
int csr_model_gwnb_is_initialized(void);

/* This function must be implemented by the application. Gateway northbound's logs are provided to the
 * application using this callback.
 */
extern void csr_model_gwnb_log(int log_level, const char* log);

#endif
