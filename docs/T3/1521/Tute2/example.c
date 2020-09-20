#include <stdio.h>

int main(void) {
    union {
        double f;
        int x;
    } swap = {.f = 4.3373};
    printf("%f %d\n", swap.f, swap.x);
}