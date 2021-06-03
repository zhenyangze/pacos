
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
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/object.h"


/**
 * Parser
 */
ZEPHIR_INIT_CLASS(Pacos_Utils_Parser) {

	ZEPHIR_REGISTER_CLASS(Pacos\\Utils, Parser, pacos, utils_parser, pacos_utils_parser_method_entry, 0);

	return SUCCESS;

}

/**
 * properties
 *
 * @param content
 *
 * @return
 */
PHP_METHOD(Pacos_Utils_Parser, properties) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *content_param = NULL, values, lines, line, firstChar, kv, key, value, *_0, _1, _2$$3, _3$$3, _4$$3, _5$$3, _6$$3, _7$$3, _8$$3, _9$$3, _11$$7, _12$$7, _13$$7, _14$$7, _15$$7, _16$$7, _17$$7, _18$$7;
	zval content;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&lines);
	ZVAL_UNDEF(&line);
	ZVAL_UNDEF(&firstChar);
	ZVAL_UNDEF(&kv);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content_param);

	zephir_get_strval(&content, content_param);


	ZEPHIR_INIT_VAR(&values);
	array_init(&values);
	ZEPHIR_INIT_VAR(&lines);
	array_init(&lines);
	ZEPHIR_INIT_VAR(&line);
	ZVAL_STRING(&line, "");
	ZEPHIR_INIT_NVAR(&lines);
	zephir_fast_explode_str(&lines, SL("\n"), &content, LONG_MAX);
	ZEPHIR_INIT_VAR(&firstChar);
	ZVAL_STRING(&firstChar, "");
	ZEPHIR_INIT_VAR(&kv);
	array_init(&kv);
	zephir_is_iterable(&lines, 0, "pacos/Utils/Parser.zep", 52);
	if (Z_TYPE_P(&lines) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&lines), _0)
		{
			ZEPHIR_INIT_NVAR(&line);
			ZVAL_COPY(&line, _0);
			ZEPHIR_INIT_NVAR(&_2$$3);
			zephir_fast_trim(&_2$$3, &line, NULL , ZEPHIR_TRIM_BOTH);
			ZEPHIR_CPY_WRT(&line, &_2$$3);
			if (!zephir_is_true(&line)) {
				continue;
			}
			ZVAL_LONG(&_3$$3, 0);
			ZVAL_LONG(&_4$$3, 1);
			ZEPHIR_INIT_NVAR(&firstChar);
			zephir_substr(&firstChar, &line, 0 , 1 , 0);
			ZEPHIR_INIT_NVAR(&_5$$3);
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "/[A-Za-z]/");
			ZEPHIR_INIT_NVAR(&_6$$3);
			ZEPHIR_INIT_NVAR(&_7$$3);
			ZVAL_STRING(&_7$$3, "/[A-Za-z]/");
			zephir_preg_match(&_6$$3, &_7$$3, &firstChar, &_5$$3, 0, 0 , 0 );
			if (!zephir_is_true(&_6$$3)) {
				continue;
			}
			ZEPHIR_INIT_NVAR(&kv);
			zephir_fast_explode_str(&kv, SL("="), &line, 2 );
			if (zephir_fast_count_int(&kv) != 2) {
				continue;
			}
			ZEPHIR_OBS_NVAR(&key);
			zephir_array_fetch_long(&key, &kv, 0, PH_NOISY, "pacos/Utils/Parser.zep", 44);
			ZEPHIR_OBS_NVAR(&value);
			zephir_array_fetch_long(&value, &kv, 1, PH_NOISY, "pacos/Utils/Parser.zep", 45);
			ZEPHIR_INIT_NVAR(&_8$$3);
			zephir_fast_trim(&_8$$3, &key, NULL , ZEPHIR_TRIM_BOTH);
			ZEPHIR_CPY_WRT(&key, &_8$$3);
			ZEPHIR_CALL_STATIC(&_9$$3, "translatevalue", &_10, 0, &value);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&value, &_9$$3);
			zephir_array_update_zval(&values, &key, &value, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &lines, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &lines, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&line, &lines, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_11$$7);
				zephir_fast_trim(&_11$$7, &line, NULL , ZEPHIR_TRIM_BOTH);
				ZEPHIR_CPY_WRT(&line, &_11$$7);
				if (!zephir_is_true(&line)) {
					continue;
				}
				ZVAL_LONG(&_12$$7, 0);
				ZVAL_LONG(&_13$$7, 1);
				ZEPHIR_INIT_NVAR(&firstChar);
				zephir_substr(&firstChar, &line, 0 , 1 , 0);
				ZEPHIR_INIT_NVAR(&_14$$7);
				ZEPHIR_INIT_NVAR(&_11$$7);
				ZVAL_STRING(&_11$$7, "/[A-Za-z]/");
				ZEPHIR_INIT_NVAR(&_15$$7);
				ZEPHIR_INIT_NVAR(&_16$$7);
				ZVAL_STRING(&_16$$7, "/[A-Za-z]/");
				zephir_preg_match(&_15$$7, &_16$$7, &firstChar, &_14$$7, 0, 0 , 0 );
				if (!zephir_is_true(&_15$$7)) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&kv);
				zephir_fast_explode_str(&kv, SL("="), &line, 2 );
				if (zephir_fast_count_int(&kv) != 2) {
					continue;
				}
				ZEPHIR_OBS_NVAR(&key);
				zephir_array_fetch_long(&key, &kv, 0, PH_NOISY, "pacos/Utils/Parser.zep", 44);
				ZEPHIR_OBS_NVAR(&value);
				zephir_array_fetch_long(&value, &kv, 1, PH_NOISY, "pacos/Utils/Parser.zep", 45);
				ZEPHIR_INIT_NVAR(&_17$$7);
				zephir_fast_trim(&_17$$7, &key, NULL , ZEPHIR_TRIM_BOTH);
				ZEPHIR_CPY_WRT(&key, &_17$$7);
				ZEPHIR_CALL_STATIC(&_18$$7, "translatevalue", &_10, 0, &value);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&value, &_18$$7);
				zephir_array_update_zval(&values, &key, &value, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &lines, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&line);
	RETURN_CCTOR(&values);

}

