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
    
    close(f_in);
}
