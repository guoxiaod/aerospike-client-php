/*
 *
 * Copyright (C) 2014-2016 Aerospike, Inc.
 *
 * Portions may be licensed to Aerospike, Inc. under one or more contributor
 * license agreements.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy of
 * the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations under
 * the License.
 */

#ifndef __AEROSPIKE_POLICY_H__
#define __AEROSPIKE_POLICY_H__

#include "aerospike/as_scan.h"
#include "aerospike/as_job.h"
#include "aerospike/as_admin.h"
/*
 *******************************************************************************************************
 * Enum for PHP client's optional policy constant keys. (OPT_*)
 *******************************************************************************************************
 */
enum Aerospike_constants {
	OPT_CONNECT_TIMEOUT = 1, /* value in milliseconds, default: 1000                                          */
	OPT_READ_TIMEOUT,        /* value in milliseconds, default: 1000                                          */
	OPT_WRITE_TIMEOUT,       /* value in milliseconds, default: 1000                                          */
	OPT_POLICY_RETRY,        /* set to a Aerospike::POLICY_RETRY_* value                                      */
	OPT_POLICY_EXISTS,       /* set to a Aerospike::POLICY_EXISTS_* value                                     */
	OPT_SERIALIZER,          /* set the unsupported type handler                                              */
	OPT_SCAN_PRIORITY,       /* set to a Aerospike::SCAN_PRIORITY_* value                                     */
	OPT_SCAN_PERCENTAGE,     /* integer value 1-100, default: 100                                             */
	OPT_SCAN_CONCURRENTLY,   /* boolean value, default: false                                                 */
	OPT_SCAN_NOBINS,         /* boolean value, default: false                                                 */
	OPT_SCAN_INCLUDELDT,     /* Include large data type bin values in addition to large data type bin names   */
	OPT_POLICY_KEY,          /* records store the digest unique ID, optionally also its (ns, set, key) inputs */
	OPT_POLICY_GEN,          /* set to one of Aerospike::OPT_POLICY_GEN_*                                     */
	OPT_POLICY_REPLICA,      /* set to one of Aerospike::POLICY_REPLICA_*                                     */
	OPT_POLICY_CONSISTENCY,  /* set to one of Aerospike::POLICY_CONSISTENCY_*                                 */
	OPT_POLICY_COMMIT_LEVEL, /* set to one of Aerospike::POLICY_COMMIT_LEVEL_*                                */
	OPT_TTL,                 /* set to time-to-live of the record in seconds                                  */
	USE_BATCH_DIRECT,        /* use new batch index protocol if server supports it                            */
	COMPRESSION_THRESHOLD,   /* Minimum record size beyond which it is compressed and sent to the server      */
	OPT_POLICY_DURABLE_DELETE /* set to true to enable durable delete for the operation                       */
};

/*
 *******************************************************************************************************
 * Enum for PHP client's SERIALIZER_* constant values. Possible values for
 * OPT_SERIALIZER.
 *******************************************************************************************************
 */
enum Aerospike_serializer_values {
	SERIALIZER_NONE,
	SERIALIZER_PHP, /* default handler for serializer type */
	SERIALIZER_USER,
};

#define SERIALIZER_DEFAULT "php"

#define MAX_CONSTANT_STR_SIZE 512
/*
 *******************************************************************************************************
 * Structure to map constant number to constant name string for Aerospike constants.
 *******************************************************************************************************
 */
typedef struct Aerospike_Constants {
	long constantno;
	char constant_str[MAX_CONSTANT_STR_SIZE];
} AerospikeConstants;

#define AEROSPIKE_CONSTANTS_ARR_SIZE (sizeof(aerospike_constants)/sizeof(AerospikeConstants))

/*
 *******************************************************************************************************
 * Instance of Mapper of constant number to constant name string for Aerospike constants.
 *******************************************************************************************************
 */
