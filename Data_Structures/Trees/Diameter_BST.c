#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

// Function to find height and update diameter
int height(struct Node *root, int *diameter)
{
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left, diameter);
    int rightHeight = height(root->right, diameter);

    *diameter = (*diameter > leftHeight + rightHeight + 1) ? *diameter : (leftHeight + rightHeight + 1);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to get diameter of a tree
int getDiameter(struct Node *root)
{
    int diameter = 0;
    height(root, &diameter);
    return diameter;
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
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    printf("Diameter of the tree: %d\n", getDiameter(root));
    return 0;
}
