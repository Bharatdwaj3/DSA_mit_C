#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Definition of a binary tree node
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

// 1. Check if a Tree is a Subtree
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
int isSubtree(struct Node *T, struct Node *S)
{
    if (!S)
        return 1;
    if (!T)
        return 0;
    if (areIdentical(T, S))
        return 1;
    return isSubtree(T->left, S) || isSubtree(T->right, S);
}

// 2. Check for Single Valued Subtree
int isSingleValued(struct Node *root, int *count)
{
    if (!root)
        return 1;
    int left = isSingleValued(root->left, count);
    int right = isSingleValued(root->right, count);
    if (!left || !right)
        return 0;
    if (root->left && root->data != root->left->data)
        return 0;
    if (root->right && root->data != root->right->data)
        return 0;
    (*count)++;
    return 1;
}
int countSingleValuedSubtrees(struct Node *root)
{
    int count = 0;
    isSingleValued(root, &count);
    return count;
}

// 3. Unique BSTs (Catalan Number)
int uniqueBST(int n)
{
    int dp[n + 1];
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = 0;
        for (int j = 0; j < i; j++)
            dp[i] += dp[j] * dp[i - j - 1];
    }
    return dp[n];
}

// 4. Iterative Inorder Traversal
void inorderIterative(struct Node *root)
{
    struct Node *stack[100];
    int top = -1;
    while (root || top != -1)
    {
        while (root)
        {
            stack[++top] = root;
            root = root->left;
        }
        root = stack[top--];
        printf("%d ", root->data);
        root = root->right;
    }
}

// 5. Iterative Preorder Traversal
void preorderIterative(struct Node *root)
{
    if (!root)
        return;
    struct Node *stack[100];
    int top = -1;
    stack[++top] = root;
    while (top != -1)
    {
        struct Node *node = stack[top--];
        printf("%d ", node->data);
        if (node->right)
            stack[++top] = node->right;
        if (node->left)
            stack[++top] = node->left;
    }
}

// 6. Iterative Postorder Traversal
void postorderIterative(struct Node *root)
{
    if (!root)
        return;
    struct Node *stack1[100], *stack2[100];
    int top1 = -1, top2 = -1;
    stack1[++top1] = root;
    while (top1 != -1)
    {
        struct Node *node = stack1[top1--];
        stack2[++top2] = node;
        if (node->left)
            stack1[++top1] = node->left;
        if (node->right)
            stack1[++top1] = node->right;
    }
    while (top2 != -1)
        printf("%d ", stack2[top2--]->data);
}

// 7. Lowest Common Ancestor (LCA)
struct Node *LCA(struct Node *root, int n1, int n2)
{
    if (!root)
        return NULL;
    if (root->data == n1 || root->data == n2)
        return root;
    struct Node *left = LCA(root->left, n1, n2);
    struct Node *right = LCA(root->right, n1, n2);
    if (left && right)
        return root;
    return left ? left : right;
}

// 8. Minimum Distance Between Two Nodes
int findLevel(struct Node *root, int key, int level)
{
    if (!root)
        return -1;
    if (root->data == key)
        return level;
    int left = findLevel(root->left, key, level + 1);
    return left != -1 ? left : findLevel(root->right, key, level + 1);
}
int minDist(struct Node *root, int a, int b)
{
    struct Node *lca = LCA(root, a, b);
    int d1 = findLevel(lca, a, 0);
    int d2 = findLevel(lca, b, 0);
    return d1 + d2;
}

// 9. Maximum Sum Leaf to Root Path
int maxSumLeafToRoot(struct Node *root, int sum)
{
    if (!root)
        return sum;
    sum += root->data;
    if (!root->left && !root->right)
        return sum;
    int left = maxSumLeafToRoot(root->left, sum);
    int right = maxSumLeafToRoot(root->right, sum);
    return left > right ? left : right;
}

// 10. Odd-Even Level Difference
int oddEvenDifference(struct Node *root, int level)
{
    if (!root)
        return 0;
    return (level % 2 == 0 ? -root->data : root->data) +
           oddEvenDifference(root->left, level + 1) +
           oddEvenDifference(root->right, level + 1);
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

    printf("Inorder Traversal (Iterative): ");
    inorderIterative(root);
    printf("\n");

    printf("Preorder Traversal (Iterative): ");
    preorderIterative(root);
    printf("\n");

    printf("Postorder Traversal (Iterative): ");
    postorderIterative(root);
    printf("\n");

    printf("Unique BSTs with 3 nodes: %d\n", uniqueBST(3));
    printf("Lowest Common Ancestor of 20 and 40: %d\n", LCA(root, 20, 40)->data);
    printf("Minimum Distance between 20 and 40: %d\n", minDist(root, 20, 40));
    printf("Max Sum Leaf to Root Path: %d\n", maxSumLeafToRoot(root, 0));
    printf("Odd-Even Level Difference: %d\n", oddEvenDifference(root, 1));

    return 0;
}
