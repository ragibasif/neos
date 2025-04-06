#################################################################################
#
# Make commands:
# `make`
# `make all`
# `make clean`
#
#################################################################################

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
#
# ANSI colors for stdout
GREEN=\033[0;92m
RED=\033[0;91m
MAGENTA=\033[0;95m
RESET=\033[0m


# CXX := g++
# CXXFLAGS := -std=c++17 -Wshadow -Wall -Wextra -pedantic -O2 -Wno-unused-result -g -D_GLIBCXX_DEBUG
CC := gcc
DEBUG_CFLAGS += -Wall -Wextra -O0 -g -pedantic -DDEBUG
# -03 -DNDEBUG for release build
RELEASE_CFLAGS := -O3 -DNDEBUG
COMMON_CFLAGS := -std=c99 -Iinclude
CFLAGS := $(DEBUG_CFLAGS)
# CFLAGS := -std=c99 $(RELEASE_CFLAGS)
#
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

# Executable name
# executable name, name of the final program
EXECUTABLE := $(BUILD_DIRECTORY)/DEFAULT

# Wildcards and pattern substitution
# Source and object files
SRCS := $(wildcard $(SOURCE_DIRECTORY)/*.c)
HDRS := $(wildcard $(INCLUDE_DIRECTORY)/*.c)
# need to use pattern substitution because objects files may not always exist
OBJS := $(patsubst $(SOURCE_DIRECTORY)/%.c, $(BUILD_DIRECTORY)/%.o, $(SRCS))



# Default rule
default: all


# This line uses the special target ".PHONY". It says that the word "clean", "all", etc.,
# are all phony targets. So even if there is a file named "clean" in the directory,
# make will ignore it and run the rule for the phony target "clean".
.PHONY: all clean default help run install

all: $(EXECUTABLE)


# Automatic variables:
#   $@  name of target
#   $^  list of all prerequisites of the target separated by spaces
#   $?  list of prerequisites for the current target that are newer than
#       the target separated by  spaces
#   $<  name of the first prerequisite. If the target got its recipe
#       from an implicit rule, this is the first prerequisite added by the
#       implicit rule.

# name the executable whatever the name of the target is,
# and to compile using all of the prerequisites then echo the changed prerequisites
#
# $(EXECUTABLE): $(OBJS)
# 	@echo "${MAGENTA}make all${RESET} $(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)"
# 	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)
# 	@ echo Changed files: $?

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



# RM - is 'rm -f' by default
# The "*.o" is expanded by the shell to include all .o files in the current directory.
# Clean build files

clean:
	@echo "${MAGENTA}make clean${RESET} $(RM) -r $(EXECUTABLE) $(OBJS) $(INSTALL_DIRECTORY) $(BUILD_DIRECTORY) *~ *.bak *.dSYM *.out .install"
	@$(RM) -r $(EXECUTABLE) $(OBJS) $(INSTALL_DIRECTORY) $(BUILD_DIRECTORY) *~ *.bak *.dSYM *.out .install


# Optional: run the program
run: $(EXECUTABLE)
	@echo "${MAGENTA}make run${RESET}"
	@make clean
	@$(EXECUTABLE)

# run:
# 	@echo "${MAGENTA}make run${RESET} ./run.sh"
# 	@./run.sh


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
	@echo "  ${MAGENTA}make run${RESET}         — run program using ./run.sh"
	@echo "  ${MAGENTA}make install${RESET}     — install binary to $(INSTALL_DIRECTORY)"

#################################################################################
# References:
#
# 1. [Stewart Weiss Make-Tutorial](https://gitlab.com/stewartweiss/Make-Tutorial)
#
