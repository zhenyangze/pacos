
extern zend_class_entry *pacos_utils_parser_ce;

ZEPHIR_INIT_CLASS(Pacos_Utils_Parser);

PHP_METHOD(Pacos_Utils_Parser, properties);
PHP_METHOD(Pacos_Utils_Parser, translateValue);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_utils_parser_properties, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, content, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, content)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_utils_parser_translatevalue, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pacos_utils_parser_method_entry) {
	PHP_ME(Pacos_Utils_Parser, properties, arginfo_pacos_utils_parser_properties, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Pacos_Utils_Parser, translateValue, arginfo_pacos_utils_parser_translatevalue, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
