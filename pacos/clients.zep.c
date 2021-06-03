
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Pacos_Clients) {

	ZEPHIR_REGISTER_CLASS(Pacos, Clients, pacos, clients, pacos_clients_method_entry, 0);

	zend_declare_property_null(pacos_clients_ce, SL("instance"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);

	zend_declare_property_null(pacos_clients_ce, SL("name"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(pacos_clients_ce, SL("endpoint"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(pacos_clients_ce, SL("port"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(pacos_clients_ce, SL("options"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(pacos_clients_ce, SL("configObj"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(pacos_clients_ce, SL("instanceObj"), ZEND_ACC_PRIVATE);

	zephir_declare_class_constant_string(pacos_clients_ce, SL("DEFAULT_GROUP"), "DEFAULT_GROUP");

	return SUCCESS;

}

PHP_METHOD(Pacos_Clients, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval options;
	zend_long port;
	zval *endpoint_param = NULL, *port_param = NULL, *options_param = NULL, _0;
	zval endpoint;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&endpoint);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &endpoint_param, &port_param, &options_param);

	if (!endpoint_param) {
		ZEPHIR_INIT_VAR(&endpoint);
		ZVAL_STRING(&endpoint, "http://localhost");
	} else {
		zephir_get_strval(&endpoint, endpoint_param);
	}
	if (!port_param) {
		port = 8848;
	} else {
		port = zephir_get_intval(port_param);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("endpoint"), &endpoint);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, port);
	zephir_update_property_zval(this_ptr, ZEND_STRL("port"), &_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("options"), &options);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Pacos_Clients, __clone) {

	zval *this_ptr = getThis();



}

PHP_METHOD(Pacos_Clients, init) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval options;
	zend_long port, ZEPHIR_LAST_CALL_STATUS;
	zval *endpoint_param = NULL, *port_param = NULL, *options_param = NULL, _0, _3, _1$$3, _2$$3;
	zval endpoint;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&endpoint);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &endpoint_param, &port_param, &options_param);

	if (!endpoint_param) {
		ZEPHIR_INIT_VAR(&endpoint);
		ZVAL_STRING(&endpoint, "http://localhost");
	} else {
		zephir_get_strval(&endpoint, endpoint_param);
	}
	if (!port_param) {
		port = 8848;
	} else {
		port = zephir_get_intval(port_param);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	zephir_read_static_property_ce(&_0, pacos_clients_ce, SL("instance"), PH_NOISY_CC | PH_READONLY);
	if (!zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, pacos_clients_ce);
		ZVAL_LONG(&_2$$3, port);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 9, &endpoint, &_2$$3, &options);
		zephir_check_call_status();
		zephir_update_static_property_ce(pacos_clients_ce, ZEND_STRL("instance"), &_1$$3);
	}
	zephir_read_static_property_ce(&_3, pacos_clients_ce, SL("instance"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTOR(&_3);

}

PHP_METHOD(Pacos_Clients, getConfigObj) {

	zval instance, _0, _5, _1$$3, _2$$3, _3$$3, _4$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_SELF(&instance, "init", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, &instance, ZEND_STRL("configObj"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, pacos_config_ce);
		zephir_read_property(&_2$$3, &instance, ZEND_STRL("endPoint"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_3$$3, &instance, ZEND_STRL("port"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_4$$3, &instance, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 10, &_2$$3, &_3$$3, &_4$$3);
		zephir_check_call_status();
		zephir_update_property_zval(&instance, ZEND_STRL("configObj"), &_1$$3);
	}
	ZEPHIR_OBS_VAR(&_5);
	zephir_read_property(&_5, &instance, ZEND_STRL("configObj"), PH_NOISY_CC);
	RETURN_CCTOR(&_5);

}

PHP_METHOD(Pacos_Clients, getInstanceObj) {

	zval instance, _0, _5, _1$$3, _2$$3, _3$$3, _4$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_SELF(&instance, "init", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, &instance, ZEND_STRL("instanceObj"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, pacos_instance_ce);
		zephir_read_property(&_2$$3, &instance, ZEND_STRL("endPoint"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_3$$3, &instance, ZEND_STRL("port"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_4$$3, &instance, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 10, &_2$$3, &_3$$3, &_4$$3);
		zephir_check_call_status();
		zephir_update_property_zval(&instance, ZEND_STRL("instanceObj"), &_1$$3);
	}
	ZEPHIR_OBS_VAR(&_5);
	zephir_read_property(&_5, &instance, ZEND_STRL("Instance"), PH_NOISY_CC);
	RETURN_CCTOR(&_5);

}

PHP_METHOD(Pacos_Clients, configGet) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *dataId_param = NULL, *group_param = NULL, *callback = NULL, callback_sub, __$null, configObj;
	zval dataId, group;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dataId);
	ZVAL_UNDEF(&group);
	ZVAL_UNDEF(&callback_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&configObj);

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


	ZEPHIR_CALL_SELF(&configObj, "getconfigobj", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&configObj, "get", NULL, 0, &dataId, &group, callback);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Pacos_Clients, configSet) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *dataId_param = NULL, *group_param = NULL, *content_param = NULL, configObj;
	zval dataId, group, content;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dataId);
	ZVAL_UNDEF(&group);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&configObj);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &dataId_param, &group_param, &content_param);

	zephir_get_strval(&dataId, dataId_param);
	zephir_get_strval(&group, group_param);
	zephir_get_strval(&content, content_param);


	ZEPHIR_CALL_SELF(&configObj, "getconfigobj", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "print_r", NULL, 11, &configObj);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&configObj, "set", NULL, 0, &dataId, &group, &content);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Pacos_Clients, configSearch) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long pageNo, pageSize, ZEPHIR_LAST_CALL_STATUS;
	zval *dataId_param = NULL, *group_param = NULL, *pageNo_param = NULL, *pageSize_param = NULL, configObj, _0, _1;
	zval dataId, group;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dataId);
	ZVAL_UNDEF(&group);
	ZVAL_UNDEF(&configObj);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

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


	ZEPHIR_CALL_SELF(&configObj, "getconfigobj", NULL, 0);
	zephir_check_call_status();
	ZVAL_LONG(&_0, pageNo);
	ZVAL_LONG(&_1, pageSize);
	ZEPHIR_RETURN_CALL_METHOD(&configObj, "search", NULL, 0, &dataId, &group, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Pacos_Clients, configDelete) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *dataId_param = NULL, *group_param = NULL, configObj;
	zval dataId, group;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dataId);
	ZVAL_UNDEF(&group);
	ZVAL_UNDEF(&configObj);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &dataId_param, &group_param);

	zephir_get_strval(&dataId, dataId_param);
	if (!group_param) {
		ZEPHIR_INIT_VAR(&group);
		ZVAL_STRING(&group, "DEFAULT_GROUP");
	} else {
		zephir_get_strval(&group, group_param);
	}


	ZEPHIR_CALL_SELF(&configObj, "getconfigobj", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&configObj, "delete", NULL, 0, &dataId, &group);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Pacos_Clients, configListen) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long timeout, ZEPHIR_LAST_CALL_STATUS;
	zval *configs_param = NULL, *timeout_param = NULL, configObj, _0;
	zval configs;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&configs);
	ZVAL_UNDEF(&configObj);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &configs_param, &timeout_param);

	zephir_get_arrval(&configs, configs_param);
	if (!timeout_param) {
		timeout = 30;
	} else {
		timeout = zephir_get_intval(timeout_param);
	}


	ZEPHIR_CALL_SELF(&configObj, "getconfigobj", NULL, 0);
	zephir_check_call_status();
	ZVAL_LONG(&_0, timeout);
	ZEPHIR_RETURN_CALL_METHOD(&configObj, "listen", NULL, 0, &configs, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

