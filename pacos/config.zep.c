
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/time.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/exception.h"


/**
 * Config
 */
ZEPHIR_INIT_CLASS(Pacos_Config) {

	ZEPHIR_REGISTER_CLASS_EX(Pacos, Config, pacos, config, pacos_client_ce, pacos_config_method_entry, 0);

	zend_declare_property_null(pacos_config_ce, SL("tmpList"), ZEND_ACC_PROTECTED);

	pacos_config_ce->create_object = zephir_init_properties_Pacos_Config;
	return SUCCESS;

}

/**
 * 获取配置项
 * @param string dataId
 * @param string group
 * @return string
 * @throws PacosConfigNotFound
 */
PHP_METHOD(Pacos_Config, get) {

	zval _37, _41;
	zend_string *_4, *_11$$3, *_26$$13;
	zend_ulong _3, _10$$3, _25$$13;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *dataId_param = NULL, *group_param = NULL, *callback = NULL, callback_sub, __$false, __$null, time, md5List, contentList, currentMd5, md5Value, _0, *_1, _2, query, _35, resp, _38, _39, _40, _48, _5$$3, _6$$3, *_8$$3, _9$$3, _7$$4, _12$$5, _13$$5, _14$$5, _15$$8, _16$$9, _17$$9, _18$$9, _19$$12, _20$$13, _21$$13, *_23$$13, _24$$13, _22$$14, _27$$15, _28$$15, _29$$15, _30$$18, _31$$19, _32$$19, _33$$19, _34$$22, _36$$23, _42$$24, _43$$24, _44$$24, _45$$24, _46$$24, _47$$24;
	zval dataId, group;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dataId);
	ZVAL_UNDEF(&group);
	ZVAL_UNDEF(&callback_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&time);
	ZVAL_UNDEF(&md5List);
	ZVAL_UNDEF(&contentList);
	ZVAL_UNDEF(&currentMd5);
	ZVAL_UNDEF(&md5Value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&resp);
	ZVAL_UNDEF(&_38);
	ZVAL_UNDEF(&_39);
	ZVAL_UNDEF(&_40);
	ZVAL_UNDEF(&_48);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_21$$13);
	ZVAL_UNDEF(&_24$$13);
	ZVAL_UNDEF(&_22$$14);
	ZVAL_UNDEF(&_27$$15);
	ZVAL_UNDEF(&_28$$15);
	ZVAL_UNDEF(&_29$$15);
	ZVAL_UNDEF(&_30$$18);
	ZVAL_UNDEF(&_31$$19);
	ZVAL_UNDEF(&_32$$19);
	ZVAL_UNDEF(&_33$$19);
	ZVAL_UNDEF(&_34$$22);
	ZVAL_UNDEF(&_36$$23);
	ZVAL_UNDEF(&_42$$24);
	ZVAL_UNDEF(&_43$$24);
	ZVAL_UNDEF(&_44$$24);
	ZVAL_UNDEF(&_45$$24);
	ZVAL_UNDEF(&_46$$24);
	ZVAL_UNDEF(&_47$$24);
	ZVAL_UNDEF(&_37);
	ZVAL_UNDEF(&_41);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &dataId_param, &group_param, &callback);

	zephir_get_strval(&dataId, dataId_param);
	if (!group_param) {
		ZEPHIR_INIT_VAR(&group);
		ZVAL_STRING(&group, "DEFAULT_GROUP");
	} else {
		zephir_get_strval(&group, group_param);
	}
	if (!callback) {
		callback = &callback_sub;
		callback = &__$null;
	}


	ZEPHIR_INIT_VAR(&md5List);
	array_init(&md5List);
	ZEPHIR_INIT_VAR(&contentList);
	array_init(&contentList);
	ZEPHIR_INIT_VAR(&currentMd5);
	ZVAL_STRING(&currentMd5, "");
	ZEPHIR_INIT_VAR(&md5Value);
	ZVAL_STRING(&md5Value, "");
	zephir_read_property(&_0, this_ptr, ZEND_STRL("tmpList"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "pacos/Config.zep", 47);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&time);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&time, _4);
			} else {
				ZVAL_LONG(&time, _3);
			}
			ZEPHIR_INIT_NVAR(&md5List);
			ZVAL_COPY(&md5List, _1);
			ZEPHIR_INIT_NVAR(&_5$$3);
			zephir_time(&_5$$3);
			zephir_read_property(&_6$$3, this_ptr, ZEND_STRL("timeout"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_LT_LONG(&time, (zephir_get_numberval(&_5$$3) - (zephir_get_numberval(&_6$$3) * 1000)))) {
				zephir_read_property(&_7$$4, this_ptr, ZEND_STRL("tmpList"), PH_NOISY_CC | PH_READONLY);
				zephir_array_unset(&_7$$4, &time, PH_SEPARATE);
				continue;
			}
			zephir_is_iterable(&md5List, 0, "pacos/Config.zep", 45);
			if (Z_TYPE_P(&md5List) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&md5List), _10$$3, _11$$3, _8$$3)
				{
					ZEPHIR_INIT_NVAR(&md5Value);
					if (_11$$3 != NULL) { 
						ZVAL_STR_COPY(&md5Value, _11$$3);
					} else {
						ZVAL_LONG(&md5Value, _10$$3);
					}
					ZEPHIR_INIT_NVAR(&contentList);
					ZVAL_COPY(&contentList, _8$$3);
					ZEPHIR_INIT_NVAR(&_12$$5);
					zephir_md5(&_12$$5, &dataId);
					ZEPHIR_INIT_NVAR(&_13$$5);
					zephir_md5(&_13$$5, &group);
					ZEPHIR_INIT_NVAR(&currentMd5);
					ZEPHIR_CONCAT_VSV(&currentMd5, &_12$$5, "_", &_13$$5);
					if (!ZEPHIR_IS_EQUAL(&md5Value, &currentMd5)) {
						continue;
					}
					zephir_array_fetch_string(&_14$$5, &contentList, SL("type"), PH_NOISY | PH_READONLY, "pacos/Config.zep", 39);
					if (ZEPHIR_IS_STRING(&_14$$5, "delete")) {
						RETURN_MM_NULL();
					} else {
						zephir_array_fetch_string(&_15$$8, &contentList, SL("value"), PH_NOISY | PH_READONLY, "pacos/Config.zep", 42);
						RETURN_CTOR(&_15$$8);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &md5List, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_9$$3, &md5List, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_9$$3)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&md5Value, &md5List, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&contentList, &md5List, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_16$$9);
						zephir_md5(&_16$$9, &dataId);
						ZEPHIR_INIT_NVAR(&_17$$9);
						zephir_md5(&_17$$9, &group);
						ZEPHIR_INIT_NVAR(&currentMd5);
						ZEPHIR_CONCAT_VSV(&currentMd5, &_16$$9, "_", &_17$$9);
						if (!ZEPHIR_IS_EQUAL(&md5Value, &currentMd5)) {
							continue;
						}
						zephir_array_fetch_string(&_18$$9, &contentList, SL("type"), PH_NOISY | PH_READONLY, "pacos/Config.zep", 39);
						if (ZEPHIR_IS_STRING(&_18$$9, "delete")) {
							RETURN_MM_NULL();
						} else {
							zephir_array_fetch_string(&_19$$12, &contentList, SL("value"), PH_NOISY | PH_READONLY, "pacos/Config.zep", 42);
							RETURN_CTOR(&_19$$12);
						}
					ZEPHIR_CALL_METHOD(NULL, &md5List, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&contentList);
			ZEPHIR_INIT_NVAR(&md5Value);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&time, &_0, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&md5List, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_20$$13);
				zephir_time(&_20$$13);
				zephir_read_property(&_21$$13, this_ptr, ZEND_STRL("timeout"), PH_NOISY_CC | PH_READONLY);
				if (ZEPHIR_LT_LONG(&time, (zephir_get_numberval(&_20$$13) - (zephir_get_numberval(&_21$$13) * 1000)))) {
					zephir_read_property(&_22$$14, this_ptr, ZEND_STRL("tmpList"), PH_NOISY_CC | PH_READONLY);
					zephir_array_unset(&_22$$14, &time, PH_SEPARATE);
					continue;
				}
				zephir_is_iterable(&md5List, 0, "pacos/Config.zep", 45);
				if (Z_TYPE_P(&md5List) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&md5List), _25$$13, _26$$13, _23$$13)
					{
						ZEPHIR_INIT_NVAR(&md5Value);
						if (_26$$13 != NULL) { 
							ZVAL_STR_COPY(&md5Value, _26$$13);
						} else {
							ZVAL_LONG(&md5Value, _25$$13);
						}
						ZEPHIR_INIT_NVAR(&contentList);
						ZVAL_COPY(&contentList, _23$$13);
						ZEPHIR_INIT_NVAR(&_27$$15);
						zephir_md5(&_27$$15, &dataId);
						ZEPHIR_INIT_NVAR(&_28$$15);
						zephir_md5(&_28$$15, &group);
						ZEPHIR_INIT_NVAR(&currentMd5);
						ZEPHIR_CONCAT_VSV(&currentMd5, &_27$$15, "_", &_28$$15);
						if (!ZEPHIR_IS_EQUAL(&md5Value, &currentMd5)) {
							continue;
						}
						zephir_array_fetch_string(&_29$$15, &contentList, SL("type"), PH_NOISY | PH_READONLY, "pacos/Config.zep", 39);
						if (ZEPHIR_IS_STRING(&_29$$15, "delete")) {
							RETURN_MM_NULL();
						} else {
							zephir_array_fetch_string(&_30$$18, &contentList, SL("value"), PH_NOISY | PH_READONLY, "pacos/Config.zep", 42);
							RETURN_CTOR(&_30$$18);
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &md5List, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_24$$13, &md5List, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_24$$13)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&md5Value, &md5List, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&contentList, &md5List, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_31$$19);
							zephir_md5(&_31$$19, &dataId);
							ZEPHIR_INIT_NVAR(&_32$$19);
							zephir_md5(&_32$$19, &group);
							ZEPHIR_INIT_NVAR(&currentMd5);
							ZEPHIR_CONCAT_VSV(&currentMd5, &_31$$19, "_", &_32$$19);
							if (!ZEPHIR_IS_EQUAL(&md5Value, &currentMd5)) {
								continue;
							}
							zephir_array_fetch_string(&_33$$19, &contentList, SL("type"), PH_NOISY | PH_READONLY, "pacos/Config.zep", 39);
							if (ZEPHIR_IS_STRING(&_33$$19, "delete")) {
								RETURN_MM_NULL();
							} else {
								zephir_array_fetch_string(&_34$$22, &contentList, SL("value"), PH_NOISY | PH_READONLY, "pacos/Config.zep", 42);
								RETURN_CTOR(&_34$$22);
							}
						ZEPHIR_CALL_METHOD(NULL, &md5List, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&contentList);
				ZEPHIR_INIT_NVAR(&md5Value);
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&md5List);
	ZEPHIR_INIT_NVAR(&time);
	ZEPHIR_INIT_VAR(&query);
	zephir_create_array(&query, 2, 0);
	zephir_array_update_string(&query, SL("dataId"), &dataId, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&query, SL("group"), &group, PH_COPY | PH_SEPARATE);
	zephir_read_property(&_35, this_ptr, ZEND_STRL("_namespace"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_35)) {
		zephir_read_property(&_36$$23, this_ptr, ZEND_STRL("_namespace"), PH_NOISY_CC | PH_READONLY);
		zephir_array_update_string(&query, SL("tenant"), &_36$$23, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(&_37);
	zephir_create_array(&_37, 2, 0);
	zephir_array_update_string(&_37, SL("http_errors"), &__$false, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_37, SL("query"), &query, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_38);
	ZVAL_STRING(&_38, "GET");
	ZEPHIR_INIT_VAR(&_39);
	ZVAL_STRING(&_39, "/nacos/v1/cs/configs");
	ZEPHIR_CALL_METHOD(&resp, this_ptr, "request", NULL, 0, &_38, &_39, &_37);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_40, &resp, "getstatuscode", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_41);
	zephir_create_array(&_41, 1, 0);
	ZEPHIR_INIT_NVAR(&_38);
	ZVAL_LONG(&_38, 200);
	zephir_array_fast_append(&_41, &_38);
	if (!(zephir_fast_in_array(&_40, &_41))) {
		if (zephir_is_callable(callback)) {
			ZEPHIR_RETURN_CALL_ZVAL_FUNCTION(callback, NULL, 0, &dataId, &group);
			zephir_check_call_status();
			RETURN_MM();
		}
		zephir_read_property(&_42$$24, this_ptr, ZEND_STRL("display_error"), PH_NOISY_CC | PH_READONLY);
		if (!(zephir_is_true(&_42$$24))) {
			RETURN_MM_NULL();
		}
		ZEPHIR_INIT_VAR(&_43$$24);
		object_init_ex(&_43$$24, pacos_exceptions_pacosconfignotfound_ce);
		zephir_read_property(&_44$$24, this_ptr, ZEND_STRL("_namespace"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_45$$24);
		ZVAL_STRING(&_45$$24, "config not found, dataId:%s group:%s tenant:%s");
		ZEPHIR_CALL_FUNCTION(&_46$$24, "sprintf", NULL, 4, &_45$$24, &dataId, &group, &_44$$24);
		zephir_check_call_status();
		ZVAL_LONG(&_47$$24, 404);
		ZEPHIR_CALL_METHOD(NULL, &_43$$24, "__construct", NULL, 9, &_46$$24, &_47$$24);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_43$$24, "pacos/Config.zep", 73);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_48, &resp, "getbody", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_38);
	ZVAL_STRING(&_38, "get");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendtmp", NULL, 0, &dataId, &group, &_38, &_48);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&resp, "getbody", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 发布配置
 * @param string dataId
 * @param string group
 * @param string content
 * @return string
 * @throws PacosRequestException
 */
PHP_METHOD(Pacos_Config, set) {

	zval _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *dataId_param = NULL, *group_param = NULL, *content_param = NULL, formParams, _0, resp, _3, _4, _1$$3;
	zval dataId, group, content;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dataId);
	ZVAL_UNDEF(&group);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&formParams);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&resp);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &dataId_param, &group_param, &content_param);

	zephir_get_strval(&dataId, dataId_param);
	zephir_get_strval(&group, group_param);
	zephir_get_strval(&content, content_param);


	ZEPHIR_INIT_VAR(&formParams);
	zephir_create_array(&formParams, 3, 0);
	zephir_array_update_string(&formParams, SL("dataId"), &dataId, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&formParams, SL("group"), &group, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&formParams, SL("content"), &content, PH_COPY | PH_SEPARATE);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("_namespace"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("_namespace"), PH_NOISY_CC | PH_READONLY);
		zephir_array_update_string(&formParams, SL("tenant"), &_1$$3, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 1, 0);
	zephir_array_update_string(&_2, SL("form_params"), &formParams, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "POST");
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "/nacos/v1/cs/configs");
	ZEPHIR_CALL_METHOD(&resp, this_ptr, "request", NULL, 0, &_3, &_4, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "true");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "Client update config fail");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "assertresponse", NULL, 0, &resp, &_3, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "set");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendtmp", NULL, 0, &dataId, &group, &_3, &content);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);

}

