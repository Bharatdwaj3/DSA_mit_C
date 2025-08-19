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

//0 Find Maximum in BST
struct Node *findMax(struct Node *node)
{
    if (!node)
        return NULL;
    if (!node->right)
        return node;
    return findMax(node->right);
}

// 1. Find Minimum in BST
struct Node *findMin(struct Node *node)
{
    if (!node)
        return NULL;
    if (!node->left)
        return node;
    return findMin(node->left);
}

// 2. Inorder Successor (Recursive)
struct Node *inorderSuccessorRecursive(struct Node *root, struct Node *target)
{
    if (!root)
        return NULL;
    if (target->data < root->data)
    {
        struct Node *left = inorderSuccessorRecursive(root->left, target);
        return left ? left : root;
    }
    else if (target->data > root->data)
    {
        return inorderSuccessorRecursive(root->right, target);
    }
    else
    {
        if (root->right)
            return findMin(root->right);
    }
    return NULL;
}

// 3. Count Nodes
int countTotal(struct Node *root)
{
    if (!root)
        return 0;
    return 1 + countTotal(root->left) + countTotal(root->right);
}

int countLeft(struct Node *root)
{
    if (!root || !root->left)
        return 0;
    return 1 + countTotal(root->left);
}

int countRight(struct Node *root)
{
    if (!root || !root->right)
        return 0;
    return 1 + countTotal(root->right);
}

// 4a. Delete node with only right child
struct Node *deleteWithRightChild(struct Node *root, int key)
{
    if (!root)
        return NULL;
    if (key < root->data)
        root->left = deleteWithRightChild(root->left, key);
    else if (key > root->data)
        root->right = deleteWithRightChild(root->right, key);
    else{
        if (root->right && !root->left){ 
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
    }
    return root;
}

// 4b. Delete leaf
struct Node *deleteLeaf(struct Node *root, int key)
{
    if (!root)
        return NULL;
    if (key < root->data)
        root->left = deleteLeaf(root->left, key);
    else if (key > root->data)
        root->right = deleteLeaf(root->right, key);
    else
    {
        if (!root->left && !root->right)
        {
            free(root);
            return NULL;
        }
    }
    return root;
}

// 4c. Delete node with one child (left or right)
struct Node *deleteWithOneChild(struct Node *root, int key)
{
    if (!root)
        return NULL;
    if (key < root->data)
        root->left = deleteWithOneChild(root->left, key);
    else if (key > root->data)
        root->right = deleteWithOneChild(root->right, key);
    else
    {
        if (root->left && !root->right)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        else if (root->right && !root->left)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
    }
    return root;
}

// 5. Delete node with 2 children
struct Node *deleteNode(struct Node *root, int key)
{
    if (!root)
        return NULL;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
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
        else if (!root->right)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        struct Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// 7. Replace child with parent (simple version)
struct Node *replaceWithChild(struct Node *root, int key)
{
    if (!root)
        return NULL;
    if (key < root->data)
        root->left = replaceWithChild(root->left, key);
    else if (key > root->data)
        root->right = replaceWithChild(root->right, key);
    else
    {
        if (root->left && !root->right)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        else if (root->right && !root->left)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else
        {
            printf("Node with two children — cannot replace directly with one child.\n");
        }
    }
    return root;
}

// Inorder traversal
void inorder(struct Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
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

    struct Node *minNode = findMin(root);
    if (minNode)
        printf("Min node: %d\n", minNode->data);

    struct Node *successor = inorderSuccessorRecursive(root, root->left);
    if (successor)
        printf("Inorder Successor of %d: %d\n", root->left->data, successor->data);

    root = deleteNode(root, 20); // delete node with 2 children
    printf("After deleting 20: ");
    inorder(root);
    printf("\n");

    return 0;
}
