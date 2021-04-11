
extern zend_class_entry *pacos_clients_ce;

ZEPHIR_INIT_CLASS(Pacos_Clients);

PHP_METHOD(Pacos_Clients, __construct);
PHP_METHOD(Pacos_Clients, __clone);
PHP_METHOD(Pacos_Clients, init);
PHP_METHOD(Pacos_Clients, getConfigObj);
PHP_METHOD(Pacos_Clients, getInstanceObj);
PHP_METHOD(Pacos_Clients, configGet);
PHP_METHOD(Pacos_Clients, configSet);
PHP_METHOD(Pacos_Clients, configSearch);
PHP_METHOD(Pacos_Clients, configDelete);
PHP_METHOD(Pacos_Clients, configListen);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_clients___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, endpoint, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, endpoint)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, port, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, port)
#endif
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_clients_init, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, endpoint, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, endpoint)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, port, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, port)
#endif
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_clients_configget, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, dataId, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, dataId)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, group, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, group)
#endif
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_clients_configset, 0, 0, 3)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, dataId, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, dataId)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, group, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, group)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, content, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, content)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_clients_configsearch, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, dataId, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, dataId)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, group, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, group)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, pageNo, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, pageNo)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, pageSize, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, pageSize)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_clients_configdelete, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, dataId, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, dataId)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, group, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, group)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_clients_configlisten, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, configs, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, timeout, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, timeout)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pacos_clients_method_entry) {
	PHP_ME(Pacos_Clients, __construct, arginfo_pacos_clients___construct, ZEND_ACC_PRIVATE|ZEND_ACC_CTOR)
	PHP_ME(Pacos_Clients, __clone, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Pacos_Clients, init, arginfo_pacos_clients_init, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Pacos_Clients, getConfigObj, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Pacos_Clients, getInstanceObj, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Pacos_Clients, configGet, arginfo_pacos_clients_configget, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Pacos_Clients, configSet, arginfo_pacos_clients_configset, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Pacos_Clients, configSearch, arginfo_pacos_clients_configsearch, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Pacos_Clients, configDelete, arginfo_pacos_clients_configdelete, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Pacos_Clients, configListen, arginfo_pacos_clients_configlisten, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