/**
 * 查询历史版本
 * @param string dataId
 * @param string group
 * @param int pageNo
 * @param int pageSize
 * @return 
 * @throws PacosRequestException
 */
PHP_METHOD(Pacos_Config, search) {

	zval _3, _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long pageNo, pageSize, ZEPHIR_LAST_CALL_STATUS;
	zval *dataId_param = NULL, *group_param = NULL, *pageNo_param = NULL, *pageSize_param = NULL, __$false, query, _0, _1, resp, _4, _5, _2$$3, _7$$4, _8$$4, _9$$4, _10$$4, _11$$4, _12$$4;
	zval dataId, group;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dataId);
	ZVAL_UNDEF(&group);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&resp);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &dataId_param, &group_param, &pageNo_param, &pageSize_param);

	zephir_get_strval(&dataId, dataId_param);
	zephir_get_strval(&group, group_param);
	if (!pageNo_param) {
		pageNo = 1;
	} else {
		pageNo = zephir_get_intval(pageNo_param);
	}
	if (!pageSize_param) {
		pageSize = 100;
	} else {
		pageSize = zephir_get_intval(pageSize_param);
	}


	ZEPHIR_INIT_VAR(&query);
	zephir_create_array(&query, 5, 0);
	add_assoc_stringl_ex(&query, SL("search"), SL("accurate"));
	zephir_array_update_string(&query, SL("dataId"), &dataId, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&query, SL("group"), &group, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, pageNo);
	zephir_array_update_string(&query, SL("pageNo"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, pageSize);
	zephir_array_update_string(&query, SL("pageSize"), &_0, PH_COPY | PH_SEPARATE);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("_namespace"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_1)) {
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("_namespace"), PH_NOISY_CC | PH_READONLY);
		zephir_array_update_string(&query, SL("tenant"), &_2$$3, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 2, 0);
	zephir_array_update_string(&_3, SL("http_errors"), &__$false, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_3, SL("query"), &query, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "GET");
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "/nacos/v1/cs/history");
	ZEPHIR_CALL_METHOD(&resp, this_ptr, "request", NULL, 0, &_0, &_4, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, &resp, "getstatuscode", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 1, 0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, 200);
	zephir_array_fast_append(&_6, &_0);
	if (!(zephir_fast_in_array(&_5, &_6))) {
		zephir_read_property(&_7$$4, this_ptr, ZEND_STRL("display_error"), PH_NOISY_CC | PH_READONLY);
		if (!(zephir_is_true(&_7$$4))) {
			RETURN_MM_NULL();
		}
		ZEPHIR_INIT_VAR(&_8$$4);
		object_init_ex(&_8$$4, pacos_exceptions_pacosconfignotfound_ce);
		zephir_read_property(&_9$$4, this_ptr, ZEND_STRL("_namespace"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_10$$4);
		ZVAL_STRING(&_10$$4, "config not found, dataId:%s group:%s tenant:%s");
		ZEPHIR_CALL_FUNCTION(&_11$$4, "sprintf", NULL, 4, &_10$$4, &dataId, &group, &_9$$4);
		zephir_check_call_status();
		ZVAL_LONG(&_12$$4, 404);
		ZEPHIR_CALL_METHOD(NULL, &_8$$4, "__construct", NULL, 9, &_11$$4, &_12$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_8$$4, "pacos/Config.zep", 145);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD(&resp, "getbody", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * appendTmp
 *
 * @param type
 * @param content
 *
 * @return
 */
PHP_METHOD(Pacos_Config, appendTmp) {

	zval _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *dataId_param = NULL, *group_param = NULL, *type_param = NULL, *content_param = NULL, _0, _1, _5, _6, _7, _8, _2$$3, _3$$3;
	zval dataId, group, type, content;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dataId);
	ZVAL_UNDEF(&group);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &dataId_param, &group_param, &type_param, &content_param);

	zephir_get_strval(&dataId, dataId_param);
	zephir_get_strval(&type, type_param);
	zephir_get_strval(&content, content_param);
	if (!group_param) {
		ZEPHIR_INIT_VAR(&group);
		ZVAL_STRING(&group, "DEFAULT_GROUP");
	} else {
		zephir_get_strval(&group, group_param);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("tmpList"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_time(&_1);
	if (!(zephir_array_isset(&_0, &_1))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		array_init(&_2$$3);
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_time(&_3$$3);
		zephir_update_property_array(this_ptr, SL("tmpList"), &_3$$3, &_2$$3);
	}
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 2, 0);
	zephir_array_update_string(&_4, SL("type"), &type, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_4, SL("value"), &content, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_5);
	zephir_time(&_5);
	ZEPHIR_INIT_VAR(&_6);
	zephir_md5(&_6, &dataId);
	ZEPHIR_INIT_VAR(&_7);
	zephir_md5(&_7, &group);
	ZEPHIR_INIT_VAR(&_8);
	ZEPHIR_CONCAT_VSV(&_8, &_6, "_", &_7);
	zephir_update_property_array_multi(this_ptr, SL("tmpList"), &_4, SL("zz"), 2, &_5, &_8);
	ZEPHIR_MM_RESTORE();

}

/**
 * 删除配置
 * @param string dataId
 * @param string group
 * @return string
 * @throws PacosRequestException
 */
PHP_METHOD(Pacos_Config, delete) {

	zval _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *dataId_param = NULL, *group_param = NULL, query, resp, _0, _1, _4, _5, _2$$3;
	zval dataId, group;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dataId);
	ZVAL_UNDEF(&group);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&resp);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &dataId_param, &group_param);

	zephir_get_strval(&dataId, dataId_param);
	if (!group_param) {
		ZEPHIR_INIT_VAR(&group);
		ZVAL_STRING(&group, "DEFAULT_GROUP");
	} else {
		zephir_get_strval(&group, group_param);
	}


	ZEPHIR_INIT_VAR(&query);
	array_init(&query);
	ZEPHIR_INIT_VAR(&resp);
	ZVAL_STRING(&resp, "");
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	zephir_array_update_string(&_0, SL("dataId"), &dataId, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("group"), &group, PH_COPY | PH_SEPARATE);
	ZEPHIR_CPY_WRT(&query, &_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("_namespace"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_1)) {
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("_namespace"), PH_NOISY_CC | PH_READONLY);
		zephir_array_update_string(&query, SL("tenant"), &_2$$3, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 1, 0);
	zephir_array_update_string(&_3, SL("query"), &query, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "DELETE");
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "/nacos/v1/cs/configs");
	ZEPHIR_CALL_METHOD(&resp, this_ptr, "request", NULL, 0, &_4, &_5, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "true");
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "Client delete config fail");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "assertresponse", NULL, 0, &resp, &_4, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "delete");
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendtmp", NULL, 0, &dataId, &group, &_4, &_5);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);

}

