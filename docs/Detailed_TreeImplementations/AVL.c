#include <stdlib.h>

typedef struct avl_node_t AVLNode;

struct avl_node_t {
    AVLNode *left;
    AVLNode *right;
    int key;
    // Could we also store height?
    // Yes -- it would make it faster
    // But we won't since its easy to get
};

/* Instead of storing height we'll just recalculate it each time
 * of course if we want to actually reach O(log n) insertions we'll need
 * to have this be cached and only updated when necessary.
 */
int height(AVLNode *n) {
    if (n == NULL) {
        return -1;
    } else {
        int left = height(n->left);
        int right = height(n->right);
        return (left > right ? left : right) + 1;
    }
}

/*
Right Rotating at 7
      7
     / \
    3   8
   /     \
  2       5

1)
        3
       / \
      2   7
     /     \
    3       8
   /         \
  2           5

2)
     3
    / \
   2   7
  /     \
 5       8
*/
AVLNode *right_rotate(AVLNode *root) {
    AVLNode *left = root->left;
    AVLNode *left_right = left->right;
    left->right = root;             // 1)
    root->left = left_right;        // 2)
    return left;
}

/*
Left Rotating at 3
     3
    / \
   2   7
  /     \
 5       8

1)
        7
       / \
      3   8
     /     \
    2       7
   /         \
  5           8

2)
     7
    / \
   3   8
  /     \
 2       5
*/
AVLNode *left_rotate(AVLNode *root) {
    AVLNode *right = root->right;
    AVLNode *right_left = right->left;
    right->left = root;             // 1)
    root->right = right_left;       // 2)
    return right;
}

AVLNode *insert(AVLNode *root, int key) {
    // Case 1) Empty Tree
    if (root == NULL) {
        root = malloc(sizeof(*root));
        root->left = root->right = NULL;
        root->key = key;
        return root;
    }

    // Case 2) Duplicates
    if (root->key == key) {
        // We can return here because we aren't going to insert
        // So as long as tree was balanced prior it'll still be balanced
        return root;
    } else if (key < root->key) /* Case 3) Left */ {
        root->left = insert(root->left, key);
    } else /* Case 4) Right */ {
        root->right = insert(root->right, key);
    }

    // What happens if we do height(root->right) - height(root->left)
    // Answer: The tree prefers to be more balanced on the right than on the left
    int balance = height(root->left) - height(root->right);
    if (balance > 1) {
        // Unbalanced in left
        // What way do we rotate??
        // Which one do we need to double rotate?
        if (key < root->left->key) {
            root = right_rotate(root);
        } else {
            // key > root->left->key;
            // Need to double rotate as to move a better middle node up
            root->left = left_rotate(root->left);
            root = right_rotate(root);
        }
    } else if (balance < -1) {
        // Unbalanced in right
        // What way do we rotate??
        // Which one do we need to double rotate?
        if (key > root->right->key) {
            root = left_rotate(root);
        } else {
            // key < root->right->key
            // Need to double rotate as to move a better middle node up
            root->right = right_rotate(root->right);
            root = left_rotate(root);
        }
    }
    return root;
}

AVLNode *find_node(AVLNode *root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    } else if (key < root->key) {
        return find_node(root->left, key);
    } else if (key > root->key) {
        return find_node(root->right, key);
    }
}
