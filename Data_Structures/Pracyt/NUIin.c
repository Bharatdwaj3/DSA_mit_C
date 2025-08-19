#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *insert(struct Node *root, int key)
{
    if (root == NULL)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = key;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

int countNodesWithBothChildren(struct Node *root)
{
    if (root == NULL)
        return 0;
    int count = 0;
    if (root->left != NULL && root->right != NULL)
        count = 1;
    return count + countNodesWithBothChildren(root->left) + countNodesWithBothChildren(root->right);
}
