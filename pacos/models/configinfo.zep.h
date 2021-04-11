
extern zend_class_entry *pacos_models_configinfo_ce;

ZEPHIR_INIT_CLASS(Pacos_Models_ConfigInfo);

PHP_METHOD(Pacos_Models_ConfigInfo, setDataId);
PHP_METHOD(Pacos_Models_ConfigInfo, getDataId);
PHP_METHOD(Pacos_Models_ConfigInfo, setGroup);
PHP_METHOD(Pacos_Models_ConfigInfo, getGroup);
PHP_METHOD(Pacos_Models_ConfigInfo, setContentMd5);
PHP_METHOD(Pacos_Models_ConfigInfo, getContentMd5);
PHP_METHOD(Pacos_Models_ConfigInfo, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_models_configinfo_setdataid, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, dataId, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, dataId)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_pacos_models_configinfo_getdataid, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_pacos_models_configinfo_getdataid, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_models_configinfo_setgroup, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, group, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, group)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_pacos_models_configinfo_getgroup, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_pacos_models_configinfo_getgroup, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_models_configinfo_setcontentmd5, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, contentMd5, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, contentMd5)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_pacos_models_configinfo_getcontentmd5, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_pacos_models_configinfo_getcontentmd5, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_models_configinfo___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, info, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pacos_models_configinfo_method_entry) {
	PHP_ME(Pacos_Models_ConfigInfo, setDataId, arginfo_pacos_models_configinfo_setdataid, ZEND_ACC_PUBLIC)
	PHP_ME(Pacos_Models_ConfigInfo, getDataId, arginfo_pacos_models_configinfo_getdataid, ZEND_ACC_PUBLIC)
	PHP_ME(Pacos_Models_ConfigInfo, setGroup, arginfo_pacos_models_configinfo_setgroup, ZEND_ACC_PUBLIC)
	PHP_ME(Pacos_Models_ConfigInfo, getGroup, arginfo_pacos_models_configinfo_getgroup, ZEND_ACC_PUBLIC)
	PHP_ME(Pacos_Models_ConfigInfo, setContentMd5, arginfo_pacos_models_configinfo_setcontentmd5, ZEND_ACC_PUBLIC)
	PHP_ME(Pacos_Models_ConfigInfo, getContentMd5, arginfo_pacos_models_configinfo_getcontentmd5, ZEND_ACC_PUBLIC)
	PHP_ME(Pacos_Models_ConfigInfo, __construct, arginfo_pacos_models_configinfo___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
