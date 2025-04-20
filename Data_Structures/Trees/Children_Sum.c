#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

// Function to check children sum property
int isChildrenSum(struct Node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 1;

    int leftData = (root->left) ? root->left->data : 0;
    int rightData = (root->right) ? root->right->data : 0;

    return (root->data == leftData + rightData) && isChildrenSum(root->left) && isChildrenSum(root->right);
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
    struct Node *root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->right->right = newNode(2);

    if (isChildrenSum(root))
        printf("The tree satisfies the children sum property.\n");
    else
        printf("The tree does not satisfy the children sum property.\n");

    return 0;
}
