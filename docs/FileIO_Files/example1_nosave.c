/*

    NOTE: This code is intentionally wrong it removes the copy of the strings

 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUF_SIZE (1000)

struct node_t {
    struct node_t *next;
    char *text;
};

struct node_t *new_node(char *text) {
    // Q) What does sizeof(*node) do?
    struct node_t *node = malloc(sizeof(*node));
    node->next = NULL;
    node->text = text;
    return node;
}

int main(void) {
    // Q) Can I do this recursively?  Any downside?

    // this is a very easy way to make a lazy stack
    struct node_t *head = NULL;

    // Q) Why +1?
    // Q) Why can we use a local array... when do we have to do malloc?
    char buffer[MAX_BUF_SIZE + 1];

    while (scanf("%s", buffer) == 1) {
        // This is all it takes to add a new item to the stack
        struct node_t *new = new_node(buffer);
        new->next = head;
        head = new;
    }

    printf("\n\n== And now each word in reverse ==\n\n");

    // print out in reverse and free
    for (struct node_t *cur = head; cur != NULL;) {
        printf("%s\n", cur->text);

        struct node_t *tmp = cur->next;
        // the free is removed here
        free(cur);
        cur = tmp;
    }

    return 0;
}
