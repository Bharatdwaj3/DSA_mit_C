#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node
{
    int data;
    struct Node *left, *right;
};

// Preorder traversal: Root -> Left -> Right
void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder traversal: Left -> Root -> Right
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Postorder traversal: Left -> Right -> Root
void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    struct Node *root = NULL;
    struct Node *temp;
    int value, searchVal;

    // Insert nodes into the BST (directly in main)
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = 50;
    root->left = root->right = NULL;

    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = 30;
    temp->left = temp->right = NULL;
    root->left = temp;

    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = 70;
    temp->left = temp->right = NULL;
    root->right = temp;

    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = 20;
    temp->left = temp->right = NULL;
    root->left->left = temp;

    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = 40;
    temp->left = temp->right = NULL;
    root->left->right = temp;

    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = 60;
    temp->left = temp->right = NULL;
    root->right->left = temp;

    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = 80;
    temp->left = temp->right = NULL;
    root->right->right = temp;

    // Display the tree using all traversal methods
    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    // Delete a node (directly in main)
    value = 30;
    struct Node *parent = NULL;
    struct Node *current = root;
    while (current != NULL && current->data != value)
    {
        parent = current;
        current = (value < current->data) ? current->left : current->right;
    }

    if (current != NULL)
    {
        // Node with only one child or no child
        if (current->left == NULL)
        {
            if (parent == NULL)
            {
                root = current->right;
            }
            else if (parent->left == current)
            {
                parent->left = current->right;
            }
            else
            {
                parent->right = current->right;
            }
        }
        else if (current->right == NULL)
        {
            if (parent == NULL)
            {
                root = current->left;
            }
            else if (parent->left == current)
            {
                parent->left = current->left;
            }
            else
            {
                parent->right = current->left;
            }
        }
        free(current);
        printf("Node %d deleted.\n", value);
    }
    else
    {
        printf("Node %d not found for deletion.\n", value);
    }

    // Display the tree after deletion
    printf("Preorder traversal after deletion: ");
    preorder(root);
    printf("\n");

    printf("Inorder traversal after deletion: ");
    inorder(root);
    printf("\n");

    printf("Postorder traversal after deletion: ");
    postorder(root);
    printf("\n");

    return 0;
}
