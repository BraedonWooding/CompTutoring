#include "recursion.h"


/*
                             fib(5)
                            /     \
                           /       \
                          /         \
                         /           \
                       fib(4)          ------fib(3)---
                      /       \                /      \
                   fib(3)      fib(2)         fib(2)  fib(1)
                  /   \         /     \        /   \
                fib(2) fib(1)  fib(1) fib(0) fib(1) fib(0)
                /    \
              fib(1) fib(0)
 */

    /*

        1, 1, 2, 3, 5, 8, 13, 21, ...

        fib(n) =
            IF n <= 1: 1
            OTHERWISE: fib(n - 1) + fib(n - 2)

     */

/*



 */

int fib_rec(int n) {
}

// 1, 1, 2, 3, 5, 8, 13, ...

int fib_upwards(int n) {
}

int fib_memo(int n) {
