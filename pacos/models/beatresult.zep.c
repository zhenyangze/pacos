
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


ZEPHIR_INIT_CLASS(Pacos_Models_BeatResult) {

	ZEPHIR_REGISTER_CLASS(Pacos\\Models, BeatResult, pacos, models_beatresult, NULL, 0);

	/**
	 * @var int
	 */
	zend_declare_property_null(pacos_models_beatresult_ce, SL("clientBeatInterval"), ZEND_ACC_PUBLIC);

	return SUCCESS;

}

