#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUF_SIZE (1000)

int main(void) {
    char word[MAX_BUF_SIZE + 1];

    FILE *word_list = fopen("1.in", "r");
    while (fscanf(word_list, "%s", word) == 1) {
        printf("%s\n", word);
    }

    return 0;
}
