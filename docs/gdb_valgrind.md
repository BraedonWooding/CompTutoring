# GDB and Valgrind

!> Sorry I don't really use windows enough (for C) to be able to give you good suggestions for debuggers, if you find any please feel free to let me know and I'll place the info here.

Note: Don't use gdb or valgrind with anything BUT `gcc`.  To compile the code use `-g` like `gcc in.c -g`, NOTE: On MacOSX you need to use `-gdwarf`.

## GDB (Linux / CSE)

There are 2 different ways to use GDB the basic way is; `gdb ex.out` you can also add `-tui` (like `gdb ex.out -tui`).

Once loaded type `run` or `r` to run the command.

Here are a few useful commands (I'm going to run a few examples during the lab).

- you can use `--args <program> <args>` to parse command line arguments i.e. `gdb --args ./my_file.out 2 4 9`
- `next` or `n` go to the next line (won't 'step' into functions)
- `step` or `s` go to the next line and step inside functions
- `continue` or `c` will just keep running till it reaches a breakpoint
- `breakpoint` or `b` followed by EITHER a line or a function
  - i.e. `b MyFile.c:100`, `b MyFunction`
- `print` or `p` prints out an expression.  NOTE: any expression will work
  - i.e. `p head->next->next` will work but it'll print out a pointer if you want to see inside I suggest doing `p *head->next->next`
- `where` shows the current call stack
- `where full` shows all current variables as well
- `info locals` prints all local variables
- `watch` can be used to watch for a variable to change
  - i.e. `watch x == 2`
  - you can also just say `watch x` to print out x for each point

## LLDB (Mac version of GDB)

Only differences are:

- instead of `info locals` do `frame variable` or `fr var`
- `bt` is good to print out the entire stack call trace
- To pass arguments you just add a -- before the arguments i.e. `lldb ./a.out -- 1 2 3 4`.

## Valgrind

To use valgrind just write it like; `valgrind --leak-check=full ./a.out`

The `--leak-check=full` just writes a ton of memory leak information to stdout that indicates which variables weren't freed and more importantly also where they were allocated and how.  Extremely important information!!!
