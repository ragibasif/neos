CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O0
SRC := $(wildcard *.cpp)
EXECUTABLE := solve

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRCS)
	@$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) $(SRC)

clean:
	@$(RM) -r $(EXECUTABLE) *~ *.bak *.dSYM *.out *.o .*.un~

run:
	@make clean
	@make all
	@./$(EXECUTABLE)

.PHONY: all clean run
