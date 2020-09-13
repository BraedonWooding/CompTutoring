#include <stdlib.h>

typedef struct splay_node_t SplayNode;

struct splay_node_t {
    SplayNode *left;
    SplayNode *right;
    int key;
};

/*
  For example if we have:
      7
     / \
    /   \
   3     9
  / \   / \
 2   5 8  10

 A left rotation on '7' will be
 1)
     7
    / \
   3    8
  / \
 2   5
 
 right = 9
        / \
       8  10
       
 2)
       9
      / \
     7  10
    / \
   3   8
  / \
 2   5
*/
SplayNode *left_rotate(SplayNode *node) {
    SplayNode *right = node->right;
    node->right = right->left;  // 1)
    right->left = node;         // 2)
    return right;
}

/*
  For example if we have:
      7
     / \
    /   \
   3     9
  / \   / \
 2   5 8  10

 A right rotation on '7' will be
 1)
     7
    / \
   5   9
      / \
     8  10

 left  = 3
        / \
       2   5

 2)
       3
      / \
     2   7
        / \
       5   9
          / \
         8  10
*/
SplayNode *right_rotate(SplayNode *node) {
    SplayNode *left = node->left;
    node->left = left->right;    // 1)
    left->right = node;          // 2)
    return left;
}

/*
  Bring the node that holds key to the top and return the new root.
  If the key doesn't exist then just do nothing (i.e. return root)
*/
SplayNode *splay(SplayNode *root, int key) {
    // TODO: I'll just give some cases

    // Case 1) Empty tree
    if (root == NULL) {
        return root;
    }

    // Case 2) The root node is key
    if (root->key == key) {
        return root;
    }

    // Case 3) Key Lies in left subtree
    if (key < root->key) {
        // Case 3) a) Key Not in tree
        if (root->left == NULL) {
            return root;
        }

        // Case 3) b) Zig Zig (i.e. Left Left)
        // Left Left means that our wanted node
        // is in our left -> left subtree

        // What do we do?  How many rotations
        // What do we want to do beforehand
        if (key < root->left->key) {
            // Lies in left -> left
            root->left->left = splay(root->left->left, key);
            // This is probably too safe I think the node can't actually be NULL
            if (root->left != NULL) {
                root = right_rotate(root);
            }
        } else if (key > root->left->key) /* Case 3) c) Zig Zag i.e. Left Right */ {
            // Lies in left -> right
            root->left->right = splay(root->left->right, key);
            if (root->left->right != NULL) {
                root->left = left_rotate(root->left);
            }
        }

        // What do we do now to make it so that our new root is our left child
        // Remember that we may not find our left child (meaning our left may be NULL)
        // We definitely need this though.
        if (root->left != NULL) {
            root = right_rotate(root);
        }
    } else /* Case 4) Lies in Right subtree */ {
        // Case 4) a) Key Not in tree
        if (root->right == NULL) {
            return root;
        }

        // Case 4) b) Zag Zig (i.e. Right Left)
        // What do we do?  How many rotations
        // What do we want to do beforehand
        if (key < root->right->key) {
            // lies in right -> left
            root->right->left = splay(root->right->left, key);
            // This is probably too safe I think the node can't actually be NULL
            if (root->right->left != NULL) {
                root->right = right_rotate(root->right);
            }
        } else if (key > root->right->key) /* Case 4) c) Zig Zag i.e. Right Right */ {
            // lies in right -> right
            root->right->right = splay(root->right->right, key);
            // This is probably too safe I think the node can't actually be NULL
            if (root->right != NULL) {
                root = left_rotate(root);
            }
        }

        // What do we do now to make it so that our new root is our right child
        // Remember that we may not find our right child (meaning our right may be NULL)
        if (root->right != NULL) {
            root = left_rotate(root);
        }
    }
    return root;
}

// Returns new root  
SplayNode *insert(SplayNode *root, int key) {
    // Iterative method since its a little cleaner in this specific case
    SplayNode *cur = root;
    SplayNode *prev = NULL;
    while (cur) {
        prev = cur;
        if (key > cur->key) {
            cur = cur->right;
        } else if (key < cur->key) {
            cur = cur->left;
        } else {
            // MOST websites get this wrong!!  Even wikipedia!!
            // We want to have no duplicates
            // So we have to check for ==
            // Q) Why can't we just do return root??
            // What are they expecting to be root at the end...
            return splay(root, key);
        }
    }

    SplayNode *new = malloc(sizeof(*new));
    new->left = new->right = NULL;
    new->key = key;

    if (prev == NULL) {
        // empty tree
        root = new;
    } else if (key < prev->key) {
        // in left subtree
        prev->left = new;
    } else {
        prev->right = new;
    }
    return splay(root, key);
}

// Splays the tree for the given key
// If the returned node doesn't contain key
// Then the key wasn't found.
// There are other ways to do this (such as taking root by SplayNode **)
SplayNode *search(SplayNode *root, int key) {
    // Yes it is this simple!
    return splay(root, key);
}
