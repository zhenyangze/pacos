
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
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"


/**
 * ServiceInstance
 */
ZEPHIR_INIT_CLASS(Pacos_Models_ServiceInstance) {

	ZEPHIR_REGISTER_CLASS(Pacos\\Models, ServiceInstance, pacos, models_serviceinstance, pacos_models_serviceinstance_method_entry, 0);

	/**
	 * 服务名，不能为空
	 * @var string
	 */
	zend_declare_property_null(pacos_models_serviceinstance_ce, SL("serviceName"), ZEND_ACC_PUBLIC);

	/**
	 * 服务实例 IP，不能为空
	 * @var string
	 */
	zend_declare_property_null(pacos_models_serviceinstance_ce, SL("ip"), ZEND_ACC_PUBLIC);

	/**
	 * 服务实例 port，不能为空
	 * @var int
	 */
	zend_declare_property_null(pacos_models_serviceinstance_ce, SL("port"), ZEND_ACC_PUBLIC);

	/**
	 * 命名空间ID
	 * @var string
	 */
	zend_declare_property_null(pacos_models_serviceinstance_ce, SL("namespaceId"), ZEND_ACC_PUBLIC);

	/**
	 * 权重
	 * @var double
	 */
	zend_declare_property_long(pacos_models_serviceinstance_ce, SL("weight"), 0, ZEND_ACC_PUBLIC);

	/**
	 * 是否健康
	 * @var boolean
	 */
	zend_declare_property_null(pacos_models_serviceinstance_ce, SL("healthy"), ZEND_ACC_PUBLIC);

	/**
	 * 是否上线
	 * @var boolean
	 */
	zend_declare_property_null(pacos_models_serviceinstance_ce, SL("enable"), ZEND_ACC_PUBLIC);

	/**
	 * 扩展信息
	 * @var array
	 */
	zend_declare_property_null(pacos_models_serviceinstance_ce, SL("metadata"), ZEND_ACC_PUBLIC);

	/**
	 * 集群名
	 * @var string
	 */
	zend_declare_property_null(pacos_models_serviceinstance_ce, SL("clusterName"), ZEND_ACC_PUBLIC);

	/**
	 * 是否临时实例 否
	 * @var string
	 */
	zend_declare_property_bool(pacos_models_serviceinstance_ce, SL("ephemeral"), 0, ZEND_ACC_PUBLIC);

	/**
	 * @var bool
	 */
	zend_declare_property_null(pacos_models_serviceinstance_ce, SL("marked"), ZEND_ACC_PUBLIC);

	/**
	 * @var bool
	 */
	zend_declare_property_null(pacos_models_serviceinstance_ce, SL("valid"), ZEND_ACC_PUBLIC);

	/**
	 * @var string
	 */
	zend_declare_property_null(pacos_models_serviceinstance_ce, SL("instanceId"), ZEND_ACC_PUBLIC);

	/**
	 * @var healthyOnly
	 */
	zend_declare_property_bool(pacos_models_serviceinstance_ce, SL("healthyOnly"), 0, ZEND_ACC_PUBLIC);

	return SUCCESS;

}

/**
 * __construct 
 *
 * @param info
 *
 * @return 
 */
PHP_METHOD(Pacos_Models_ServiceInstance, __construct) {

	zend_string *_7;
	zend_ulong _6;
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *info_param = NULL, metadata, key, value, _1, *_4, _5, _2$$3, _3$$3, _8$$5, _10$$7;
	zval info;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&info);
	ZVAL_UNDEF(&metadata);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_10$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &info_param);

	if (!info_param) {
		ZEPHIR_INIT_VAR(&info);
		array_init(&info);
	} else {
		zephir_get_arrval(&info, info_param);
	}


	ZEPHIR_INIT_VAR(&metadata);
	array_init(&metadata);
	_0 = zephir_array_isset_string(&info, SL("metadata"));
	if (_0) {
		zephir_array_fetch_string(&_1, &info, SL("metadata"), PH_NOISY | PH_READONLY, "pacos/Models/ServiceInstance.zep", 102);
		_0 = Z_TYPE_P(&_1) == IS_STRING;
	}
	if (_0) {
		zephir_array_fetch_string(&_2$$3, &info, SL("metadata"), PH_NOISY | PH_READONLY, "pacos/Models/ServiceInstance.zep", 103);
		ZVAL_LONG(&_3$$3, 1);
		ZEPHIR_INIT_NVAR(&metadata);
		zephir_json_decode(&metadata, &_2$$3, zephir_get_intval(&_3$$3) );
		if (zephir_is_true(&metadata)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("metadata"), &metadata);
		}
		zephir_array_unset_string(&info, SL("metadata"), PH_SEPARATE);
	}
	zephir_is_iterable(&info, 0, "pacos/Models/ServiceInstance.zep", 115);
	if (Z_TYPE_P(&info) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&info), _6, _7, _4)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_7 != NULL) { 
				ZVAL_STR_COPY(&key, _7);
			} else {
				ZVAL_LONG(&key, _6);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _4);
			ZEPHIR_CALL_FUNCTION(&_8$$5, "property_exists", &_9, 1, this_ptr, &key);
			zephir_check_call_status();
			if (zephir_is_true(&_8$$5)) {
				zephir_update_property_zval_zval(this_ptr, &key, &value);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &info, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_5, &info, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &info, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &info, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_10$$7, "property_exists", &_9, 1, this_ptr, &key);
				zephir_check_call_status();
				if (zephir_is_true(&_10$$7)) {
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

/**
 * validate 
 *
 * @return 
 */
PHP_METHOD(Pacos_Models_ServiceInstance, validate) {

	zval _0, _1, _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("ip"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "ip");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "assertnotnull", &_2, 0, &_1, &_0);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("port"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "port");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "assertnotnull", &_2, 0, &_1, &_3);
	zephir_check_call_status();
	zephir_read_property(&_4, this_ptr, ZEND_STRL("serviceName"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "serviceName");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "assertnotnull", &_2, 0, &_1, &_4);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * assertNotNull 
 *
 * @param name
 * @param value
 *
 * @return 
 */
