#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main (int argc, char **argv) {
    if (argc < 1) {
        printf("Usage: %s files... \n", argv[0]);
        return 0;
    }

    if (argc==1) {
        argv[1] = ".";
        argc++;
    }

    for (int i = 1; i < argc; i++) {
        
    }
}