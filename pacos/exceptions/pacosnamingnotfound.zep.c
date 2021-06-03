
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


ZEPHIR_INIT_CLASS(Pacos_Exceptions_PacosNamingNotFound) {

	ZEPHIR_REGISTER_CLASS_EX(Pacos\\Exceptions, PacosNamingNotFound, pacos, exceptions_pacosnamingnotfound, pacos_exceptions_pacosexception_ce, NULL, 0);

	return SUCCESS;

}

