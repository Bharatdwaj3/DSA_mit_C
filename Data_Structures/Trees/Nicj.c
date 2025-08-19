#include <stdio.h>
#include <stdlib.h>

// Linked List Node Definition
struct ListNode
{
    int data;
    struct ListNode *next;
};

// Binary Tree Node Definition
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// === Linked List Functions ===

// Print Nth node from end
void printNthFromLast(struct ListNode *head, int N)
{
    struct ListNode *main_ptr = head;
    struct ListNode *ref_ptr = head;

    int count = 0;
    while (count < N)
    {
        if (ref_ptr == NULL)
            return; // N is greater than length
        ref_ptr = ref_ptr->next;
        count++;
    }

    while (ref_ptr != NULL)
    {
        main_ptr = main_ptr->next;
        ref_ptr = ref_ptr->next;
    }

    if (main_ptr != NULL)
        printf("%d\n", main_ptr->data);
}

// Multiply least significant digits of all nodes
int multiplyLeastSignificantDigits(struct ListNode *start)
{
    int product = 1;
    while (start != NULL)
    {
        int lsd = start->data % 10; // Least Significant Digit
        product *= lsd;
        start = start->next;
    }
    return product;
}

// Delete all nodes with odd values
void deleteOddNodes(struct ListNode **ptr)
{
    struct ListNode *temp;

    while (*ptr != NULL && (*ptr)->data % 2 != 0)
    {
        temp = *ptr;
        *ptr = (*ptr)->next;
        free(temp);
    }

    struct ListNode *current = *ptr;
    while (current != NULL && current->next != NULL)
    {
        if (current->next->data % 2 != 0)
        {
            temp = current->next;
            current->next = current->next->next;
            free(temp);
        }
        else
        {
            current = current->next;
        }
    }
}

// Convert singly linked list to circular linked list
void convertToCircular(struct ListNode *head)
{
    if (head == NULL)
        return;

    struct ListNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
}

// === Binary Search Tree Functions ===

// Insert a node in BST
struct TreeNode *insert(struct TreeNode *root, int key)
{
    if (root == NULL)
    {
        struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        newNode->data = key;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

// Count nodes with both children in BST
int countNodesWithBothChildren(struct TreeNode *root)
{
    if (root == NULL)
        return 0;
    int count = 0;
    if (root->left != NULL && root->right != NULL)
        count = 1;
    return count + countNodesWithBothChildren(root->left) + countNodesWithBothChildren(root->right);
}
int main()
{
    // ==== Linked List Operations ====
    struct ListNode *head = NULL, *temp = NULL;

    // Create linked list: 123 -> 242 -> 334 -> 455
    int listValues[] = {123, 242, 334, 455};
    for (int i = 0; i < 4; i++)
    {
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->data = listValues[i];
        newNode->next = NULL;
        if (head == NULL)
            head = newNode;
        else
            temp->next = newNode;
        temp = newNode;
    }

    printf("Nth node from end (N=2): ");
    printNthFromLast(head, 2); // Expected: 334

    int product = multiplyLeastSignificantDigits(head);
    printf("Product of least significant digits: %d\n", product); // Expected: 3*2*4*5 = 120

    deleteOddNodes(&head);
    printf("Linked list after deleting odd nodes: ");
    temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    convertToCircular(head);
    printf("Converted to circular. First 4 elements in circular list: ");
    temp = head;
    for (int i = 0; i < 4 && temp != NULL; i++)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("...\n");

    // ==== Binary Search Tree Operations ====
    struct TreeNode *root = NULL;
    int bstValues[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++)
    {
        root = insert(root, bstValues[i]);
    }

    int count = countNodesWithBothChildren(root);
    printf("Number of BST nodes with both children: %d\n", count); // Expected: 3 (50, 30, 70)

    return 0;
}
