
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/time.h"


/**
 * Client
 */
ZEPHIR_INIT_CLASS(Pacos_Client) {

	ZEPHIR_REGISTER_CLASS(Pacos, Client, pacos, client, pacos_client_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_null(pacos_client_ce, SL("endpoint"), ZEND_ACC_PROTECTED);

	/**
	 * @var int
	 */
	zend_declare_property_null(pacos_client_ce, SL("port"), ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_null(pacos_client_ce, SL("_namespace"), ZEND_ACC_PROTECTED);

	/**
	 * @var timeout
	 */
	zend_declare_property_long(pacos_client_ce, SL("timeout"), 3, ZEND_ACC_PROTECTED);

	/**
	 * @var debug
	 */
	zend_declare_property_bool(pacos_client_ce, SL("debug"), 0, ZEND_ACC_PROTECTED);

	/**
	 * @var shmKey
	 */
	zend_declare_property_long(pacos_client_ce, SL("shmKey"), 0x4337b007, ZEND_ACC_PROTECTED);

	/**
	 * @var shmSize
	 */
	zend_declare_property_long(pacos_client_ce, SL("shmSize"), 1048576, ZEND_ACC_PROTECTED);

	/**
	 * @var defaultPeriod
	 */
	zend_declare_property_long(pacos_client_ce, SL("defaultPeriod"), 10, ZEND_ACC_PROTECTED);

	/**
	 * @var defaultMode
	 */
	zend_declare_property_long(pacos_client_ce, SL("defaultMode"), 0644, ZEND_ACC_PROTECTED);

	/**
	 * 1全局进程, 2独立进程
	 */
	zend_declare_property_long(pacos_client_ce, SL("beat_run_mode"), 1, ZEND_ACC_PROTECTED);

	/**
	 * @var beat_pid_file
	 */
	zend_declare_property_string(pacos_client_ce, SL("beat_pid_file"), "/tmp/pacos.beat.pid", ZEND_ACC_PROTECTED);

	/**
	 * 是否自动关闭进程
	 */
	zend_declare_property_long(pacos_client_ce, SL("auto_close"), 0, ZEND_ACC_PROTECTED);

	zend_declare_property_long(pacos_client_ce, SL("display_error"), 1, ZEND_ACC_PROTECTED);

	zephir_declare_class_constant_long(pacos_client_ce, SL("DEFAULT_PORT"), 8848);

	zephir_declare_class_constant_long(pacos_client_ce, SL("DEFAULT_TIMEOUT"), 3);

	zephir_declare_class_constant_string(pacos_client_ce, SL("DEFAULT_GROUP"), "DEFAULT_GROUP");

	zephir_declare_class_constant_string(pacos_client_ce, SL("WORD_SEPARATOR"), "\x02");

	zephir_declare_class_constant_string(pacos_client_ce, SL("LINE_SEPARATOR"), "\x01");

	zephir_declare_class_constant_long(pacos_client_ce, SL("SHM_KEY"), 0x4337b007);

	zephir_declare_class_constant_long(pacos_client_ce, SL("SHM_SIZE"), 1048576);

	zephir_declare_class_constant_long(pacos_client_ce, SL("DEFAULT_PERIOD"), 10);

	zephir_declare_class_constant_long(pacos_client_ce, SL("DEFAULT_MODE"), 0644);

	return SUCCESS;

}

/**
 * __construct
 *
 * @param endpoint
 * @param port
 *
 * @return
 */
PHP_METHOD(Pacos_Client, __construct) {

	zend_string *_4;
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	zval options;
	zend_long port, ZEPHIR_LAST_CALL_STATUS;
	zval *endpoint_param = NULL, *port_param = NULL, *options_param = NULL, _0, key, value, *_1, _2, _5$$3, _7$$5;
	zval endpoint;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&endpoint);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &endpoint_param, &port_param, &options_param);

	if (!endpoint_param) {
		ZEPHIR_INIT_VAR(&endpoint);
		ZVAL_STRING(&endpoint, "http://localhost");
	} else {
		zephir_get_strval(&endpoint, endpoint_param);
	}
	if (!port_param) {
		port = 8848;
	} else {
		port = zephir_get_intval(port_param);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("endpoint"), &endpoint);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, port);
	zephir_update_property_zval(this_ptr, ZEND_STRL("port"), &_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "getvar", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&options, 0, "pacos/Client.zep", 110);
	if (Z_TYPE_P(&options) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&options), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&key, _4);
			} else {
				ZVAL_LONG(&key, _3);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			ZEPHIR_CALL_FUNCTION(&_5$$3, "property_exists", &_6, 1, this_ptr, &key);
			zephir_check_call_status();
			if (zephir_is_true(&_5$$3)) {
				zephir_update_property_zval_zval(this_ptr, &key, &value);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &options, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &options, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &options, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &options, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_7$$5, "property_exists", &_6, 1, this_ptr, &key);
				zephir_check_call_status();
				if (zephir_is_true(&_7$$5)) {
					zephir_update_property_zval_zval(this_ptr, &key, &value);
				}
			ZEPHIR_CALL_METHOD(NULL, &options, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();

}

/**
 * getVar 
 *
 * @return 
 */
PHP_METHOD(Pacos_Client, getVar) {

	zend_string *_3;
	zend_ulong _2;
	zval configList, tmpValue, key, value, *_0, _1, _5$$5, _6$$9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&configList);
	ZVAL_UNDEF(&tmpValue);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$9);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&configList);
	zephir_create_array(&configList, 7, 0);
	add_assoc_stringl_ex(&configList, SL("_namespace"), SL("pacos_namespace"));
	add_assoc_stringl_ex(&configList, SL("beat_run_mode"), SL("pacos_run_mode"));
	add_assoc_stringl_ex(&configList, SL("beat_pid_file"), SL("pacos_pid_file"));
	add_assoc_stringl_ex(&configList, SL("defaultPeriod"), SL("pacos_period_time"));
	add_assoc_stringl_ex(&configList, SL("auto_close"), SL("pacos_auto_close"));
	add_assoc_stringl_ex(&configList, SL("timeout"), SL("pacos_http_timeout"));
	add_assoc_stringl_ex(&configList, SL("display_error"), SL("pacos_display_error"));
	zephir_is_iterable(&configList, 0, "pacos/Client.zep", 144);
	if (Z_TYPE_P(&configList) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&configList), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			ZEPHIR_CALL_FUNCTION(&tmpValue, "get_cfg_var", &_4, 2, &value);
			zephir_check_call_status();
			if (zephir_fast_strlen_ev(&tmpValue) > 0) {
				zephir_update_property_zval_zval(this_ptr, &key, &tmpValue);
				if (zephir_is_numeric(&tmpValue)) {
					ZEPHIR_INIT_NVAR(&_5$$5);
					ZVAL_LONG(&_5$$5, zephir_get_intval(&tmpValue));
					zephir_update_property_zval_zval(this_ptr, &key, &_5$$5);
				} else {
					zephir_update_property_zval_zval(this_ptr, &key, &tmpValue);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &configList, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &configList, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &configList, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &configList, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&tmpValue, "get_cfg_var", &_4, 2, &value);
				zephir_check_call_status();
				if (zephir_fast_strlen_ev(&tmpValue) > 0) {
					zephir_update_property_zval_zval(this_ptr, &key, &tmpValue);
					if (zephir_is_numeric(&tmpValue)) {
						ZEPHIR_INIT_NVAR(&_6$$9);
						ZVAL_LONG(&_6$$9, zephir_get_intval(&tmpValue));
						zephir_update_property_zval_zval(this_ptr, &key, &_6$$9);
					} else {
						zephir_update_property_zval_zval(this_ptr, &key, &tmpValue);
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &configList, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string namespace
 * @return static
 */
PHP_METHOD(Pacos_Client, setNamespace) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *_namespace_param = NULL;
	zval _namespace;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_namespace);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &_namespace_param);

	zephir_get_strval(&_namespace, _namespace_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("_namespace"), &_namespace);
	RETURN_THIS();

}

