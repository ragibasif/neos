# 🤟 C

## 📘 C Standard Library Cheat Sheet (with Linker Flags)

| Header | Category | Example Functions / Macros | Linker Flag |
|--------|----------|-----------------------------|-------------|
| `#include <assert.h>` | Diagnostics | `assert()` | *(none)* |
| `#include <complex.h>` | Complex Arithmetic | `cabs()`, `cexp()`, `cpow()` | `-lm` |
| `#include <ctype.h>` | Character Classification | `isalpha()`, `isdigit()`, `isalnum()`, `isspace()`, `toupper()`, `tolower()` | *(none)* |
| `#include <errno.h>` | Error Handling | `errno`, `EDOM`, `ERANGE` | *(none)* |
| `#include <fenv.h>` | Floating-Point Environment | `feclearexcept()`, `fetestexcept()` | `-lm` |
| `#include <float.h>` | Floating Point Limits | `FLT_MAX`, `DBL_MIN`, `FLT_EPSILON`, `LDBL_MAX` | *(none)* |
| `#include <inttypes.h>` | Integer Types and Format | `intmax_t`, `PRId32`, `strtoimax()` | *(none)* |
| `#include <iso646.h>` | Alternative Operators | `and`, `or`, `not` | *(none)* |
| `#include <limits.h>` | Integer Limits | `INT_MAX`, `INT_MIN`, `CHAR_MAX`, `LONG_MAX`, `SHRT_MIN` | *(none)* |
| `#include <locale.h>` | Localization | `setlocale()`, `localeconv()` | *(none)* |
| `#include <math.h>` | Mathematics | `pow()`, `sqrt()`, `log()`, `exp()`, `sin()`, `cos()`, `tan()`, `fabs()`, `ceil()`, `floor()` | `-lm` |
| `#include <setjmp.h>` | Non-local Jumps | `setjmp()`, `longjmp()` | *(none)* |
| `#include <signal.h>` | Signal Handling | `signal()`, `raise()`, `SIGINT`, `SIGTERM` | *(none)* |
| `#include <stdarg.h>` | Variadic Functions | `va_start()`, `va_arg()`, `va_end()` | *(none)* |
| `#include <stdbool.h>` | Boolean Type *(C99+)* | `bool`, `true`, `false` | *(none)* |
| `#include <stddef.h>` | Common Macros & Types | `size_t`, `ptrdiff_t`, `NULL`, `offsetof()` | *(none)* |
| `#include <stdint.h>` | Fixed-Width Integers *(C99+)* | `int8_t`, `uint16_t`, `int32_t`, `INT64_MAX`, `UINT8_MAX` | *(none)* |
| `#include <stdio.h>` | I/O (Input/Output) | `printf()`, `scanf()`, `fgets()`, `puts()`, `fopen()`, `fclose()`, `fread()`, `fwrite()`, `fprintf()`, `fscanf()`, `getc()`, `putc()` | *(none)* |
| `#include <stdlib.h>` | General Utilities | `malloc()`, `calloc()`, `realloc()`, `free()`, `exit()`, `atoi()`, `atof()`, `rand()`, `srand()`, `abs()`, `system()` | *(none)* |
| `#include <string.h>` | Strings & Memory | `strlen()`, `strcpy()`, `strncmp()`, `strcat()`, `strchr()`, `strstr()`, `memcpy()`, `memmove()`, `memset()` | *(none)* |
| `#include <tgmath.h>` | Type-generic Math (C99) | `tgamma()`, `cabs()` (wraps `<math.h>` / `<complex.h>`) | `-lm` |
| `#include <time.h>` | Time/Date | `time()`, `clock()`, `difftime()`, `mktime()`, `localtime()`, `gmtime()`, `strftime()` | *(none)* |
| `#include <wchar.h>` | Wide Characters | `wprintf()`, `wcslen()`, `wcscpy()` | *(none)* |
| `#include <wctype.h>` | Wide Character Classification | `iswalpha()`, `towlower()` | *(none)* |

### 🔧 Note on Linker Flags

