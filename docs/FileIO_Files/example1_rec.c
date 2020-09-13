#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUF_SIZE (1000)

// Each recursive call is going to require 1000bytes (about 1kb)
// meaning that you can stack overflow pretty easily...
// in this case I was lazy an generated a file of 10,000 numbers (each number
// is counted as a separate word) that is going to use up 10 MB of memory
// this ends up segfaulting.  However it will work on the malloc examples.
void print_words_backwards() {
    char buffer[MAX_BUF_SIZE + 1];

    if (scanf("%s", buffer) == 1) {
        print_words_backwards();
        printf("%s\n", buffer);
    } else {
        printf("\n\n== And now each word in reverse ==\n\n");
    }
}

int main(void) {
    print_words_backwards();

    return 0;
}
