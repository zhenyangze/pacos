
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/main.h"


/**
 * Instance
 */
ZEPHIR_INIT_CLASS(Pacos_Instance) {

	ZEPHIR_REGISTER_CLASS_EX(Pacos, Instance, pacos, instance, pacos_client_ce, pacos_instance_method_entry, 0);

	return SUCCESS;

}

/**
 * 注册一个实例到服务
 * @param ServiceInstance instance
 * @return boolean
 */
PHP_METHOD(Pacos_Instance, add) {

	zval _4;
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *instance, instance_sub, newInstance, _0, _2, resp, _5, _6, _7, _3$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&instance_sub);
	ZVAL_UNDEF(&newInstance);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&resp);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &instance);



	if (Z_TYPE_P(instance) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&newInstance);
		object_init_ex(&newInstance, pacos_models_serviceinstance_ce);
		ZEPHIR_CALL_METHOD(NULL, &newInstance, "__construct", NULL, 10, instance);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&newInstance, instance);
	}
	zephir_read_property(&_0, &newInstance, ZEND_STRL("namespaceId"), PH_NOISY_CC | PH_READONLY);
	_1 = Z_TYPE_P(&_0) == IS_NULL;
	if (_1) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("_namespace"), PH_NOISY_CC | PH_READONLY);
		_1 = Z_TYPE_P(&_2) != IS_NULL;
	}
	if (_1) {
		zephir_read_property(&_3$$5, this_ptr, ZEND_STRL("_namespace"), PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval(&newInstance, ZEND_STRL("namespaceId"), &_3$$5);
	}
	ZEPHIR_CALL_METHOD(NULL, &newInstance, "validate", NULL, 11);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 1, 0);
	ZEPHIR_CALL_METHOD(&_5, &newInstance, "tocreateparams", NULL, 12);
	zephir_check_call_status();
	zephir_array_update_string(&_4, SL("form_params"), &_5, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "POST");
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "/nacos/v1/ns/instance");
	ZEPHIR_CALL_METHOD(&resp, this_ptr, "request", NULL, 0, &_6, &_7, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_6);
	ZVAL_STRING(&_6, "ok");
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_STRING(&_7, "Client create service instance fail");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "assertresponse", NULL, 0, &resp, &_6, &_7);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);

}

/**
 * 删除服务下的一个实例
 * @param string serviceName
 * @param string ip
 * @param int port
 * @param string|null clusterName
 * @param string|null namespaceId
 * @return boolean
 */
PHP_METHOD(Pacos_Instance, delete) {

	zval _2, _4;
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long port, ZEPHIR_LAST_CALL_STATUS;
	zval *serviceName_param = NULL, *ip_param = NULL, *port_param = NULL, *clusterName_param = NULL, *namespaceId_param = NULL, newNamespace, _1, instance, _3, resp, _5, _6;
	zval serviceName, ip, clusterName, namespaceId;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serviceName);
	ZVAL_UNDEF(&ip);
	ZVAL_UNDEF(&clusterName);
	ZVAL_UNDEF(&namespaceId);
	ZVAL_UNDEF(&newNamespace);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&resp);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 2, &serviceName_param, &ip_param, &port_param, &clusterName_param, &namespaceId_param);

	zephir_get_strval(&serviceName, serviceName_param);
	zephir_get_strval(&ip, ip_param);
	port = zephir_get_intval(port_param);
	if (!clusterName_param) {
		ZEPHIR_INIT_VAR(&clusterName);
		ZVAL_STRING(&clusterName, "");
	} else {
		zephir_get_strval(&clusterName, clusterName_param);
	}
	if (!namespaceId_param) {
		ZEPHIR_INIT_VAR(&namespaceId);
		ZVAL_STRING(&namespaceId, "");
	} else {
		zephir_get_strval(&namespaceId, namespaceId_param);
	}


	ZEPHIR_INIT_VAR(&newNamespace);
	ZVAL_NULL(&newNamespace);
	_0 = ZEPHIR_IS_STRING(&namespaceId, "");
	if (_0) {
		zephir_read_property(&_1, this_ptr, ZEND_STRL("_namespace"), PH_NOISY_CC | PH_READONLY);
		_0 = Z_TYPE_P(&_1) != IS_NULL;
	}
	if (_0) {
		ZEPHIR_OBS_NVAR(&newNamespace);
		zephir_read_property(&newNamespace, this_ptr, ZEND_STRL("_namespace"), PH_NOISY_CC);
	} else {
		ZEPHIR_CPY_WRT(&newNamespace, &namespaceId);
	}
	ZEPHIR_INIT_VAR(&instance);
	object_init_ex(&instance, pacos_models_serviceinstance_ce);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 5, 0);
	zephir_array_update_string(&_2, SL("serviceName"), &serviceName, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_2, SL("ip"), &ip, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_LONG(&_3, port);
	zephir_array_update_string(&_2, SL("port"), &_3, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_2, SL("clusterName"), &clusterName, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_2, SL("namespaceId"), &newNamespace, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, &instance, "__construct", NULL, 10, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 1, 0);
	ZEPHIR_CALL_METHOD(&_5, &instance, "todeleteparams", NULL, 13);
	zephir_check_call_status();
	zephir_array_update_string(&_4, SL("query"), &_5, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "DELETE");
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "/nacos/v1/ns/instance");
	ZEPHIR_CALL_METHOD(&resp, this_ptr, "request", NULL, 0, &_3, &_6, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "ok");
	ZEPHIR_INIT_NVAR(&_6);
	ZVAL_STRING(&_6, "Client delete service instance fail");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "assertresponse", NULL, 0, &resp, &_3, &_6);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);

}

