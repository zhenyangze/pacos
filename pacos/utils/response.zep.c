
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"


/**
 * Short description for Response.php
 *
 * @package Response
 * @author zhenyangze <zhenyangze@gmail.com>
 * @version 0.1
 * @copyright (C) 2021 zhenyangze <zhenyangze@gmail.com>
 * @license MIT
 */
/**
 * response
 */
ZEPHIR_INIT_CLASS(Pacos_Utils_Response) {

	ZEPHIR_REGISTER_CLASS(Pacos\\Utils, Response, pacos, utils_response, pacos_utils_response_method_entry, 0);

	/**
	 * 
	 */
	zend_declare_property_null(pacos_utils_response_ce, SL("contents"), ZEND_ACC_PROTECTED);

	/**
	 * 
	 */
	zend_declare_property_null(pacos_utils_response_ce, SL("httpStatus"), ZEND_ACC_PROTECTED);

	return SUCCESS;

}

/**
 * __construct 
 *
 * @param contents
 * @param httpStatus
 *
 * @return 
 */
PHP_METHOD(Pacos_Utils_Response, __construct) {

	zval *contents, contents_sub, *httpStatus, httpStatus_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&contents_sub);
	ZVAL_UNDEF(&httpStatus_sub);

	zephir_fetch_params_without_memory_grow(2, 0, &contents, &httpStatus);



	zephir_update_property_zval(this_ptr, ZEND_STRL("contents"), contents);
	zephir_update_property_zval(this_ptr, ZEND_STRL("httpStatus"), httpStatus);

}

/**
 * getBody 
 *
 * @return 
 */
PHP_METHOD(Pacos_Utils_Response, getBody) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "contents");

}

/**
 * getStatusCode 
 *
 * @return 
 */
PHP_METHOD(Pacos_Utils_Response, getStatusCode) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("httpStatus"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("http_code"), PH_NOISY | PH_READONLY, "pacos/Utils/Response.zep", 58);
	RETURN_CTORW(&_1);

}

/**
 * getHttpStatus 
 *
 * @return 
 */
PHP_METHOD(Pacos_Utils_Response, getHttpStatus) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "httpStatus");

}

/**
 * __toString 
 *
 * @return 
 */
PHP_METHOD(Pacos_Utils_Response, __toString) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getbody", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

