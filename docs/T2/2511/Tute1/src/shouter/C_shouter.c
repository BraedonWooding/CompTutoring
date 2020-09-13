#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // for toupper/tolower

/**
    This code shows roughly what Shouter could look like if we wrote it in C
    we'll build on this idea and do V-Table's next week!

    I've used 'const' here since I don't want to allocate the msg's (it would
    complicate the implementation) so I've just resorted to encouraging constant
    strings.
 **/

typedef struct shouter_t {
    const char *msg;
} Shouter;

// This is like a 'constructor'
void init(Shouter *shouter, const char *msg) {
    shouter->msg = msg;
}

// Notice the similarity to init
// This is pretty similar to how the java constructor / setMsg are similar
void setMsg(Shouter *shouter, const char *msg) {
    shouter->msg = msg;
}

const char *getMsg(Shouter *shouter) {
    return shouter->msg;
}

void whisper(Shouter *shouter) {
    for (const char *c = shouter->msg; *c; c++) {
        putchar(tolower(*c));
    }
    putchar('\n');
}

void shout(Shouter *shouter) {
    for (const char *c = shouter->msg; *c; c++) {
        putchar(toupper(*c));
    }
    putchar('\n');
}

int main(void) {
    // NOTE: How 'new' becomes a malloc -> init
    Shouter *shouter = malloc(sizeof(Shouter));
    init(shouter, "COMP2511");
    shout(shouter);
    whisper(shouter);

    setMsg(shouter, "Yayyy");
    shout(shouter);
    whisper(shouter);
}