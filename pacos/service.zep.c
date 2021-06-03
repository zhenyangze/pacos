
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Pacos_Service) {

	ZEPHIR_REGISTER_CLASS(Pacos, Service, pacos, service, pacos_service_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Pacos_Service, register) {

	zval *this_ptr = getThis();



}

PHP_METHOD(Pacos_Service, update) {

	zval *this_ptr = getThis();



}

PHP_METHOD(Pacos_Service, deelte) {

	zval *this_ptr = getThis();



}

