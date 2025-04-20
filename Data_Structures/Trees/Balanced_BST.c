#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

// Function to check if tree is balanced
int isBalanced(struct Node *root, int *height)
{
    if (root == NULL)
    {
        *height = 0;
        return 1;
    }

    int leftHeight, rightHeight;
    int leftBalanced = isBalanced(root->left, &leftHeight);
    int rightBalanced = isBalanced(root->right, &rightHeight);

    *height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;

    return leftBalanced && rightBalanced && abs(leftHeight - rightHeight) <= 1;
}

int main()
{
    struct Node *root = (struct Node *)malloc(sizeof(struct Node));
    root->data = 1;
    root->left = (struct Node *)malloc(sizeof(struct Node));
    root->left->data = 2;
    root->right = (struct Node *)malloc(sizeof(struct Node));
    root->right->data = 3;

    root->left->left = (struct Node *)malloc(sizeof(struct Node));
    root->left->left->data = 4;
    root->left->right = (struct Node *)malloc(sizeof(struct Node));
    root->left->right->data = 5;

    int height = 0;
    if (isBalanced(root, &height))
        printf("The tree is balanced.\n");
    else
        printf("The tree is not balanced.\n");

    return 0;
}
