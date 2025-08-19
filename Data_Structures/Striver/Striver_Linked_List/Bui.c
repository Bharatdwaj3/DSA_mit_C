#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Insert node at the start
void insertStart(struct Node **head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Print linked list
void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// ---------- Q1: Merge two sorted linked lists ----------
struct Node *mergeSortedLists(struct Node *l1, struct Node *l2)
{
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;

    struct Node *result = NULL;

    if (l1->data < l2->data)
    {
        result = l1;
        result->next = mergeSortedLists(l1->next, l2);
    }
    else
    {
        result = l2;
        result->next = mergeSortedLists(l1, l2->next);
    }
    return result;
}

// ---------- Q2: Insert after Nth position (0-based index) ----------
void insertNth(struct Node **head, int index, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (index == 0)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    for (int i = 0; temp != NULL && i < index - 1; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of bounds.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// ---------- Q3: Remove duplicates from unsorted list ----------
void removeDuplicates(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        struct Node *runner = current;
        while (runner->next != NULL)
        {
            if (runner->next->data == current->data)
            {
                struct Node *temp = runner->next;
                runner->next = runner->next->next;
                free(temp);
            }
            else
            {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

int main()
{
    // === Q1: Merge Two Sorted Lists ===
    struct Node *list1 = NULL, *list2 = NULL;
    insertStart(&list1, 9);
    insertStart(&list1, 7);
    insertStart(&list1, 5);
    insertStart(&list2, 8);
    insertStart(&list2, 6);
    insertStart(&list2, 2);

    printf("Sorted List 1: ");
    printList(list1);
    printf("Sorted List 2: ");
    printList(list2);

    struct Node *mergedList = mergeSortedLists(list1, list2);
    printf("Merged Sorted List: ");
    printList(mergedList);

    // === Q2: Insert After Nth Position ===
    printf("\nInsert value 100 after position 2 in merged list.\n");
    insertNth(&mergedList, 2, 100);
    printList(mergedList);

    // === Q3: Remove Duplicates from Unsorted List ===
    printf("\nAdd duplicates to merged list and remove them.\n");
    insertStart(&mergedList, 5); // Adding duplicate
    insertStart(&mergedList, 7); // Adding duplicate
    printf("List with duplicates: ");
    printList(mergedList);

    removeDuplicates(mergedList);
    printf("List after removing duplicates: ");
    printList(mergedList);

    return 0;
}
