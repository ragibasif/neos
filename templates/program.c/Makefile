################################################################################
# MAKEFILE                                                                     #
################################################################################
#
# Make commands:
# `make`
# `make all`
# `make clean`
# `make test`
#
################################################################################

# Makefile rules:
#     TARGET ... : PREREQUISITE ...
#     <tab char> RECIPE
#
# TARGET - name of generated file(s) (executable or object)
# PREREQUISITE - input file(s) needed to create the TARGET
# RECIPE - command(s) that generate the TARGET
# <tab char> - all indentations are made by tabs not spaces
#
# Make is recursive, if one PREREQUISITE changes, the RECIPE is rerun to generate a new TARGET
#
# To execute make commands:
# make - runs the first TARGET in the Makefile
# make TARGET - to run a specific TARGET rule


# Variables:
#     VAR = value
# or
#     VAR := value
#
# "=" - recursively expanded variables (The expression is not evaluated until the variable is actually used)
# ":=" - simply expanded variables (the expression is evaluated as soon as it is assigned)
#
# Can use variables by:
#    $(VAR)  or ${VAR}
#
# leading spaces are ignored but trailing spaces are not
# compilation flags
# Make has implicit variables with predefined rules, but you can override them
# CC        Program for compiling C programs; default ‘cc’.
# CXX       Program for compiling C++ programs; default ‘g++’.
# CPP       Program for running the C preprocessor, with results to standard
#               output; default ‘$(CC) -E’.
# CFLAGS    Extra flags to give to the C compiler.
# CXXFLAGS  Extra flags to give to the C++ compiler.
# LDFLAGS   Extra flags to give to compilers when they are supposed to invoke
#               the linker, ‘ld’.
# RM        Command to remove a file; default ‘rm -f’. (-f means "force" )
#
# Some are defined in the ENVIRONMENT and others are defined in make's database.

# compiler flags
# -Wall -Werror -Wextra -O0 -pedantic -DDEBUG for debug build
# -Weverything: Display all warnings
# -Wall       : Enable all common warnings to catch potential issues
# -Wextra     : Enable extra warnings for stricter code checking
# -Werror     : Treat warnings as errors
# -std=c99    : Enforce C99 standard compliance
# -O0         : No optimization (useful for debugging)
# -O1         : Optimize for size and speed with minimal transformations
# -O2         : Optimize more aggressively while maintaining stability
# -O3         : Enable maximum optimization, including aggressive inlining
# -Os         : Optimize for smallest binary size
# -Og         : Optimize while preserving debugging information
# -march=native: Optimize code for the current machine architecture
# -fPIC       : Generate position-independent code (for shared libraries)
# -fstack-protector-strong : Adds stack protection against buffer overflows
# -g          : Include debugging symbols
# -DNDEBUG    : Disable assertions
# -fno-strict-aliasing : Prevents strict aliasing optimizations
#
## Automatic variables:
#   $@  name of target
#   $^  list of all prerequisites of the target separated by spaces
#   $?  list of prerequisites for the current target that are newer than
#       the target separated by  spaces
#   $<  name of the first prerequisite. If the target got its recipe
#       from an implicit rule, this is the first prerequisite added by the
#       implicit rule.
#
#

