#include "recursion.h"

#include <stdlib.h>
#include <stdio.h>

#include "include/cbench.h"

int main(void) {
    volatile int *result = malloc(sizeof *result);

    // generate base fib data
    FILE *f = fopen("generatedFibData_Recursive.csv", "w");
    fprintf(f, "Time,N\n");
    
    for (int i = 1; i < 45; i++) {
        cbenchTime start = cbenchGetTime();
        // trick to get it to not optimise the function call
        // without having a very slow sys call or something
        *result = fib_rec(i);
        cbenchTime end = cbenchGetTime();
        double diff = end.userTime - start.userTime;
        printf("%d\n", i);
        
        fprintf(f, "%lf,%d\n", diff, i);
    }
    
    fclose(f);
    
    // generate iterative
    f = fopen("generatedFibData_Iterative.csv", "w");
    fprintf(f, "Time,N\n");
    
    for (int i = 1; i < 1000000; i++) {
        cbenchTime start = cbenchGetTime();
        // trick to get it to not optimise the function call
        // without having a very slow sys call or something
        *result = fib_upwards(i);
        cbenchTime end = cbenchGetTime();
        double diff = end.userTime - start.userTime;
        
        fprintf(f, "%lf,%d\n", diff, i);
    }
    
    fclose(f);
    
    // generate memo
    f = fopen("generatedFibData_Memo.csv", "w");
    fprintf(f, "Time,N\n");

    for (int i = 1; i < 100000; i++) {
        cbenchTime start = cbenchGetTime();
        // trick to get it to not optimise the function call
        // without having a very slow sys call or something
        *result = fib_memo(i);
        cbenchTime end = cbenchGetTime();
        double diff = end.userTime - start.userTime;
        fprintf(f, "%lf,%d\n", diff, i);
    }
    
    fclose(f);
}
