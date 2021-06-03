
extern zend_class_entry *pacos_config_ce;

ZEPHIR_INIT_CLASS(Pacos_Config);

PHP_METHOD(Pacos_Config, get);
PHP_METHOD(Pacos_Config, set);
PHP_METHOD(Pacos_Config, search);
PHP_METHOD(Pacos_Config, appendTmp);
PHP_METHOD(Pacos_Config, delete);
PHP_METHOD(Pacos_Config, listen);
zend_object *zephir_init_properties_Pacos_Config(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_config_get, 0, 0, 1)
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_config_set, 0, 0, 3)
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_config_search, 0, 0, 2)
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_config_appendtmp, 0, 0, 3)
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
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, content, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, content)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_config_delete, 0, 0, 1)
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_config_listen, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, configs, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, timeout, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, timeout)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pacos_config_method_entry) {
	PHP_ME(Pacos_Config, get, arginfo_pacos_config_get, ZEND_ACC_PUBLIC)
	PHP_ME(Pacos_Config, set, arginfo_pacos_config_set, ZEND_ACC_PUBLIC)
	PHP_ME(Pacos_Config, search, arginfo_pacos_config_search, ZEND_ACC_PUBLIC)
	PHP_ME(Pacos_Config, appendTmp, arginfo_pacos_config_appendtmp, ZEND_ACC_PROTECTED)
	PHP_ME(Pacos_Config, delete, arginfo_pacos_config_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Pacos_Config, listen, arginfo_pacos_config_listen, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
