# @file Makefile

# ANSI colors for stdout
GREEN=\033[0;92m
RED=\033[0;91m
MAGENTA=\033[0;95m
RESET=\033[0m

CC := gcc
DEBUG_CFLAGS += -Wall -Wextra -O0 -g -pedantic -DDEBUG
RELEASE_CFLAGS := -O3 -DNDEBUG
COMMON_CFLAGS := -std=c99
CFLAGS := $(DEBUG_CFLAGS)

# Determine build type
ifeq ($(RELEASE),1)
	CFLAGS := $(COMMON_CFLAGS) $(RELEASE_CFLAGS)
else
	CFLAGS := $(COMMON_CFLAGS) $(DEBUG_CFLAGS)
endif

LDFLAGS :=
LIBS =

EXECUTABLE := DEFAULT

SRCS := $(wildcard *.c)
HDRS := $(wildcard *.h)
OBJS := $(patsubst %.c, %.o, $(SRCS))

.PHONY: all clean help run

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	@echo "🔧 Linking ${MAGENTA}$@${RESET} ..."
	@$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS) && \
		echo "$(GREEN)✅ Build successful: $@$(RESET)" || \
		(echo "$(RED)❌ Linking failed: $@$(RESET)" && exit 1)

%.o: %.c
	@echo "🔧 Compiling ${MAGENTA}$<${RESET} ..."
	@$(CC) $(CFLAGS) -c $< -o $@ && \
		echo "$(GREEN)✅ Compiled: $<$(RESET)" || \
		(echo "$(RED)❌ Compile failed: $<$(RESET)" && exit 1)

clean:
	@echo "${MAGENTA}make clean${RESET} $(RM) -r $(EXECUTABLE) $(OBJS) *~ *.bak *.dSYM *.out"
	@$(RM) -r $(EXECUTABLE) $(OBJS) *~ *.bak *.dSYM *.out .*.un~

run: $(EXECUTABLE)
	@echo "${MAGENTA}make run${RESET}"
	@make clean
	@make all
	@./$(EXECUTABLE)

help:
	@echo "${MAGENTA}make help${RESET}"
	@echo "Makefile for Building ${MAGENTA}${EXECUTABLE}${RESET}."
	@echo "Usage:"
	@echo "  ${MAGENTA}make${RESET}             — debug build"
	@echo "  ${MAGENTA}make DEBUG=1${RESET}     — force debug build"
	@echo "  ${MAGENTA}make RELEASE=1${RESET}   — release build"
	@echo "  ${MAGENTA}make clean${RESET}       — remove built files"
	@echo "  ${MAGENTA}make run${RESET}         — run program"

