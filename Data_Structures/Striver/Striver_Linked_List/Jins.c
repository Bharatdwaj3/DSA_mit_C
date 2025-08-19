#include <stdio.h>
#include <stdlib.h>

// Node definition
struct Node
{
    int data;
    struct Node *left, *right;
};

// Utility function to create a new node
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}


// 5. Delete node with 2 children
struct Node *deleteWithTwoChild(struct Node *root, int key)
{
    if (!root)
        return NULL;
    if (key < root->data)
        root->left = deleteWithTwoChild(root->left, key);
    else if (key > root->data)
        root->right = deleteWithTwoChild(root->right, key);
    else
    {
        if (!root->left && !root->right)
        {
            free(root);
            return NULL;
        }
        else if (!root->left)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right && root->left)
        {
            struct Node *temp=root->left;
            free(root);
            return temp;
        }
        struct Node *temp=findMin(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right, temp->data);
    }
    return root;
}


// Driver code
int main()
{
    struct Node *root = newNode(20);
    root->left = newNode(10);
    root->right = newNode(30);
    root->left->left = newNode(5);
    root->left->right = newNode(15);
    root->right->left = newNode(25);
    root->right->right = newNode(35);

    printf("Initial Tree (Inorder): ");
    inorder(root);
    printf("\n");

    printf("Total Nodes: %d\n", countTotal(root));
    printf("Left Subtree Nodes: %d\n", countLeft(root));
    printf("Right Subtree Nodes: %d\n", countRight(root));

   
}