PHP_METHOD(Pacos_Models_ServiceInstance, assertNotNull) {

	zval *name, name_sub, *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&value_sub);

	zephir_fetch_params_without_memory_grow(2, 0, &name, &value);



	if (Z_TYPE_P(value) == IS_NULL) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(pacos_exceptions_pacosexception_ce, "ServiceInstance `{name}` cannot be null", "pacos/Models/ServiceInstance.zep", 140);
		return;
	}

}

/**
 * toCreateParams 
 *
 * @return 
 */
PHP_METHOD(Pacos_Models_ServiceInstance, toCreateParams) {

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
	zephir_create_array(&_0, 10, 0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("serviceName"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("serviceName"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("ip"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("ip"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("port"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("port"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("namespaceId"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("namespaceId"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getweightdouble", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("weight"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("enable"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("enable"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("healthy"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("healthy"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("ephemeral"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("ephemeral"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getmetadatajson", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("metadata"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("clusterName"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("clusterName"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "filter", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * toDeleteParams 
 *
 * @return 
 */
PHP_METHOD(Pacos_Models_ServiceInstance, toDeleteParams) {

	zval _1;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 5, 0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("serviceName"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("serviceName"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("ip"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("ip"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("port"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("port"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("clusterName"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("clusterName"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("namespaceId"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("namespaceId"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "filter", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * toBeatParams 
 *
 * @return 
 */
PHP_METHOD(Pacos_Models_ServiceInstance, toBeatParams) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval __$true, _1;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 7, 0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("clusterName"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("cluster"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("ip"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("ip"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("metadata"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("metadata"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("port"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("port"), &_1, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("scheduled"), &__$true, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("serviceName"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("serviceName"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("weight"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("weight"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "filter", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * toGetParams 
 *
 * @return 
 */
PHP_METHOD(Pacos_Models_ServiceInstance, toGetParams) {

	zval _1;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 7, 0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("serviceName"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("serviceName"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("ip"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("ip"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("port"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("port"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("namespaceId"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("namespaceId"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("enable"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("enable"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("healthyOnly"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("healthyOnly"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("clusterName"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("cluster"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "filter", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * toUpdateParams 
 *
 * @return 
 */
PHP_METHOD(Pacos_Models_ServiceInstance, toUpdateParams) {

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
	zephir_create_array(&_0, 9, 0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("serviceName"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("serviceName"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("ip"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("ip"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("port"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("port"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("namespaceId"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("namespaceId"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getweightdouble", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("weight"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("enable"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("enable"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("healthy"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("healthy"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getmetadatajson", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("metadata"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("clusterName"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("clusterName"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "filter", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * getMetadataJson 
 *
 * @return 
 */
PHP_METHOD(Pacos_Models_ServiceInstance, getMetadataJson) {

	zval _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("metadata"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_1)) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("metadata"), PH_NOISY_CC | PH_READONLY);
		zephir_json_encode(&_0, &_2, 0 );
	} else {
		ZVAL_NULL(&_0);
	}
	RETURN_CCTOR(&_0);

}

/**
 * getWeightDouble 
 *
 * @return 
 */
PHP_METHOD(Pacos_Models_ServiceInstance, getWeightDouble) {

	zval _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("weight"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_1)) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("weight"), PH_NOISY_CC | PH_READONLY);
		ZVAL_DOUBLE(&_0, zephir_get_doubleval(&_2));
	} else {
		ZVAL_LONG(&_0, 0);
	}
	RETURN_CCTOR(&_0);

}

/**
 * filter 
 *
 * @param array
 *
 * @return 
 */
PHP_METHOD(Pacos_Models_ServiceInstance, filter) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, _0;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_arrval(&data, data_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, pacos_1__closure_ce, SL("__invoke"));
	ZEPHIR_RETURN_CALL_FUNCTION("array_filter", NULL, 17, &data, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

