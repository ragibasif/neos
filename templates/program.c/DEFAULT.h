/**
 * @file DEFAULT.h
 * @brief One-line description of the header's purpose
 *
 * @author [Ragib Asif](https://github.com/ragibasif)
 * @date YYYY-MM-DD
 * @version 1.0.0
 * @copyright MIT License
 */

#ifndef __DEFAULT_H__
#define __DEFAULT_H__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


/******************************************************************************/
/*                                                                    VERSION */
/******************************************************************************/

/* --- Version Information --- */
#define DEFAULT_VERSION_MAJOR    1     /**< Major version (API-breaking changes) */
#define DEFAULT_VERSION_MINOR    0     /**< Minor version (backwards-compatible additions) */
#define DEFAULT_VERSION_PATCH    0     /**< Patch version (bug fixes) */

/* String representation of version */
#define DEFAULT_VERSION_STRING  "1.0.0"

/* Version comparison macros (useful for dependency checks) */
#define DEFAULT_VERSION_CHECK(major, minor, patch) \
    ((major) < DEFAULT_VERSION_MAJOR || \
    ((major) == DEFAULT_VERSION_MAJOR && (minor) < DEFAULT_VERSION_MINOR) || \
    ((major) == DEFAULT_VERSION_MAJOR && (minor) == DEFAULT_VERSION_MINOR && (patch) <= DEFAULT_VERSION_PATCH))

/******************************************************************************/
/*                                                                   INCLUDES */
/******************************************************************************/

/******************************************************************************/
/*                                                                     MACROS */
/******************************************************************************/

/**
 * @brief Brief description of the macro's purpose
 *
 * Detailed description including any special considerations.
 *
 * @param x Description of macro parameter (if applicable)
 */
#define MY_MACRO(x) ((x) * 2)

/******************************************************************************/
/*                                                                   TYPEDEFS */
/******************************************************************************/

/**
 * @brief Brief description of the type
 *
 * Detailed description of what this type represents and how it should be used.
 */
typedef struct {
    int member1;    /**< Description of member1 */
    float member2; /**< Description of member2 */
} my_struct_t;

/******************************************************************************/
/*                                                                      ENUMS */
/******************************************************************************/

/**
 * @brief Brief description of the enum's purpose
 *
 * Detailed description of when and how to use these values.
 */
typedef enum {
    VALUE1, /**< Description of VALUE1 */
    VALUE2, /**< Description of VALUE2 */
    VALUE3  /**< Description of VALUE3 */
} my_enum_t;

/******************************************************************************/
/*                                                                    STRUCTS */
/******************************************************************************/

/******************************************************************************/
/*                                                                        API */
/******************************************************************************/


/**
 * @brief Brief one-line description of the function
 *
 * Detailed description of the function's purpose and behavior.
 *
 * @param param1 Description of first parameter
 * @param param2 Description of second parameter
 * @return Description of return value
 * @note Any important notes about usage
 * @warning Any critical warnings about the function
 * @see Related functions or resources
 * @example
 *   // Example usage
 *   int result = my_function(1, 2);
 */
int my_function(int param1, int param2);


#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __DEFAULT_H__

/******************************************************************************/
/*                                                                     AUTHOR */
/******************************************************************************/

/**
 * Author:              Ragib Asif
 * Email:               ragib.asif30@myhunter.cuny.edu
 * GitHub:              https://github.com/ragibasif
 * LinkedIn:            https://www.linkedin.com/in/ragibasif/
 */

/******************************************************************************/
/*                                                                DESCRIPTION */
/******************************************************************************/

/**
 * <This is a default C header file.>
 * Detailed description of the header file contents. This should explain:
 * - What functionality is declared in this header
 * - Any important concepts or usage patterns
 * - Relationships to other headers/files
 */

/******************************************************************************/
/*                                                                      USAGE */
/******************************************************************************/

/**
 * <Describe how to use this program.>
 */

/******************************************************************************/
/*                                                                      NOTES */
/******************************************************************************/

/**
 *  - <Notes go here.>
 *  - <TODO: Example 'todo'.>
 *  - <FIXME: Example 'fixme'.>
 */

/******************************************************************************/
/*                                                       MODIFICATION HISTORY */
/******************************************************************************/

/**
 *  - <All modification dates go here>
 */

/******************************************************************************/
/*                                                                 REFERENCES */
/******************************************************************************/

/**
 *  - <Any references go here.>
 */

/******************************************************************************/
/*                                                        SEMANTIC VERSIONING */
/******************************************************************************/

