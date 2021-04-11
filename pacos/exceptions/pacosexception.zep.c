
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
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(Pacos_Exceptions_PacosException) {

	ZEPHIR_REGISTER_CLASS_EX(Pacos\\Exceptions, PacosException, pacos, exceptions_pacosexception, spl_ce_RuntimeException, NULL, 0);

	return SUCCESS;

}