/**
 * update 
 *
 * @param instance
 *
 * @return 
 */
PHP_METHOD(Pacos_Instance, update) {

	zval _4;
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *instance, instance_sub, newInstance, _0, _2, resp, _5, _6, _7, _3$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&instance_sub);
	ZVAL_UNDEF(&newInstance);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&resp);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &instance);



	if (Z_TYPE_P(instance) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&newInstance);
		object_init_ex(&newInstance, pacos_models_serviceinstance_ce);
		ZEPHIR_CALL_METHOD(NULL, &newInstance, "__construct", NULL, 10, instance);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&newInstance, instance);
	}
	zephir_read_property(&_0, &newInstance, ZEND_STRL("namespaceId"), PH_NOISY_CC | PH_READONLY);
	_1 = Z_TYPE_P(&_0) == IS_NULL;
	if (_1) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("_namespace"), PH_NOISY_CC | PH_READONLY);
		_1 = Z_TYPE_P(&_2) != IS_NULL;
	}
	if (_1) {
		zephir_read_property(&_3$$5, this_ptr, ZEND_STRL("_namespace"), PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval(&newInstance, ZEND_STRL("namespaceId"), &_3$$5);
	}
	ZEPHIR_CALL_METHOD(NULL, &newInstance, "validate", NULL, 11);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 1, 0);
	ZEPHIR_CALL_METHOD(&_5, &newInstance, "toupdateparams", NULL, 14);
	zephir_check_call_status();
	zephir_array_update_string(&_4, SL("form_params"), &_5, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "PUT");
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "/nacos/v1/ns/instance");
	ZEPHIR_CALL_METHOD(&resp, this_ptr, "request", NULL, 0, &_6, &_7, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_6);
	ZVAL_STRING(&_6, "ok");
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_STRING(&_7, "Client update service instance fail");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "assertresponse", NULL, 0, &resp, &_6, &_7);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);

}

/**
 * 查询服务下的实例列表
 *
 * @param string serviceName      服务名
 * @param string|null namespaceId 命名空间ID
 * @param string[] clusters       集群名称
 * @return ServiceInstanceList
 */
