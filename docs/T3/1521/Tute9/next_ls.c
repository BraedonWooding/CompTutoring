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
#include <fts.h>

int main (int argc, char **argv, char **envp) {
    if (argc <= 1) {
        printf("Usage: %s files... \n", argv[0]);
        return 0;
    }
    
    FTS *ftsp = fts_open(argv + 1, FTS_LOGICAL | FTS_NOCHDIR, NULL);
    if (ftsp == NULL) {
        perror("fts");
        exit(1);
    }

    while (1) {
        FTSENT *entry = fts_read(ftsp); // get next entry (file OR directory)
        if (entry == NULL) {
            if (errno == 0) {
                break; // finished!
            } else {
                perror("fts_read");
                exit(1);
            }
        }

        if (entry->fts_info & FTS_SL) {
            printf("Symlink %s\n", entry->fts_name);
        } else if (entry->fts_info & FTS_D) {
            printf("Directory %s\n", entry->fts_path);
        } else if (entry->fts_info & FTS_F) {
            printf("File %s\n", entry->fts_path);
        }
    }
    
    if (fts_close(ftsp) != 0) {
        perror("fts_close");
        exit(1);
    }
    
    return 0;
}