MAGENTA=\033[0;95m
RESET=\033[0m
# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wshadow -Wall -Wextra -pedantic -O2 -Wno-unused-result -g -D_GLIBCXX_DEBUG

# Source file(s)
SRCS = $(wildcard *.cpp)
# Name of the output executable
TARGET = solve

default: all
# Targets
all: $(TARGET)

$(TARGET): $(SRCS)
	@echo "${MAGENTA}make all${RESET} $(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)"
	@$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)


# Clean up build files.
# Clean Target: Remove compiled files and object files
clean:
	@echo "${MAGENTA}make clean${RESET} $(RM) -r $(TARGET) *~ *.bak *.dSYM *.out *.o"
	@$(RM) -r $(TARGET) *~ *.bak *.dSYM *.out *.o

run:
	@echo "${MAGENTA}make run${RESET} ./run.sh"
	@./run.sh

# Prevents Make from treating them as actual files
# Phony targets
.PHONY: all clean default help run


help:
	@echo "${MAGENTA}make help${RESET}"
	@echo "Makefile for Building ${MAGENTA}${TARGET}${RESET}."
	@echo "Usage: ${MAGENTA}make${RESET} [ ${MAGENTA}all${RESET} | ${MAGENTA}clean${RESET} | ${MAGENTA}help${RESET} | ${MAGENTA}run${RESET} ]"

