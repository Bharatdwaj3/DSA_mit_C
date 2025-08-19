#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure for a node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new node
struct Node *createNode(int data) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Insert node into BST
void insert(struct Node **root, int data) {
    if (!*root) {
        *root = createNode(data);
        return;
    }
    if (data < (*root)->data)
        insert(&(*root)->left, data);
    else
        insert(&(*root)->right, data);
}

// 1. Height of a Binary Tree
void height(struct Node *root, int *res) {
    if (!root) {
        *res = 0;
        return;
    }
    int left, right;
    height(root->left, &left);
    height(root->right, &right);
    *res = 1 + (left > right ? left : right);
}

// 2. Check if Two Trees are Identical
void areIdentical(struct Node *root1, struct Node *root2, int *result) {
    if (!root1 && !root2) {
        *result = 1;
        return;
    }
    if (!root1 || !root2) {
        *result = 0;
        return;
    }
    int left, right;
    areIdentical(root1->left, root2->left, &left);
    areIdentical(root1->right, root2->right, &right);
    *result = (root1->data == root2->data) && left && right;
}

// 3. Convert to Mirror Tree
void mirror(struct Node *root) {
    if (!root)
        return;
    mirror(root->left);
    mirror(root->right);
    struct Node *temp = root->left;
    root->left = root->right;
    root->right = temp;
}

// 4. Check if Tree is Symmetric
void isMirror(struct Node *root1, struct Node *root2, int *res) {
    if (!root1 && !root2) {
        *res = 1;
        return;
    }
    if (!root1 || !root2) {
        *res = 0;
        return;
    }
    int left, right;
    isMirror(root1->left, root2->right, &left);
    isMirror(root1->right, root2->left, &right);
    *res = (root1->data == root2->data) && left && right;
}

void isSymmetric(struct Node *root, int *res) {
    isMirror(root, root, res);
}

void isAsymmetric(struct Node *root, int *res) {
    isMirror(root, root, res);
    *res = !(*res);
}

// 5. Diameter of a Tree
void diameter(struct Node *root, int *height, int *dia) {
    if (!root) {
        *height = 0;
        *dia = 0;
        return;
    }
    int lh, rh, ld, rd;
    diameter(root->left, &lh, &ld);
    diameter(root->right, &rh, &rd);
    *height = 1 + (lh > rh ? lh : rh);
    int current = lh + rh + 1;
    *dia = (current > (ld > rd ? ld : rd)) ? current : (ld > rd ? ld : rd);
}

// 6. Check if a Tree is Balanced
void isBalanced(struct Node *root, int *height, int *res) {
    if (!root) {
        *height = 0;
        *res = 1;
        return;
    }
    int lh, rh, lb, rb;
    isBalanced(root->left, &lh, &lb);
    isBalanced(root->right, &rh, &rb);
    *height = 1 + (lh > rh ? lh : rh);
    *res = lb && rb && abs(lh - rh) <= 1;
}

// 7. Check for BST
void isBSTUtil(struct Node *root, int min, int max, int *res) {
    if (!root) {
        *res = 1;
        return;
    }
    if (root->data <= min || root->data >= max) {
        *res = 0;
        return;
    }
    int left, right;
    isBSTUtil(root->left, min, root->data, &left);
    isBSTUtil(root->right, root->data, max, &right);
    *res = left && right;
}

void isBST(struct Node *root, int *res) {
    isBSTUtil(root, INT_MIN, INT_MAX, res);
}

// 8. Convert Sorted Array to BST
void sortedArrayToBST(int arr[], int start, int end, struct Node **root) {
    if (start > end) {
        *root = NULL;
        return;
    }
    int mid = (start + end) / 2;
    *root = createNode(arr[mid]);
    sortedArrayToBST(arr, start, mid - 1, &(*root)->left);
    sortedArrayToBST(arr, mid + 1, end, &(*root)->right);
}

// 9. Largest Value in Each Level of Binary Tree
void findMaxAtEachLevel(struct Node *root, int level, int *maxValues) {
    if (!root)
        return;
    if (maxValues[level] < root->data)
        maxValues[level] = root->data;
    findMaxAtEachLevel(root->left, level + 1, maxValues);
    findMaxAtEachLevel(root->right, level + 1, maxValues);
}

// 10. Zigzag Tree Traversal
void zigzagTraversal(struct Node *root) {
    if (!root)
        return;
    struct Node *queue[100];
    int front = 0, rear = 0, leftToRight = 1;
    queue[rear++] = root;
    while (front < rear) {
        int levelSize = rear - front;
        struct Node *levelNodes[levelSize];
        for (int i = 0; i < levelSize; i++) {
            levelNodes[i] = queue[front++];
            if (levelNodes[i]->left)
                queue[rear++] = levelNodes[i]->left;
            if (levelNodes[i]->right)
                queue[rear++] = levelNodes[i]->right;
        }
        if (!leftToRight) {
            for (int i = levelSize - 1; i >= 0; i--)
                printf("%d ", levelNodes[i]->data);
        } else {
            for (int i = 0; i < levelSize; i++)
                printf("%d ", levelNodes[i]->data);
        }
        leftToRight = !leftToRight;
    }
}

// 11. Inorder Successor in BST
void inorderSuccessor(struct Node *root, struct Node *target, struct Node **successor) {
    *successor = NULL;
    while (root) {
        if (target->data < root->data) {
            *successor = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
}

// 12. Kth Largest Element in BST
void kthLargestUtil(struct Node *root, int k, int *count, int *result) {
    if (!root || *count >= k)
        return;
    kthLargestUtil(root->right, k, count, result);
    (*count)++;
    if (*count == k)
        *result = root->data;
    kthLargestUtil(root->left, k, count, result);
}
void kthLargest(struct Node *root, int k, int *res) {
    int count = 0;
    *res = -1;
    kthLargestUtil(root, k, &count, res);
}

// Main Function
int main() {
    struct Node *root = NULL;
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 70);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 60);
    insert(&root, 80);

    int h;
    height(root, &h);
    printf("Height: %d\n", h);

    int bst;
    isBST(root, &bst);
    printf("Is BST: %s\n", bst ? "Yes" : "No");

    int dia, ht;
    diameter(root, &ht, &dia);
    printf("Diameter: %d\n", dia);

    printf("Zigzag Traversal: ");
    zigzagTraversal(root);
    printf("\n");

    return 0;
}
