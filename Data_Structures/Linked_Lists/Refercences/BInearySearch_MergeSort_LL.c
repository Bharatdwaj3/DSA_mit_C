#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Function to create a new node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end
void append(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to find the middle of the linked list
Node *getMiddle(Node *head)
{
    if (!head)
        return NULL;
    Node *slow = head, *fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Merge function for merge sort
Node *merge(Node *left, Node *right)
{
    if (!left)
        return right;
    if (!right)
        return left;

    Node *result = NULL;
    if (left->data <= right->data)
    {
        result = left;
        result->next = merge(left->next, right);
    }
    else
    {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}

// Merge Sort function
Node *mergeSort(Node *head)
{
    if (!head || !head->next)
        return head;

    Node *middle = getMiddle(head);
    Node *rightHalf = middle->next;
    middle->next = NULL;

    Node *leftSorted = mergeSort(head);
    Node *rightSorted = mergeSort(rightHalf);

    return merge(leftSorted, rightSorted);
}

// Binary search function on sorted linked list
int binarySearch(Node *head, int key)
{
    Node *low = head, *high = NULL;
    do
    {
        Node *mid = getMiddle(low);
        if (!mid)
            return 0;
        if (mid->data == key)
            return 1;
        else if (mid->data < key)
            low = mid->next;
        else
            high = mid;
    } while (low != high);
    return 0;
}

// Function to print the linked list
void printList(Node *head)
{
    while (head)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Driver code
int main()
{
    Node *head = NULL;

    append(&head, 5);
    append(&head, 2);
    append(&head, 8);
    append(&head, 3);
    append(&head, 1);

    printf("Original List: \n");
    printList(head);

    head = mergeSort(head);
    printf("Sorted List: \n");
    printList(head);

    int key = 3;
    if (binarySearch(head, key))
        printf("%d found in the list.\n", key);
    else
        printf("%d not found in the list.\n", key);

    return 0;
}
