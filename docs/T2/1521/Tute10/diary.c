#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ./diary
// ./diary --file $HOME/.diary

/*
.data
prompt:
    .asciiz "Hello World\n"
*/

/*
    addi    $sp, $sp, -4
    add     $sp, $sp, $t0
 */

int main(int argc, char *argv[]) {
    const char *diary_path = getenv("HOME");
    char diary_buffer[strlen(diary_path) + strlen("/.diary") + 1];
    snprintf(diary_buffer, sizeof(diary_buffer), "%s/.diary", diary_path);

    FILE *stream = fopen(diary_buffer, "r");
    if (!stream) {
        perror(diary_buffer);
        exit(1);
    }
    
    int byte;
    while((byte = fgetc(stream)) != EOF) {
        fputc(byte, stdout);
    }
    fclose(stream);
    return 0;
}