/**
 * @param int timeout
 */
PHP_METHOD(Pacos_Client, setTimeout) {

	zval *timeout_param = NULL, _0;
	zend_long timeout;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params_without_memory_grow(1, 0, &timeout_param);

	timeout = zephir_get_intval(timeout_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, timeout);
	zephir_update_property_zval(this_ptr, ZEND_STRL("timeout"), &_0);

}

/**
 * request
 *
 * @param method
 * @param uri
 * @param options
 *
 * @return
 */
PHP_METHOD(Pacos_Client, request) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *method_param = NULL, *uri_param = NULL, *options_param = NULL, _0$$3, url, _1, _2, header, data, timeout, _3$$4, _4$$4, _5$$4, _6$$9, _7$$9, _8$$9;
	zval method, uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&header);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&timeout);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &method_param, &uri_param, &options_param);

	zephir_get_strval(&method, method_param);
	zephir_get_strval(&uri, uri_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	if (!(zephir_array_isset_string(&options, SL("timeout")))) {
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("timeout"), PH_NOISY_CC | PH_READONLY);
		zephir_array_update_string(&options, SL("timeout"), &_0$$3, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(&url);
	ZVAL_STRING(&url, "");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "://");
	ZEPHIR_CALL_FUNCTION(&_2, "stristr", NULL, 3, &uri, &_1);
	zephir_check_call_status();
	if (!zephir_is_true(&_2)) {
		zephir_read_property(&_3$$4, this_ptr, ZEND_STRL("endpoint"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_4$$4, this_ptr, ZEND_STRL("port"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_5$$4);
		ZVAL_STRING(&_5$$4, "%s:%d%s");
		ZEPHIR_CALL_FUNCTION(&url, "sprintf", NULL, 4, &_5$$4, &_3$$4, &_4$$4, &uri);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&url, &uri);
	}
	ZEPHIR_INIT_VAR(&header);
	ZVAL_STRING(&header, "");
	ZEPHIR_INIT_VAR(&data);
	ZVAL_NULL(&data);
	ZEPHIR_INIT_VAR(&timeout);
	ZVAL_NULL(&timeout);
	if (zephir_array_isset_string(&options, SL("timeout"))) {
		ZEPHIR_OBS_NVAR(&timeout);
		zephir_array_fetch_string(&timeout, &options, SL("timeout"), PH_NOISY, "pacos/Client.zep", 191);
	}
	if (zephir_array_isset_string(&options, SL("headers"))) {
		ZEPHIR_OBS_NVAR(&header);
		zephir_array_fetch_string(&header, &options, SL("headers"), PH_NOISY, "pacos/Client.zep", 195);
	}
	if (zephir_array_isset_string(&options, SL("form_params"))) {
		ZEPHIR_OBS_NVAR(&data);
		zephir_array_fetch_string(&data, &options, SL("form_params"), PH_NOISY, "pacos/Client.zep", 199);
	}
	if (zephir_array_isset_string(&options, SL("query"))) {
		zephir_array_fetch_string(&_6$$9, &options, SL("query"), PH_NOISY | PH_READONLY, "pacos/Client.zep", 203);
		ZEPHIR_CALL_FUNCTION(&_7$$9, "http_build_query", NULL, 5, &_6$$9);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_8$$9);
		ZEPHIR_CONCAT_SV(&_8$$9, "?", &_7$$9);
		zephir_concat_self(&url, &_8$$9);
	}
	ZEPHIR_RETURN_CALL_CE_STATIC(pacos_utils_http_ce, "request", &_9, 0, &url, &data, &method, &header, &timeout);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * assertResponse
 *
 * @param resp
 * @param expected
 * @param message
 *
 * @return
 */
PHP_METHOD(Pacos_Client, assertResponse) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *resp, resp_sub, *expected, expected_sub, *message, message_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&resp_sub);
	ZVAL_UNDEF(&expected_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &resp, &expected, &message);



	ZEPHIR_CALL_METHOD(&_0, resp, "getbody", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "stristr", NULL, 3, &_0, expected);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		RETVAL_ZVAL(resp, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_2);
	object_init_ex(&_2, zend_exception_get_default(TSRMLS_C));
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 6, message);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_2, "pacos/Client.zep", 224);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * limit
 *
 * @param diff
 *
 * @return
 */