static
AerospikeConstants aerospike_constants[] = {
	{ OPT_CONNECT_TIMEOUT                   ,   "OPT_CONNECT_TIMEOUT"               },
	{ OPT_READ_TIMEOUT                      ,   "OPT_READ_TIMEOUT"                  },
	{ OPT_WRITE_TIMEOUT                     ,   "OPT_WRITE_TIMEOUT"                 },
	{ OPT_POLICY_RETRY                      ,   "OPT_POLICY_RETRY"                  },
	{ OPT_POLICY_EXISTS                     ,   "OPT_POLICY_EXISTS"                 },
	{ OPT_POLICY_KEY                        ,   "OPT_POLICY_KEY"                    },
	{ OPT_SERIALIZER                        ,   "OPT_SERIALIZER"                    },
	{ OPT_SCAN_PRIORITY                     ,   "OPT_SCAN_PRIORITY"                 },
	{ OPT_SCAN_PERCENTAGE                   ,   "OPT_SCAN_PERCENTAGE"               },
	{ OPT_SCAN_CONCURRENTLY                 ,   "OPT_SCAN_CONCURRENTLY"             },
	{ OPT_SCAN_NOBINS                       ,   "OPT_SCAN_NOBINS"                   },
	{ OPT_SCAN_INCLUDELDT                   ,   "OPT_SCAN_INCLUDELDT"               },
	{ OPT_POLICY_GEN                        ,   "OPT_POLICY_GEN"                    },
	{ OPT_POLICY_REPLICA                    ,   "OPT_POLICY_REPLICA"                },
	{ OPT_POLICY_CONSISTENCY                ,   "OPT_POLICY_CONSISTENCY"            },
	{ OPT_POLICY_COMMIT_LEVEL               ,   "OPT_POLICY_COMMIT_LEVEL"           },
	{ OPT_TTL                               ,   "OPT_TTL"                           },
	{ USE_BATCH_DIRECT                      ,   "USE_BATCH_DIRECT"                  },
	{ COMPRESSION_THRESHOLD                 ,   "COMPRESSION_THRESHOLD"             },
	{ AS_POLICY_RETRY_NONE                  ,   "POLICY_RETRY_NONE"                 },
	{ AS_POLICY_RETRY_ONCE                  ,   "POLICY_RETRY_ONCE"                 },
	{ AS_POLICY_EXISTS_IGNORE               ,   "POLICY_EXISTS_IGNORE"              },
	{ AS_POLICY_EXISTS_CREATE               ,   "POLICY_EXISTS_CREATE"              },
	{ AS_POLICY_EXISTS_UPDATE               ,   "POLICY_EXISTS_UPDATE"              },
	{ AS_POLICY_EXISTS_REPLACE              ,   "POLICY_EXISTS_REPLACE"             },
	{ AS_POLICY_EXISTS_CREATE_OR_REPLACE    ,   "POLICY_EXISTS_CREATE_OR_REPLACE"   },
	{ SERIALIZER_NONE                       ,   "SERIALIZER_NONE"                   },
	{ SERIALIZER_PHP                        ,   "SERIALIZER_PHP"                    },
	{ SERIALIZER_USER                       ,   "SERIALIZER_USER"                   },
	{ AS_UDF_TYPE_LUA                       ,   "UDF_TYPE_LUA"                      },
	{ AS_SCAN_PRIORITY_AUTO                 ,   "SCAN_PRIORITY_AUTO"                },
	{ AS_SCAN_PRIORITY_LOW                  ,   "SCAN_PRIORITY_LOW"                 },
	{ AS_SCAN_PRIORITY_MEDIUM               ,   "SCAN_PRIORITY_MEDIUM"              },
	{ AS_SCAN_PRIORITY_HIGH                 ,   "SCAN_PRIORITY_HIGH"                },
	{ AS_SCAN_STATUS_UNDEF                  ,   "SCAN_STATUS_UNDEF"                 },
	{ AS_SCAN_STATUS_INPROGRESS             ,   "SCAN_STATUS_INPROGRESS"            },
	{ AS_SCAN_STATUS_ABORTED                ,   "SCAN_STATUS_ABORTED"               },
	{ AS_SCAN_STATUS_COMPLETED              ,   "SCAN_STATUS_COMPLETED"             },
	{ AS_JOB_STATUS_UNDEF                   ,   "JOB_STATUS_UNDEF"                  },
	{ AS_JOB_STATUS_INPROGRESS              ,   "JOB_STATUS_INPROGRESS"             },
	{ AS_JOB_STATUS_COMPLETED               ,   "JOB_STATUS_COMPLETED"              },
	{ AS_POLICY_KEY_DIGEST                  ,   "POLICY_KEY_DIGEST"                 },
	{ AS_POLICY_KEY_SEND                    ,   "POLICY_KEY_SEND"                   },
	{ AS_POLICY_GEN_IGNORE                  ,   "POLICY_GEN_IGNORE"                 },
	{ AS_POLICY_GEN_EQ                      ,   "POLICY_GEN_EQ"                     },
	{ AS_POLICY_GEN_GT                      ,   "POLICY_GEN_GT"                     },
	{ AS_POLICY_REPLICA_MASTER              ,   "POLICY_REPLICA_MASTER"             },
	{ AS_POLICY_REPLICA_ANY                 ,   "POLICY_REPLICA_ANY"                },
	{ AS_POLICY_CONSISTENCY_LEVEL_ONE       ,   "POLICY_CONSISTENCY_ONE"            },
	{ AS_POLICY_CONSISTENCY_LEVEL_ALL       ,   "POLICY_CONSISTENCY_ALL"            },
	{ AS_POLICY_COMMIT_LEVEL_ALL            ,   "POLICY_COMMIT_LEVEL_ALL"           },
	{ AS_POLICY_COMMIT_LEVEL_MASTER         ,   "POLICY_COMMIT_LEVEL_MASTER"        },
	{ AS_PRIVILEGE_USER_ADMIN               ,   "PRIV_USER_ADMIN"                   },
	{ AS_PRIVILEGE_SYS_ADMIN                ,   "PRIV_SYS_ADMIN"                    },
	{ AS_PRIVILEGE_READ                     ,   "PRIV_READ"                         },
	{ AS_PRIVILEGE_READ_WRITE               ,   "PRIV_READ_WRITE"                   },
	{ AS_PRIVILEGE_READ_WRITE_UDF           ,   "PRIV_READ_WRITE_UDF"               },
	{ AS_PRIVILEGE_DATA_ADMIN               ,   "PRIV_DATA_ADMIN"                   },
	{ OPT_POLICY_DURABLE_DELETE             ,   "OPT_POLICY_DURABLE_DELETE"         }
};
/*
 *******************************************************************************************************
 * Extern declarations of policy functions.
 *******************************************************************************************************
 */
