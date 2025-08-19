#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to count sibling nodes
int countSiblings(struct Node *root)
{
    if (!root)
        return 0;

    int count = 0;
    if (root->left && root->right)
    {
        count += 2; // both children are siblings
    }

    count += countSiblings(root->left);
    count += countSiblings(root->right);

    return count;
}

int main()
{

    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int siblingCount = countSiblings(root);
    printf("Number of nodes with siblings: %d\n", siblingCount);

    return 0;
}
