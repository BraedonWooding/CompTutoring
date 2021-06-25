#include <stdio.h>

typedef struct BSTNode *BSTree;
typedef struct BSTNode {
    int value;
    BSTree left;
    BSTree right;
} BSTNode;

void order(BSTree tree) {
    if (tree == NULL) return;

    order(tree->left);
    printf("%d ", tree->value);
    order(tree->right);
}

// returns the path length from root to the node with value specified
// again path length is number of links, so if value == root: depth = 0
// returns -1 for value not found.
int BSTreeNodeDepth(BSTree t, int value) {
    if (t == NULL) return -1;
    if (t->value == value) return 0;

    int depth;
    if (value < t->value) {
        depth = BSTreeNodeDepth(t->left, value);
    } else /* if (value > t->value) */ {
        depth = BSTreeNodeDepth(t->right, value);
    }

    if (depth != -1) depth++;
    return depth;
}

// counts number of internal nodes
// internal nodes have atleast one subtree (i.e. aren't leafs)
int BSTreeCountInternal(BSTree t) {
    if (t == NULL) return 0;
    int sum = BSTreeNumNodes(t->left) + BSTreeCountInternal(t->right);
    
    if (t->left != NULL || t->right != NULL) {
        sum++;
    }
    return sum;
}

// counts #nodes in a tree
int BSTreeNumNodes(BSTree t) {
    if (t == NULL) return 0;
    return BSTreeNumNodes(t->left) + BSTreeNumNodes(t->right) + 1;

    // int sum = 1;
    // if (t->left != NULL) {
    //     sum++;
    //     if (t->left->left != NULL) {
    //         sum++;
    //     }
    //     if (t->left->right != NULL) {
    //         sum++;
    //     }
    // }
}



// OUTPUT: 1 3 4 5 7 8 9
