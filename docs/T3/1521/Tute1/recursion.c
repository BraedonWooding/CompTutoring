#include "recursion.h"
#include <stdio.h>
#include <stdlib.h>

/*

    |   |
    | 1 | -> | 2 | -> | 20 | -> | 140 | -> NULL
    |   |

 */

struct LL {
    struct LL *next;
    int data;
};

int len_while(struct LL *cur) {
    int len = 0;
    while (cur != NULL) {
        len ++;
        cur = cur->next;
    }
    return len;
}

int len(struct LL *cur) {
    if (cur == NULL) return 0;
    // if (cur->next == NULL) return 1;
    // if (cur->next->next == NULL) return 1 + 1;
    // if (cur->next->next->next == NULL) return 1 + 1 + 1;

    return 1 + len(cur->next);
}

int count_while(struct LL *cur) {
    int sum = 0;
    while (cur != NULL) {
        sum += cur->data;
        cur = cur->next;
    }
    return sum;
}

int count(struct LL *cur) {
    if (cur == NULL) return 0;
    // if (cur->next == NULL) return cur->data;
    // if (cur->next->next == NULL) return cur->data + cur->next->data;
    // if (cur->next->next->next == NULL) return cur->data + cur->next->data + cur->next->next->data;

    return cur->data + count(cur->next);
}
