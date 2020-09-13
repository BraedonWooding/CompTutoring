#include <stdlib.h>

// https://en.wikipedia.org/wiki/Red%E2%80%93black_tree
// is so amazing for showing off all the cases
// it's truly a good implementation
// bar it being a little inefficient (so I've made optimisations in places)

typedef enum Color {
    RED,
    BLACK
} Color;

typedef struct red_black_node_t RedBlackNode;

struct red_black_node_t {
    int data;
    Color color;
    RedBlackNode *left;
    RedBlackNode *right;
    RedBlackNode *parent;
};

/*
        10
       /  \
      /    \
n -> 5     12
    / \   /  \
   3   \ 11  13
        7 <- right
       / \
      6   8

    We want to make it so that the right is the parent of 'n'
    so we first move them and since 'n' has to be < 'right'
    we have to move it to the left... which means the '3' has to become
    a left child of '5'.

    And we have to also move the 6! Since that is where the '5' will now live
    in this case we can just move the '6' to the right of '5'

        10
       /  \
      /    \
     7     12
    / \   /  \
   5   \ 11  13
  / \   8
 3   6
 */
RedBlackNode *left_rotation(RedBlackNode *root, RedBlackNode *node) {
    RedBlackNode *right = node->right;
    RedBlackNode *parent = node->parent;

    // The 'node' will take the place of the 'left' child of 'right'
    // so we need to move that somewhere... a free spot will be where
    // node->right is because that is going to move to become the parent
    node->right = right->left;
    if (node->right != NULL) node->right->parent = node;

    // make node a left child of right
    right->left = node;
    node->parent = right;

    // If node has a parent we have to swap it with the other
    right->parent = parent;
    if (parent != NULL) {
        if (node == parent->left) {
            parent->left = right;
        } else /* (node == parent->right) */ {
            parent->right = right;
        }
        return root;
    } else {
        // Right is going to be new root
        return right;
    }
}

/*
        8
       /  \
      /    \
     5     15 <- node
           / \
          /   \
 left -> 11    18
        /  \
       10  12
    We want to make it so that the left is the parent of 'n'
    so we first move them and since 'n' has to be > 'left'
    we have to move it to the right... which means the '15' has to become
    a right child of '11'.

    And we have to also move the 12! Since that is where the '15' will now live
    in this case we can just move the '12' to the left of '15'

        8
       /  \
      /    \
     5     11
           / \
          /   \
         10    15
              /
             12
 */
RedBlackNode *right_rotation(RedBlackNode *root, RedBlackNode *node) {
    RedBlackNode *left = node->left;
    RedBlackNode *parent = node->parent;

    // The 'node' will take the place of the 'right' child of 'left'
    // so we need to move that somewhere... a free spot will be where
    // node->left is because that is going to move to become the parent
    node->left = left->right;
    if (node->left != NULL) node->left->parent = node;

    // make node a left child of right
    left->right = node;
    node->parent = left;

    // If node has a parent we have to swap it with the other
    left->parent = parent;
    if (parent != NULL) {
        if (node == parent->left) {
            parent->left = left;
        } else /* (node == parent->right) */ {
            parent->right = left;
        }
        return root;
    } else {
        // left is going to be new root
        return left;
    }
}

RedBlackNode *new_node(int data) {
    RedBlackNode *node = malloc(sizeof(*node));
    node->data = data;
    node->color = RED;
    node->parent = NULL;
    node->left = node->right = NULL;
    return node;
}

RedBlackNode *insert_repair(RedBlackNode *root, RedBlackNode *cur) {
    while (cur != root && cur->parent->color == RED) {
        RedBlackNode *uncle;
        if (cur->parent == cur->parent->parent->left) {
            uncle = cur->parent->parent->right;
        } else {
            uncle = cur->parent->parent->left;
        }

        // If the Uncle is RED...
        // 1) Change color of parent and uncle to black
        // 2) Change color of grandparent to red
        // 3) Move cur to become grandparent
        if (uncle->color == RED) {
            uncle->color = BLACK;
            cur->parent->color = BLACK;
            cur->parent->parent->color = RED;
            cur = cur->parent->parent;
        } else {
            // Uncle is black so 4 cases (LL, LR, RL, RR)

            // LL case; swap color of parent and grandparent
            // right rotate grandparent
            if (cur->parent == cur->parent->parent->left && cur == cur->parent->left) {
                Color color = cur->parent->color;
                cur->parent->color = cur->parent->parent->color;
                cur->parent->parent->color = color;
                root = right_rotation(root, cur->parent->parent);
            }

            // LR case; swap color of node and grandparent
            // left rotate parent, right rotate grand parent
            if (cur->parent == cur->parent->parent->left && cur == cur->parent->right) {
                Color color = cur->color;
                cur->color = cur->parent->parent->color;
                cur->parent->parent->color = color;
                root = left_rotation(root, cur->parent);
                root = right_rotation(root, cur->parent->parent);
            }

            // RR case;
            // swap parent and grandparent color, left rotate grandparent
            if (cur->parent == cur->parent->parent->right && cur == cur->parent->right) {
                Color color = cur->parent->color;
                cur->parent->color = cur->parent->parent->color;
                cur->parent->parent->color = color;
                root = left_rotation(root, cur->parent->parent);
            }

            // RL case;
            // swap node and grandparent color, right rotate parent
            // left rotate grand parent
            if (cur->parent == cur->parent->parent->right && cur == cur->parent->left) {
                Color color = cur->color;
                cur->color = cur->parent->parent->color;
                cur->parent->parent->color = color;
                root = right_rotation(root, cur->parent);
                root = left_rotation(root, cur->parent->parent);
            }
        }
    }

    // regardless what happens root becomes black
    root->color = BLACK;
    return root;
}

RedBlackNode *insert(RedBlackNode *root, int data) {
    RedBlackNode *node = new_node(data);

    if (root == NULL) {
        node->color = BLACK;
        return node;
    } else {
        RedBlackNode *cur = root;
        RedBlackNode *parent = NULL;

        // this is just very very standard insertion
        // but using a while loop rather than recursion
        // both will work I was just lazy
        while (cur != NULL) {
            parent = cur;
            if (node->data < cur->data) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }

        cur->parent = parent;
        if (node->data > parent->data) {
            parent->right = node;
        } else {
            parent->left = node;
        }
        // initial nodes are going to be red and we'll fix them up
        cur->color = RED;

        return insert_repair(root, cur);
    }
}
