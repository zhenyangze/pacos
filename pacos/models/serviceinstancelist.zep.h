
extern zend_class_entry *pacos_models_serviceinstancelist_ce;

ZEPHIR_INIT_CLASS(Pacos_Models_ServiceInstanceList);

PHP_METHOD(Pacos_Models_ServiceInstanceList, __construct);
zend_object *zephir_init_properties_Pacos_Models_ServiceInstanceList(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_models_serviceinstancelist___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pacos_models_serviceinstancelist_method_entry) {
	PHP_ME(Pacos_Models_ServiceInstanceList, __construct, arginfo_pacos_models_serviceinstancelist___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
