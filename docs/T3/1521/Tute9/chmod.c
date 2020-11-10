// remove public write from specified as command line arguments if needed

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    struct stat s;
    for (int i = 1; i < argc; i++) {
        if (stat(argv[i], &s) != 0) {
            perror(argv[i]);
            exit(1);
        }
    }

    return 0;
}
