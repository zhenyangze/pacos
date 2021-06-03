
extern zend_class_entry *pacos_utils_http_ce;

ZEPHIR_INIT_CLASS(Pacos_Utils_Http);

PHP_METHOD(Pacos_Utils_Http, request);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_utils_http_request, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, headers)
	ZEND_ARG_INFO(0, timeout)
	ZEND_ARG_INFO(0, connttime)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pacos_utils_http_method_entry) {
	PHP_ME(Pacos_Utils_Http, request, arginfo_pacos_utils_http_request, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
