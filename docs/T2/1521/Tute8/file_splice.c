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
    
    for (int i = 2; i < argc; i += 3) {
        char *endptr = NULL;
        long start = strtol(argv[i], &endptr, 10);
        if (!endptr || *endptr != '\0') {
            printf("%s is not a number\n", argv[i]);
            usage();
            exit(1);
        }
        
        endptr = NULL;
        long end = strtol(argv[i + 1], &endptr, 10);
        if (!endptr || *endptr != '\0') {
            printf("%s is not a number\n", argv[i + 1]);
            usage();
            exit(1);
        }
        
        char *filename_out = argv[i + 2];
        FILE *f_out = fopen(filename_out, "w");
        // 0 -> 1, ~ -> 0
        if (!f_out) {
            perror(filename_out);
            usage();
            exit(1);
        }
        
        int cur = 1;
        while (cur < start) {
            int c = fgetc(f_in);
            if (c == '\n') cur++;
            else if (c == EOF) break;
        }
        
        while (cur < end) {
            int c = fgetc(f_in);
            if (c == '\n') cur++;
            else if (c == EOF) break;

            if (c != '\n' || cur != end) {
                fputc(c, f_out);
            }
        }

        rewind(f_in);
        fclose(f_out);
    }
    
    fclose(f_in);
}
