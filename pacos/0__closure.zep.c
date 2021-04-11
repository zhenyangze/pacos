
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
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(pacos_0__closure) {

	ZEPHIR_REGISTER_CLASS(pacos, 0__closure, pacos, 0__closure, pacos_0__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(pacos_0__closure, __invoke) {

	zval *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &value);



	RETURN_BOOL(!(Z_TYPE_P(value) == IS_NULL));

}

