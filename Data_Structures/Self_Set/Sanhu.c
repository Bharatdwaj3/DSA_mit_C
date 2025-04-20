#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void printList(struct Node *head)
{
    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertAtBeginning(struct Node **head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failure\n");
        return;
    }
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
    printf("Node with value %d inserted at the beginning\n", value);
}

void insertAtEnd(struct Node **head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failure\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Node with value %d inserted at the end\n", value);
}

void deleteAtStart(struct Node **head)
{
    if (*head == NULL)
    {
        printf("Empty List!! Nothing to delete\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    printf("Node %d deleted from the start\n", temp->data);
    free(temp);
}

void deleteAtEnd(struct Node **head)
{
    if (*head == NULL)
    {
        printf("Empty List!! Nothing to delete\n");
        return;
    }
    if ((*head)->next == NULL)
    {
        printf("Node with value %d deleted from the end\n", (*head)->data);
        free(*head);
        *head = NULL;
        return;
    }

    struct Node *temp = *head;
    struct Node *prev = NULL;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    printf("Node with value %d deleted from the end\n", temp->data);
    free(temp);
}

int main()
{
    struct Node *head = NULL;

   
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    insertAtEnd(&head, 60);
    printList(head);

    
    printList(head);

    
    deleteAtEnd(&head);
    printList(head);

   
    deleteAtStart(&head);
    deleteAtStart(&head);
    deleteAtStart(&head);
    printList(head);     
    deleteAtEnd(&head);   
    return 0;
}
