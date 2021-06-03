
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Pacos_Models_ConfigInfo) {

	ZEPHIR_REGISTER_CLASS(Pacos\\Models, ConfigInfo, pacos, models_configinfo, pacos_models_configinfo_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(pacos_models_configinfo_ce, SL("dataId"), "", ZEND_ACC_PUBLIC);

	/**
	 * @var string
	 */
	zend_declare_property_string(pacos_models_configinfo_ce, SL("group"), "DEFAULT_GROUP", ZEND_ACC_PUBLIC);

	/**
	 * @var string
	 */
	zend_declare_property_string(pacos_models_configinfo_ce, SL("contentMd5"), "", ZEND_ACC_PUBLIC);

	/**
	 * @var string
	 */
	zend_declare_property_null(pacos_models_configinfo_ce, SL("_namespace"), ZEND_ACC_PUBLIC);

	return SUCCESS;

}

/**
 */
PHP_METHOD(Pacos_Models_ConfigInfo, setDataId) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *dataId_param = NULL;
	zval dataId;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dataId);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dataId_param);

	zephir_get_strval(&dataId, dataId_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("dataId"), &dataId);
	RETURN_THIS();

}

/**
 */
PHP_METHOD(Pacos_Models_ConfigInfo, getDataId) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "dataId");

}

/**
 */
PHP_METHOD(Pacos_Models_ConfigInfo, setGroup) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *group_param = NULL;
	zval group;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&group);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &group_param);

	zephir_get_strval(&group, group_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("group"), &group);
	RETURN_THIS();

}

/**
 */
PHP_METHOD(Pacos_Models_ConfigInfo, getGroup) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "group");

}

/**
 */
PHP_METHOD(Pacos_Models_ConfigInfo, setContentMd5) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *contentMd5_param = NULL;
	zval contentMd5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&contentMd5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &contentMd5_param);

	zephir_get_strval(&contentMd5, contentMd5_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("contentMd5"), &contentMd5);
	RETURN_THIS();

}

/**
 */
PHP_METHOD(Pacos_Models_ConfigInfo, getContentMd5) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "contentMd5");

}

PHP_METHOD(Pacos_Models_ConfigInfo, __construct) {

	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *info_param = NULL, key, value, *_0, _1, _4$$3, _6$$6;
	zval info;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&info);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &info_param);

	if (!info_param) {
		ZEPHIR_INIT_VAR(&info);
		array_init(&info);
	} else {
		zephir_get_arrval(&info, info_param);
	}


	zephir_is_iterable(&info, 0, "pacos/Models/ConfigInfo.zep", 46);
	if (Z_TYPE_P(&info) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&info), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			if (ZEPHIR_IS_STRING(&key, "namespace")) {
				zephir_update_property_zval(this_ptr, ZEND_STRL("_namespace"), &value);
				continue;
			}
			ZEPHIR_CALL_FUNCTION(&_4$$3, "property_exists", &_5, 1, this_ptr, &key);
			zephir_check_call_status();
			if (zephir_is_true(&_4$$3)) {
				zephir_update_property_zval_zval(this_ptr, &key, &value);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &info, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &info, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &info, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &info, "current", NULL, 0);
			zephir_check_call_status();
				if (ZEPHIR_IS_STRING(&key, "namespace")) {
					zephir_update_property_zval(this_ptr, ZEND_STRL("_namespace"), &value);
					continue;
				}
				ZEPHIR_CALL_FUNCTION(&_6$$6, "property_exists", &_5, 1, this_ptr, &key);
				zephir_check_call_status();
				if (zephir_is_true(&_6$$6)) {
					zephir_update_property_zval_zval(this_ptr, &key, &value);
				}
			ZEPHIR_CALL_METHOD(NULL, &info, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();

}

