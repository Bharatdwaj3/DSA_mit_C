#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// Structure of a Node
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

// 1. Odd-Even Level Difference
int oddEvenDifference(struct Node *root, int level)
{
    if (!root)
        return 0;
    return (level % 2 == 0 ? -root->data : root->data) +
           oddEvenDifference(root->left, level + 1) +
           oddEvenDifference(root->right, level + 1);
}

// 2. Sum of Nodes at Odd & Even Levels Separately
void sumOddEvenLevels(struct Node *root, int level, int *oddSum, int *evenSum)
{
    if (!root)
        return;
    if (level % 2 == 0)
        *evenSum += root->data;
    else
        *oddSum += root->data;
    sumOddEvenLevels(root->left, level + 1, oddSum, evenSum);
    sumOddEvenLevels(root->right, level + 1, oddSum, evenSum);
}

// 3. Maximum Sum at Any Level
int maxLevelSum(struct Node *root)
{
    if (!root)
        return 0;
    int maxSum = INT_MIN;
    struct Node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear)
    {
        int levelSize = rear - front, levelSum = 0;
        for (int i = 0; i < levelSize; i++)
        {
            struct Node *temp = queue[front++];
            levelSum += temp->data;
            if (temp->left)
                queue[rear++] = temp->left;
            if (temp->right)
                queue[rear++] = temp->right;
        }
        if (levelSum > maxSum)
            maxSum = levelSum;
    }
    return maxSum;
}

// 4. Difference Between Left & Right Subtree Sums
int subtreeSum(struct Node *root)
{
    if (!root)
        return 0;
    return root->data + subtreeSum(root->left) + subtreeSum(root->right);
}
int leftRightDifference(struct Node *root)
{
    if (!root)
        return 0;
    return abs(subtreeSum(root->left) - subtreeSum(root->right));
}

// 5. Maximum Depth of a Tree
int maxDepth(struct Node *root)
{
    if (!root)
        return 0;
    return 1 + (maxDepth(root->left) > maxDepth(root->right) ? maxDepth(root->left) : maxDepth(root->right));
}

// 6. Zig-Zag (Spiral) Level Order Traversal
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
            for (int i = levelSize - 1; i >= 0; i--)
                printf("%d ", levelNodes[i]->data);
        else
            for (int i = 0; i < levelSize; i++)
                printf("%d ", levelNodes[i]->data);
        leftToRight = !leftToRight;
    }
}

// MAIN FUNCTION TO TEST ALL FUNCTIONS
int main()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    printf("Odd-Even Level Difference: %d\n", oddEvenDifference(root, 0));
    int oddSum = 0, evenSum = 0;
    sumOddEvenLevels(root, 0, &oddSum, &evenSum);
    printf("Odd Level Sum: %d, Even Level Sum: %d\n", oddSum, evenSum);
    printf("Max Level Sum: %d\n", maxLevelSum(root));
    printf("Left-Right Subtree Difference: %d\n", leftRightDifference(root));
    printf("Tree Depth: %d\n", maxDepth(root));
    printf("Zigzag Traversal: ");
    zigzagTraversal(root);
    printf("\n");

    return 0;
}
