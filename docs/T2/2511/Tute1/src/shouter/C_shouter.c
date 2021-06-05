#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

struct Shouter {
    char *msg;

    struct _VTable {
        char*(*getMsg)(struct Shouter*);
        void(*setMsg)(struct Shouter*, char *);
        void(*shouterMsg)(struct Shouter*, int args[]);
    } *_vtable;
};

char *getMsg(struct Shouter *self) {
    return self->msg;
}

char *getBabyMsg(struct Shouter *self) {
    return "Goo Gahh Baby";
}

const struct _VTable _shouterVtable = {
    .getMsg = getMsg
};

const struct _VTable _babyShouterVtable = {
    .getMsg = getBabyMsg
};

void baby_shouter_init(struct Shouter *self, char *msg) {
    self->_vtable = &_babyShouterVtable;
    self->msg = msg;
}

void shouter_init(struct Shouter *self, char *msg) {
    self->_vtable = &_shouterVtable;
    self->msg = msg;
}

int main(void) {
    struct Shouter *shouter = malloc(sizeof(*shouter));
    baby_shouter_init(shouter, "Hello World!");
}
