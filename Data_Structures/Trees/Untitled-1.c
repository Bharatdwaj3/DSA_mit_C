#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Node structure
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// 1. Create a new node
struct Node *createNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// 2. Insert node into BST
struct Node *insert(struct Node *root, int data)
{
    if (!root)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// 3. Inorder traversal (L, Root, R)
void inorderTraversal(struct Node *root)
{
    if (!root)
        return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// 4. Preorder traversal (Root, L, R)
void preorderTraversal(struct Node *root)
{
    if (!root)
        return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// 5. Postorder traversal (L, R, Root)
void postorderTraversal(struct Node *root)
{
    if (!root)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

// 6. Find minimum node in BST
struct Node *findMin(struct Node *node)
{
    if (!node)
        return NULL;
    while (node->left)
        node = node->left;
    return node;
}

// 7. Find height of binary tree
int height(struct Node *root)
{
    if (!root)
        return 0;
    int leftH = height(root->left);
    int rightH = height(root->right);
    return 1 + (leftH > rightH ? leftH : rightH);
}

// 8. Check if two trees are identical
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

// 9. Convert tree to its mirror
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

// 10. Check if tree is symmetric
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

// 11. Diameter of tree
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
    int maxDia = (leftHeight + rightHeight + 1);
    if (leftDia > rightDia && leftDia > maxDia)
        return leftDia;
    if (rightDia > leftDia && rightDia > maxDia)
        return rightDia;
    return maxDia;
}

// 12. Check if tree is balanced
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

// 13. Check if tree is BST
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

// 14. Count total nodes
int countTotal(struct Node *root)
{
    if (!root)
        return 0;
    return 1 + countTotal(root->left) + countTotal(root->right);
}

// 15. Count nodes in left subtree
int countLeft(struct Node *root)
{
    if (!root || !root->left)
        return 0;
    return 1 + countTotal(root->left);
}

// 16. Count nodes in right subtree
int countRight(struct Node *root)
{
    if (!root || !root->right)
        return 0;
    return 1 + countTotal(root->right);
}

// 17. Inorder successor (recursive)
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

// 18. Inorder successor (iterative)
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

// 19. Delete node (general)
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

// 20. Delete node with only right child
struct Node *deleteWithRightChild(struct Node *root, int key)
{
    if (!root)
        return NULL;
    if (key < root->data)
        root->left = deleteWithRightChild(root->left, key);
    else if (key > root->data)
        root->right = deleteWithRightChild(root->right, key);
    else
    {
        if (root->right && !root->left)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
    }
    return root;
}

// 21. Delete leaf node
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

// 22. Delete node with one child
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

// 23. Count single-valued subtrees helper
int countSingleValuedHelper(struct Node *root, int *count)
{
    if (!root)
        return 1;
    int left = countSingleValuedHelper(root->left, count);
    int right = countSingleValuedHelper(root->right, count);
    if (left && right)
    {
        if ((root->left && root->data != root->left->data) ||
            (root->right && root->data != root->right->data))
            return 0;
        (*count)++;
        return 1;
    }
    return 0;
}
// 24. Count single-valued subtrees
int countSingleValuedSubtrees(struct Node *root)
{
    int count = 0;
    countSingleValuedHelper(root, &count);
    return count;
}

// 25. Count nodes in subtree (helper for countLeft and countRight)
int countNodes(struct Node *root)
{
    if (!root)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// 26. Find kth largest node (BST property)
void kthLargestUtil(struct Node *root, int k, int *count, int *result)
{
    if (!root || *count >= k)
        return;
    kthLargestUtil(root->right, k, count, result);
    (*count)++;
    if (*count == k)
    {
        *result = root->data;
        return;
    }
    kthLargestUtil(root->left, k, count, result);
}
int kthLargest(struct Node *root, int k)
{
    int count = 0, result = -1;
    kthLargestUtil(root, k, &count, &result);
    return result;
}

// 27. Sorted array to BST
struct Node *sortedArrayToBST(int arr[], int start, int end)
{
    if (start > end)
        return NULL;
    int mid = start + (end - start) / 2;
    struct Node *node = createNode(arr[mid]);
    node->left = sortedArrayToBST(arr, start, mid - 1);
    node->right = sortedArrayToBST(arr, mid + 1, end);
    return node;
}

// 28. Find inorder successor in BST (using iterative approach)
struct Node *findInorderSuccessor(struct Node *root, struct Node *node)
{
    struct Node *successor = NULL;
    while (root)
    {
        if (node->data < root->data)
        {
            successor = root;
            root = root->left;
        }
        else if (node->data > root->data)
        {
            root = root->right;
        }
        else
        {
            if (root->right)
            {
                successor = findMin(root->right);
            }
            break;
        }
    }
    return successor;
}

// 29. Print BST in sorted order (inorder)
void printInorder(struct Node *root)
{
    if (!root)
        return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

// 30. Free BST memory
void freeBST(struct Node *root)
{
    if (!root)
        return;
    freeBST(root->left);
    freeBST(root->right);
    free(root);
}

// Main function (optional example)

int main()
{
    struct Node *root = NULL;

    // 1. createNode (used internally in insert, so just demonstrate separately)
    struct Node *testNode = createNode(100);
    printf("Created node with data: %d\n", testNode->data);

    // 2. insert nodes
    int values[] = {20, 10, 30, 5, 15, 25, 35};
    for (int i = 0; i < 7; i++)
    {
        root = insert(root, values[i]);
    }

    // 3. inorderTraversal
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    // 4. preorderTraversal
    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    // 5. postorderTraversal
    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    // 6. findMin
    struct Node *minNode = findMin(root);
    if (minNode)
        printf("Minimum node data: %d\n", minNode->data);

    // 7. height
    printf("Height of tree: %d\n", height(root));

    // 8. areIdentical (compare root with itself, should be true)
    printf("Are trees identical (root vs root)? %s\n", areIdentical(root, root) ? "Yes" : "No");

    // 9. mirror (mirror the tree, then print inorder)
    mirror(root);
    printf("Inorder traversal after mirror: ");
    inorderTraversal(root);
    printf("\n");
    mirror(root); // revert back for further tests

    // 10. isSymmetric (check if root is symmetric)
    printf("Is tree symmetric? %s\n", isSymmetric(root) ? "Yes" : "No");

    // 11. diameter
    int h = 0;
    printf("Diameter of tree: %d\n", diameter(root, &h));

    // 12. isBalanced
    int heightBalanced = 0;
    printf("Is tree balanced? %s\n", isBalanced(root, &heightBalanced) ? "Yes" : "No");

    // 13. isBST
    printf("Is tree BST? %s\n", isBST(root) ? "Yes" : "No");

    // 14. countTotal
    printf("Total nodes in tree: %d\n", countTotal(root));

    // 15. countLeft
    printf("Nodes in left subtree: %d\n", countLeft(root));

    // 16. countRight
    printf("Nodes in right subtree: %d\n", countRight(root));

    // 17. inorderSuccessorRecursive (successor of node with 15)
    struct Node target = {15, NULL, NULL};
    struct Node *succRec = inorderSuccessorRecursive(root, &target);
    printf("Inorder successor (recursive) of 15: %d\n", succRec ? succRec->data : -1);

    // 18. inorderSuccessor (iterative) of 15
    struct Node *succIter = inorderSuccessor(root, &target);
    printf("Inorder successor (iterative) of 15: %d\n", succIter ? succIter->data : -1);

    // 19. deleteNode (delete 10)
    root = deleteNode(root, 10);
    printf("Inorder after deleting 10: ");
    inorderTraversal(root);
    printf("\n");

    // 20. deleteWithRightChild (insert 12 first, then delete 12)
    root = insert(root, 12);
    root = deleteWithRightChild(root, 12);
    printf("Inorder after deleting node with only right child 12: ");
    inorderTraversal(root);
    printf("\n");

    // 21. deleteLeaf (insert 6 first, then delete leaf 6)
    root = insert(root, 6);
    root = deleteLeaf(root, 6);
    printf("Inorder after deleting leaf node 6: ");
    inorderTraversal(root);
    printf("\n");

    // 22. deleteWithOneChild (insert 17, then delete 15 which has one child 17)
    root = insert(root, 17);
    root = deleteWithOneChild(root, 15);
    printf("Inorder after deleting node 15 with one child: ");
    inorderTraversal(root);
    printf("\n");

    // 23 & 24. countSingleValuedSubtrees
    printf("Count of single-valued subtrees: %d\n", countSingleValuedSubtrees(root));

    // 25. countNodes (count nodes of left subtree)
    printf("Count nodes in left subtree: %d\n", countNodes(root->left));

    // 26. kthLargest (3rd largest)
    int k = 3;
    int kthVal = kthLargest(root, k);
    printf("The %d-th largest element is: %d\n", k, kthVal);

    // 27. sortedArrayToBST (build new BST)
    int sortedArr[] = {2, 4, 6, 8, 10};
    struct Node *newRoot = sortedArrayToBST(sortedArr, 0, 4);
    printf("Inorder of BST from sorted array: ");
    inorderTraversal(newRoot);
    printf("\n");

    // 28. findInorderSuccessor (using iterative on newRoot for node 6)
    struct Node newTarget = {6, NULL, NULL};
    struct Node *successor = findInorderSuccessor(newRoot, &newTarget);
    printf("Inorder successor of 6 in new BST: %d\n", successor ? successor->data : -1);

    // 29. printInorder (just call on newRoot)
    printf("Print inorder using printInorder: ");
    printInorder(newRoot);
    printf("\n");

    // 30. freeBST (free both trees)
    freeBST(root);
    freeBST(newRoot);
    free(testNode);

    return 0;
}
