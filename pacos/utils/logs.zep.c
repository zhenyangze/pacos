
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Pacos_Utils_Logs) {

	ZEPHIR_REGISTER_CLASS(Pacos\\Utils, Logs, pacos, utils_logs, pacos_utils_logs_method_entry, 0);

	return SUCCESS;

}

/**
 * log
 *
 * @param info
 *
 * @return
 */
PHP_METHOD(Pacos_Utils_Logs, log) {

	zval _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool debug;
	zval *category_param = NULL, *info_param = NULL, *debug_param = NULL, outInfo, _0, _1, _3, _4;
	zval category, info;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&category);
	ZVAL_UNDEF(&info);
	ZVAL_UNDEF(&outInfo);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &category_param, &info_param, &debug_param);

	zephir_get_strval(&category, category_param);
	if (!info_param) {
		ZEPHIR_INIT_VAR(&info);
		ZVAL_STRING(&info, "");
	} else {
		zephir_get_strval(&info, info_param);
	}
	if (!debug_param) {
		debug = 1;
	} else {
		debug = zephir_get_boolval(debug_param);
	}


	if (!(debug)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "[Y-m-d H:i:s]");
	ZEPHIR_CALL_FUNCTION(&_1, "date", NULL, 31, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0);
	zephir_array_fast_append(&_2, &category);
	zephir_array_fast_append(&_2, &info);
	zephir_fast_join_str(&_0, SL(":"), &_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "[%s]%s\n");
	ZEPHIR_CALL_FUNCTION(&outInfo, "sprintf", NULL, 4, &_3, &_1, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "/tmp/pacos.log");
	ZVAL_LONG(&_4, 8);
	ZEPHIR_CALL_FUNCTION(NULL, "file_put_contents", NULL, 32, &_3, &outInfo, &_4);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

