#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// ==================== NODE DEFINITION ====================
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// ==================== UTILITY FUNCTIONS ====================
int containsKey(struct Node *root, int key) {
    while (root) {
        if (key == root->data) return 1;
        else if (key < root->data) root = root->left;
        else root = root->right;
    }
    return 0;
}

struct Node *getFirstPostorder(struct Node *root) {
    while (root && (root->left || root->right)) {
        root = root->left ? root->left : root->right;
    }
    return root;
}

// ==================== INORDER SUCCESSOR ====================
struct Node *inorderSuccessor(struct Node *root, int key) {
    struct Node *successor = NULL;
    while (root) {
        if (key < root->data) {
            successor = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return successor;
}

// ==================== INORDER PREDECESSOR ====================
struct Node *inorderPredecessor(struct Node *root, int key) {
    struct Node *predecessor = NULL;
    while (root) {
        if (key > root->data) {
            predecessor = root;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return predecessor;
}

// ==================== PREORDER SUCCESSOR ====================
struct Node *preorderSuccessor(struct Node *root, int key) {
    if (!root) return NULL;
    if (root->data == key)
        return root->left ? root->left : root->right;

    if (key < root->data && root->left) {
        struct Node *left = preorderSuccessor(root->left, key);
        if (left) return left;
    }

    if (key > root->data && root->right)
        return preorderSuccessor(root->right, key);

    return NULL;
}

// ==================== POSTORDER SUCCESSOR ====================
struct Node *postorderSuccessor(struct Node *root, int key) {
    if (!root) return NULL;
    if (root->data == key) return NULL;

    if (root->left) {
        struct Node *left = postorderSuccessor(root->left, key);
        if (left) return left;
        if (containsKey(root->left, key))
            return root->right ? getFirstPostorder(root->right) : root;
    }

    if (root->right) {
        struct Node *right = postorderSuccessor(root->right, key);
        if (right) return right;
        if (containsKey(root->right, key))
            return root;
    }

    return NULL;
}

// ==================== MAIN FUNCTION ====================
int main() {
    // Sample Tree:
    //         20
    //       /    \
    //     10      30
    //    /  \    /  \
    //   5   15  25  35

    struct Node* root = newNode(20);
    root->left = newNode(10);
    root->right = newNode(30);
    root->left->left = newNode(5);
    root->left->right = newNode(15);
    root->right->left = newNode(25);
    root->right->right = newNode(35);

    int key = 10;

    struct Node* inSucc = inorderSuccessor(root, key);
    struct Node* inPred = inorderPredecessor(root, key);
    struct Node* preSucc = preorderSuccessor(root, key);
    struct Node* postSucc = postorderSuccessor(root, key);

    printf("=== Successors/Predecessor for key = %d ===\n", key);
    printf("Inorder Successor     : %d\n", inSucc ? inSucc->data : -1);
    printf("Inorder Predecessor   : %d\n", inPred ? inPred->data : -1);
    printf("Preorder Successor    : %d\n", preSucc ? preSucc->data : -1);
    printf("Postorder Successor   : %d\n", postSucc ? postSucc->data : -1);

    return 0;
}