/**
 * [Semantic Versioning 2.0.0](https://semver.org/)
 *
 * Given a version number MAJOR.MINOR.PATCH, increment the:
 * 1. MAJOR version when you make incompatible API changes
 * 2. MINOR version when you add functionality in a backward compatible manner
 * 3. PATCH version when you make backward compatible bug fixes
 *
 * Additional labels for pre-release and build metadata are available as
 * extensions to the MAJOR.MINOR.PATCH format.
 */

/******************************************************************************/
/*                                                                    LICENSE */
/******************************************************************************/

/**
 * [The MIT License](https://opensource.org/license/mit)
 *
 * Copyright (c) 2025 Ragib Asif
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/******************************************************************************/
/*                                                                      EXTRA */
/******************************************************************************/
// # C Standard Library Cheat Sheet (with Linker Flags)
//
// | Header | Category | Example Functions / Macros | Linker Flag |
// |--------|----------|-----------------------------|-------------|
// | `#include <assert.h>` | Diagnostics | `assert()` | *(none)* |
// | `#include <complex.h>` | Complex Arithmetic | `cabs()`, `cexp()`, `cpow()` | `-lm` |
// | `#include <ctype.h>` | Character Classification | `isalpha()`, `isdigit()`, `isalnum()`, `isspace()`, `toupper()`, `tolower()` | *(none)* |
// | `#include <errno.h>` | Error Handling | `errno`, `EDOM`, `ERANGE` | *(none)* |
// | `#include <fenv.h>` | Floating-Point Environment | `feclearexcept()`, `fetestexcept()` | `-lm` |
// | `#include <float.h>` | Floating Point Limits | `FLT_MAX`, `DBL_MIN`, `FLT_EPSILON`, `LDBL_MAX` | *(none)* |
// | `#include <inttypes.h>` | Integer Types and Format | `intmax_t`, `PRId32`, `strtoimax()` | *(none)* |
// | `#include <iso646.h>` | Alternative Operators | `and`, `or`, `not` | *(none)* |
// | `#include <limits.h>` | Integer Limits | `INT_MAX`, `INT_MIN`, `CHAR_MAX`, `LONG_MAX`, `SHRT_MIN` | *(none)* |
// | `#include <locale.h>` | Localization | `setlocale()`, `localeconv()` | *(none)* |
// | `#include <math.h>` | Mathematics | `pow()`, `sqrt()`, `log()`, `exp()`, `sin()`, `cos()`, `tan()`, `fabs()`, `ceil()`, `floor()` | `-lm` |
// | `#include <setjmp.h>` | Non-local Jumps | `setjmp()`, `longjmp()` | *(none)* |
// | `#include <signal.h>` | Signal Handling | `signal()`, `raise()`, `SIGINT`, `SIGTERM` | *(none)* |
// | `#include <stdarg.h>` | Variadic Functions | `va_start()`, `va_arg()`, `va_end()` | *(none)* |
// | `#include <stdbool.h>` | Boolean Type *(C99+)* | `bool`, `true`, `false` | *(none)* |
// | `#include <stddef.h>` | Common Macros & Types | `size_t`, `ptrdiff_t`, `NULL`, `offsetof()` | *(none)* |
// | `#include <stdint.h>` | Fixed-Width Integers *(C99+)* | `int8_t`, `uint16_t`, `int32_t`, `INT64_MAX`, `UINT8_MAX` | *(none)* |
// | `#include <stdio.h>` | I/O (Input/Output) | `printf()`, `scanf()`, `fgets()`, `puts()`, `fopen()`, `fclose()`, `fread()`, `fwrite()`, `fprintf()`, `fscanf()`, `getc()`, `putc()` | *(none)* |
// | `#include <stdlib.h>` | General Utilities | `malloc()`, `calloc()`, `realloc()`, `free()`, `exit()`, `atoi()`, `atof()`, `rand()`, `srand()`, `abs()`, `system()` | *(none)* |
// | `#include <string.h>` | Strings & Memory | `strlen()`, `strcpy()`, `strncmp()`, `strcat()`, `strchr()`, `strstr()`, `memcpy()`, `memmove()`, `memset()` | *(none)* |
// | `#include <tgmath.h>` | Type-generic Math (C99) | `tgamma()`, `cabs()` (wraps `<math.h>` / `<complex.h>`) | `-lm` |
// | `#include <time.h>` | Time/Date | `time()`, `clock()`, `difftime()`, `mktime()`, `localtime()`, `gmtime()`, `strftime()` | *(none)* |
// | `#include <wchar.h>` | Wide Characters | `wprintf()`, `wcslen()`, `wcscpy()` | *(none)* |
// | `#include <wctype.h>` | Wide Character Classification | `iswalpha()`, `towlower()` | *(none)* |
