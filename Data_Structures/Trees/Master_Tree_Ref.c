#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure for a node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new node
struct Node *createNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Insert node into BST
struct Node *insert(struct Node *root, int data)
{
    if (!root)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

// 1. Height of a Binary Tree
int height(struct Node *root)
{
    if (!root)
        return 0;
    int left = height(root->left);
    int right = height(root->right);
    return 1 + (left > right ? left : right);
}

// 2. Check if Two Trees are Identical
int areIdentical(struct Node *root1, struct Node *root2)
{
    if (!root1 && !root2)
        return 1;
    if (!root1 || !root2)
        return 0;
    return (root1->data == root2->data) &&
           areIdentical(root1->left, root2->left) &&
           areIdentical(root1->right, root2->right);
}

// 3. Convert to Mirror Tree
void mirror(struct Node *root)
{
    if (!root)
        return;
    mirror(root->left);
    mirror(root->right);
    struct Node *temp = root->left;
    root->left = root->right;
    root->right = temp;
}

// 4. Check if Tree is Symmetric
int isMirror(struct Node *root1, struct Node *root2)
{
    if (!root1 && !root2)
        return 1;
    if (!root1 || !root2)
        return 0;
    return (root1->data == root2->data) &&
           isMirror(root1->left, root2->right) &&
           isMirror(root1->right, root2->left);
}

int isSymmetric(struct Node *root)
{
    return isMirror(root, root);
}
int isAsymmetric(struct Node *root)
{
    return !isMirror(root, root);
}

// 5. Diameter of a Tree
int diameter(struct Node *root, int *height)
{
    if (!root)
    {
        *height = 0;
        return 0;
    }
    int leftHeight = 0, rightHeight = 0;
    int leftDia = diameter(root->left, &leftHeight);
    int rightDia = diameter(root->right, &rightHeight);
    *height = 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    return (leftHeight + rightHeight + 1) > (leftDia > rightDia ? leftDia : rightDia)
               ? (leftHeight + rightHeight + 1)
               : (leftDia > rightDia ? leftDia : rightDia);
}

// 6. Check if a Tree is Balanced
int isBalanced(struct Node *root, int *height)
{
    if (!root)
    {
        *height = 0;
        return 1;
    }
    int leftHeight = 0, rightHeight = 0;
    if (!isBalanced(root->left, &leftHeight) || !isBalanced(root->right, &rightHeight))
        return 0;
    *height = 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    return abs(leftHeight - rightHeight) <= 1;
}

// 7. Check for BST
int isBSTUtil(struct Node *root, int min, int max)
{
    if (!root)
        return 1;
    if (root->data <= min || root->data >= max)
        return 0;
    return isBSTUtil(root->left, min, root->data) && isBSTUtil(root->right, root->data, max);
}
int isBST(struct Node *root)
{
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

// 8. Convert Sorted Array to BST
struct Node *sortedArrayToBST(int arr[], int start, int end)
{
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    struct Node *root = createNode(arr[mid]);
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);
    return root;
}

// 9. Largest Value in Each Level of Binary Tree
void findMaxAtEachLevel(struct Node *root, int level, int *maxValues)
{
    if (!root)
        return;
    if (maxValues[level] < root->data)
        maxValues[level] = root->data;
    findMaxAtEachLevel(root->left, level + 1, maxValues);
    findMaxAtEachLevel(root->right, level + 1, maxValues);
}

// 10. Zigzag Tree Traversal
void zigzagTraversal(struct Node *root)
{
    if (!root)
         return;
    struct Node *queue[100];
    int front = 0, rear = 0, leftToRight = 1;
    queue[rear++] = root;
    while (front < rear)
    {
        int levelSize = rear - front;
        struct Node *levelNodes[levelSize];
        for (int i = 0; i < levelSize; i++)
        {
            levelNodes[i] = queue[front++];
            if (levelNodes[i]->left)
                queue[rear++] = levelNodes[i]->left;
            if (levelNodes[i]->right)
                queue[rear++] = levelNodes[i]->right;
        }
        if (!leftToRight)
        {
            for (int i = levelSize - 1; i >= 0; i--)
                printf("%d ", levelNodes[i]->data);
        }
        else
        {
            for (int i = 0; i < levelSize; i++)
                printf("%d ", levelNodes[i]->data);
        }
        leftToRight = !leftToRight;
    }
}

// 11. Inorder Successor in BST
struct Node *inorderSuccessor(struct Node *root, struct Node *target)
{
    struct Node *successor = NULL;
    while (root)
    {
        if (target->data < root->data)
        {
            successor = root;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return successor;
}

// 12. Kth Largest Element in BST
void kthLargestUtil(struct Node *root, int k, int *count, int *result)
{
    if (!root || *count >= k)
        return;
    kthLargestUtil(root->right, k, count, result);
    (*count)++;
    if (*count == k)
        *result = root->data;
    kthLargestUtil(root->left, k, count, result);
}
int kthLargest(struct Node *root, int k)
{
    int count = 0, result = -1;
    kthLargestUtil(root, k, &count, &result);
    return result;
}

// Main Function
int main()
{
    struct Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("Height: %d\n", height(root));
    printf("Is BST: %s\n", isBST(root) ? "Yes" : "No");
    printf("Diameter: %d\n", diameter(root, &(int){0}));
    printf("Zigzag Traversal: ");
    zigzagTraversal(root);
    printf("\n");

    return 0;
}
