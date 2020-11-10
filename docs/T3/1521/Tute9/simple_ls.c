#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ftw.h>

int forEachEntry(const char *path, const struct stat *s, int flag) {
    if (flag & FTW_SL) {
        return 0;
    }

    printf("%o\t%s\n", s->st_mode & (S_IRWXU | S_IRWXG | S_IRWXO), path);

    return 0;
}

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
        if (ftw(argv[i], forEachEntry, 20) != 0) {
            perror(argv[i]);
            exit(1);
        }
    }
    
    return 0;
}