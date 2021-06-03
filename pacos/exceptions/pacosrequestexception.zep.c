
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


ZEPHIR_INIT_CLASS(Pacos_Exceptions_PacosRequestException) {

	ZEPHIR_REGISTER_CLASS_EX(Pacos\\Exceptions, PacosRequestException, pacos, exceptions_pacosrequestexception, pacos_exceptions_pacosexception_ce, NULL, 0);

	return SUCCESS;

}

