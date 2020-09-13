#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_ori(uint8_t rt, uint8_t rs, int32_t I);
void process_or(uint8_t rd, uint8_t rs, uint8_t rt);

// ./miniasm or '$8' '$9' '$8' "syscall" ori '$8' '$9' 90

/*
    [
       [ '$', '0', '\0' ]
               ^&argv[i][1]
               ^argv[i] + 1
          ^argv[i]
    ],
    [
       [ '$', '1', '\0' ]
    ]
 */

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        if (strcmp("ori", argv[i]) == 0) {
            process_ori(atoi(argv[i + 1]), atoi(argv[i + 2]), atoi(argv[i + 3]));
        } else if (strcmp("or", argv[i]) == 0) {
            process_or(atoi(argv[i + 1]), atoi(argv[i + 2]), atoi(argv[i + 3]));
        } else if (strcmp("syscall", argv[i]) == 0) {
            printf("0xC\n");
        }
    }
}

void process_ori(uint8_t rt, uint8_t rs, int32_t I) {
    uint32_t result = (0xD << 26) | ((rs & 0x1f) << 21) | ((rt & 0x1f) << 16) | (I & 0xFFFF);
    printf("0x%X\n", result);
}

void process_or(uint8_t rd, uint8_t rs, uint8_t rt) {
    uint32_t result = (0x0 << 26) | ((rs & 0x1f) << 21) | ((rt & 0x1f) << 16) | ((rd & 0x1f) << 11) | 0x20;
    printf("0x%X\n", result);
}