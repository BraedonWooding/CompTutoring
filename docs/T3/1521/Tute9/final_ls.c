#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ftw.h>
#include <errno.h>
#include <dirent.h>
#include <fts.h>
#include <limits.h>
#include <string.h>

void recurse(char *path) {
    char fullpath[PATH_MAX + 1];
    strcpy(fullpath, path);
    size_t len = strlen(fullpath);

    DIR *dir = opendir(path);
    if (dir == NULL) {
        return;
    }
    
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_LNK) {
            printf("Symlink %s\n", entry->d_name);
        } else if (entry->d_type == DT_REG) {
            printf("File %s\n", entry->d_name);
        } else if (entry->d_type == DT_DIR &&
                   strcmp(entry->d_name, ".") && strcmp(entry->d_name, "..")) {
            printf("Directory %s\n", entry->d_name);
            fullpath[len] = '/';
            fullpath[len + 1] = '\0';
            strcpy(fullpath + len + 1, entry->d_name);
            recurse(fullpath);
        }
    }
    
    closedir(dir);
}

int main (int argc, char **argv, char **envp) {
    if (argc <= 1) {
        printf("Usage: %s files... \n", argv[0]);
        return 0;
    }
    
    for (int arg = 1; arg < argc; arg++) {
        recurse(argv[arg]);
    }
    
    return 0;
}