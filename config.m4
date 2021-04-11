PHP_ARG_ENABLE(pacos, whether to enable pacos, [ --enable-pacos   Enable Pacos])

if test "$PHP_PACOS" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, PACOS_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_PACOS, 1, [Whether you have Pacos])
	pacos_sources="pacos.c kernel/main.c kernel/memory.c kernel/exception.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c pacos/exceptions/pacosexception.zep.c
	pacos/client.zep.c
	pacos/exceptions/pacosnamingnotfound.zep.c
	pacos/exceptions/pacosrequestexception.zep.c
	pacos/clients.zep.c
	pacos/config.zep.c
	pacos/exceptions/pacosconfignotfound.zep.c
	pacos/exceptions/pacosnamingnoaliveinstance.zep.c
	pacos/instance.zep.c
	pacos/models/beatinfo.zep.c
	pacos/models/beatresult.zep.c
	pacos/models/configinfo.zep.c
	pacos/models/serviceinstance.zep.c
	pacos/models/serviceinstancelist.zep.c
	pacos/utils/http.zep.c
	pacos/utils/parser.zep.c
	pacos/utils/response.zep.c
	pacos/utils/selector.zep.c
	pacos/0__closure.zep.c
	pacos/1__closure.zep.c "
	PHP_NEW_EXTENSION(pacos, $pacos_sources, $ext_shared,, )
	PHP_ADD_BUILD_DIR([$ext_builddir/kernel/])
	PHP_ADD_BUILD_DIR([$ext_builddir/pacos/])
	PHP_SUBST(PACOS_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([pacos], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([pacos], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/pacos], [php_PACOS.h])

fi
