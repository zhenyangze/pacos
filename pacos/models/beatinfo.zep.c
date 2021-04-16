
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
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


/**
 * BeatInfo 
 */
ZEPHIR_INIT_CLASS(Pacos_Models_BeatInfo) {

	ZEPHIR_REGISTER_CLASS(Pacos\\Models, BeatInfo, pacos, models_beatinfo, pacos_models_beatinfo_method_entry, 0);

	/**
	 * @var int
	 */
	zend_declare_property_null(pacos_models_beatinfo_ce, SL("port"), ZEND_ACC_PUBLIC);

	/**
	 * @var string
	 */
	zend_declare_property_null(pacos_models_beatinfo_ce, SL("ip"), ZEND_ACC_PUBLIC);

	/**
	 * @var double
	 */
	zend_declare_property_null(pacos_models_beatinfo_ce, SL("weight"), ZEND_ACC_PUBLIC);

	/**
	 * @var string
	 */
	zend_declare_property_null(pacos_models_beatinfo_ce, SL("serviceName"), ZEND_ACC_PUBLIC);

	/**
	 * @var string
	 */
	zend_declare_property_null(pacos_models_beatinfo_ce, SL("cluster"), ZEND_ACC_PUBLIC);

	/**
	 * @var array
	 */
	zend_declare_property_null(pacos_models_beatinfo_ce, SL("metadata"), ZEND_ACC_PUBLIC);

	/**
	 * @var bool
	 */
	zend_declare_property_null(pacos_models_beatinfo_ce, SL("scheduled"), ZEND_ACC_PUBLIC);

	zend_class_implements(pacos_models_beatinfo_ce, 1, zephir_get_internal_ce(SL("jsonserializable")));
	return SUCCESS;

}

/**
 * jsonSerialize 
 *
 * @return 
 */
PHP_METHOD(Pacos_Models_BeatInfo, jsonSerialize) {

	zval _1, _2;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 7, 0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("port"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("port"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("ip"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("ip"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("weight"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("weight"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("serviceName"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("serviceName"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("cluster"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("cluster"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("metadata"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("metadata"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("scheduled"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("scheduled"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_closure_ex(&_2, NULL, pacos_0__closure_ce, SL("__invoke"));
	ZEPHIR_RETURN_CALL_FUNCTION("array_filter", NULL, 15, &_0, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * __construct 
 *
 * @param data
 *
 * @return 
 */
PHP_METHOD(Pacos_Models_BeatInfo, __construct) {

	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *info_param = NULL, key, value, *_0, _1, _4$$3, _6$$5;
	zval info;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&info);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &info_param);

	if (!info_param) {
		ZEPHIR_INIT_VAR(&info);
		array_init(&info);
	} else {
		zephir_get_arrval(&info, info_param);
	}


	zephir_is_iterable(&info, 0, "pacos/Models/BeatInfo.zep", 79);
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
				ZEPHIR_CALL_FUNCTION(&_6$$5, "property_exists", &_5, 1, this_ptr, &key);
				zephir_check_call_status();
				if (zephir_is_true(&_6$$5)) {
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

