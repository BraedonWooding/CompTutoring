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
}

int len(struct LL *cur) {
}

int sum_while(struct LL *cur) {
    int sum = 0;
    while (cur != NULL) {
        sum += cur->data;
        cur = cur ->next;
    }
    return sum;
}

int sum(struct LL *cur) {
    if (cur == NULL) return 0;
    // if (cur->next == NULL) return cur->data;
    // if (cur->next->next == NULL) return cur->data + cur->next->data;
    return cur->data + sum(cur->next);
}
