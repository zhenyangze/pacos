
extern zend_class_entry *pacos_service_ce;

ZEPHIR_INIT_CLASS(Pacos_Service);

PHP_METHOD(Pacos_Service, register);
PHP_METHOD(Pacos_Service, update);
PHP_METHOD(Pacos_Service, deelte);

ZEPHIR_INIT_FUNCS(pacos_service_method_entry) {
	PHP_ME(Pacos_Service, register, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Pacos_Service, update, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Pacos_Service, deelte, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
