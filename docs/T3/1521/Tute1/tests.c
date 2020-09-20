// you have to include your benchmarking library before obsidian
#include "cbench.h"
#include "obsidian.h"
#include "recursion.h"
#include <string.h>

int main(int argc, char *argv[]) {
    OBS_SETUP("Benchmarks", argc, argv);
    OBS_BENCHMARK("Fib Upwards", 5, {
        for (int i = 30; i < 40; i++) {
            volatile int _ = fib_upwards(i);
            printf("%d\n", _);
        }
    })
    OBS_BENCHMARK("Fib Recursive", 5, {
        for (int i = 30; i < 40; i++) {
            volatile int _ = fib_rec(i);
            printf("%d\n", _);
        }
    })

    OBS_REPORT;
    return tests_failed;
}