#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

// Helper function to check if tree is BST
int isBSTUtil(struct Node *root, int min, int max)
{
    if (root == NULL)
        return 1;

    if (root->data < min || root->data > max)
        return 0;

    return isBSTUtil(root->left, min, root->data - 1) &&
           isBSTUtil(root->right, root->data + 1, max);
}

// Function to check if a tree is BST
int isBST(struct Node *root)
{
    return isBSTUtil(root, -100000, 100000);
}

// Function to create a new node
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int main()
{
    struct Node *root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(3);

    if (isBST(root))
        printf("The tree is a BST.\n");
    else
        printf("The tree is not a BST.\n");

    return 0;
}
