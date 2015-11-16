/*
  +----------------------------------------------------------------------+
  | PHP Output Converter                                                 |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2015 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Scholer Liu <scholer_l@live.com>                             |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef PHP_CONVERTER_H
#define PHP_CONVERTER_H

extern zend_module_entry converter_module_entry;
#define phpext_converter_ptr &converter_module_entry

#define PHP_CONVERTER_VERSION "0.1.0" /* Replace with version number for your extension */

#ifdef PHP_WIN32
# define PHP_CONVERTER_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
# define PHP_CONVERTER_API __attribute__ ((visibility("default")))
#else
# define PHP_CONVERTER_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(converter);
PHP_MSHUTDOWN_FUNCTION(converter);
PHP_RINIT_FUNCTION(converter);
PHP_RSHUTDOWN_FUNCTION(converter);
PHP_MINFO_FUNCTION(converter);

PHP_FUNCTION(str_convert);


ZEND_BEGIN_MODULE_GLOBALS(converter)
    char *dictionary;
    long *auto_convert;

    zval *search;
    zval *replace;
ZEND_END_MODULE_GLOBALS(converter)

/* In every utility function you add that needs to use variables
   in php_converter_globals, call TSRMLS_FETCH(); after declaring other
   variables used by that function, or better yet, pass in TSRMLS_CC
   after the last function argument and declare your utility function
   with TSRMLS_DC after the last declared argument.  Always refer to
   the globals in your function as CONVERTER_G(variable).  You are
   encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/

#ifdef ZTS
#define CONVERTER_G(v) TSRMG(converter_globals_id, zend_converter_globals *, v)
#else
#define CONVERTER_G(v) (converter_globals.v)
#endif


int conveter_str_convert(zval *zstring, zval *str_converted);

#endif  /* PHP_CONVERTER_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
