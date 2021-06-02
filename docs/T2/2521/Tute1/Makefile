IDIR=include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR=lib

EDIR=bin

LIBS=-lm

all: $(EDIR)/test

_DEPS = cbench.h obsidian.h recursion.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = tests.o fib.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EDIR)/test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(EDIR)/* $(ODIR)/*.o *.log