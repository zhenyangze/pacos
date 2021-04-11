
extern zend_class_entry *pacos_utils_selector_ce;

ZEPHIR_INIT_CLASS(Pacos_Utils_Selector);

PHP_METHOD(Pacos_Utils_Selector, randomByWeight);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_utils_selector_randombyweight, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, instances, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pacos_utils_selector_method_entry) {
	PHP_ME(Pacos_Utils_Selector, randomByWeight, arginfo_pacos_utils_selector_randombyweight, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
