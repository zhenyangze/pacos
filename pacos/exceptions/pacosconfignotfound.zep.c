
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Pacos_Exceptions_PacosConfigNotFound) {

	ZEPHIR_REGISTER_CLASS_EX(Pacos\\Exceptions, PacosConfigNotFound, pacos, exceptions_pacosconfignotfound, pacos_exceptions_pacosrequestexception_ce, NULL, 0);

	zend_declare_property_long(pacos_exceptions_pacosconfignotfound_ce, SL("code"), 404, ZEND_ACC_PROTECTED);

	return SUCCESS;

}

