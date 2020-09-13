#include <stdlib.h>
#include <string.h>

/*
 * This is quite messy and not very recommended style
 * but yeh... it is a 2-3-4 tree
 */

typedef struct node_234_t Node234;

struct node_234_t {
    Node234 *parent;

    /*
     * In;
     * - 2 mode: children[0] is left, children[1] is right
     * - 3 mode: 0 is left, 1 is middle, 2 is right
     * - 4 mode: 0 is left, 1 is left middle, 2 is right middle, 3 is right
     */
    Node234 *children[4]; // This is an array of 4 pointers

    // either 2, 3, or 4
    int state;

    // up to 3 data elements
    int data[3];
};

// I've not included a find here since the implementation result would be weird
// we can have multiple children in a node so you would have to have some struct
// to have a pointer to the node and what child it is...
// to help you think of what it would be I've written a 'inTree' method
int isNodeInTree(Node234 *root, int data) {
    if (root == NULL) return 0;
    switch (root->state) {
        case 4:
            if (data > root->data[2]) {
                return isNodeInTree(root->children[3], data);
            } else if (data == root->data[2]) {
                return 1;
            } // else fall through
        case 3:
            if (data > root->data[1]) {
                return isNodeInTree(root->children[2], data);
            } else if (data == root->data[1]) {
                return 1;
            } // else fall through
        case 2:
            if (data > root->data[0]) {
                return isNodeInTree(root->children[1], data);
            } else if (data == root->data[0]) {
                return 1;
            } else /* data < root->data[0] */ {
                // must be in left subtree
                return isNodeInTree(root->children[0], data);
            }
        default:
            // invalid state... you have a bug
            abort();
    }
}

Node234 *new_node(int data) {
    // calloc sets all memory to 0
    Node234 *node = calloc(1, sizeof(*node));
    node->data[0] = data;
    // by default is a 2 node
    node->state = 2;
    return node;
}

void sortOrdered(int *data, int len) {
    // A very lazy bubble sort
    // normally you would probably just write a ton of if statements
    // since you are only sorting 2, 3 or 4 elements...
    int swapped = 1;
    while (swapped) {
        swapped = 0;
        for (int i = 0; i < len - 1; i++) {
            if (data[i] > data[i + 1]) {
                swapped = 1;
                int tmp = data[i];
                data[i] = data[i + 1];
                data[i + 1] = tmp;
            }
        }
    }
}

