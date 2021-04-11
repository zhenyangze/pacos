
extern zend_class_entry *pacos_utils_response_ce;

ZEPHIR_INIT_CLASS(Pacos_Utils_Response);

PHP_METHOD(Pacos_Utils_Response, __construct);
PHP_METHOD(Pacos_Utils_Response, getBody);
PHP_METHOD(Pacos_Utils_Response, getStatusCode);
PHP_METHOD(Pacos_Utils_Response, getHttpStatus);
PHP_METHOD(Pacos_Utils_Response, __toString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_utils_response___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, contents)
	ZEND_ARG_INFO(0, httpStatus)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pacos_utils_response_method_entry) {
	PHP_ME(Pacos_Utils_Response, __construct, arginfo_pacos_utils_response___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Pacos_Utils_Response, getBody, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pacos_Utils_Response, getStatusCode, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pacos_Utils_Response, getHttpStatus, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pacos_Utils_Response, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