# ANSI colors for stdout
GREEN=\033[0;92m
RED=\033[0;91m
MAGENTA=\033[0;95m
RESET=\033[0m

CC := gcc
DEBUG_CFLAGS := -Wall -Wextra -O0 -g -pedantic -DDEBUG
RELEASE_CFLAGS := -O3 -DNDEBUG
COMMON_CFLAGS := -std=c99 -Iinclude
CFLAGS := $(DEBUG_CFLAGS)

# Determine build type
ifeq ($(RELEASE),1)
	CFLAGS := $(COMMON_CFLAGS) $(RELEASE_CFLAGS)
else
	CFLAGS := $(COMMON_CFLAGS) $(DEBUG_CFLAGS)
endif

#linker flags: -v, -lm, -lefence
LDFLAGS :=
LIBS =

# Directories
INSTALL_DIRECTORY := bin
SOURCE_DIRECTORY := src
INCLUDE_DIRECTORY := include
BUILD_DIRECTORY := build
TEST_DIRECTORY := tests

# Executable name
# executable name, name of the final program
EXECUTABLE := $(BUILD_DIRECTORY)/DEFAULT

# Wildcards and pattern substitution
# Source and object files
SRCS := $(wildcard $(SOURCE_DIRECTORY)/*.c)
HDRS := $(wildcard $(INCLUDE_DIRECTORY)/*.h)
# need to use pattern substitution because objects files may not always exist
OBJS := $(patsubst $(SOURCE_DIRECTORY)/%.c, $(BUILD_DIRECTORY)/%.o, $(SRCS))

TEST_SRCS := $(wildcard $(TEST_DIRECTORY)/*.c)
TEST_BINS := $(patsubst $(TEST_DIRECTORY)/%.c, $(BUILD_DIRECTORY)/t_%, $(TEST_SRCS))



# This line uses the special target ".PHONY". It says that the word "clean", "all", etc.,
# are all phony targets. So even if there is a file named "clean" in the directory,
# make will ignore it and run the rule for the phony target "clean".
.PHONY: all clean help run install test

all: $(EXECUTABLE)




# Build executable with colored success/failure
# Link objects into the final executable
$(EXECUTABLE): $(OBJS)
	@echo "🔧 Linking ${MAGENTA}$@${RESET} ..."
	@mkdir -p $(BUILD_DIRECTORY)
	@$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS) && \
		echo "$(GREEN)✅ Build successful: $@$(RESET)" || \
		(echo "$(RED)❌ Linking failed: $@$(RESET)" && exit 1)

# This tells Make how to build any .o file from its corresponding .c file.
# Compile .c files to .o files
$(BUILD_DIRECTORY)/%.o: $(SOURCE_DIRECTORY)/%.c
	@echo "🔧 Compiling ${MAGENTA}$<${RESET} ..."
	@mkdir -p $(BUILD_DIRECTORY)
	@$(CC) $(CFLAGS) -c $< -o $@ && \
		echo "$(GREEN)✅ Compiled: $<$(RESET)" || \
		(echo "$(RED)❌ Compile failed: $<$(RESET)" && exit 1)



test: $(TEST_BINS)

# Build test executables
$(BUILD_DIRECTORY)/test_%: $(TEST_DIRECTORY)/%.c $(wildcard $(INCLUDE_DIRECTORY)/*.h)
	@echo "🧪 Compiling test ${MAGENTA}$<${RESET} ..."
	@mkdir -p $(BUILD_DIRECTORY)
	@$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS) && \
		echo "$(GREEN)✅ Test build successful: $@$(RESET)" || \
		(echo "$(RED)❌ Test build failed: $<$(RESET)" && exit 1)


# RM - is 'rm -f' by default
# The "*.o" is expanded by the shell to include all .o files in the current directory.
# Clean build files

clean:
	@echo "${MAGENTA}make clean${RESET} $(RM) -r $(EXECUTABLE) $(OBJS) $(INSTALL_DIRECTORY) $(BUILD_DIRECTORY) *~ *.bak *.dSYM *.out .install"
	@$(RM) -r $(EXECUTABLE) $(OBJS) $(INSTALL_DIRECTORY) $(BUILD_DIRECTORY) *~ *.bak *.dSYM *.out .install .*.un~


# Optional: run the program
run: $(EXECUTABLE)
	@echo "${MAGENTA}make run${RESET}"
	@./$(EXECUTABLE)



# It is common to supply a "make install" command when providing software
# packages for distribution.
install: $(EXECUTABLE)
	@ if [ ! -d $(INSTALL_DIRECTORY) ] ; then mkdir -p $(INSTALL_DIRECTORY) ; fi
	@cp $(EXECUTABLE) $(INSTALL_DIRECTORY)
	@touch .install && echo $(shell date) >> .install

# Since make is verbose by default, the "@" turns off echoing


help:
	@echo "${MAGENTA}make help${RESET}"
	@echo "Makefile for Building ${MAGENTA}${EXECUTABLE}${RESET}."
	@echo "Usage:"
	@echo "  ${MAGENTA}make${RESET}             — debug build"
	@echo "  ${MAGENTA}make DEBUG=1${RESET}     — force debug build"
	@echo "  ${MAGENTA}make RELEASE=1${RESET}   — release build"
	@echo "  ${MAGENTA}make clean${RESET}       — remove built files"
	@echo "  ${MAGENTA}make run${RESET}         — run program"
	@echo "  ${MAGENTA}make install${RESET}     — install binary to $(INSTALL_DIRECTORY)"

################################################################################
# COMPILATION FLAGS                                                            #
################################################################################
#
#
#### 🔧 Note on Linker Flags
#
# - Most headers do **not** need extra linker flags (they're part of the standard C library).
# - `math.h` **requires** linking with the **math library**:
#
# ```bash
# gcc my_program.c -o my_program -lm
# ```
#
#
# ## ⚒️ Compiler Flags (GCC)
#
# ### ⚙️ General Compilation
#
# - `-c`: Compile source files into object files without linking.
# - `-o <file>`: Specify the output file name.
# - `-v`: Enable verbose output, showing the compilation steps.
# - `-pipe`: Use pipes rather than temporary files during compilation.
#
# ### 🧪 Debugging
#
# - `-g`: Generate debug information for use with debuggers like `gdb`.
# - `-ggdb`: Produce debug information specifically tailored for `gdb`.
# - `-grecord-gcc-switches`: Embed the compiler command-line options into the binary.
#
# ### 🚀 Optimization
#
# - `-O0`: No optimization (default).
# - `-O1`, `-O2`, `-O3`: Increasing levels of optimization.
# - `-Os`: Optimize for size.
# - `-Ofast`: Enable aggressive, non-standard compliant optimizations.
# - `-funroll-loops`, `-funroll-all-loops`: Unroll loops to improve performance.
# - `-ftree-parallelize-loops=N`: Attempt to parallelize loops using N threads.
#
# ### ⚠️ Warnings and Errors
#
# - `-Wall`: Enable most common warnings.
# - `-Wextra`: Enable additional warnings.
# - `-Werror`: Treat all warnings as errors.
# - `-Wshadow`: Warn when a local variable shadows another.
# - `-Wundef`: Warn if an undefined macro is used in `#if`.
# - `-Wstrict-prototypes`: Warn if functions lack argument types.
# - `-Wconversion`: Warn for implicit conversions.
# - `-Wfloat-equal`: Warn when comparing floating-point values for equality.
# - `-Wcast-align`: Warn about misaligned pointer casts.
# - `-Wwrite-strings`: Make string literals `const` qualified.
# - `-Wswitch-enum`: Warn when switch does not cover all enum values.
# - `-Wstrict-overflow=5`: Warn about signed overflow assumptions.
#
# ### 🔐 Security and Hardening
#
# - `-D_FORTIFY_SOURCE=2`: Enable additional checks for functions like `sprintf`.
# - `-fstack-protector-strong`: Enable stack protection.
# - `-fstack-clash-protection`: Protect against stack clash attacks.
# - `-fcf-protection`, `-mcet`: Enable control-flow protection.
# - `-fpie`, `-fPIE`: Generate position-independent code (PIE).
# - `-fpic`, `-fPIC`: Generate position-independent code for shared libraries.
#
# ### 🧹 Preprocessor and Macros
#
# - `-D<macro>[=<value>]`: Define a macro.
# - `-U<macro>`: Undefine a macro.
# - `-I<dir>`: Add directory for header file search.
# - `-include <file>`: Include a file before compiling each source file.
#
# ### 🧪 Sanitizers and Instrumentation
#
# - `-fsanitize=address`: Enable AddressSanitizer.
# - `-fsanitize=undefined`: Enable UndefinedBehaviorSanitizer.
# - `-fsanitize=thread`: Enable ThreadSanitizer.
# - `-finstrument-functions`: Instrument function entry and exit.
#
#
# ## 🔗 Linker Flags
#
# ### 📦 Linking and Libraries
#
# - `-l<library>`: Link with the specified library (e.g., `-lm`).
# - `-L<dir>`: Add directory to search for libraries.
# - `-Wl,<option>`: Pass options to the linker.
# - `-Wl,--gc-sections`: Remove unused sections.
# - `-Wl,--strip-all`: Strip all symbols from the binary.
# - `-Wl,-O2`: Optimize the linking process.
#

################################################################################
# REFERENCES                                                                   #
################################################################################
#
# - [Stewart Weiss Make-Tutorial](https://gitlab.com/stewartweiss/Make-Tutorial)
# - [GCC Manual](https://gcc.gnu.org/onlinedocs/)
# - [GCC Command Options](https://gcc.gnu.org/onlinedocs/gcc/Option-Summary.html)
# - [GCC Optimization Options](https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html)
# - [GCC Warning Options](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html)
# - [GCC Debugging Options](https://gcc.gnu.org/onlinedocs/gcc/Debugging-Options.html)
# - [GCC Preprocessor Options](https://gcc.gnu.org/onlinedocs/cpp/Invocation.html)
# - [GCC Sanitizers](https://gcc.gnu.org/onlinedocs/gcc/Instrumentation-Options.html)
# - [Wikipedia - C standard library](https://en.wikipedia.org/wiki/C_standard_library)
# - [CPP Reference - C Standard Library headers](https://en.cppreference.com/w/c/header)
# - [Stack Overflow - What are the useful GCC flags for C?](https://stackoverflow.com/questions/3375697/what-are-the-useful-gcc-flags-for-c)
