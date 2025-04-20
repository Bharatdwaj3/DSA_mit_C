#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

// Helper function to check if two subtrees are mirrors of each other
int isMirror(struct Node *tree1, struct Node *tree2)
{
    if (tree1 == NULL && tree2 == NULL)
        return 1;
    if (tree1 == NULL || tree2 == NULL)
        return 0;
    return (tree1->data == tree2->data) &&
           isMirror(tree1->left, tree2->right) &&
           isMirror(tree1->right, tree2->left);
}

// Function to check if a tree is symmetric
int isSymmetric(struct Node *root)
{
    if (root == NULL)
        return 1;
    return isMirror(root->left, root->right);
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
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);

    if (isSymmetric(root))
        printf("The tree is symmetric.\n");
    else
        printf("The tree is not symmetric.\n");

    return 0;
}
