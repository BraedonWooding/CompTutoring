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
        FILE *f_out = fopen(filename_out, "wb");
        if (f_out == NULL) {
            perror(filename_out);
            usage();
            exit(1);
        }
        
        fseek(f_in, start, SEEK_SET);
        // 5000 to read
        // 5000 - 1024 = 3976 - 1024 = 2952 - 1024 = 1928 - 1024
        //             = 904 - 1024 = 0
        int amount_to_read = end - start;
        char buf[1024];
        int bytes = 0;

        // buffer is only 1024 bytes big
        // so don't try to read more than 1024
        // but also only read the minimum(amount_to_read, 1024)
        while (amount_to_read > 0 &&
              (bytes = fread(buf, 1, minimum(amount_to_read, 1024), f_in)) > 0) {
            fwrite(buf, 1, bytes, f_out);
            amount_to_read -= bytes;
        }
        
        // int cur = 1;
        // while (cur < start) {
        //     // 0 <-> 255
        //     // also -1
        //     int c = fgetc(f_in);
        //     if (c == EOF) break;
        //     cur++;
        // }
        
        // while (cur < end) {
        //     int c = fgetc(f_in);
        //     if (c == EOF) break;
        //     cur++;
        //     fputc(c, f_out);
        // }

        fclose(f_out);
    }
    
    close(f_in);
}
