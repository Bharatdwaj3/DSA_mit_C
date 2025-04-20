#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

// Function to convert a sorted array to BST
struct Node *sortedArrayToBST(int arr[], int start, int end)
{
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    struct Node *root = (struct Node *)malloc(sizeof(struct Node));
    root->data = arr[mid];
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);
    return root;
}

// Function to print Inorder Traversal
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Node *root = sortedArrayToBST(arr, 0, n - 1);
    printf("Inorder Traversal of BST: ");
    inorder(root);
    printf("\n");

    return 0;
}
