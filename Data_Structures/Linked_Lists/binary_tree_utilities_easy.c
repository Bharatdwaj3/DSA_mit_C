#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Binary Tree Node Definition
struct Node {
    int data;
    struct Node *left, *right;
};

// Utility function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// 1. Height of Binary Tree
int height(struct Node* root) {
    if (!root) return 0;
    int l = height(root->left);
    int r = height(root->right);
    return (l > r ? l : r) + 1;
}

// 2. Determine if two trees are identical
int isIdentical(struct Node* a, struct Node* b) {
    if (!a && !b) return 1;
    if (!a || !b) return 0;
    return (a->data == b->data) && isIdentical(a->left, b->left) && isIdentical(a->right, b->right);
}

// 3. Mirror tree
void mirror(struct Node* root) {
    if (!root) return;
    mirror(root->left);
    mirror(root->right);
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

// 4. Symmetric Tree
int isMirror(struct Node* a, struct Node* b) {
    if (!a && !b) return 1;
    if (!a || !b) return 0;
    return (a->data == b->data) &&
           isMirror(a->left, b->right) &&
           isMirror(a->right, b->left);
}
int isSymmetric(struct Node* root) {
    return isMirror(root, root);
}

// 5. Diameter of tree
int diameterUtil(struct Node* root, int* height) {
    if (!root) {
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int ldiameter = diameterUtil(root->left, &lh);
    int rdiameter = diameterUtil(root->right, &rh);
    *height = (lh > rh ? lh : rh) + 1;
    return (lh + rh + 1 > ldiameter && lh + rh + 1 > rdiameter) ?
           lh + rh + 1 : (ldiameter > rdiameter ? ldiameter : rdiameter);
}
int diameter(struct Node* root) {
    int height = 0;
    return diameterUtil(root, &height);
}

// 6. Check for Balanced tree
int isBalanced(struct Node* root) {
    if (!root) return 1;
    int lh = height(root->left);
    int rh = height(root->right);
    return abs(lh - rh) <= 1 &&
           isBalanced(root->left) &&
           isBalanced(root->right);
}

// 7. Children Sum Property
int isChildrenSum(struct Node* root) {
    if (!root || (!root->left && !root->right)) return 1;
    int left = root->left ? root->left->data : 0;
    int right = root->right ? root->right->data : 0;
    return (root->data == left + right) &&
           isChildrenSum(root->left) &&
           isChildrenSum(root->right);
}

// 8. Check for BST
int isBSTUtil(struct Node* root, int min, int max) {
    if (!root) return 1;
    if (root->data <= min || root->data >= max) return 0;
    return isBSTUtil(root->left, min, root->data) &&
           isBSTUtil(root->right, root->data, max);
}
int isBST(struct Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

// 9. Sorted Array to BST
struct Node* sortedArrayToBST(int arr[], int start, int end) {
    if (start > end) return NULL;
    int mid = (start + end) / 2;
    struct Node* root = newNode(arr[mid]);
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);
    return root;
}