PHP_METHOD(Pacos_Instance, list) {

	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval clusters, _2, _3;
	zval *serviceName_param = NULL, *namespaceId_param = NULL, *clusters_param = NULL, __$false, newNamespace, _1, clusterStr, query, resp, _4, _5, data, _8, _6$$5, _7$$5, _9$$7, _10$$7, _11$$7;
	zval serviceName, namespaceId;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serviceName);
	ZVAL_UNDEF(&namespaceId);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&newNamespace);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&clusterStr);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&resp);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&clusters);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &serviceName_param, &namespaceId_param, &clusters_param);

	zephir_get_strval(&serviceName, serviceName_param);
	if (!namespaceId_param) {
		ZEPHIR_INIT_VAR(&namespaceId);
		ZVAL_STRING(&namespaceId, "");
	} else {
		zephir_get_strval(&namespaceId, namespaceId_param);
	}
	if (!clusters_param) {
		ZEPHIR_INIT_VAR(&clusters);
		array_init(&clusters);
	} else {
		zephir_get_arrval(&clusters, clusters_param);
	}


	ZEPHIR_INIT_VAR(&newNamespace);
	ZVAL_NULL(&newNamespace);
	_0 = ZEPHIR_IS_STRING(&namespaceId, "");
	if (_0) {
		zephir_read_property(&_1, this_ptr, ZEND_STRL("_namespace"), PH_NOISY_CC | PH_READONLY);
		_0 = Z_TYPE_P(&_1) != IS_NULL;
	}
	if (_0) {
		ZEPHIR_OBS_NVAR(&newNamespace);
		zephir_read_property(&newNamespace, this_ptr, ZEND_STRL("_namespace"), PH_NOISY_CC);
	} else {
		ZEPHIR_CPY_WRT(&newNamespace, &namespaceId);
	}
	ZEPHIR_INIT_VAR(&clusterStr);
	zephir_fast_join_str(&clusterStr, SL(","), &clusters);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 4, 0);
	zephir_array_update_string(&_2, SL("serviceName"), &serviceName, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_2, SL("namespaceId"), &newNamespace, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_2, SL("clusters"), &clusterStr, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(&_2, SL("healthyOnly"), SL("true"));
	ZEPHIR_CALL_FUNCTION(&query, "array_filter", NULL, 15, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 2, 0);
	zephir_array_update_string(&_3, SL("http_errors"), &__$false, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_3, SL("query"), &query, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "GET");
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "/nacos/v1/ns/instance/list");
	ZEPHIR_CALL_METHOD(&resp, this_ptr, "request", NULL, 0, &_4, &_5, &_3);
	zephir_check_call_status();

	/* try_start_1: */

		ZEPHIR_CALL_METHOD(&_6$$5, &resp, "getbody", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		ZVAL_LONG(&_7$$5, 1);
		ZEPHIR_INIT_VAR(&data);
		zephir_json_decode(&data, &_6$$5, zephir_get_intval(&_7$$5) );

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_NVAR(&_4);
		ZVAL_OBJ(&_4, EG(exception));
		Z_ADDREF_P(&_4);
		ZEPHIR_INIT_NVAR(&_5);
		if (zephir_instance_of_ev(&_4, zend_exception_get_default(TSRMLS_C))) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&_5, &_4);
			ZEPHIR_INIT_NVAR(&data);
			array_init(&data);
		}
	}
	ZEPHIR_CALL_METHOD(&_8, &resp, "getstatuscode", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG_IDENTICAL(&_8, 404)) {
		ZEPHIR_INIT_VAR(&_9$$7);
		object_init_ex(&_9$$7, pacos_exceptions_pacosnamingnotfound_ce);
		ZEPHIR_INIT_VAR(&_10$$7);
		ZVAL_STRING(&_10$$7, "service not found: serviceName");
		ZVAL_LONG(&_11$$7, 404);
		ZEPHIR_CALL_METHOD(NULL, &_9$$7, "__construct", NULL, 7, &_10$$7, &_11$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_9$$7, "pacos/Instance.zep", 149);
		ZEPHIR_MM_RESTORE();
		return;
	}
	object_init_ex(return_value, pacos_models_serviceinstancelist_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 16, &data);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 查询一个服务下个某个实例详情
 *
 * @param string serviceName      服务名
 * @param string ip               实例IP
 * @param int port                实例端口
 * @param string|null namespaceId 命名空间 id
 * @param string|null cluster     集群名称
 * @param bool healthyOnly        是否只返回健康实例
 * @return ServiceInstance
 */
