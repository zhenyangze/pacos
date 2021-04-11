
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


ZEPHIR_INIT_CLASS(Pacos_Exceptions_PacosNamingNoAliveInstance) {

	ZEPHIR_REGISTER_CLASS_EX(Pacos\\Exceptions, PacosNamingNoAliveInstance, pacos, exceptions_pacosnamingnoaliveinstance, pacos_exceptions_pacosnamingnotfound_ce, NULL, 0);

	return SUCCESS;

}

