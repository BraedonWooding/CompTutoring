struct Shouter {
    char *message;

    void(*shouter_say)(struct Shouter*);
};

void shouter_init(struct Shouter *this, char *message) {
    this->shouter_say = shouter_say;

    this->message = message;
}

void shouter_subclass_init(struct Shouter *this, char *message) {
    this->shouter_say = shouter_say_out;

    this->message = message;
}

void shouter_say_out(struct Shouter *this) {
    fprintf(stdout, "%s", this->message);
}

void shouter_say(struct Shouter *this) {
    fprintf(stderr, "%s", this->message);
}

int main(void) {
    struct Shouter *shouter = malloc(sizeof(*shouter));
    shouter_init(shouter, "Hello World!");
    shouter_say(shouter);

}
