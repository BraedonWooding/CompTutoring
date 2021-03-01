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
    if (n <= 1) return 1;
    else        return fib_rec(n - 1) + fib_rec(n - 2);
}

// 1, 1, 2, 3, 5, 8, 13, ...

int fib_upwards(int n) {
    if (n <= 1) return 1;

    int prev = 1;
    int cur = 1;

    for (int i = 2; i <= n; i++) {
        int next = prev + cur;
        prev = cur;
        cur = next;
    }

    return cur;
}

int fib_memo(int n) {
    static int cached[100000] = {1, 1};

    if (cached[n] == 0) {
        cached[n] = fib_memo(n - 1) + fib_memo(n - 2);
    }

    return cached[n];
}
