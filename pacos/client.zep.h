
extern zend_class_entry *pacos_client_ce;

ZEPHIR_INIT_CLASS(Pacos_Client);

PHP_METHOD(Pacos_Client, __construct);
PHP_METHOD(Pacos_Client, getVar);
PHP_METHOD(Pacos_Client, setNamespace);
PHP_METHOD(Pacos_Client, setTimeout);
PHP_METHOD(Pacos_Client, request);
PHP_METHOD(Pacos_Client, assertResponse);
PHP_METHOD(Pacos_Client, limit);
zend_object *zephir_init_properties_Pacos_Client(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_client___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, endpoint, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, endpoint)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, port, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, port)
#endif
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_client_setnamespace, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, _namespace, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, _namespace)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_client_settimeout, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, timeout, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, timeout)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_client_request, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, method)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, uri)
#endif
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_client_assertresponse, 0, 0, 3)
	ZEND_ARG_INFO(0, resp)
	ZEND_ARG_INFO(0, expected)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_client_limit, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, diff, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, diff)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pacos_client_method_entry) {
	PHP_ME(Pacos_Client, __construct, arginfo_pacos_client___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Pacos_Client, getVar, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Pacos_Client, setNamespace, arginfo_pacos_client_setnamespace, ZEND_ACC_PUBLIC)
	PHP_ME(Pacos_Client, setTimeout, arginfo_pacos_client_settimeout, ZEND_ACC_PUBLIC)
	PHP_ME(Pacos_Client, request, arginfo_pacos_client_request, ZEND_ACC_PROTECTED)
	PHP_ME(Pacos_Client, assertResponse, arginfo_pacos_client_assertresponse, ZEND_ACC_PROTECTED)
	PHP_ME(Pacos_Client, limit, arginfo_pacos_client_limit, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
