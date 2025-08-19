#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h> // for abs()

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int value)
{
    if (!root)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

void inorderTraversal(struct Node *root)
{
    if (root)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct Node *root)
{
    if (root)
    {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct Node *root)
{
    if (root)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int height(struct Node *root)
{
    if (!root)
        return 0;
    int left = height(root->left);
    int right = height(root->right);
    return 1 + (left > right ? left : right);
}

int isBalanced(struct Node *root, int *height)
{
    if (!root)
    {
        *height = 0;
        return 1;
    }

    int lh = 0, rh = 0;
    if (!isBalanced(root->left, &lh) || !isBalanced(root->right, &rh))
        return 0;

    *height = 1 + (lh > rh ? lh : rh);
    return abs(lh - rh) <= 1;
}

int isBSTUtil(struct Node *root, int min, int max)
{
    if (!root)
        return 1;
    if (root->data <= min || root->data >= max)
        return 0;
    return isBSTUtil(root->left, min, root->data) &&
           isBSTUtil(root->right, root->data, max);
}

int isBST(struct Node *root)
{
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

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

int main()
{
    struct Node *root = NULL;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++)
        root = insert(root, values[i]);

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    printf("Height: %d\n", height(root));

    printf("Is symmetric: %s\n", isSymmetric(root) ? "Yes" : "No");

    printf("Is BST: %s\n", isBST(root) ? "Yes" : "No");

    int k = 3;
    printf("%d-th Largest element: %d\n", k, kthLargest(root, k));

    int a = 20, b = 80;
    printf("Minimum distance between %d and %d: %d\n", a, b, minDist(root, a, b));

    printf("Maximum sum from leaf to root: %d\n", maxSumLeafToRoot(root, 0));

    int h = 0;
    printf("Is Balanced: %s\n", isBalanced(root, &h) ? "Yes" : "No");

    return 0;
}
