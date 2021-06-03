
extern zend_class_entry *pacos_0__closure_ce;

ZEPHIR_INIT_CLASS(pacos_0__closure);

PHP_METHOD(pacos_0__closure, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_0__closure___invoke, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pacos_0__closure_method_entry) {
	PHP_ME(pacos_0__closure, __invoke, arginfo_pacos_0__closure___invoke, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_FE_END
};
