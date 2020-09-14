#include <stdio.h>
#include <stdlib.h>

// We can define crazy macros like this
// You don't have to know how this works or why
// But effectively... we are just defining some text replacement
// and the ##__VA_ARGS__ is just going to either do name(x, some arguments)
// or just name(x) if there are none :)
#define V_CALL(x, name, ...) x->_vtable.name(x, ##__VA_ARGS__)

typedef struct shouter_t {
    char *msg;
    
    // In reality this should be a pointer to a struct
    // so we can utilise polymorphism as we'll see soon
    // but for now it's okay to visualise it like this
    struct {
        void(*whisper_fn)(Shouter *shouter);
    } _vtable;
} Shouter;

void whisper(Shouter *this) {
    // A pretty standard C for loop for iterating through a string
    // the '*c' will check each character and if the character is \0
    // then that'll resolve to 0 which is false!
    for (char *c = this->msg; *c; c++) {
        putchar(tolower(c));
    }
    putchar('\n');
}

void init(Shouter *this, char *msg) {
    this->msg = msg;
    this->_vtable.whisper_fn = whisper;
}

int main(void) {
    // this is like writing new Shouter("Hello World")
    Shouter *shouter = malloc(sizeof(*shouter));
    init(shouter, "Hello World");
    // using our special macro
    V_CALL(shouter, whisper_fn);
    // in reality we could also just do
    shouter->_vtable.whisper_fn(shouter);
}