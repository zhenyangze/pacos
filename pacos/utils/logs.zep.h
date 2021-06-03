
extern zend_class_entry *pacos_utils_logs_ce;

ZEPHIR_INIT_CLASS(Pacos_Utils_Logs);

PHP_METHOD(Pacos_Utils_Logs, log);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_utils_logs_log, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, category, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, category)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, info, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, info)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, debug, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, debug)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pacos_utils_logs_method_entry) {
	PHP_ME(Pacos_Utils_Logs, log, arginfo_pacos_utils_logs_log, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
