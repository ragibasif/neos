# TODO:
#
#

# compilation flags
CFLAGS= -O2 -Wall -std=c99
#linker flags
LDFLAGS=

.PHONY: all clean

all: clean DEFAULT

DEFAULT: DEFAULT.o
	cc $(CFLAGS) $^ -o $@ $(LDFLAGS)

DEFAULT.o: DEFAULT.c DEFAULT.h
	cc $(CFLAGS) -c $<

clean:
	rm -f *.o DEFAULT
