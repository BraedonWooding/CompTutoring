#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *a = fopen(argv[1], "r");
    FILE *b = fopen(argv[2], "r");
    char a_buf[1000];
    char b_buf[1000];
    int has_a = 0;
    int has_b = 0;

    // a b c
    // d e f

    while (1) {
        if (!has_a) has_a = fgets(a_buf, 1000, a) != NULL;
        if (!has_b) has_b = fgets(b_buf, 1000, b) != NULL;

        if (has_a && has_b) {
            if (strcmp(a_buf, b_buf) > 0) {
                printf("%s", a_buf);
                has_a = 0;
            } else {
                printf("%s", b_buf);
                has_b = 0;
            }
        } else if (!has_a && has_b) {
            printf("%s", b_buf);
            has_b = 0;
        } else if (has_a && !has_b) {
            printf("%s", a_buf);
            has_a = 0;
        } else {
            break;
        }
    }
}