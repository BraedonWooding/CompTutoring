# Make in hopefully < 10 mins

Let's go this bus on the road, hopefully after this you'll be able to write a basic makefile and understand how they work!

## Why makefiles?

In 1511 / others you typically only dealt with one or two files (sometimes a few more) for cases like this running gcc manually is fine!  But as soon as you get like let's say 20 files or a more reasonable 150+ we run into issues very fast.

It gets even more complicated when you start using libraries people created, are you expected to know how to compile thier code?  Have a really long gcc command?  Maybe they require special flags or a special version?  Or maybe require some actions such as running a bash script prior?

Makefiles solve this.  They let you specify a series of commands to execute.

A very simple makefile is as such;

```makefile
# Hashtags are comments

## step 1) choose a compiler
## - you can use gcc, dcc, and others!
## dcc may make debugging issues a little easier! (slightly recommend till
## we talk about gdb)
CC = gcc

# step 2) choose your flags
# these enable:
# -Wall enables more warnings
# -Werror makes all warnings errors
# -g enables debug mode (if running on a mac use -gDwarf except for vlab/remote vscode/ssh)
CFLAGS = -Wall -Werror -g

## step 3) the first 'recipe' will be executed if you don't specify any recipe
## i.e. `make mySecondExecutable` would compile just mySecondExecutable
## where as both `make all` and `make` compile both.
all: myFirstExecutable mySecondExecutable
.PHONY: all # always put this here for all and clean

# to compile my first executable we need the helper recipe along with
# the myFirstExecutable.c soure code
myFirstExecutable: myFirstExecutable.o helper.o

# helper recipe requires both .c and .h
helper.o: helper.c helper.h
# I don't need to specify myFirstExecutable since it just requires the .c file
# I don't have a .h file for this one!

# similar idea here
mySecondExecutable: mySecondExecutable.o helper.o
# these two .c files need to be compiled together (for whatever reason)
mySecondExecutable.o: mySecondExecutable.c mySecondExecutableActions.c mySecondExecutableActions.h

# and now under clean we are going to try to put each recipe on a new line
# this way I can run `make clean` and it'll go and clean up all the extra files
# I generated!!  Very useful / nice.
clean:
    rm -f myFirstExecutable myFirstExecutable.o
    rm -f mySecondExecutable mySecondExecutable.o
    rm -f helper.o
.PHONY: clean
```

## Can they get very complicated?

Yes!  For example below may hurt your head a bit!  That's okay you won't have to write something like this at all in this course so try to just focus on the simple ones for now.

People who write these either write too many of these (i.e. me) or want to show off (i.e. me).

```makefile
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
```