PHP_METHOD(Pacos_Instance, get) {

	zval _2, _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_bool healthyOnly, _0;
	zend_long port, ZEPHIR_LAST_CALL_STATUS;
	zval *serviceName_param = NULL, *ip_param = NULL, *port_param = NULL, *namespaceId_param = NULL, *cluster_param = NULL, *healthyOnly_param = NULL, newNamespace, _1, instance, _3, query, resp, _6, data, _9, _7$$5, _8$$5;
	zval serviceName, ip, namespaceId, cluster;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serviceName);
	ZVAL_UNDEF(&ip);
	ZVAL_UNDEF(&namespaceId);
	ZVAL_UNDEF(&cluster);
	ZVAL_UNDEF(&newNamespace);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&resp);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 3, &serviceName_param, &ip_param, &port_param, &namespaceId_param, &cluster_param, &healthyOnly_param);

	zephir_get_strval(&serviceName, serviceName_param);
	zephir_get_strval(&ip, ip_param);
	port = zephir_get_intval(port_param);
	if (!namespaceId_param) {
		ZEPHIR_INIT_VAR(&namespaceId);
		ZVAL_STRING(&namespaceId, "");
	} else {
		zephir_get_strval(&namespaceId, namespaceId_param);
	}
	if (!cluster_param) {
		ZEPHIR_INIT_VAR(&cluster);
		ZVAL_STRING(&cluster, "");
	} else {
		zephir_get_strval(&cluster, cluster_param);
	}
	if (!healthyOnly_param) {
		healthyOnly = 0;
	} else {
		healthyOnly = zephir_get_boolval(healthyOnly_param);
	}


	ZEPHIR_INIT_VAR(&newNamespace);
	ZVAL_NULL(&newNamespace);
	_0 = ZEPHIR_IS_STRING(&namespaceId, "");
	if (_0) {
		zephir_read_property(&_1, this_ptr, ZEND_STRL("_namespace"), PH_NOISY_CC | PH_READONLY);
		_0 = Z_TYPE_P(&_1) != IS_NULL;
	}
	if (_0) {
		ZEPHIR_OBS_NVAR(&newNamespace);
		zephir_read_property(&newNamespace, this_ptr, ZEND_STRL("_namespace"), PH_NOISY_CC);
	} else {
		ZEPHIR_CPY_WRT(&newNamespace, &namespaceId);
	}
	ZEPHIR_INIT_VAR(&instance);
	object_init_ex(&instance, pacos_models_serviceinstance_ce);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 6, 0);
	zephir_array_update_string(&_2, SL("serviceName"), &serviceName, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_2, SL("ip"), &ip, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_LONG(&_3, port);
	zephir_array_update_string(&_2, SL("port"), &_3, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_2, SL("clusterName"), &cluster, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_2, SL("namespaceId"), &newNamespace, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_BOOL(&_3, healthyOnly);
	zephir_array_update_string(&_2, SL("healthyOnly"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, &instance, "__construct", &_4, 10, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&query, &instance, "togetparams", NULL, 17);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 1, 0);
	zephir_array_update_string(&_5, SL("query"), &query, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "GET");
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "/nacos/v1/ns/instance");
	ZEPHIR_CALL_METHOD(&resp, this_ptr, "request", NULL, 0, &_3, &_6, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&data);
	array_init(&data);

	/* try_start_1: */

		ZEPHIR_CALL_METHOD(&_7$$5, &resp, "getbody", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		ZVAL_LONG(&_8$$5, 1);
		ZEPHIR_INIT_NVAR(&data);
		zephir_json_decode(&data, &_7$$5, zephir_get_intval(&_8$$5) );

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_NVAR(&_3);
		ZVAL_OBJ(&_3, EG(exception));
		Z_ADDREF_P(&_3);
		ZEPHIR_INIT_NVAR(&_6);
		if (zephir_instance_of_ev(&_3, zend_exception_get_default(TSRMLS_C))) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&_6, &_3);
			ZEPHIR_INIT_NVAR(&data);
			array_init(&data);
		}
	}
	zephir_array_fetch_string(&_9, &data, SL("service"), PH_NOISY | PH_READONLY, "pacos/Instance.zep", 199);
	zephir_array_update_string(&data, SL("serviceName"), &_9, PH_COPY | PH_SEPARATE);
	object_init_ex(return_value, pacos_models_serviceinstance_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", &_4, 10, &data);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 发送实例心跳
 * @param BeatInfo beat
 * @return BeatResult
 */
PHP_METHOD(Pacos_Instance, beat) {

	zval _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *beat, beat_sub, newBeat, serviceName, _0, formParams, _1, _2, _3, resp, _6, ret, result, _9, _4$$5, _7$$6, _8$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&beat_sub);
	ZVAL_UNDEF(&newBeat);
	ZVAL_UNDEF(&serviceName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&formParams);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&resp);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&ret);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &beat);



	if (Z_TYPE_P(beat) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&newBeat);
		object_init_ex(&newBeat, pacos_models_beatinfo_ce);
		ZEPHIR_CALL_METHOD(NULL, &newBeat, "__construct", NULL, 18, beat);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&newBeat, beat);
	}
	zephir_read_property(&_0, &newBeat, ZEND_STRL("serviceName"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&serviceName, &_0);
	ZEPHIR_INIT_VAR(&formParams);
	array_init(&formParams);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0);
	zephir_array_update_string(&_1, SL("serviceName"), &serviceName, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_2);
	zephir_json_encode(&_2, &newBeat, 0 );
	zephir_array_update_string(&_1, SL("beat"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_CPY_WRT(&formParams, &_1);
	ZEPHIR_OBS_VAR(&_3);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("_namespace"), PH_NOISY_CC);
	if (!(ZEPHIR_IS_EMPTY(&_3))) {
		zephir_read_property(&_4$$5, this_ptr, ZEND_STRL("_namespace"), PH_NOISY_CC | PH_READONLY);
		zephir_array_update_string(&formParams, SL("namespaceId"), &_4$$5, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 1, 0);
	zephir_array_update_string(&_5, SL("form_params"), &formParams, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "PUT");
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "/nacos/v1/ns/instance/beat");
	ZEPHIR_CALL_METHOD(&resp, this_ptr, "request", NULL, 0, &_2, &_6, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&ret);
	array_init(&ret);

	/* try_start_1: */

		ZEPHIR_CALL_METHOD(&_7$$6, &resp, "getbody", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		ZVAL_LONG(&_8$$6, 1);
		ZEPHIR_INIT_NVAR(&ret);
		zephir_json_decode(&ret, &_7$$6, zephir_get_intval(&_8$$6) );

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_NVAR(&_2);
		ZVAL_OBJ(&_2, EG(exception));
		Z_ADDREF_P(&_2);
		ZEPHIR_INIT_NVAR(&_6);
		if (zephir_instance_of_ev(&_2, zend_exception_get_default(TSRMLS_C))) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&_6, &_2);
			ZEPHIR_INIT_NVAR(&ret);
			array_init(&ret);
		}
	}
	ZEPHIR_INIT_VAR(&result);
	object_init_ex(&result, pacos_models_beatresult_ce);
	if (zephir_has_constructor(&result)) {
		ZEPHIR_CALL_METHOD(NULL, &result, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_array_fetch_string(&_9, &ret, SL("clientBeatInterval"), PH_NOISY | PH_READONLY, "pacos/Instance.zep", 240);
	zephir_update_property_zval(&result, ZEND_STRL("clientBeatInterval"), &_9);
	RETURN_CCTOR(&result);

}

/**
 * select 
 *
 * @param serviceName
 * @param namespaceId
 *
 * @return 
 */
PHP_METHOD(Pacos_Instance, select) {

	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *serviceName_param = NULL, *namespaceId_param = NULL, newNamespace, _1, list, _2, _4;
	zval serviceName, namespaceId;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serviceName);
	ZVAL_UNDEF(&namespaceId);
	ZVAL_UNDEF(&newNamespace);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&list);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &serviceName_param, &namespaceId_param);

	zephir_get_strval(&serviceName, serviceName_param);
	if (!namespaceId_param) {
		ZEPHIR_INIT_VAR(&namespaceId);
		ZVAL_STRING(&namespaceId, "");
	} else {
		zephir_get_strval(&namespaceId, namespaceId_param);
	}


	ZEPHIR_INIT_VAR(&newNamespace);
	ZVAL_NULL(&newNamespace);
	_0 = ZEPHIR_IS_STRING(&namespaceId, "");
	if (_0) {
		zephir_read_property(&_1, this_ptr, ZEND_STRL("_namespace"), PH_NOISY_CC | PH_READONLY);
		_0 = Z_TYPE_P(&_1) != IS_NULL;
	}
	if (_0) {
		ZEPHIR_OBS_NVAR(&newNamespace);
		zephir_read_property(&newNamespace, this_ptr, ZEND_STRL("_namespace"), PH_NOISY_CC);
	} else {
		ZEPHIR_CPY_WRT(&newNamespace, &namespaceId);
	}
	ZEPHIR_CALL_METHOD(&list, this_ptr, "list", NULL, 0, &serviceName, &newNamespace);
	zephir_check_call_status();
	zephir_read_property(&_2, &list, ZEND_STRL("hosts"), PH_NOISY_CC | PH_READONLY);
	if (zephir_fast_count_int(&_2) == 0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(pacos_exceptions_pacosnamingnoaliveinstance_ce, "serviceName no alive instnace", "pacos/Instance.zep", 264);
		return;
	}
	zephir_read_property(&_4, &list, ZEND_STRL("hosts"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_CE_STATIC(pacos_utils_selector_ce, "randombyweight", &_3, 0, &_4);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * call 
 *
 * @param serviceName
 * @param method
 * @param uri
 * @param options
 * @param namespaceId
 * @param Unknown
 *
 * @return 
 */
PHP_METHOD(Pacos_Instance, call) {

	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *serviceName_param = NULL, *method_param = NULL, *uri_param = NULL, *options_param = NULL, *namespaceId_param = NULL, newNamespace, _1, instance, ip, _2, port, url, _3;
	zval serviceName, method, uri, namespaceId;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serviceName);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&namespaceId);
	ZVAL_UNDEF(&newNamespace);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&ip);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&port);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 2, &serviceName_param, &method_param, &uri_param, &options_param, &namespaceId_param);

	zephir_get_strval(&serviceName, serviceName_param);
	zephir_get_strval(&method, method_param);
	zephir_get_strval(&uri, uri_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	if (!namespaceId_param) {
		ZEPHIR_INIT_VAR(&namespaceId);
		ZVAL_STRING(&namespaceId, "");
	} else {
		zephir_get_strval(&namespaceId, namespaceId_param);
	}


	ZEPHIR_INIT_VAR(&newNamespace);
	ZVAL_NULL(&newNamespace);
	_0 = ZEPHIR_IS_STRING(&namespaceId, "");
	if (_0) {
		zephir_read_property(&_1, this_ptr, ZEND_STRL("_namespace"), PH_NOISY_CC | PH_READONLY);
		_0 = Z_TYPE_P(&_1) != IS_NULL;
	}
	if (_0) {
		ZEPHIR_OBS_NVAR(&newNamespace);
		zephir_read_property(&newNamespace, this_ptr, ZEND_STRL("_namespace"), PH_NOISY_CC);
	} else {
		ZEPHIR_CPY_WRT(&newNamespace, &namespaceId);
	}
	ZEPHIR_CALL_METHOD(&instance, this_ptr, "select", NULL, 0, &serviceName, &newNamespace);
	zephir_check_call_status();
	zephir_read_property(&_2, &instance, ZEND_STRL("ip"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&ip, &_2);
	zephir_read_property(&_2, &instance, ZEND_STRL("port"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&port, &_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "http://%s:%s%s");
	ZEPHIR_CALL_FUNCTION(&url, "sprintf", NULL, 4, &_3, &ip, &port, &uri);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "request", NULL, 0, &method, &url, &options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * cleanRegister 
 *
 * @return 
 */
PHP_METHOD(Pacos_Instance, cleanRegister) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *info_param = NULL, shmId, _0, _1, _2, _3, infoLength, _4, _5;
	zval info;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&info);
	ZVAL_UNDEF(&shmId);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&infoLength);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &info_param);

	if (!info_param) {
		ZEPHIR_INIT_VAR(&info);
		ZVAL_STRING(&info, "");
	} else {
		zephir_get_strval(&info, info_param);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("shmKey"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("defaultMode"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("shmSize"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "c");
	ZEPHIR_CALL_FUNCTION(&shmId, "shmop_open", NULL, 19, &_0, &_3, &_1, &_2);
	zephir_check_call_status();
	if (!(zephir_is_true(&shmId))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "open memory failed", "pacos/Instance.zep", 309);
		return;
	}
	ZEPHIR_INIT_VAR(&infoLength);
	ZVAL_LONG(&infoLength, zephir_fast_strlen_ev(&info));
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "%010s%s");
	ZVAL_LONG(&_4, (zephir_get_numberval(&infoLength) + 10));
	ZEPHIR_CALL_FUNCTION(&_5, "sprintf", NULL, 4, &_3, &_4, &info);
	zephir_check_call_status();
	ZVAL_LONG(&_4, 0);
	ZEPHIR_CALL_FUNCTION(NULL, "shmop_write", NULL, 20, &shmId, &_5, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "shmop_close", NULL, 21, &shmId);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * register 
 *
 * @param uniqueName
 * @param instanceList
 * @param timeout
 * @param remote
 *
 * @return 
 */
PHP_METHOD(Pacos_Instance, register) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_0 = NULL, *_30 = NULL;
	zend_long timeout, ZEPHIR_LAST_CALL_STATUS;
	zval instanceList, _24, _25;
	zval *uniqueName_param = NULL, *instanceList_param = NULL, *timeout_param = NULL, *remote_param = NULL, __$true, _1, _2, _3, _4, _5, shmId, _9, _10, _11, data, _12, _13, shmopLengthStr, shmopLength, _14, subData, _16, _17, _18, dataArr, _20, _21, _22, _23, _26, jsonData, _27, _28, _29, _31, _32, _6$$3, _7$$3, _8$$3;
	zval uniqueName, remote, _15, _19;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uniqueName);
	ZVAL_UNDEF(&remote);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_19);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&shmId);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&shmopLengthStr);
	ZVAL_UNDEF(&shmopLength);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&subData);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&dataArr);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&jsonData);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&instanceList);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_25);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &uniqueName_param, &instanceList_param, &timeout_param, &remote_param);

	zephir_get_strval(&uniqueName, uniqueName_param);
	zephir_get_arrval(&instanceList, instanceList_param);
	if (!timeout_param) {
		timeout = 300;
	} else {
		timeout = zephir_get_intval(timeout_param);
	}
	if (!remote_param) {
		ZEPHIR_INIT_VAR(&remote);
		ZVAL_STRING(&remote, "localhost");
	} else {
		zephir_get_strval(&remote, remote_param);
	}


	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	zephir_get_args(&_2);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("debug"), PH_NOISY_CC | PH_READONLY);
	zephir_json_encode(&_1, &_2, zephir_get_intval(&_3) );
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "instance.register:");
	ZEPHIR_CALL_CE_STATIC(NULL, pacos_utils_logs_ce, "log", &_0, 0, &_4, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "limit", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE(&_5)) {
		zephir_read_property(&_6$$3, this_ptr, ZEND_STRL("debug"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "instance.register:limit");
		ZVAL_NULL(&_8$$3);
		ZEPHIR_CALL_CE_STATIC(NULL, pacos_utils_logs_ce, "log", &_0, 0, &_7$$3, &_8$$3, &_6$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	zephir_read_property(&_9, this_ptr, ZEND_STRL("shmKey"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_10, this_ptr, ZEND_STRL("defaultMode"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_11, this_ptr, ZEND_STRL("shmSize"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "c");
	ZEPHIR_CALL_FUNCTION(&shmId, "shmop_open", NULL, 19, &_9, &_4, &_10, &_11);
	zephir_check_call_status();
	if (!(zephir_is_true(&shmId))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "open memory failed", "pacos/Instance.zep", 336);
		return;
	}
	zephir_read_property(&_12, this_ptr, ZEND_STRL("defaultMode"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_13, 0);
	ZEPHIR_CALL_FUNCTION(&data, "shmop_read", NULL, 22, &shmId, &_13, &_12);
	zephir_check_call_status();
	ZVAL_LONG(&_13, 0);
	ZVAL_LONG(&_14, 10);
	ZEPHIR_INIT_NVAR(&_4);
	zephir_substr(&_4, &data, 0 , 10 , 0);
	zephir_get_strval(&_15, &_4);
	ZEPHIR_CPY_WRT(&shmopLengthStr, &_15);
	ZEPHIR_INIT_VAR(&shmopLength);
	ZVAL_LONG(&shmopLength, zephir_get_intval(&shmopLengthStr));
	ZVAL_LONG(&_16, 10);
	ZVAL_LONG(&_17, (zephir_get_numberval(&shmopLength) - 10));
	ZEPHIR_INIT_VAR(&_18);
	zephir_substr(&_18, &data, 10 , zephir_get_intval(&_17), 0);
	zephir_get_strval(&_19, &_18);
	ZEPHIR_CPY_WRT(&subData, &_19);

	/* try_start_1: */

		ZEPHIR_INIT_VAR(&dataArr);
		zephir_json_decode(&dataArr, &subData, zephir_get_intval(&__$true) );

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_20);
		ZVAL_OBJ(&_20, EG(exception));
		Z_ADDREF_P(&_20);
		ZEPHIR_INIT_VAR(&_21);
		if (zephir_instance_of_ev(&_20, zend_exception_get_default(TSRMLS_C))) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&_21, &_20);
			ZEPHIR_INIT_NVAR(&dataArr);
			array_init(&dataArr);
		}
	}
	ZEPHIR_INIT_VAR(&_22);
	zephir_gettype(&_22, &dataArr);
	if (!ZEPHIR_IS_STRING(&_22, "array")) {
		ZEPHIR_INIT_NVAR(&dataArr);
		array_init(&dataArr);
	}
	ZEPHIR_INIT_VAR(&_23);
	zephir_md5(&_23, &uniqueName);
	zephir_get_strval(&uniqueName, &_23);
	ZEPHIR_INIT_VAR(&_24);
	zephir_create_array(&_24, 2, 0);
	ZEPHIR_INIT_VAR(&_25);
	zephir_create_array(&_25, 3, 0);
	ZEPHIR_OBS_VAR(&_26);
	zephir_read_property(&_26, this_ptr, ZEND_STRL("endpoint"), PH_NOISY_CC);
	zephir_array_update_string(&_25, SL("endpoint"), &_26, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_26);
	zephir_read_property(&_26, this_ptr, ZEND_STRL("port"), PH_NOISY_CC);
	zephir_array_update_string(&_25, SL("port"), &_26, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_26);
	zephir_read_property(&_26, this_ptr, ZEND_STRL("options"), PH_NOISY_CC);
	zephir_array_update_string(&_25, SL("options"), &_26, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_24, SL("service"), &_25, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_24, SL("instance"), &instanceList, PH_COPY | PH_SEPARATE);
	zephir_array_update_zval(&dataArr, &uniqueName, &_24, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&jsonData);
	zephir_json_encode(&jsonData, &dataArr, 0 );
	ZEPHIR_INIT_VAR(&_27);
	ZVAL_STRING(&_27, "%010s%s");
	ZVAL_LONG(&_28, (zephir_fast_strlen_ev(&jsonData) + 10));
	ZEPHIR_CALL_FUNCTION(&_29, "sprintf", &_30, 4, &_27, &_28, &jsonData);
	zephir_check_call_status();
	zephir_read_property(&_28, this_ptr, ZEND_STRL("debug"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_27);
	ZVAL_STRING(&_27, "instance.register:write");
	ZEPHIR_CALL_CE_STATIC(NULL, pacos_utils_logs_ce, "log", &_0, 0, &_27, &_29, &_28);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_27);
	ZVAL_STRING(&_27, "%010s%s");
	ZVAL_LONG(&_31, (zephir_fast_strlen_ev(&jsonData) + 10));
	ZEPHIR_CALL_FUNCTION(&_32, "sprintf", &_30, 4, &_27, &_31, &jsonData);
	zephir_check_call_status();
	ZVAL_LONG(&_31, 0);
	ZEPHIR_CALL_FUNCTION(NULL, "shmop_write", NULL, 20, &shmId, &_32, &_31);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "shmop_close", NULL, 21, &shmId);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

