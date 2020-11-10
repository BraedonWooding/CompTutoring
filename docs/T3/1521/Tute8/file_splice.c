#include <stdio.h>
#include <stdlib.h>

// Filename: "1"
// hey
// cats
// what's
// up
// dawgs

// ./file_splice "./1" 1 3 "./o1" 1 4 "./o2" 5 6 "./o3"

// Filename: "o1"
// hey
// cats

// Filename: "o2"
// hey
// cats
// what's

// Filename: "o3"
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
    
    for (int arg = 2; arg < argc; arg += 3) {
        char *endptr = NULL;
        int start = (int)strtol(argv[arg], &endptr, 10);
        if (!endptr || *endptr != '\0') {
            fprintf(stderr, "Error: not a number %s\n", argv[arg]);
            usage();
            exit(1);
        }
        
        endptr = NULL;
        int end = (int)strtol(argv[arg + 1], &endptr, 10);
        if (!endptr || *endptr != '\0') {
            fprintf(stderr, "Error: not a number %s\n", argv[arg + 1]);
            usage();
            exit(1);
        }
        
        FILE *f_out = fopen(argv[arg + 2], "w");
        
        int line = 1;
        while (line < start) {
            int c = fgetc(f_in);
            if (c == EOF) {
                break;
            } else if (c == '\n') {
                line++;
            }
        }
        
        while (line < end) {
            int c = fgetc(f_in);
            if (c == EOF) {
                break;
            } else if (c == '\n') {
                line++;
            }
            
            if (line < end) fputc(c, f_out);
        }

        rewind(f_in);
    }
    
    fclose(f_in);
}
