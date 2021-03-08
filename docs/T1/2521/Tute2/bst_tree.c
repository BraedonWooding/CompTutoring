#include <stdlib.h>

typedef struct _bst_tree_t {
    struct _bst_tree_t *left;
    struct _bst_tree_t *right;

    int data;
} *BSTree;

// Sum all nodes in t
int BSTreeSum(BSTree t) {
    if (t == NULL) return 0;
    return t->data + BSTreeSum(t->left) + BSTreeSum(t->right);

    // single node, no children
    // if (t->left == NULL && t->right == NULL) return t->data;
    // internal (has children) node, only left child which is a leaf (has no children)
    // if (t->left != NULL && t->left->left == NULL && t->left->right == NULL && t->right == NULL)
    //    return t->data + t->left->data;
    // internal node, only right child which is a leaf
    // if (t->right != NULL && t->right->left == NULL && t->right->right == NULL && t->left == NULL)
    //     return t->data + t->right->data;
    // internal node, left and right child which are both leaves
    // if (t->right != NULL && t->right->left == NULL && t->right->right == NULL && t->left != NULL && t->left->left == NULL && t->left->right == NULL)
    //     return t->data + t->left->data + t->right->data;
}
