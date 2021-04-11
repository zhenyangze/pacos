
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
#include "kernel/concat.h"
#include "kernel/file.h"


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
		ZEPHIR_CALL_METHOD(NULL, &newInstance, "__construct", NULL, 15, instance);
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
	ZEPHIR_CALL_METHOD(NULL, &newInstance, "validate", NULL, 16);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 1, 0);
	ZEPHIR_CALL_METHOD(&_5, &newInstance, "tocreateparams", NULL, 17);
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
	ZEPHIR_CALL_METHOD(NULL, &instance, "__construct", NULL, 15, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 1, 0);
	ZEPHIR_CALL_METHOD(&_5, &instance, "todeleteparams", NULL, 18);
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
		ZEPHIR_CALL_METHOD(NULL, &newInstance, "__construct", NULL, 15, instance);
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
	ZEPHIR_CALL_METHOD(NULL, &newInstance, "validate", NULL, 16);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 1, 0);
	ZEPHIR_CALL_METHOD(&_5, &newInstance, "toupdateparams", NULL, 19);
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
	ZEPHIR_CALL_FUNCTION(&query, "array_filter", NULL, 20, &_2);
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
		ZEPHIR_CALL_METHOD(NULL, &_9$$7, "__construct", NULL, 12, &_10$$7, &_11$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_9$$7, "pacos/Instance.zep", 148);
		ZEPHIR_MM_RESTORE();
		return;
	}
	object_init_ex(return_value, pacos_models_serviceinstancelist_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 21, &data);
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
	ZEPHIR_CALL_METHOD(NULL, &instance, "__construct", &_4, 15, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&query, &instance, "togetparams", NULL, 22);
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
	zephir_array_fetch_string(&_9, &data, SL("service"), PH_NOISY | PH_READONLY, "pacos/Instance.zep", 198);
	zephir_array_update_string(&data, SL("serviceName"), &_9, PH_COPY | PH_SEPARATE);
	object_init_ex(return_value, pacos_models_serviceinstance_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", &_4, 15, &data);
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
		ZEPHIR_CALL_METHOD(NULL, &newBeat, "__construct", NULL, 23, beat);
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
	zephir_array_fetch_string(&_9, &ret, SL("clientBeatInterval"), PH_NOISY | PH_READONLY, "pacos/Instance.zep", 239);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(pacos_exceptions_pacosnamingnoaliveinstance_ce, "serviceName no alive instnace", "pacos/Instance.zep", 263);
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
	ZEPHIR_CALL_FUNCTION(&shmId, "shmop_open", NULL, 24, &_0, &_3, &_1, &_2);
	zephir_check_call_status();
	if (!(zephir_is_true(&shmId))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "open memory failed", "pacos/Instance.zep", 308);
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
	ZEPHIR_CALL_FUNCTION(NULL, "shmop_write", NULL, 25, &shmId, &_5, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "shmop_close", NULL, 26, &shmId);
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
	zephir_fcall_cache_entry *_23 = NULL;
	zend_long timeout, ZEPHIR_LAST_CALL_STATUS;
	zval instanceList;
	zval *uniqueName_param = NULL, *instanceList_param = NULL, *timeout_param = NULL, *remote_param = NULL, __$true, _0, _1, _2, _3, shmId, _5, _6, _7, data, _8, _9, shmopLengthStr, shmopLength, _10, subData, _12, _13, _14, dataArr, _16, _17, _18, _19, jsonData, _20, _21, _22, _24, _4$$3;
	zval uniqueName, remote, _11, _15;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uniqueName);
	ZVAL_UNDEF(&remote);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_15);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&shmId);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&shmopLengthStr);
	ZVAL_UNDEF(&shmopLength);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&subData);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&dataArr);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&jsonData);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&instanceList);

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


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_get_args(&_1);
	zephir_json_encode(&_0, &_1, 0 );
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "instance.register:");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_2, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "limit", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE(&_3)) {
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "instance.register:limit");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_4$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	zephir_read_property(&_5, this_ptr, ZEND_STRL("shmKey"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_6, this_ptr, ZEND_STRL("defaultMode"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_7, this_ptr, ZEND_STRL("shmSize"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "c");
	ZEPHIR_CALL_FUNCTION(&shmId, "shmop_open", NULL, 24, &_5, &_2, &_6, &_7);
	zephir_check_call_status();
	if (!(zephir_is_true(&shmId))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "open memory failed", "pacos/Instance.zep", 335);
		return;
	}
	zephir_read_property(&_8, this_ptr, ZEND_STRL("defaultMode"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_9, 0);
	ZEPHIR_CALL_FUNCTION(&data, "shmop_read", NULL, 27, &shmId, &_9, &_8);
	zephir_check_call_status();
	ZVAL_LONG(&_9, 0);
	ZVAL_LONG(&_10, 10);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_substr(&_2, &data, 0 , 10 , 0);
	zephir_get_strval(&_11, &_2);
	ZEPHIR_CPY_WRT(&shmopLengthStr, &_11);
	ZEPHIR_INIT_VAR(&shmopLength);
	ZVAL_LONG(&shmopLength, zephir_get_intval(&shmopLengthStr));
	ZVAL_LONG(&_12, 10);
	ZVAL_LONG(&_13, (zephir_get_numberval(&shmopLength) - 10));
	ZEPHIR_INIT_VAR(&_14);
	zephir_substr(&_14, &data, 10 , zephir_get_intval(&_13), 0);
	zephir_get_strval(&_15, &_14);
	ZEPHIR_CPY_WRT(&subData, &_15);

	/* try_start_1: */

		ZEPHIR_INIT_VAR(&dataArr);
		zephir_json_decode(&dataArr, &subData, zephir_get_intval(&__$true) );

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_16);
		ZVAL_OBJ(&_16, EG(exception));
		Z_ADDREF_P(&_16);
		ZEPHIR_INIT_VAR(&_17);
		if (zephir_instance_of_ev(&_16, zend_exception_get_default(TSRMLS_C))) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&_17, &_16);
			ZEPHIR_INIT_NVAR(&dataArr);
			array_init(&dataArr);
		}
	}
	ZEPHIR_INIT_VAR(&_18);
	zephir_gettype(&_18, &dataArr);
	if (!ZEPHIR_IS_STRING(&_18, "array")) {
		ZEPHIR_INIT_NVAR(&dataArr);
		array_init(&dataArr);
	}
	ZEPHIR_INIT_VAR(&_19);
	zephir_md5(&_19, &uniqueName);
	zephir_get_strval(&uniqueName, &_19);
	zephir_array_update_zval(&dataArr, &uniqueName, &instanceList, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&jsonData);
	zephir_json_encode(&jsonData, &dataArr, 0 );
	ZEPHIR_INIT_VAR(&_20);
	ZVAL_STRING(&_20, "%010s%s");
	ZVAL_LONG(&_21, (zephir_fast_strlen_ev(&jsonData) + 10));
	ZEPHIR_CALL_FUNCTION(&_22, "sprintf", &_23, 4, &_20, &_21, &jsonData);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_20);
	ZVAL_STRING(&_20, "instance.register.write");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_20, &_22);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_20);
	ZVAL_STRING(&_20, "%010s%s");
	ZVAL_LONG(&_21, (zephir_fast_strlen_ev(&jsonData) + 10));
	ZEPHIR_CALL_FUNCTION(&_24, "sprintf", &_23, 4, &_20, &_21, &jsonData);
	zephir_check_call_status();
	ZVAL_LONG(&_21, 0);
	ZEPHIR_CALL_FUNCTION(NULL, "shmop_write", NULL, 25, &shmId, &_24, &_21);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "shmop_close", NULL, 26, &shmId);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "backend", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * backend 
 *
 * @return 
 */