Node234 *insert(Node234 *root, int data) {
    if (root == NULL) {
        root = new_node(data);
        return root;
    }

    switch (root->state) {
        case 2: {
            // Can we insert us
            if (root->children[0] == NULL && root->children[1] == NULL) {
                // If I am a leaf I can become a 3 node
                root->state = 3;
                root->data[1] = data;
                root->children[2] = NULL;
                sortOrdered(root->data, 2);
            } else if (data < root->data[0]) {
                // go to left
                root->children[0] = insert(root->children[0], data);
                root->children[0]->parent = root;
                return root;
            } else if (data > root->data[0]) {
                // go right
                root->children[1] = insert(root->children[1], data);
                root->children[1]->parent = root;
                return root;
            } else {
                // equal
                return root;
            }
        } break;
        case 3: {
            if (root->children[0] == NULL && root->children[1] == NULL &&
                root->children[2] == NULL) {
                // If I am a leaf I can become a 4 node
                root->state = 4;
                root->data[2] = data;
                root->children[3] = NULL;
                sortOrdered(root->data, 3);
            } else if (data < root->data[0]) {
                // go to left
                root->children[0] = insert(root->children[0], data);
                root->children[0]->parent = root;
                return root;
            } else if (root->data[0] < data && data < root->data[1]) {
                // go middle
                root->children[1] = insert(root->children[1], data);
                root->children[1]->parent = root;
                return root;
            } else if (data > root->data[1]) {
                // go right
                root->children[2] = insert(root->children[2], data);
                root->children[2]->parent = root;
                return root;
            } else {
                // equal
                return root;
            }
        } break;
        case 4: {
            if (root->parent == NULL) {
                // we have to split such that we have
                // [child0 data0 child1] data1 [child2 data2 child3]
                Node234 *new_root = new_node(root->data[1]);
                Node234 *left = new_node(root->data[0]);
                Node234 *right = new_node(root->data[2]);
                left->children[0] = root->children[0];
                left->children[1] = root->children[1];
                right->children[0] = root->children[2];
                right->children[1] = root->children[3];

                new_root->children[0] = left;
                new_root->children[1] = right;
                left->parent = new_root;
                right->parent = new_root;
                // we could repurpose this into new root but ugh
                // too much effort tbh.
                free(root);

                // try again since we split
                return insert(new_root, data);
            } else {
                Node234 *parent = root->parent;
                switch (parent->state) {
                    case 2: {
                        if (parent->children[1] == root) {
                            // If parent has root as the right child
                            // becomes a 3 state as it moves the child
                            // into itself
                            parent->state = 3;
                            parent->data[1] = root->data[1];
                            Node234 *middle = new_node(root->data[0]);
                            Node234 *right = new_node(root->data[2]);
                            middle->children[0] = root->children[0];
                            middle->children[1] = root->children[1];
                            right->children[0] = root->children[2];
                            right->children[1] = root->children[3];
                            middle->parent = parent;
                            right->parent = parent;

                            parent->children[1] = middle;
                            parent->children[2] = right;
                            root->children[0]->parent = parent;
                            root->children[1]->parent = parent;
                            free(root);
                            return insert(parent, data);
                        } else /* parent->children[0] == root */ {
                            // same kind of thing
                            parent->state = 3;
                            parent->data[1] = parent->data[0];
                            parent->data[0] = root->data[1];
                            Node234 *left = new_node(root->data[0]);
                            Node234 *middle = new_node(root->data[2]);
                            left->children[0] = root->children[0];
                            left->children[1] = root->children[1];
                            middle->children[0] = root->children[2];
                            middle->children[1] = root->children[3];
                            left->parent = parent;
                            middle->parent = parent;
                            parent->children[0] = left;
                            parent->children[1] = middle;
                            free(root);
                            return insert(parent, data);
                        }
                    } break;
                    case 3: {
                        // same kind of thing but for 3...
                        // basically just move child up
                        if (parent->children[2] == root) {
                            parent->state = 4;
                            parent->data[2] = root->data[1];
                            Node234 *middleRight = new_node(root->data[0]);
                            Node234 *right = new_node(root->data[2]);
                            middleRight->children[0] = root->children[0];
                            middleRight->children[1] = root->children[1];
                            right->children[0] = root->children[2];
                            right->children[1] = root->children[3];
                            right->parent = parent;
                            middleRight->parent = parent;
                            parent->children[2] = middleRight;
                            parent->children[3] = right;
                            free(root);
                            return insert(parent, data);
                        } else if (parent->children[1] == root) {
                            parent->state = 4;
                            parent->data[2] = parent->data[1];
                            parent->data[1] = root->data[1];
                            parent->children[3] = parent->children[2];
                            Node234 *middleLeft = new_node(root->data[0]);
                            Node234 *middleRight = new_node(root->data[2]);
                            middleLeft->children[0] = root->children[0];
                            middleLeft->children[1] = root->children[1];
                            middleRight->children[0] = root->children[2];
                            middleRight->children[1] = root->children[3];
                            middleLeft->parent = parent;
                            middleRight->parent = parent;
                            parent->children[1] = middleLeft;
                            parent->children[2] = middleRight;
                            free(root);
                            return insert(parent, data);
                        } else /* parent->children[0] == root */ {
                            parent->state = 4;
                            parent->data[2] = root->data[1];
                            parent->data[1] = root->data[0];
                            parent->children[3] = parent->children[2];
                            parent->children[2] = parent->children[1];
                            Node234 *left = new_node(root->data[0]);
                            Node234 *middleLeft = new_node(root->data[2]);
                            left->children[0] = root->children[0];
                            left->children[1] = root->children[1];
                            middleLeft->children[0] = root->children[2];
                            middleLeft->children[1] = root->children[3];
                            left->parent = parent;
                            middleLeft->parent = parent;
                            parent->children[0] = left;
                            parent->children[1] = middleLeft;
                            free(root);
                            return insert(parent, data);
                        }
                    } break;
                }
            }
        } break;
        default: {
            // You have an issue...
            // Normally you would print out an assertion
            // or something
            abort();
        } break;
    }
}

