#include <stdio.h>
#include <stdlib.h>

// "1"
// hey
// cats
// what's
// up
// dawgs

// ./file_splice "./1" 1 3 "./o1" 1 4 "./o2" 5 6 "./o3"

// "o1"
// hey
// cats

// "o2"
// hey
// cats
// what's

// "o3"
// dawgs

void usage(void) {
    printf(
        "./file_splice <filepath> aStart aEnd <aOut> bStart bEnd <bOut> ...\n"
    );
}

int main(int argc, char *argv[]) {
    if (argc < 2 || (argc - 2) % 3 != 0) {
        fprintf(stderr, "Invalid Arguments...\n");
        usage();
        exit(1);
    }

    char *filename_in = argv[1];
    FILE *f_in = fopen(filename_in, "r");
    // 0 -> 1, ~ -> 0
    if (!f_in) {
        perror(filename_in);
        usage();
        exit(1);
    }
    
    fclose(f_in);
}