PHP_METHOD(Pacos_Client, limit) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *diff_param = NULL, times, beatTime;
	zend_long diff;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&times);
	ZVAL_UNDEF(&beatTime);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &diff_param);

	if (!diff_param) {
		diff = 0;
	} else {
		diff = zephir_get_intval(diff_param);
	}


	ZEPHIR_INIT_VAR(&times);
	zephir_time(&times);
	ZEPHIR_INIT_VAR(&beatTime);
	ZVAL_LONG(&beatTime, ZEPHIR_GLOBAL(instance_limit_time));
	if (ZEPHIR_GE_LONG(&beatTime, (zephir_get_numberval(&times) - diff))) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_GLOBAL(instance_limit_time) = Z_LVAL_P(&times);
	RETURN_MM_BOOL(0);

}

/**
 * log
 *
 * @param info
 *
 * @return
 */
PHP_METHOD(Pacos_Client, log) {

	zval _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *category_param = NULL, *info_param = NULL, _0, outInfo, _1, _2, _4, _5;
	zval category, info;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&category);
	ZVAL_UNDEF(&info);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&outInfo);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &category_param, &info_param);

	zephir_get_strval(&category, category_param);
	if (!info_param) {
		ZEPHIR_INIT_VAR(&info);
		ZVAL_STRING(&info, "");
	} else {
		zephir_get_strval(&info, info_param);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("debug"), PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_TRUE(&_0)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "[Y-m-d H:i:s]");
	ZEPHIR_CALL_FUNCTION(&_2, "date", NULL, 7, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 2, 0);
	zephir_array_fast_append(&_3, &category);
	zephir_array_fast_append(&_3, &info);
	zephir_fast_join_str(&_1, SL(":"), &_3);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "[%s]%s\n");
	ZEPHIR_CALL_FUNCTION(&outInfo, "sprintf", NULL, 4, &_4, &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "/tmp/pacos.log");
	ZVAL_LONG(&_5, 8);
	ZEPHIR_CALL_FUNCTION(NULL, "file_put_contents", NULL, 8, &_4, &outInfo, &_5);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

