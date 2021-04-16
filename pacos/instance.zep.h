
extern zend_class_entry *pacos_instance_ce;

ZEPHIR_INIT_CLASS(Pacos_Instance);

PHP_METHOD(Pacos_Instance, add);
PHP_METHOD(Pacos_Instance, delete);
PHP_METHOD(Pacos_Instance, update);
PHP_METHOD(Pacos_Instance, list);
PHP_METHOD(Pacos_Instance, get);
PHP_METHOD(Pacos_Instance, beat);
PHP_METHOD(Pacos_Instance, select);
PHP_METHOD(Pacos_Instance, call);
PHP_METHOD(Pacos_Instance, cleanRegister);
PHP_METHOD(Pacos_Instance, register);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_instance_add, 0, 0, 1)
	ZEND_ARG_INFO(0, instance)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_instance_delete, 0, 0, 3)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, serviceName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, serviceName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, ip, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, ip)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, port, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, port)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, clusterName, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, clusterName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, namespaceId, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, namespaceId)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_instance_update, 0, 0, 1)
	ZEND_ARG_INFO(0, instance)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_instance_list, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, serviceName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, serviceName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, namespaceId, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, namespaceId)
#endif
	ZEND_ARG_ARRAY_INFO(0, clusters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_instance_get, 0, 0, 3)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, serviceName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, serviceName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, ip, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, ip)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, port, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, port)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, namespaceId, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, namespaceId)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, cluster, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, cluster)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, healthyOnly, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, healthyOnly)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_instance_beat, 0, 0, 1)
	ZEND_ARG_INFO(0, beat)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_instance_select, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, serviceName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, serviceName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, namespaceId, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, namespaceId)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_instance_call, 0, 0, 3)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, serviceName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, serviceName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, method)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, uri)
#endif
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, namespaceId, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, namespaceId)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_instance_cleanregister, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, info, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, info)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_instance_register, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, uniqueName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, uniqueName)
#endif
	ZEND_ARG_ARRAY_INFO(0, instanceList, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, timeout, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, timeout)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, remote, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, remote)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pacos_instance_method_entry) {
	PHP_ME(Pacos_Instance, add, arginfo_pacos_instance_add, ZEND_ACC_PUBLIC)
	PHP_ME(Pacos_Instance, delete, arginfo_pacos_instance_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Pacos_Instance, update, arginfo_pacos_instance_update, ZEND_ACC_PUBLIC)
	PHP_ME(Pacos_Instance, list, arginfo_pacos_instance_list, ZEND_ACC_PUBLIC)
	PHP_ME(Pacos_Instance, get, arginfo_pacos_instance_get, ZEND_ACC_PUBLIC)
	PHP_ME(Pacos_Instance, beat, arginfo_pacos_instance_beat, ZEND_ACC_PUBLIC)
	PHP_ME(Pacos_Instance, select, arginfo_pacos_instance_select, ZEND_ACC_PUBLIC)
	PHP_ME(Pacos_Instance, call, arginfo_pacos_instance_call, ZEND_ACC_PUBLIC)
	PHP_ME(Pacos_Instance, cleanRegister, arginfo_pacos_instance_cleanregister, ZEND_ACC_PUBLIC)
	PHP_ME(Pacos_Instance, register, arginfo_pacos_instance_register, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
