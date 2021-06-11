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
        len++;
        cur = cur->next;
    }
    return len;
}

int len(struct LL *cur) {
    // if (cur == NULL) {
    //     return 0;
    // } else if (cur->next == NULL) {
    //     return 1;
    // } else if (cur->next->next == NULL) {
    //     return 2;
    // } ...

    if (cur == NULL) {
        return 0;
    }

    return len(cur->next) + 1;
}

int count_odds_while(struct LL *cur) {
    int count = 0;
    while (cur != NULL) {
        if (cur->data % 2 != 0) {
            count++;
        }
        cur = cur->next;
    }
    return count;
}

int count_odds(struct LL *cur) {
    // if (cur == NULL) {
    //     return 0;
    // } else if (cur->next == NULL) {
    //     if (cur->data % 2 != 0) {
    //         return 1;
    //     } else {
    //         return 0;
    //     }
    // } else if (cur->next->next == NULL) {
    //     if (cur->data % 2 != 0) {
    //         if (cur->next->data % 2 != 0) {
    //             return 2;
    //         } else {
    //             return 1;
    //         }
    //     } else {
    //         if (cur->next->data % 2 != 0) {
    //             return 1;
    //         } else {
    //             return 0;
    //         }
    //     }
    // }

    if (cur == NULL) return 0;
    return (cur->data % 2 != 0 ? 1 : 0) +
        count_odds(cur->next);
}
