
extern zend_class_entry *pacos_models_beatinfo_ce;

ZEPHIR_INIT_CLASS(Pacos_Models_BeatInfo);

PHP_METHOD(Pacos_Models_BeatInfo, jsonSerialize);
PHP_METHOD(Pacos_Models_BeatInfo, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pacos_models_beatinfo___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, info, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pacos_models_beatinfo_method_entry) {
	PHP_ME(Pacos_Models_BeatInfo, jsonSerialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pacos_Models_BeatInfo, __construct, arginfo_pacos_models_beatinfo___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
