#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void usage(void) {
    printf(
        "./byte_splice <filepath> aStart aEnd <aOut> bStart bEnd <bOut> ...\n"
    );
}

int main(int argc, char *argv[]) {
    if (argc < 2 || (argc - 2) % 3 != 0) {
        fprintf(stderr, "Invalid Arguments...\n");
        usage();
        exit(1);
    }

    char *filename = argv[1];
    int i = 2;
    int f_in = open(filename, O_RDONLY);
    if (f_in < 0) {
        perror(filename);
        exit(1);
    }
    
    // while we still have parts to splice up!
    while (i < argc) {
        char *endptr = NULL;
        long start = strtol(argv[i], &endptr, 10);
        if (endptr == NULL || *endptr != '\0') {
            // incorrect number
            fprintf(stderr, "Error: %s is not a number\n", argv[i]);
            exit(1);   
        }

        endptr = NULL;
        long end = strtol(argv[i + 1], &endptr, 10);
        if (endptr == NULL || *endptr != '\0') {
            // incorrect number
            fprintf(stderr, "Error: %s is not a number\n", argv[i + 1]);
            exit(1);
        }

        char *output = argv[i + 2];
        FILE *f_out = fopen(output, "w");
        if (!f_out) {
            perror(output);
            exit(1);
        }
        
        lseek(f_in, start, SEEK_SET);
        // 5000 to read
        // 5000 - 1024 = 3976 - 1924 = 2952 - 1024 = 1928 = 904
        // 
        
        int amount_to_read = end - start;
        char buf[1024];
        int amount_actually_read = 0;

        // socket => networks
        while ((amount_actually_read = read(f_in, buf, amount_to_read < 1024 ? amount_to_read : 1024)) > 0) {
            fwrite(buf, 1, amount_actually_read, f_out);
            amount_to_read -= amount_actually_read;
        }

        fclose(f_out);
        i += 3;
    }
    
    close(f_in);
}
