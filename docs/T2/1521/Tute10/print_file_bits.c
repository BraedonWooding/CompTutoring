#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ./diary
// .diary $HOME/.diary

/*
.data
prompt:
    .asciiz "Hello World\n"
*/

int main(int argc, char *argv[]) {
    char *file = argv[1];

    FILE *stream = fopen(file, "r");
    if (!stream) {
        perror(file);
        exit(1);
    }
    
    int32_t number;
    while (fscanf(stream, "%x", &number)) {
        // 0b101010...10101010 1111 0111
        // 0b111111...11111111 1111 0111
        int32_t low_byte = number & 0xFF;
        if (low_byte & 1 << 7) {
            /*
                0000 0000 0001 0000 0000
                1111 1111 1111 0000 0000
                               1111 1111
                
            */
        
            low_byte = -(int32_t)(1 << 8) + low_byte;
        }
        printf("%d\n", low_byte);
    }

    fclose(stream);
    return 0;
}
