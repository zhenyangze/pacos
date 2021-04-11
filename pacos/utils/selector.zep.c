
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Pacos_Utils_Selector) {

	ZEPHIR_REGISTER_CLASS(Pacos\\Utils, Selector, pacos, utils_selector, pacos_utils_selector_method_entry, 0);

	return SUCCESS;

}

/**
 * 权重+随机选择 instance
 *
 * @param ServiceInstance[] instances
 * @return ServiceInstance
 * @throws \Exception
 */
PHP_METHOD(Pacos_Utils_Selector, randomByWeight) {

	zend_bool sameWeight, _3, _8, _7$$4, _11$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, _4, _5, _12$$6, _13$$6;
	zval *instances_param = NULL, length, firstWeight, _1, weights, _2, totalWeight, i, weight, offset, _16, _17, _18, _19, _0$$3, _6$$4, _9$$6, _10$$6, _14$$7, _15$$8;
	zval instances;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&instances);
	ZVAL_UNDEF(&length);
	ZVAL_UNDEF(&firstWeight);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&weights);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&totalWeight);
	ZVAL_UNDEF(&i);
	ZVAL_UNDEF(&weight);
	ZVAL_UNDEF(&offset);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &instances_param);

	zephir_get_arrval(&instances, instances_param);


	ZEPHIR_INIT_VAR(&length);
	ZVAL_LONG(&length, zephir_fast_count_int(&instances));
	if (ZEPHIR_IS_LONG_IDENTICAL(&length, 1)) {
		zephir_array_fetch_long(&_0$$3, &instances, 0, PH_NOISY | PH_READONLY, "pacos/Utils/Selector.zep", 20);
		RETURN_CTOR(&_0$$3);
	}
	sameWeight = 1;
	zephir_array_fetch_long(&_1, &instances, 0, PH_NOISY | PH_READONLY, "pacos/Utils/Selector.zep", 25);
	ZEPHIR_CALL_METHOD(&firstWeight, &_1, "getweightdouble", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&weights);
	array_init(&weights);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 1, 0);
	zephir_array_update_long(&_2, 0, &firstWeight, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	ZEPHIR_CPY_WRT(&weights, &_2);
	ZEPHIR_CPY_WRT(&totalWeight, &firstWeight);
	ZEPHIR_INIT_VAR(&i);
	ZVAL_LONG(&i, 1);
	_5 = (zephir_get_numberval(&length) - 1);
	_4 = 1;
	_3 = 0;
	if (_4 <= _5) {
		while (1) {
			if (_3) {
				_4++;
				if (!(_4 <= _5)) {
					break;
				}
			} else {
				_3 = 1;
			}
			ZEPHIR_INIT_NVAR(&i);
			ZVAL_LONG(&i, _4);
			zephir_array_fetch(&_6$$4, &instances, &i, PH_NOISY | PH_READONLY, "pacos/Utils/Selector.zep", 35);
			ZEPHIR_CALL_METHOD(&weight, &_6$$4, "getweightdouble", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_zval(&weights, &i, &weight, PH_COPY | PH_SEPARATE);
			ZEPHIR_ADD_ASSIGN(&totalWeight, &weight);
			_7$$4 = sameWeight;
			if (_7$$4) {
				_7$$4 = !ZEPHIR_IS_EQUAL(&weight, &firstWeight);
			}
			if (_7$$4) {
				sameWeight = 0;
			}
		}
	}
	_8 = (ZEPHIR_GT_LONG(&totalWeight, 0));
	if (_8) {
		_8 = (sameWeight == 0);
	}
	if (_8) {
		ZVAL_LONG(&_9$$6, 0);
		ZVAL_LONG(&_10$$6, (zephir_get_numberval(&totalWeight) - 1));
		ZEPHIR_CALL_FUNCTION(&offset, "random_int", NULL, 42, &_9$$6, &_10$$6);
		zephir_check_call_status();
		_13$$6 = (zephir_get_numberval(&length) - 1);
		_12$$6 = 1;
		_11$$6 = 0;
		if (_12$$6 <= _13$$6) {
			while (1) {
				if (_11$$6) {
					_12$$6++;
					if (!(_12$$6 <= _13$$6)) {
						break;
					}
				} else {
					_11$$6 = 1;
				}
				ZEPHIR_INIT_NVAR(&i);
				ZVAL_LONG(&i, _12$$6);
				zephir_array_fetch(&_14$$7, &weights, &i, PH_NOISY | PH_READONLY, "pacos/Utils/Selector.zep", 49);
				ZEPHIR_SUB_ASSIGN(&offset, &_14$$7);
				if (ZEPHIR_LT_LONG(&offset, 0)) {
					zephir_array_fetch(&_15$$8, &instances, &i, PH_NOISY | PH_READONLY, "pacos/Utils/Selector.zep", 51);
					RETURN_CTOR(&_15$$8);
				}
			}
		}
	}
	ZVAL_LONG(&_17, 0);
	ZVAL_LONG(&_18, (zephir_get_numberval(&length) - 1));
	ZEPHIR_CALL_FUNCTION(&_19, "random_int", NULL, 42, &_17, &_18);
	zephir_check_call_status();
	zephir_array_fetch(&_16, &instances, &_19, PH_NOISY | PH_READONLY, "pacos/Utils/Selector.zep", 57);
	RETURN_CTOR(&_16);

}

