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

int fib_rec(int n) { 
    if (n <= 1) return 1;
    else        return fib_rec(n - 1) + fib_rec(n - 2);
}

int fib_upwards(int n) {
    // Not needed since if n <= 1
    // then !(i < n) i.e. i >= n;
    if (n <= 1) return 1;

    int prev = 1;
    int cur = 1;
    int i = 1;
    while (i < n) {
        /**
            prev = 1;
            cur = 1;
            
            tmp = 2;
            prev = 1;
            cur = 2;
            
            tmp = 3;
            prev = 2;
            cur = 3;
         **/
    
        int tmp = prev + cur;
        prev = cur;
        cur = tmp;
        i++;
    }
    return cur;
}

int fib_memo(int n) {
    // initialised to 1, 1 followed by zeros
    // zeroes mean no calcuated value for that 'n'
    static int fib_array[250] = {1, 1};

    // if it has a value, fib_array[n] will be non-zero
    if (fib_array[n] == 0) {
        fib_array[n] = fib_memo(n - 1) + fib_memo(n - 2);
    }

    return fib_array[n];
}