- Most headers do **not** need extra linker flags (they're part of the standard C library).
- `math.h` **requires** linking with the **math library**:

```bash
gcc my_program.c -o my_program -lm
```


## ⚒️ Compiler Flags (GCC)

### ⚙️ General Compilation

- `-c`: Compile source files into object files without linking.
- `-o <file>`: Specify the output file name.
- `-v`: Enable verbose output, showing the compilation steps.
- `-pipe`: Use pipes rather than temporary files during compilation.

### 🧪 Debugging

- `-g`: Generate debug information for use with debuggers like `gdb`.
- `-ggdb`: Produce debug information specifically tailored for `gdb`.
- `-grecord-gcc-switches`: Embed the compiler command-line options into the binary.

### 🚀 Optimization

- `-O0`: No optimization (default).
- `-O1`, `-O2`, `-O3`: Increasing levels of optimization.
- `-Os`: Optimize for size.
- `-Ofast`: Enable aggressive, non-standard compliant optimizations.
- `-funroll-loops`, `-funroll-all-loops`: Unroll loops to improve performance.
- `-ftree-parallelize-loops=N`: Attempt to parallelize loops using N threads.

### ⚠️ Warnings and Errors

- `-Wall`: Enable most common warnings.
- `-Wextra`: Enable additional warnings.
- `-Werror`: Treat all warnings as errors.
- `-Wshadow`: Warn when a local variable shadows another.
- `-Wundef`: Warn if an undefined macro is used in `#if`.
- `-Wstrict-prototypes`: Warn if functions lack argument types.
- `-Wconversion`: Warn for implicit conversions.
- `-Wfloat-equal`: Warn when comparing floating-point values for equality.
- `-Wcast-align`: Warn about misaligned pointer casts.
- `-Wwrite-strings`: Make string literals `const` qualified.
- `-Wswitch-enum`: Warn when switch does not cover all enum values.
- `-Wstrict-overflow=5`: Warn about signed overflow assumptions.

### 🔐 Security and Hardening

- `-D_FORTIFY_SOURCE=2`: Enable additional checks for functions like `sprintf`.
- `-fstack-protector-strong`: Enable stack protection.
- `-fstack-clash-protection`: Protect against stack clash attacks.
- `-fcf-protection`, `-mcet`: Enable control-flow protection.
- `-fpie`, `-fPIE`: Generate position-independent code (PIE).
- `-fpic`, `-fPIC`: Generate position-independent code for shared libraries.

### 🧹 Preprocessor and Macros

- `-D<macro>[=<value>]`: Define a macro.
- `-U<macro>`: Undefine a macro.
- `-I<dir>`: Add directory for header file search.
- `-include <file>`: Include a file before compiling each source file.

### 🧪 Sanitizers and Instrumentation

- `-fsanitize=address`: Enable AddressSanitizer.
- `-fsanitize=undefined`: Enable UndefinedBehaviorSanitizer.
- `-fsanitize=thread`: Enable ThreadSanitizer.
- `-finstrument-functions`: Instrument function entry and exit.


## 🔗 Linker Flags

### 📦 Linking and Libraries

- `-l<library>`: Link with the specified library (e.g., `-lm`).
- `-L<dir>`: Add directory to search for libraries.
- `-Wl,<option>`: Pass options to the linker.
- `-Wl,--gc-sections`: Remove unused sections.
- `-Wl,--strip-all`: Strip all symbols from the binary.
- `-Wl,-O2`: Optimize the linking process.


## 📚 References

- [GCC Manual](https://gcc.gnu.org/onlinedocs/)
- [GCC Command Options](https://gcc.gnu.org/onlinedocs/gcc/Option-Summary.html)
- [GCC Optimization Options](https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html)
- [GCC Warning Options](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html)
- [GCC Debugging Options](https://gcc.gnu.org/onlinedocs/gcc/Debugging-Options.html)
- [GCC Preprocessor Options](https://gcc.gnu.org/onlinedocs/cpp/Invocation.html)
- [GCC Sanitizers](https://gcc.gnu.org/onlinedocs/gcc/Instrumentation-Options.html)
- [Wikipedia - C standard library](https://en.wikipedia.org/wiki/C_standard_library)
- [CPP Reference - C Standard Library headers](https://en.cppreference.com/w/c/header)
- [Stack Overflow - What are the useful GCC flags for C?](https://stackoverflow.com/questions/3375697/what-are-the-useful-gcc-flags-for-c)
