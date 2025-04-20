#include <stdio.h>
#include <stdlib.h>

// Structure for a Node
struct Node
{
    int data;
    struct Node *left, *right;
};

// Function to check if two trees are identical
int areIdentical(struct Node *root1, struct Node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return 1;
    if (root1 == NULL || root2 == NULL)
        return 0;
    return (root1->data == root2->data) &&
           areIdentical(root1->left, root2->left) &&
           areIdentical(root1->right, root2->right);
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
    struct Node *root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);

    struct Node *root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);

    if (areIdentical(root1, root2))
        printf("The trees are identical.\n");
    else
        printf("The trees are not identical.\n");

    return 0;
}
