
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_PACOS_H
#define PHP_PACOS_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_PACOS_NAME        "pacos"
#define PHP_PACOS_VERSION     "1.0.0"
#define PHP_PACOS_EXTNAME     "pacos"
#define PHP_PACOS_AUTHOR      "zhenyangze"
#define PHP_PACOS_ZEPVERSION  "0.12.20-$Id$"
#define PHP_PACOS_DESCRIPTION "php extends for nacos"



ZEND_BEGIN_MODULE_GLOBALS(pacos)

	int initialized;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	
	int instance_limit_time;

	int instance_backend_pid;

	int instance_close_sign;

	int instance_shmop_length;


ZEND_END_MODULE_GLOBALS(pacos)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(pacos)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) ZEND_MODULE_GLOBALS_ACCESSOR(pacos, v)
#else
	#define ZEPHIR_GLOBAL(v) (pacos_globals.v)
#endif

#ifdef ZTS
	ZEND_TSRMLS_CACHE_EXTERN()
	#define ZEPHIR_VGLOBAL ((zend_pacos_globals *) (*((void ***) tsrm_get_ls_cache()))[TSRM_UNSHUFFLE_RSRC_ID(pacos_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(pacos_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def pacos_globals
#define zend_zephir_globals_def zend_pacos_globals

extern zend_module_entry pacos_module_entry;
#define phpext_pacos_ptr &pacos_module_entry

#endif
