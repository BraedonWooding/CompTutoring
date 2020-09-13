/*
 * Step by step boore's moore with checking
 * Please only run on CSE (it will work on any posix system -- probably)
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearScreen(void) { system("clear"); }

void printLastOccurences(int lastOccurences[26]) {
    int first = 1;
    printf("L = { ");
    for (int i = 0; i < 26; i++) {
        if (lastOccurences[i] != -1) {
            printf("%s%c: %d", first ? "" : ", ", i + 'a', lastOccurences[i]);
            first = 0;
        }
    }
    printf(" }\n");
}

void printState(char *text, char *pattern, int i, int j) {
    printf("T: ");
    int diff = i - j;
    if (diff < 0)
        for (int k = 0; k < -diff; k++) putchar(' ');
    puts(text);
    int end = 3 + i;
    if (diff < 0) end += -diff;
    for (int k = 0; k < end; k++) putchar(' ');
    printf("^i\n");

    printf("P: ");
    if (diff > 0)
        for (int k = 0; k < diff; k++) putchar(' ');
    puts(pattern);
    end = 3 + j;
    if (diff > 0) end += diff;
    for (int k = 0; k < end; k++) putchar(' ');
    printf("^j\n");
}

void buildLastOccurence(char *pattern, int alphabet[26]) {
    int i = 0;
    memset(alphabet, -1, sizeof(int) * 26);
    while (pattern[i] != '\0') {
        // taking alphabet as a-z
        assert(pattern[i] >= 'a' && pattern[i] <= 'z');
        alphabet[pattern[i] - 'a'] = i;
        i++;
    }
}

// lower case alphabet of a-z
// returns starting index of match or -1 if no match
int boyer_moore(char *text, char *pattern) {
    int lastOccurences[26];
    buildLastOccurence(pattern, lastOccurences);
    int i = strlen(pattern) - 1;
    int j = i;
    int numCompares = 0;

    // to keep to the style of the lectures
    // you normally would write this as a while though
    do {
        clearScreen();
        printf("Comparing text[%d] '%c' to pattern[%d] '%c'\n", i, text[i], j,
               pattern[j]);
        printLastOccurences(lastOccurences);
        printState(text, pattern, i, j);

        numCompares++;
        if (text[i] == pattern[j]) {
            // we found a character match
            if (j == 0) {
                // no more pattern to look for
                printf("Total number of comparisons is %d\n", numCompares);
                return i;
            } else {
                // we still have pattern to match
                printf("Simple match of text[%d] = pattern[%d] = %c\n", i, j, text[j]);
                i--;
                j--;
            }
        } else {
            // failure state
            int min = 1 + lastOccurences[(int)text[i] - 'a'];
            if (lastOccurences[(int)text[i] - 'a'] == -1) {
                printf("There is no occurence of %c in pattern therefore we are going to shift the pattern by %d (length of pattern)\n", text[i], strlen(pattern));
            } else if (j < min) {
                printf("I can't align text[%d] with pattern[%d] because then pattern will be off the left side of text so we are going to effectively just shift the pattern right\n", i, j);
                min = j;
            } else {
                printf("Moving to align text[%d] = %c with pattern[%d]\n", i, text[i], lastOccurences[(int)text[i] - 'a']);
            }
            i += strlen(pattern) - min;
            j = strlen(pattern) - 1;
        }

        printf("Press enter to continue: ");
        getchar();
    } while (i < (int)strlen(text));
    // ^^ not a very elegant way to handle size_t
    //    but our strings won't be large enough to care
    //    in reality we probably would use ssize_t or something

    printf("Total number of comparisons is %d\n", numCompares);
    return -1;
}

void convertToLower(char *str) {
    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 'a' - 'A';
        } else if (str[i] < 'a' || str[i] > 'z') {
            fprintf(stderr, "Not a valid string must be between a-z");
            exit(1);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(
            stderr,
            "Need to give pattern and text as ./boyer_moore <text> <pattern>");
        return 1;
    }

    convertToLower(argv[1]);
    convertToLower(argv[2]);

    int substring = boyer_moore(argv[1], argv[2]);
    if (substring == -1) {
        printf("No match\n");
    } else {
        printf("Match starting at %d\n", substring);
    }

    return 0;
}