extern void
set_policy(as_config* as_config_p,
	as_policy_read *read_policy_p,
	as_policy_write *write_policy_p,
	as_policy_operate *operate_policy_p,
	as_policy_remove *remove_policy_p,
	as_policy_info *info_policy_p,
	as_policy_scan *scan_policy_p,
	as_policy_query *query_policy_p,
	int8_t *serializer_policy_p,
	zval *options_p,
	as_error *error_p TSRMLS_DC);

extern void
set_general_policies(as_config* as_config_p,
	zval *options_p,
	as_error *error_p,
	int8_t *serializer_opt TSRMLS_DC);

extern void
set_policy_scan(as_config* as_config_p,
	as_policy_scan *scan_policy_p,
	int8_t *serializer_policy_p,
	as_scan *as_scan_p,
	zval *options_p,
	as_error *error_p TSRMLS_DC);

extern void
set_policy_batch(as_config* as_config_p,
	as_policy_batch *batch_policy_p,
	zval *options_p,
	as_error *error_p TSRMLS_DC);

extern void
set_policy_udf_apply(as_config* as_config_p,
	as_policy_apply *apply_policy_p,
	int8_t *serializer_policy_p,
	zval *options_p,
	as_error *error_p TSRMLS_DC);

extern void
set_policy_query_apply(as_config *as_config_p,
	as_policy_write *write_policy_p,
	zval *options_p,
	as_error *error_p TSRMLS_DC);

extern as_status
declare_policy_constants_php(zend_class_entry *Aerospike_ce TSRMLS_DC);
#endif /* end of __AEROSPIKE_POLICY_H__ */
