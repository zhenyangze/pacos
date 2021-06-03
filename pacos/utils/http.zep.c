
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Pacos_Utils_Http) {

	ZEPHIR_REGISTER_CLASS(Pacos\\Utils, Http, pacos, utils_http, pacos_utils_http_method_entry, 0);

	return SUCCESS;

}

/**
 * doReqeust
 *
 * @param url
 * @param data
 * @param type
 * @param eaders
 * @param timeout
 * @param connttime
 *
 * @return
 */
PHP_METHOD(Pacos_Utils_Http, request) {

	zend_string *_8$$4;
	zend_ulong _7$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *url, url_sub, *data = NULL, data_sub, *type = NULL, type_sub, *headers = NULL, headers_sub, *timeout = NULL, timeout_sub, *connttime = NULL, connttime_sub, __$false, __$true, __$null, ch, key, val, val2, _0, _1, querystring, _35, _37, contents, httpCode, _2$$3, _4$$3, *_5$$4, _6$$4, _32$$4, _33$$4, _34$$4, *_9$$6, _10$$6, _11$$7, _13$$7, _14$$7, _15$$8, _16$$8, _17$$8, _18$$9, _19$$9, _20$$9, *_21$$11, _22$$11, _23$$12, _24$$12, _25$$12, _26$$13, _27$$13, _28$$13, _29$$14, _30$$14, _31$$14, _36$$16, _38$$17, _39$$17, _40$$18, _41$$18, _42$$19, _43$$20, _44$$20, _45$$21, _46$$21, _47$$22;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&type_sub);
	ZVAL_UNDEF(&headers_sub);
	ZVAL_UNDEF(&timeout_sub);
	ZVAL_UNDEF(&connttime_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&ch);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&val2);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&querystring);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_37);
	ZVAL_UNDEF(&contents);
	ZVAL_UNDEF(&httpCode);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_32$$4);
	ZVAL_UNDEF(&_33$$4);
	ZVAL_UNDEF(&_34$$4);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_19$$9);
	ZVAL_UNDEF(&_20$$9);
	ZVAL_UNDEF(&_22$$11);
	ZVAL_UNDEF(&_23$$12);
	ZVAL_UNDEF(&_24$$12);
	ZVAL_UNDEF(&_25$$12);
	ZVAL_UNDEF(&_26$$13);
	ZVAL_UNDEF(&_27$$13);
	ZVAL_UNDEF(&_28$$13);
	ZVAL_UNDEF(&_29$$14);
	ZVAL_UNDEF(&_30$$14);
	ZVAL_UNDEF(&_31$$14);
	ZVAL_UNDEF(&_36$$16);
	ZVAL_UNDEF(&_38$$17);
	ZVAL_UNDEF(&_39$$17);
	ZVAL_UNDEF(&_40$$18);
	ZVAL_UNDEF(&_41$$18);
	ZVAL_UNDEF(&_42$$19);
	ZVAL_UNDEF(&_43$$20);
	ZVAL_UNDEF(&_44$$20);
	ZVAL_UNDEF(&_45$$21);
	ZVAL_UNDEF(&_46$$21);
	ZVAL_UNDEF(&_47$$22);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 5, &url, &data, &type, &headers, &timeout, &connttime);

	if (!data) {
		data = &data_sub;
		data = &__$null;
	}
	if (!type) {
		type = &type_sub;
		ZEPHIR_INIT_VAR(type);
		ZVAL_STRING(type, "GET");
	} else {
		ZEPHIR_SEPARATE_PARAM(type);
	}
	if (!headers) {
		headers = &headers_sub;
		ZEPHIR_INIT_VAR(headers);
		array_init(headers);
	}
	if (!timeout) {
		timeout = &timeout_sub;
		timeout = &__$null;
	}
	if (!connttime) {
		connttime = &connttime_sub;
		connttime = &__$null;
	}


	ZEPHIR_CALL_FUNCTION(&ch, "curl_init", NULL, 36);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strtoupper(&_0, type);
	ZEPHIR_CPY_WRT(type, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "https://");
	ZEPHIR_CALL_FUNCTION(&_1, "stripos", NULL, 37, url, &_0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_1)) {
		ZVAL_LONG(&_2$$3, 64);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_3, 38, &ch, &_2$$3, &__$false);
		zephir_check_call_status();
		ZVAL_LONG(&_2$$3, 81);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_3, 38, &ch, &_2$$3, &__$false);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$3);
		ZEPHIR_GET_CONSTANT(&_4$$3, "CURLOPT_SSLVERSION");
		ZVAL_LONG(&_2$$3, 1);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_3, 38, &ch, &_4$$3, &_2$$3);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&querystring);
	ZVAL_STRING(&querystring, "");
	if (Z_TYPE_P(data) == IS_ARRAY) {
		zephir_is_iterable(data, 0, "pacos/Utils/Http.zep", 42);
		if (Z_TYPE_P(data) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(data), _7$$4, _8$$4, _5$$4)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_8$$4 != NULL) { 
					ZVAL_STR_COPY(&key, _8$$4);
				} else {
					ZVAL_LONG(&key, _7$$4);
				}
				ZEPHIR_INIT_NVAR(&val);
				ZVAL_COPY(&val, _5$$4);
				if (Z_TYPE_P(&val) == IS_ARRAY) {
					zephir_is_iterable(&val, 0, "pacos/Utils/Http.zep", 38);
					if (Z_TYPE_P(&val) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&val), _9$$6)
						{
							ZEPHIR_INIT_NVAR(&val2);
							ZVAL_COPY(&val2, _9$$6);
							ZEPHIR_CALL_FUNCTION(&_11$$7, "urlencode", &_12, 39, &key);
							zephir_check_call_status();
							ZEPHIR_CALL_FUNCTION(&_13$$7, "urlencode", &_12, 39, &val2);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_14$$7);
							ZEPHIR_CONCAT_VSVS(&_14$$7, &_11$$7, "=", &_13$$7, "&");
							zephir_concat_self(&querystring, &_14$$7);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &val, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_10$$6, &val, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_10$$6)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&val2, &val, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_CALL_FUNCTION(&_15$$8, "urlencode", &_12, 39, &key);
								zephir_check_call_status();
								ZEPHIR_CALL_FUNCTION(&_16$$8, "urlencode", &_12, 39, &val2);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_17$$8);
								ZEPHIR_CONCAT_VSVS(&_17$$8, &_15$$8, "=", &_16$$8, "&");
								zephir_concat_self(&querystring, &_17$$8);
							ZEPHIR_CALL_METHOD(NULL, &val, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&val2);
				} else {
					ZEPHIR_CALL_FUNCTION(&_18$$9, "urlencode", &_12, 39, &key);
					zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(&_19$$9, "urlencode", &_12, 39, &val);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_20$$9);
					ZEPHIR_CONCAT_VSVS(&_20$$9, &_18$$9, "=", &_19$$9, "&");
					zephir_concat_self(&querystring, &_20$$9);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, data, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_6$$4, data, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_6$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, data, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&val, data, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&val) == IS_ARRAY) {
						zephir_is_iterable(&val, 0, "pacos/Utils/Http.zep", 38);
						if (Z_TYPE_P(&val) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&val), _21$$11)
							{
								ZEPHIR_INIT_NVAR(&val2);
								ZVAL_COPY(&val2, _21$$11);
								ZEPHIR_CALL_FUNCTION(&_23$$12, "urlencode", &_12, 39, &key);
								zephir_check_call_status();
								ZEPHIR_CALL_FUNCTION(&_24$$12, "urlencode", &_12, 39, &val2);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_25$$12);
								ZEPHIR_CONCAT_VSVS(&_25$$12, &_23$$12, "=", &_24$$12, "&");
								zephir_concat_self(&querystring, &_25$$12);
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &val, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_22$$11, &val, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_22$$11)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&val2, &val, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_CALL_FUNCTION(&_26$$13, "urlencode", &_12, 39, &key);
									zephir_check_call_status();
									ZEPHIR_CALL_FUNCTION(&_27$$13, "urlencode", &_12, 39, &val2);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_28$$13);
									ZEPHIR_CONCAT_VSVS(&_28$$13, &_26$$13, "=", &_27$$13, "&");
									zephir_concat_self(&querystring, &_28$$13);
								ZEPHIR_CALL_METHOD(NULL, &val, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&val2);
					} else {
						ZEPHIR_CALL_FUNCTION(&_29$$14, "urlencode", &_12, 39, &key);
						zephir_check_call_status();
						ZEPHIR_CALL_FUNCTION(&_30$$14, "urlencode", &_12, 39, &val);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_31$$14);
						ZEPHIR_CONCAT_VSVS(&_31$$14, &_29$$14, "=", &_30$$14, "&");
						zephir_concat_self(&querystring, &_31$$14);
					}
				ZEPHIR_CALL_METHOD(NULL, data, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&val);
		ZEPHIR_INIT_NVAR(&key);
		ZVAL_LONG(&_32$$4, 0);
		ZVAL_LONG(&_33$$4, -1);
		ZEPHIR_INIT_VAR(&_34$$4);
		zephir_substr(&_34$$4, &querystring, 0 , -1 , 0);
		ZEPHIR_CPY_WRT(&querystring, &_34$$4);
	} else {
		ZEPHIR_CPY_WRT(&querystring, data);
	}
	ZVAL_LONG(&_35, 10002);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_3, 38, &ch, &_35, url);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(headers))) {
		ZVAL_LONG(&_36$$16, 10023);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_3, 38, &ch, &_36$$16, headers);
		zephir_check_call_status();
	}
	ZVAL_LONG(&_35, 19913);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_3, 38, &ch, &_35, &__$true);
	zephir_check_call_status();
	ZVAL_LONG(&_35, 52);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_3, 38, &ch, &_35, &__$true);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_GET_CONSTANT(&_0, "CURLOPT_HTTP_VERSION");
	ZEPHIR_INIT_VAR(&_37);
	ZEPHIR_GET_CONSTANT(&_37, "CURL_HTTP_VERSION_1_1");
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_3, 38, &ch, &_0, &_37);
	zephir_check_call_status();
	if (ZEPHIR_GT_LONG(connttime, 0)) {
		ZVAL_LONG(&_38$$17, 156);
		ZVAL_LONG(&_39$$17, (zephir_get_numberval(connttime) * 1000));
		ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_3, 38, &ch, &_38$$17, &_39$$17);
		zephir_check_call_status();
	}
	if (ZEPHIR_GT_LONG(timeout, 0)) {
		ZVAL_LONG(&_40$$18, 155);
		ZVAL_LONG(&_41$$18, (zephir_get_numberval(timeout) * 1000));
		ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_3, 38, &ch, &_40$$18, &_41$$18);
		zephir_check_call_status();
	}
	do {
		if (ZEPHIR_IS_STRING(type, "POST")) {
			ZVAL_LONG(&_42$$19, 47);
			ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_3, 38, &ch, &_42$$19, &__$true);
			zephir_check_call_status();
			ZVAL_LONG(&_42$$19, 10015);
			ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_3, 38, &ch, &_42$$19, &querystring);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(type, "PUT")) {
			ZVAL_LONG(&_43$$20, 10036);
			ZEPHIR_INIT_VAR(&_44$$20);
			ZVAL_STRING(&_44$$20, "PUT");
			ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_3, 38, &ch, &_43$$20, &_44$$20);
			zephir_check_call_status();
			ZVAL_LONG(&_43$$20, 10015);
			ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_3, 38, &ch, &_43$$20, &querystring);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(type, "DELETE")) {
			ZVAL_LONG(&_45$$21, 10036);
			ZEPHIR_INIT_VAR(&_46$$21);
			ZVAL_STRING(&_46$$21, "DELETE");
			ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_3, 38, &ch, &_45$$21, &_46$$21);
			zephir_check_call_status();
			ZVAL_LONG(&_45$$21, 10015);
			ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_3, 38, &ch, &_45$$21, &querystring);
			zephir_check_call_status();
			break;
		}
		ZVAL_LONG(&_47$$22, 80);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_3, 38, &ch, &_47$$22, &__$true);
		zephir_check_call_status();
		break;
	} while(0);

	ZEPHIR_CALL_FUNCTION(&contents, "curl_exec", NULL, 40, &ch);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&httpCode, "curl_getinfo", NULL, 41, &ch);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "curl_close", NULL, 42, &ch);
	zephir_check_call_status();
	object_init_ex(return_value, pacos_utils_response_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 43, &contents, &httpCode);
	zephir_check_call_status();
	RETURN_MM();

}