/**
 * 监听配置
 * @param Config[] configs
 * @param int timeout 长轮询等待事件，默认 30 ，单位：秒
 * @return Config[]
 */
PHP_METHOD(Pacos_Config, listen) {

	zval _21;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long timeout, ZEPHIR_LAST_CALL_STATUS;
	zval *configs_param = NULL, *timeout_param = NULL, configStringList, cacheObj, items, tmpCache, *_0, _1, configString, _15, _16, resp, _18, _20, _22, _23, respString, changed, lines, line, parts, c, _24, *_25, _26, _3$$3, _4$$3, _5$$3, _7$$3, _8$$3, _6$$6, _9$$7, _10$$7, _11$$7, _13$$7, _14$$7, _12$$10, _27$$12, _28$$13, _29$$13, _30$$13, _31$$14, _32$$14, _33$$16, _34$$17, _35$$17, _36$$17, _37$$18, _38$$18;
	zval configs, _17, _19;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&configs);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&configStringList);
	ZVAL_UNDEF(&cacheObj);
	ZVAL_UNDEF(&items);
	ZVAL_UNDEF(&tmpCache);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&configString);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&resp);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&respString);
	ZVAL_UNDEF(&changed);
	ZVAL_UNDEF(&lines);
	ZVAL_UNDEF(&line);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&c);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_27$$12);
	ZVAL_UNDEF(&_28$$13);
	ZVAL_UNDEF(&_29$$13);
	ZVAL_UNDEF(&_30$$13);
	ZVAL_UNDEF(&_31$$14);
	ZVAL_UNDEF(&_32$$14);
	ZVAL_UNDEF(&_33$$16);
	ZVAL_UNDEF(&_34$$17);
	ZVAL_UNDEF(&_35$$17);
	ZVAL_UNDEF(&_36$$17);
	ZVAL_UNDEF(&_37$$18);
	ZVAL_UNDEF(&_38$$18);
	ZVAL_UNDEF(&_21);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &configs_param, &timeout_param);

	zephir_get_arrval(&configs, configs_param);
	if (!timeout_param) {
		timeout = 30;
	} else {
		timeout = zephir_get_intval(timeout_param);
	}


	ZEPHIR_INIT_VAR(&configStringList);
	array_init(&configStringList);
	ZEPHIR_INIT_VAR(&items);
	array_init(&items);
	zephir_is_iterable(&configs, 0, "pacos/Config.zep", 222);
	if (Z_TYPE_P(&configs) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&configs), _0)
		{
			ZEPHIR_INIT_NVAR(&tmpCache);
			ZVAL_COPY(&tmpCache, _0);
			if (Z_TYPE_P(&tmpCache) == IS_ARRAY) {
				ZEPHIR_INIT_NVAR(&cacheObj);
				object_init_ex(&cacheObj, pacos_models_configinfo_ce);
				ZEPHIR_CALL_METHOD(NULL, &cacheObj, "__construct", &_2, 10, &tmpCache);
				zephir_check_call_status();
			} else {
				ZEPHIR_CPY_WRT(&cacheObj, &tmpCache);
			}
			ZEPHIR_INIT_NVAR(&_3$$3);
			zephir_create_array(&_3$$3, 3, 0);
			ZEPHIR_OBS_NVAR(&_4$$3);
			zephir_read_property(&_4$$3, &cacheObj, ZEND_STRL("dataId"), PH_NOISY_CC);
			zephir_array_fast_append(&_3$$3, &_4$$3);
			ZEPHIR_OBS_NVAR(&_4$$3);
			zephir_read_property(&_4$$3, &cacheObj, ZEND_STRL("group"), PH_NOISY_CC);
			zephir_array_fast_append(&_3$$3, &_4$$3);
			ZEPHIR_OBS_NVAR(&_4$$3);
			zephir_read_property(&_4$$3, &cacheObj, ZEND_STRL("contentMd5"), PH_NOISY_CC);
			zephir_array_fast_append(&_3$$3, &_4$$3);
			ZEPHIR_CPY_WRT(&items, &_3$$3);
			zephir_read_property(&_5$$3, &cacheObj, ZEND_STRL("_namespace"), PH_NOISY_CC | PH_READONLY);
			if (zephir_is_true(&_5$$3)) {
				zephir_read_property(&_6$$6, &cacheObj, ZEND_STRL("_namespace"), PH_NOISY_CC | PH_READONLY);
				zephir_array_append(&items, &_6$$6, PH_SEPARATE, "pacos/Config.zep", 218);
			}
			ZEPHIR_INIT_NVAR(&_7$$3);
			ZEPHIR_INIT_NVAR(&_8$$3);
			ZVAL_STRING(&_8$$3, "\x02");
			zephir_fast_join(&_7$$3, &_8$$3, &items);
			zephir_array_append(&configStringList, &_7$$3, PH_SEPARATE, "pacos/Config.zep", 220);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &configs, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &configs, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&tmpCache, &configs, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&tmpCache) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(&cacheObj);
					object_init_ex(&cacheObj, pacos_models_configinfo_ce);
					ZEPHIR_CALL_METHOD(NULL, &cacheObj, "__construct", &_2, 10, &tmpCache);
					zephir_check_call_status();
				} else {
					ZEPHIR_CPY_WRT(&cacheObj, &tmpCache);
				}
				ZEPHIR_INIT_NVAR(&_9$$7);
				zephir_create_array(&_9$$7, 3, 0);
				ZEPHIR_OBS_NVAR(&_10$$7);
				zephir_read_property(&_10$$7, &cacheObj, ZEND_STRL("dataId"), PH_NOISY_CC);
				zephir_array_fast_append(&_9$$7, &_10$$7);
				ZEPHIR_OBS_NVAR(&_10$$7);
				zephir_read_property(&_10$$7, &cacheObj, ZEND_STRL("group"), PH_NOISY_CC);
				zephir_array_fast_append(&_9$$7, &_10$$7);
				ZEPHIR_OBS_NVAR(&_10$$7);
				zephir_read_property(&_10$$7, &cacheObj, ZEND_STRL("contentMd5"), PH_NOISY_CC);
				zephir_array_fast_append(&_9$$7, &_10$$7);
				ZEPHIR_CPY_WRT(&items, &_9$$7);
				zephir_read_property(&_11$$7, &cacheObj, ZEND_STRL("_namespace"), PH_NOISY_CC | PH_READONLY);
				if (zephir_is_true(&_11$$7)) {
					zephir_read_property(&_12$$10, &cacheObj, ZEND_STRL("_namespace"), PH_NOISY_CC | PH_READONLY);
					zephir_array_append(&items, &_12$$10, PH_SEPARATE, "pacos/Config.zep", 218);
				}
				ZEPHIR_INIT_NVAR(&_13$$7);
				ZEPHIR_INIT_NVAR(&_14$$7);
				ZVAL_STRING(&_14$$7, "\x02");
				zephir_fast_join(&_13$$7, &_14$$7, &items);
				zephir_array_append(&configStringList, &_13$$7, PH_SEPARATE, "pacos/Config.zep", 220);
			ZEPHIR_CALL_METHOD(NULL, &configs, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&tmpCache);
	ZEPHIR_INIT_VAR(&configString);
	ZVAL_STRING(&configString, "");
	ZEPHIR_INIT_VAR(&_15);
	ZEPHIR_INIT_VAR(&_16);
	ZVAL_STRING(&_16, "\x01");
	zephir_fast_join(&_15, &_16, &configStringList);
	ZEPHIR_INIT_NVAR(&configString);
	ZEPHIR_CONCAT_VS(&configString, &_15, "\x01");
	ZEPHIR_INIT_VAR(&resp);
	ZVAL_STRING(&resp, "");
	ZEPHIR_INIT_VAR(&_17);
	zephir_create_array(&_17, 3, 0);
	zephir_read_property(&_18, this_ptr, ZEND_STRL("timeout"), PH_NOISY_CC | PH_READONLY);
	add_assoc_long_ex(&_17, SL("timeout"), (timeout + zephir_get_numberval(&_18)));
	ZEPHIR_INIT_VAR(&_19);
	zephir_create_array(&_19, 1, 0);
	ZEPHIR_INIT_VAR(&_20);
	ZVAL_LONG(&_20, (timeout * 1000));
	ZEPHIR_INIT_VAR(&_21);
	ZEPHIR_CONCAT_SV(&_21, "Long-Pulling-Timeout:", &_20);
	zephir_array_fast_append(&_19, &_21);
	zephir_array_update_string(&_17, SL("headers"), &_19, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_19);
	zephir_create_array(&_19, 1, 0);
	zephir_array_update_string(&_19, SL("Listening-Configs"), &configString, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_17, SL("form_params"), &_19, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_22);
	ZVAL_STRING(&_22, "POST");
	ZEPHIR_INIT_VAR(&_23);
	ZVAL_STRING(&_23, "/nacos/v1/cs/configs/listener");
	ZEPHIR_CALL_METHOD(&resp, this_ptr, "request", NULL, 0, &_22, &_23, &_17);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&respString);
	ZVAL_STRING(&respString, "");
	ZEPHIR_CALL_METHOD(&respString, &resp, "getbody", NULL, 0);
	zephir_check_call_status();
	if (!zephir_is_true(&respString)) {
		array_init(return_value);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&changed);
	array_init(&changed);
	ZEPHIR_INIT_VAR(&lines);
	array_init(&lines);
	ZEPHIR_INIT_VAR(&line);
	ZVAL_STRING(&line, "");
	ZEPHIR_INIT_VAR(&parts);
	array_init(&parts);
	ZEPHIR_CALL_FUNCTION(&_24, "urldecode", NULL, 11, &respString);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_22);
	ZVAL_STRING(&_22, "\x01");
	ZEPHIR_INIT_NVAR(&lines);
	zephir_fast_explode(&lines, &_22, &_24, LONG_MAX);
	zephir_is_iterable(&lines, 0, "pacos/Config.zep", 263);
	if (Z_TYPE_P(&lines) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&lines), _25)
		{
			ZEPHIR_INIT_NVAR(&line);
			ZVAL_COPY(&line, _25);
			ZEPHIR_INIT_NVAR(&_27$$12);
			ZVAL_STRING(&_27$$12, "\x02");
			ZEPHIR_INIT_NVAR(&parts);
			zephir_fast_explode(&parts, &_27$$12, &line, LONG_MAX);
			ZEPHIR_INIT_NVAR(&c);
			object_init_ex(&c, pacos_models_configinfo_ce);
			ZEPHIR_CALL_METHOD(NULL, &c, "__construct", &_2, 10);
			zephir_check_call_status();
			if (zephir_fast_count_int(&parts) == 3) {
				zephir_array_fetch_long(&_28$$13, &parts, 0, PH_NOISY | PH_READONLY, "pacos/Config.zep", 252);
				zephir_update_property_zval(&c, ZEND_STRL("dataId"), &_28$$13);
				zephir_array_fetch_long(&_29$$13, &parts, 1, PH_NOISY | PH_READONLY, "pacos/Config.zep", 253);
				zephir_update_property_zval(&c, ZEND_STRL("group"), &_29$$13);
				zephir_array_fetch_long(&_30$$13, &parts, 2, PH_NOISY | PH_READONLY, "pacos/Config.zep", 254);
				zephir_update_property_zval(&c, ZEND_STRL("_namespace"), &_30$$13);
			} else if (zephir_fast_count_int(&parts) == 2) {
				zephir_array_fetch_long(&_31$$14, &parts, 0, PH_NOISY | PH_READONLY, "pacos/Config.zep", 256);
				zephir_update_property_zval(&c, ZEND_STRL("dataId"), &_31$$14);
				zephir_array_fetch_long(&_32$$14, &parts, 1, PH_NOISY | PH_READONLY, "pacos/Config.zep", 257);
				zephir_update_property_zval(&c, ZEND_STRL("group"), &_32$$14);
			} else {
				continue;
			}
			zephir_array_append(&changed, &c, PH_SEPARATE, "pacos/Config.zep", 261);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &lines, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_26, &lines, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_26)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&line, &lines, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_33$$16);
				ZVAL_STRING(&_33$$16, "\x02");
				ZEPHIR_INIT_NVAR(&parts);
				zephir_fast_explode(&parts, &_33$$16, &line, LONG_MAX);
				ZEPHIR_INIT_NVAR(&c);
				object_init_ex(&c, pacos_models_configinfo_ce);
				ZEPHIR_CALL_METHOD(NULL, &c, "__construct", &_2, 10);
				zephir_check_call_status();
				if (zephir_fast_count_int(&parts) == 3) {
					zephir_array_fetch_long(&_34$$17, &parts, 0, PH_NOISY | PH_READONLY, "pacos/Config.zep", 252);
					zephir_update_property_zval(&c, ZEND_STRL("dataId"), &_34$$17);
					zephir_array_fetch_long(&_35$$17, &parts, 1, PH_NOISY | PH_READONLY, "pacos/Config.zep", 253);
					zephir_update_property_zval(&c, ZEND_STRL("group"), &_35$$17);
					zephir_array_fetch_long(&_36$$17, &parts, 2, PH_NOISY | PH_READONLY, "pacos/Config.zep", 254);
					zephir_update_property_zval(&c, ZEND_STRL("_namespace"), &_36$$17);
				} else if (zephir_fast_count_int(&parts) == 2) {
					zephir_array_fetch_long(&_37$$18, &parts, 0, PH_NOISY | PH_READONLY, "pacos/Config.zep", 256);
					zephir_update_property_zval(&c, ZEND_STRL("dataId"), &_37$$18);
					zephir_array_fetch_long(&_38$$18, &parts, 1, PH_NOISY | PH_READONLY, "pacos/Config.zep", 257);
					zephir_update_property_zval(&c, ZEND_STRL("group"), &_38$$18);
				} else {
					continue;
				}
				zephir_array_append(&changed, &c, PH_SEPARATE, "pacos/Config.zep", 261);
			ZEPHIR_CALL_METHOD(NULL, &lines, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&line);
	RETURN_CCTOR(&changed);

}

zend_object *zephir_init_properties_Pacos_Config(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("tmpList"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("tmpList"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

