#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void addNode(struct Node **head, int value)
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
}

void deleteNode(struct Node **head, int value)
{

    if (*head == NULL)
    {
        printf("Empty List");
        return;
    }

    struct Node *temp = head;
    if (temp != NULL && temp->data == value)
    {
        *head = temp->next;
        free(temp);
        printf("Node with value %d deleted\n", value);
        return;
    }
    struct Node *prev = NULL;
    while (temp != NULL & temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("%d Node hai hi nahi", value);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Node with value %d deleted\n", value);
}

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

int main()
{
    struct Node *head = NULL;
    int n;

    printf("How many elements do you want to add to the linked list? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int value;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);

        addNode(&head, value);
    }

    printList(head);
    return 0;
}
