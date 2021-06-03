
extern zend_class_entry *pacos_models_serviceinstance_ce;

ZEPHIR_INIT_CLASS(Pacos_Models_ServiceInstance);

PHP_METHOD(Pacos_Models_ServiceInstance, __construct);
PHP_METHOD(Pacos_Models_ServiceInstance, validate);
PHP_METHOD(Pacos_Models_ServiceInstance, assertNotNull);
PHP_METHOD(Pacos_Models_ServiceInstance, toCreateParams);
PHP_METHOD(Pacos_Models_ServiceInstance, toDeleteParams);
PHP_METHOD(Pacos_Models_ServiceInstance, toBeatParams);
PHP_METHOD(Pacos_Models_ServiceInstance, toGetParams);
PHP_METHOD(Pacos_Models_ServiceInstance, toUpdateParams);
PHP_METHOD(Pacos_Models_ServiceInstance, getMetadataJson);
PHP_METHOD(Pacos_Models_ServiceInstance, getWeightDouble);
PHP_METHOD(Pacos_Models_ServiceInstance, filter);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_models_serviceinstance___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, info, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_models_serviceinstance_assertnotnull, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_models_serviceinstance_filter, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pacos_models_serviceinstance_method_entry) {
	PHP_ME(Pacos_Models_ServiceInstance, __construct, arginfo_pacos_models_serviceinstance___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Pacos_Models_ServiceInstance, validate, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pacos_Models_ServiceInstance, assertNotNull, arginfo_pacos_models_serviceinstance_assertnotnull, ZEND_ACC_PROTECTED)
	PHP_ME(Pacos_Models_ServiceInstance, toCreateParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pacos_Models_ServiceInstance, toDeleteParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pacos_Models_ServiceInstance, toBeatParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pacos_Models_ServiceInstance, toGetParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pacos_Models_ServiceInstance, toUpdateParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pacos_Models_ServiceInstance, getMetadataJson, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Pacos_Models_ServiceInstance, getWeightDouble, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pacos_Models_ServiceInstance, filter, arginfo_pacos_models_serviceinstance_filter, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