/**
 * translateValue
 *
 * @param value
 *
 * @return
 */
PHP_METHOD(Pacos_Utils_Parser, translateValue) {

	zend_bool _4$$5, _5$$5, _6$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *value = NULL, value_sub, _0, start, end, _1$$5, _2$$5, _3$$5, _7$$6, _8$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&start);
	ZVAL_UNDEF(&end);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);

	ZEPHIR_SEPARATE_PARAM(value);


	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_trim(&_0, value, NULL , ZEPHIR_TRIM_BOTH);
	ZEPHIR_CPY_WRT(value, &_0);
	do {
		if (ZEPHIR_IS_STRING(value, "true")) {
			RETURN_MM_BOOL(1);
		}
		if (ZEPHIR_IS_STRING(value, "false")) {
			RETURN_MM_BOOL(0);
		}
	} while(0);

	if (zephir_fast_strlen_ev(value) > 1) {
		ZVAL_LONG(&_1$$5, 0);
		ZVAL_LONG(&_2$$5, 1);
		ZEPHIR_INIT_VAR(&start);
		zephir_substr(&start, value, 0 , 1 , 0);
		ZVAL_LONG(&_3$$5, -1);
		ZEPHIR_INIT_VAR(&end);
		zephir_substr(&end, value, -1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		_4$$5 = ZEPHIR_IS_STRING_IDENTICAL(&start, "");
		if (_4$$5) {
			_4$$5 = ZEPHIR_IS_STRING_IDENTICAL(&end, "");
		}
		_5$$5 = _4$$5;
		if (!(_5$$5)) {
			_6$$5 = ZEPHIR_IS_STRING_IDENTICAL(&start, "");
			if (_6$$5) {
				_6$$5 = ZEPHIR_IS_STRING_IDENTICAL(&end, "");
			}
			_5$$5 = _6$$5;
		}
		if (_5$$5) {
			ZVAL_LONG(&_7$$6, 1);
			ZVAL_LONG(&_8$$6, -1);
			zephir_substr(return_value, value, 1 , -1 , 0);
			RETURN_MM();
		}
	}
	RETVAL_ZVAL(value, 1, 0);
	RETURN_MM();

}