PHP_METHOD(Pacos_Instance, backend) {

	zval _0, backendPid, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&backendPid);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "instance.backend.start");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&backendPid);
	ZVAL_LONG(&backendPid, ZEPHIR_GLOBAL(instance_backend_pid));
	if (ZEPHIR_GT_LONG(&backendPid, 0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "instance.backend.already");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_1$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "startjob", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * startJob 
 *
 * @return 
 */
PHP_METHOD(Pacos_Instance, startJob) {

	zend_bool _33$$12;
	zval _25$$12;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, _0, backendPid, output, _4, pid, sid, _1$$3, _3$$4, oldPid$$5, _5$$5, _6$$5, _7$$7, _8$$7, _9$$8, _10$$9, _12$$12, shmId$$12, data$$12, dataArr$$12, item$$12, _16$$12, _17$$12, _18$$12, _19$$12, _21$$12, _22$$12, shmopLengthStr$$12, shmopLength$$12, _24$$12, subData$$12, _26$$12, _27$$12, _28$$12, _29$$12, _30$$12, _31$$12, _32$$12, _34$$12, subItem$$12, *_36$$12, _37$$12, _52$$12, _13$$14, _14$$14, _35$$19, *_38$$20, _39$$20, _40$$21, _41$$21, _43$$23, _44$$23, *_45$$25, _46$$25, _47$$26, _48$$26, _49$$28, _50$$28, _54$$30;
	zephir_fcall_cache_entry *_2 = NULL, *_11 = NULL, *_15 = NULL, *_20 = NULL, *_23 = NULL, *_42 = NULL, *_51 = NULL, *_53 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&backendPid);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&pid);
	ZVAL_UNDEF(&sid);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&oldPid$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_12$$12);
	ZVAL_UNDEF(&shmId$$12);
	ZVAL_UNDEF(&data$$12);
	ZVAL_UNDEF(&dataArr$$12);
	ZVAL_UNDEF(&item$$12);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_21$$12);
	ZVAL_UNDEF(&_22$$12);
	ZVAL_UNDEF(&shmopLengthStr$$12);
	ZVAL_UNDEF(&shmopLength$$12);
	ZVAL_UNDEF(&_24$$12);
	ZVAL_UNDEF(&subData$$12);
	ZVAL_UNDEF(&_26$$12);
	ZVAL_UNDEF(&_27$$12);
	ZVAL_UNDEF(&_28$$12);
	ZVAL_UNDEF(&_29$$12);
	ZVAL_UNDEF(&_30$$12);
	ZVAL_UNDEF(&_31$$12);
	ZVAL_UNDEF(&_32$$12);
	ZVAL_UNDEF(&_34$$12);
	ZVAL_UNDEF(&subItem$$12);
	ZVAL_UNDEF(&_37$$12);
	ZVAL_UNDEF(&_52$$12);
	ZVAL_UNDEF(&_13$$14);
	ZVAL_UNDEF(&_14$$14);
	ZVAL_UNDEF(&_35$$19);
	ZVAL_UNDEF(&_39$$20);
	ZVAL_UNDEF(&_40$$21);
	ZVAL_UNDEF(&_41$$21);
	ZVAL_UNDEF(&_43$$23);
	ZVAL_UNDEF(&_44$$23);
	ZVAL_UNDEF(&_46$$25);
	ZVAL_UNDEF(&_47$$26);
	ZVAL_UNDEF(&_48$$26);
	ZVAL_UNDEF(&_49$$28);
	ZVAL_UNDEF(&_50$$28);
	ZVAL_UNDEF(&_54$$30);
	ZVAL_UNDEF(&_25$$12);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "instance.startJob.start");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&backendPid);
	ZVAL_LONG(&backendPid, ZEPHIR_GLOBAL(instance_backend_pid));
	if (ZEPHIR_GT_LONG(&backendPid, 0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CONCAT_SV(&_1$$3, "ps -p ", &backendPid);
		ZEPHIR_MAKE_REF(&output);
		ZEPHIR_CALL_FUNCTION(NULL, "exec", &_2, 28, &_1$$3, &output);
		ZEPHIR_UNREF(&output);
		zephir_check_call_status();
		if (zephir_fast_count_int(&output) >= 2) {
			ZEPHIR_INIT_VAR(&_3$$4);
			ZVAL_STRING(&_3$$4, "instance.startJob.already");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_3$$4);
			zephir_check_call_status();
			RETURN_MM_BOOL(1);
		}
	}
	zephir_read_property(&_4, this_ptr, ZEND_STRL("beat_run_mode"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_LONG(&_4, 1)) {
		zephir_read_property(&_5$$5, this_ptr, ZEND_STRL("beat_pid_file"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_6$$5, "is_file", NULL, 29, &_5$$5);
		zephir_check_call_status();
		if (zephir_is_true(&_6$$5)) {

			/* try_start_1: */

				zephir_read_property(&_7$$7, this_ptr, ZEND_STRL("beat_pid_file"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&oldPid$$5);
				zephir_file_get_contents(&oldPid$$5, &_7$$7);
				ZEPHIR_INIT_VAR(&_8$$7);
				ZEPHIR_CONCAT_SV(&_8$$7, "ps -p ", &oldPid$$5);
				ZEPHIR_MAKE_REF(&output);
				ZEPHIR_CALL_FUNCTION(NULL, "exec", &_2, 28, &_8$$7, &output);
				ZEPHIR_UNREF(&output);
				zephir_check_call_status_or_jump(try_end_1);
				if (zephir_fast_count_int(&output) >= 2) {
					ZEPHIR_INIT_VAR(&_9$$8);
					ZVAL_STRING(&_9$$8, "instance.startJob.already");
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_9$$8);
					zephir_check_call_status_or_jump(try_end_1);
					RETURN_MM_BOOL(1);
				}

			try_end_1:

			zend_clear_exception(TSRMLS_C);
		}
	}
	ZEPHIR_CALL_FUNCTION(&pid, "pcntl_fork", NULL, 30);
	zephir_check_call_status();
	if (ZEPHIR_GT_LONG(&pid, 0)) {
		ZEPHIR_INIT_VAR(&_10$$9);
		ZVAL_STRING(&_10$$9, "instance.startJob.pid:");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_10$$9, &pid);
		zephir_check_call_status();
		ZEPHIR_GLOBAL(instance_backend_pid) = Z_LVAL_P(&pid);
		RETURN_MM_NULL();
	} else if (ZEPHIR_IS_LONG(&pid, -1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "fork child error", "pacos/Instance.zep", 420);
		return;
	}
	ZEPHIR_CALL_FUNCTION(&sid, "posix_setsid", NULL, 31);
	zephir_check_call_status();
	if (ZEPHIR_LT_LONG(&sid, 0)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_GLOBAL(instance_backend_pid) = Z_LVAL_P(&sid);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "instance.startJob.sid:");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_0, &sid);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_FUNCTION(&pid, "getmypid", &_11, 32);
		zephir_check_call_status();
		ZEPHIR_GLOBAL(instance_backend_pid) = Z_LVAL_P(&pid);
		zephir_read_property(&_12$$12, this_ptr, ZEND_STRL("beat_run_mode"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_IS_LONG(&_12$$12, 1)) {

			/* try_start_2: */

				zephir_read_property(&_13$$14, this_ptr, ZEND_STRL("beat_pid_file"), PH_NOISY_CC | PH_READONLY);
				ZVAL_LONG(&_14$$14, 2);
				ZEPHIR_CALL_FUNCTION(NULL, "file_put_contents", &_15, 8, &_13$$14, &pid, &_14$$14);
				zephir_check_call_status_or_jump(try_end_2);

			try_end_2:

			zend_clear_exception(TSRMLS_C);
		}
		zephir_read_property(&_16$$12, this_ptr, ZEND_STRL("shmKey"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_17$$12, this_ptr, ZEND_STRL("defaultMode"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_18$$12, this_ptr, ZEND_STRL("shmSize"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_19$$12);
		ZVAL_STRING(&_19$$12, "a");
		ZEPHIR_CALL_FUNCTION(&shmId$$12, "shmop_open", &_20, 24, &_16$$12, &_19$$12, &_17$$12, &_18$$12);
		zephir_check_call_status();
		if (!(zephir_is_true(&shmId$$12))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "open memory failed", "pacos/Instance.zep", 443);
			return;
		}
		zephir_read_property(&_21$$12, this_ptr, ZEND_STRL("shmSize"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_22$$12, 0);
		ZEPHIR_CALL_FUNCTION(&data$$12, "shmop_read", &_23, 27, &shmId$$12, &_22$$12, &_21$$12);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_19$$12);
		ZVAL_STRING(&_19$$12, "instance.startJob.shmop.read");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_19$$12, &data$$12);
		zephir_check_call_status();
		ZVAL_LONG(&_22$$12, 0);
		ZVAL_LONG(&_24$$12, 10);
		ZEPHIR_INIT_NVAR(&_19$$12);
		zephir_substr(&_19$$12, &data$$12, 0 , 10 , 0);
		zephir_get_strval(&_25$$12, &_19$$12);
		ZEPHIR_CPY_WRT(&shmopLengthStr$$12, &_25$$12);
		ZEPHIR_INIT_NVAR(&shmopLength$$12);
		ZVAL_LONG(&shmopLength$$12, zephir_get_intval(&shmopLengthStr$$12));
		ZVAL_LONG(&_26$$12, 10);
		ZVAL_LONG(&_27$$12, (zephir_get_numberval(&shmopLength$$12) - 10));
		ZEPHIR_INIT_NVAR(&subData$$12);
		zephir_substr(&subData$$12, &data$$12, 10 , zephir_get_intval(&_27$$12), 0);
		ZEPHIR_INIT_NVAR(&_28$$12);
		ZVAL_STRING(&_28$$12, "instance.startJob.shmop.read");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_28$$12, &subData$$12);
		zephir_check_call_status();

		/* try_start_3: */

			ZEPHIR_INIT_NVAR(&dataArr$$12);
			zephir_json_decode(&dataArr$$12, &subData$$12, zephir_get_intval(&__$true) );

		try_end_3:

		if (EG(exception)) {
			ZEPHIR_INIT_NVAR(&_28$$12);
			ZVAL_OBJ(&_28$$12, EG(exception));
			Z_ADDREF_P(&_28$$12);
			ZEPHIR_INIT_NVAR(&_29$$12);
			if (zephir_instance_of_ev(&_28$$12, zend_exception_get_default(TSRMLS_C))) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CPY_WRT(&_29$$12, &_28$$12);
				ZEPHIR_INIT_NVAR(&dataArr$$12);
				array_init(&dataArr$$12);
			}
		}
		ZEPHIR_INIT_NVAR(&_30$$12);
		zephir_gettype(&_30$$12, &dataArr$$12);
		if (!ZEPHIR_IS_STRING(&_30$$12, "array")) {
			ZEPHIR_INIT_NVAR(&dataArr$$12);
			array_init(&dataArr$$12);
		}
		ZEPHIR_INIT_NVAR(&_31$$12);
		zephir_json_encode(&_31$$12, &dataArr$$12, 0 );
		ZEPHIR_INIT_NVAR(&_32$$12);
		ZVAL_STRING(&_32$$12, "instance.startJob.beat");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_32$$12, &_31$$12);
		zephir_check_call_status();
		_33$$12 = ZEPHIR_IS_EMPTY(&dataArr$$12);
		if (_33$$12) {
			ZEPHIR_OBS_NVAR(&_34$$12);
			zephir_read_property(&_34$$12, this_ptr, ZEND_STRL("auto_close"), PH_NOISY_CC);
			_33$$12 = !(ZEPHIR_IS_EMPTY(&_34$$12));
		}
		if (_33$$12) {
			ZEPHIR_INIT_NVAR(&_35$$19);
			ZVAL_STRING(&_35$$19, "instance.startJob.auto_close");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_35$$19);
			zephir_check_call_status();
			break;
		}
		zephir_is_iterable(&dataArr$$12, 0, "pacos/Instance.zep", 478);
		if (Z_TYPE_P(&dataArr$$12) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&dataArr$$12), _36$$12)
			{
				ZEPHIR_INIT_NVAR(&item$$12);
				ZVAL_COPY(&item$$12, _36$$12);
				zephir_is_iterable(&item$$12, 0, "pacos/Instance.zep", 477);
				if (Z_TYPE_P(&item$$12) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&item$$12), _38$$20)
					{
						ZEPHIR_INIT_NVAR(&subItem$$12);
						ZVAL_COPY(&subItem$$12, _38$$20);
						ZEPHIR_INIT_NVAR(&_40$$21);
						zephir_json_encode(&_40$$21, &subItem$$12, 0 );
						ZEPHIR_INIT_NVAR(&_41$$21);
						ZVAL_STRING(&_41$$21, "instance.startJob.beat.detail");
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_41$$21, &_40$$21);
						zephir_check_call_status();

						/* try_start_4: */

							ZEPHIR_CALL_METHOD(NULL, this_ptr, "beat", &_42, 0, &subItem$$12);
							zephir_check_call_status_or_jump(try_end_4);

						try_end_4:

						zend_clear_exception(TSRMLS_C);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &item$$12, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_39$$20, &item$$12, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_39$$20)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&subItem$$12, &item$$12, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_43$$23);
							zephir_json_encode(&_43$$23, &subItem$$12, 0 );
							ZEPHIR_INIT_NVAR(&_44$$23);
							ZVAL_STRING(&_44$$23, "instance.startJob.beat.detail");
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_44$$23, &_43$$23);
							zephir_check_call_status();

							/* try_start_5: */

								ZEPHIR_CALL_METHOD(NULL, this_ptr, "beat", &_42, 0, &subItem$$12);
								zephir_check_call_status_or_jump(try_end_5);

							try_end_5:

							zend_clear_exception(TSRMLS_C);
						ZEPHIR_CALL_METHOD(NULL, &item$$12, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&subItem$$12);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &dataArr$$12, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_37$$12, &dataArr$$12, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_37$$12)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&item$$12, &dataArr$$12, "current", NULL, 0);
				zephir_check_call_status();
					zephir_is_iterable(&item$$12, 0, "pacos/Instance.zep", 477);
					if (Z_TYPE_P(&item$$12) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&item$$12), _45$$25)
						{
							ZEPHIR_INIT_NVAR(&subItem$$12);
							ZVAL_COPY(&subItem$$12, _45$$25);
							ZEPHIR_INIT_NVAR(&_47$$26);
							zephir_json_encode(&_47$$26, &subItem$$12, 0 );
							ZEPHIR_INIT_NVAR(&_48$$26);
							ZVAL_STRING(&_48$$26, "instance.startJob.beat.detail");
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_48$$26, &_47$$26);
							zephir_check_call_status();

							/* try_start_6: */

								ZEPHIR_CALL_METHOD(NULL, this_ptr, "beat", &_42, 0, &subItem$$12);
								zephir_check_call_status_or_jump(try_end_6);

							try_end_6:

							zend_clear_exception(TSRMLS_C);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &item$$12, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_46$$25, &item$$12, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_46$$25)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&subItem$$12, &item$$12, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_49$$28);
								zephir_json_encode(&_49$$28, &subItem$$12, 0 );
								ZEPHIR_INIT_NVAR(&_50$$28);
								ZVAL_STRING(&_50$$28, "instance.startJob.beat.detail");
								ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_50$$28, &_49$$28);
								zephir_check_call_status();

								/* try_start_7: */

									ZEPHIR_CALL_METHOD(NULL, this_ptr, "beat", &_42, 0, &subItem$$12);
									zephir_check_call_status_or_jump(try_end_7);

								try_end_7:

								zend_clear_exception(TSRMLS_C);
							ZEPHIR_CALL_METHOD(NULL, &item$$12, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&subItem$$12);
				ZEPHIR_CALL_METHOD(NULL, &dataArr$$12, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&item$$12);
		ZEPHIR_CALL_FUNCTION(NULL, "shmop_close", &_51, 26, &shmId$$12);
		zephir_check_call_status();
		zephir_read_property(&_52$$12, this_ptr, ZEND_STRL("defaultPeriod"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "sleep", &_53, 33, &_52$$12);
		zephir_check_call_status();
		if (ZEPHIR_GLOBAL(instance_close_sign) > 0) {
			ZEPHIR_INIT_NVAR(&_54$$30);
			ZVAL_STRING(&_54$$30, "instance.startJob.finish");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_54$$30);
			zephir_check_call_status();
			break;
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * stopJob 
 *
 * @return 
 */
PHP_METHOD(Pacos_Instance, stopJob) {

	zval _0, backendPid, _3, _1$$3, oldPid$$4, _4$$4, _5$$4, _6$$6, _7$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&backendPid);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&oldPid$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "instance.startJob.stop");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&backendPid);
	ZVAL_LONG(&backendPid, ZEPHIR_GLOBAL(instance_backend_pid));
	if (ZEPHIR_GT_LONG(&backendPid, 0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CONCAT_SV(&_1$$3, "kill -USR1 ", &backendPid);
		ZEPHIR_CALL_FUNCTION(NULL, "exec", &_2, 28, &_1$$3);
		zephir_check_call_status();
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("beat_run_mode"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_LONG(&_3, 1)) {
		zephir_read_property(&_4$$4, this_ptr, ZEND_STRL("beat_pid_file"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_5$$4, "is_file", NULL, 29, &_4$$4);
		zephir_check_call_status();
		if (zephir_is_true(&_5$$4)) {

			/* try_start_1: */

				zephir_read_property(&_6$$6, this_ptr, ZEND_STRL("beat_pid_file"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&oldPid$$4);
				zephir_file_get_contents(&oldPid$$4, &_6$$6);
				ZEPHIR_INIT_VAR(&_7$$6);
				ZEPHIR_CONCAT_SV(&_7$$6, "kill -USR1 ", &oldPid$$4);
				ZEPHIR_CALL_FUNCTION(NULL, "exec", &_2, 28, &_7$$6);
				zephir_check_call_status_or_jump(try_end_1);

			try_end_1:

			zend_clear_exception(TSRMLS_C);
		}
	}
	ZEPHIR_MM_RESTORE();

}

