CXX = g++
CXXFLAGS = -std=c++17 -Wshadow -Wall -Wextra -pedantic -O2 -Wno-unused-result -g -D_GLIBCXX_DEBUG
SRC = $(wildcard *.cpp)
EXECUTABLE = solve

default: all

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRCS)
	@$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) $(SRC)

clean:
	@$(RM) -r $(EXECUTABLE) *~ *.bak *.dSYM *.out *.o

.PHONY: all clean default run

