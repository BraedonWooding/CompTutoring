#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef struct _shouter_t {
    const char *msg;
} Shouter;

void shouter_init(Shouter *this, const char *msg) {
    this->msg = msg;
}

void shouter_shout(Shouter *this) {
    for (const char *p = this->msg; *p; p++) {
        putchar(toupper(*p));
    }
}

int main(void) {
    Shouter *shouter = malloc(sizeof(*shouter));
    shouter_init(shouter, "Hello World");
    shouter_shout(shouter);
}
