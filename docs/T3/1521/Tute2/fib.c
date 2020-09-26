#define MAX_FIB (40)    

#include <stdio.h>
#include <stdlib.h>

int fib(int n) {
    static int results[MAX_FIB] = {0, 1};
    if (n <= 1) return 1;

    if (results[n] == 0) {
        results[n] = fib(n - 1) + fib(n - 2);
    }

    return results[n];
}

int main(int argc, char *argv[]) {
    printf("%d\n", fib(atoi(argv[1])));
    return 0;
}
