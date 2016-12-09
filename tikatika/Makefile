CC = gcc

CSRCS = $(shell ls *.c 2> /dev/null)
CXXSRCS = $(shell ls *.cpp 2> /dev/null)
OBJS = $(CSRCS:.c=.o) $(CXXSRCS:.cpp=.o)
	HEADS = $(shell ls *.h 2> /dev/null) $(shell ls *.hpp 2> /dev/null)

CFLAGS = -O3 -g -Wall
LFLAGS = -lrt -lgpiommap

PROD = ./a.out

all: $(PROD)

$(PROD): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

.SUFFIXES: .c .cpp .o
.c.o:
	$(CC) $(CFLAGS) -c $< $(LFLAGS)
.cpp.o:
	$(CC) $(CFLAGS) -c $< $(LFLAGS)

$(OBJS): $(HEADS)

clean:
	rm -f $(PROD) $(OBJS)
