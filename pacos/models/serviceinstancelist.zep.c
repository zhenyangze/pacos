
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
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"


/**
 * ServiceInstanceList
 */
ZEPHIR_INIT_CLASS(Pacos_Models_ServiceInstanceList) {

	ZEPHIR_REGISTER_CLASS(Pacos\\Models, ServiceInstanceList, pacos, models_serviceinstancelist, pacos_models_serviceinstancelist_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_null(pacos_models_serviceinstancelist_ce, SL("dom"), ZEND_ACC_PUBLIC);

	/**
	 * @var array
	 */
	zend_declare_property_null(pacos_models_serviceinstancelist_ce, SL("metadata"), ZEND_ACC_PUBLIC);

	/**
	 * @var int
	 */
	zend_declare_property_null(pacos_models_serviceinstancelist_ce, SL("cacheMillis"), ZEND_ACC_PUBLIC);

	/**
	 * @var bool
	 */
	zend_declare_property_null(pacos_models_serviceinstancelist_ce, SL("useSpecifiedURL"), ZEND_ACC_PUBLIC);

	/**
	 * @var ServiceInstance[]
	 */
	zend_declare_property_null(pacos_models_serviceinstancelist_ce, SL("hosts"), ZEND_ACC_PUBLIC);

	/**
	 * @var string
	 */
	zend_declare_property_null(pacos_models_serviceinstancelist_ce, SL("checksum"), ZEND_ACC_PUBLIC);

	/**
	 * @var int
	 */
	zend_declare_property_null(pacos_models_serviceinstancelist_ce, SL("lastRefTime"), ZEND_ACC_PUBLIC);

	/**
	 * @var string
	 */
	zend_declare_property_null(pacos_models_serviceinstancelist_ce, SL("env"), ZEND_ACC_PUBLIC);

	/**
	 * @var string
	 */
	zend_declare_property_null(pacos_models_serviceinstancelist_ce, SL("clusters"), ZEND_ACC_PUBLIC);

	pacos_models_serviceinstancelist_ce->create_object = zephir_init_properties_Pacos_Models_ServiceInstanceList;
	return SUCCESS;

}

/**
 * __construct 
 *
 * @param data
 *
 * @return 
 */
PHP_METHOD(Pacos_Models_ServiceInstanceList, __construct) {

	zend_string *_9;
	zend_ulong _8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, host, key, value, *_6, _7, _0$$4, *_1$$4, _2$$4, _3$$5, _5$$6, _10$$7, _12$$9;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_12$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data_param);

	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
		zephir_get_arrval(&data, data_param);
	}


	if (ZEPHIR_IS_EMPTY(&data)) {
		RETURN_MM_NULL();
	}
	if (zephir_array_isset_string(&data, SL("hosts"))) {
		zephir_array_fetch_string(&_0$$4, &data, SL("hosts"), PH_NOISY | PH_READONLY, "pacos/Models/ServiceInstanceList.zep", 71);
		zephir_is_iterable(&_0$$4, 0, "pacos/Models/ServiceInstanceList.zep", 74);
		if (Z_TYPE_P(&_0$$4) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0$$4), _1$$4)
			{
				ZEPHIR_INIT_NVAR(&host);
				ZVAL_COPY(&host, _1$$4);
				ZEPHIR_INIT_NVAR(&_3$$5);
				object_init_ex(&_3$$5, pacos_models_serviceinstance_ce);
				ZEPHIR_CALL_METHOD(NULL, &_3$$5, "__construct", &_4, 15, &host);
				zephir_check_call_status();
				zephir_update_property_array_append(this_ptr, SL("hosts"), &_3$$5);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_0$$4, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_2$$4, &_0$$4, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_2$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&host, &_0$$4, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_5$$6);
					object_init_ex(&_5$$6, pacos_models_serviceinstance_ce);
					ZEPHIR_CALL_METHOD(NULL, &_5$$6, "__construct", &_4, 15, &host);
					zephir_check_call_status();
					zephir_update_property_array_append(this_ptr, SL("hosts"), &_5$$6);
				ZEPHIR_CALL_METHOD(NULL, &_0$$4, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&host);
		zephir_array_unset_string(&data, SL("hosts"), PH_SEPARATE);
	}
	zephir_is_iterable(&data, 0, "pacos/Models/ServiceInstanceList.zep", 82);
	if (Z_TYPE_P(&data) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _8, _9, _6)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_9 != NULL) { 
				ZVAL_STR_COPY(&key, _9);
			} else {
				ZVAL_LONG(&key, _8);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _6);
			ZEPHIR_CALL_FUNCTION(&_10$$7, "property_exists", &_11, 1, this_ptr, &key);
			zephir_check_call_status();
			if (zephir_is_true(&_10$$7)) {
				zephir_update_property_zval_zval(this_ptr, &key, &value);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_7, &data, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &data, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &data, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_12$$9, "property_exists", &_11, 1, this_ptr, &key);
				zephir_check_call_status();
				if (zephir_is_true(&_12$$9)) {
					zephir_update_property_zval_zval(this_ptr, &key, &value);
				}
			ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Pacos_Models_ServiceInstanceList(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("hosts"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("hosts"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("metadata"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("metadata"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

