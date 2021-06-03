
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "pacos.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *pacos_exceptions_pacosexception_ce;
zend_class_entry *pacos_client_ce;
zend_class_entry *pacos_exceptions_pacosnamingnotfound_ce;
zend_class_entry *pacos_exceptions_pacosrequestexception_ce;
zend_class_entry *pacos_0__closure_ce;
zend_class_entry *pacos_1__closure_ce;
zend_class_entry *pacos_config_ce;
zend_class_entry *pacos_exceptions_pacosconfignotfound_ce;
zend_class_entry *pacos_exceptions_pacosnamingnoaliveinstance_ce;
zend_class_entry *pacos_instance_ce;
zend_class_entry *pacos_models_beatinfo_ce;
zend_class_entry *pacos_models_beatresult_ce;
zend_class_entry *pacos_models_configinfo_ce;
zend_class_entry *pacos_models_serviceinstance_ce;
zend_class_entry *pacos_models_serviceinstancelist_ce;
zend_class_entry *pacos_utils_http_ce;
zend_class_entry *pacos_utils_parser_ce;
zend_class_entry *pacos_utils_response_ce;
zend_class_entry *pacos_utils_selector_ce;

ZEND_DECLARE_MODULE_GLOBALS(pacos)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(pacos)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(Pacos_Exceptions_PacosException);
	ZEPHIR_INIT(Pacos_Client);
	ZEPHIR_INIT(Pacos_Exceptions_PacosNamingNotFound);
	ZEPHIR_INIT(Pacos_Exceptions_PacosRequestException);
	ZEPHIR_INIT(Pacos_Config);
	ZEPHIR_INIT(Pacos_Exceptions_PacosConfigNotFound);
	ZEPHIR_INIT(Pacos_Exceptions_PacosNamingNoAliveInstance);
	ZEPHIR_INIT(Pacos_Instance);
	ZEPHIR_INIT(Pacos_Models_BeatInfo);
	ZEPHIR_INIT(Pacos_Models_BeatResult);
	ZEPHIR_INIT(Pacos_Models_ConfigInfo);
	ZEPHIR_INIT(Pacos_Models_ServiceInstance);
	ZEPHIR_INIT(Pacos_Models_ServiceInstanceList);
	ZEPHIR_INIT(Pacos_Utils_Http);
	ZEPHIR_INIT(Pacos_Utils_Parser);
	ZEPHIR_INIT(Pacos_Utils_Response);
	ZEPHIR_INIT(Pacos_Utils_Selector);
	ZEPHIR_INIT(pacos_0__closure);
	ZEPHIR_INIT(pacos_1__closure);
	
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(pacos)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_pacos_globals *pacos_globals TSRMLS_DC)
{
	pacos_globals->initialized = 0;

	/* Cache Enabled */
	pacos_globals->cache_enabled = 1;

	/* Recursive Lock */
	pacos_globals->recursive_lock = 0;

	/* Static cache */
	memset(pacos_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);

	
	
}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_pacos_globals *pacos_globals TSRMLS_DC)
{
		pacos_globals->instance_limit_time = -1;
	pacos_globals->instance_backend_pid = -1;
	pacos_globals->instance_close_sign = -1;
	pacos_globals->instance_shmop_length = 0;

}

static PHP_RINIT_FUNCTION(pacos)
{
	zend_pacos_globals *pacos_globals_ptr;
	pacos_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(pacos_globals_ptr);
	zephir_initialize_memory(pacos_globals_ptr);

	
	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(pacos)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}



static PHP_MINFO_FUNCTION(pacos)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_PACOS_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_PACOS_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_PACOS_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_PACOS_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_end();
    php_info_print_table_start();
	php_info_print_table_header(2, "Directive", "Local Value");
	php_info_print_table_row(2, "pacos_run_mode", "1");
	php_info_print_table_row(2, "pacos_display_error", "1");
	php_info_print_table_row(2, "pacos_auto_close", "1");
	php_info_print_table_row(2, "pacos_period_time", "10");
	php_info_print_table_row(2, "pacos_check_period_time", "0.5");
	php_info_print_table_row(2, "pacos_http_timeout", "10");
	php_info_print_table_row(2, "pacos_pid_file", "/tmp/pacos.beat.pid");
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(pacos)
{
#if defined(COMPILE_DL_PACOS) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	php_zephir_init_globals(pacos_globals);
	php_zephir_init_module_globals(pacos_globals);
}

static PHP_GSHUTDOWN_FUNCTION(pacos)
{
	
}


zend_function_entry php_pacos_functions[] = {
	ZEND_FE_END

};

static const zend_module_dep php_pacos_deps[] = {
	ZEND_MOD_REQUIRED("shmop")
	ZEND_MOD_REQUIRED("pcntl")
	ZEND_MOD_END
};

zend_module_entry pacos_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	php_pacos_deps,
	PHP_PACOS_EXTNAME,
	php_pacos_functions,
	PHP_MINIT(pacos),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(pacos),
#else
	NULL,
#endif
	PHP_RINIT(pacos),
	PHP_RSHUTDOWN(pacos),
	PHP_MINFO(pacos),
	PHP_PACOS_VERSION,
	ZEND_MODULE_GLOBALS(pacos),
	PHP_GINIT(pacos),
	PHP_GSHUTDOWN(pacos),
#ifdef ZEPHIR_POST_REQUEST
	PHP_PRSHUTDOWN(pacos),
#else
	NULL,
#endif
	STANDARD_MODULE_PROPERTIES_EX
};

/* implement standard "stub" routine to introduce ourselves to Zend */
#ifdef COMPILE_DL_PACOS
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(pacos)
#endif
