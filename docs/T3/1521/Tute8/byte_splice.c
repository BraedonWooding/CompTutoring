#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void usage(void) {
    printf(
        "./byte_splice <filepath> aStart aEnd <aOut> bStart bEnd <bOut> ...\n"
    );
}

int minimum(int a, int b) {
    return a < b ? a : b;
}

int main(int argc, char *argv[]) {
    if (argc < 2 || (argc - 2) % 3 != 0) {
        fprintf(stderr, "Invalid Arguments...\n");
        usage();
        exit(1);
    }

    char *filename = argv[1];
    int i = 2;
    FILE *f_in = fopen(filename, "rb");
    if (!f_in) {
        perror(filename);
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
        fseek(f_out, start, SEEK_SET);
        char buf[1024];
        int totalToRead = end - start;
        while (totalToRead > 0) {
            int len = fread(buf, 1, minimum(1024, totalToRead), f_in);
            if (len == 0) break;
            fwrite(buf, 1, len, f_out);
            totalToRead -= len;
        }
    }
    
    close(f_in);
}
