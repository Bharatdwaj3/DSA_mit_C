#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

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
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void convertToCircular(Node *head)
{
    if (head == NULL)
        return;

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head; 
}

void displayCircularLinkedList(Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    Node *temp = head;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(Back to Head)\n");
}

int main()
{
    Node *head = NULL;

   
    for (int i = 1; i <= 6; i++)
    {
        append(&head, i);
    }

    printf("\nSingly Linked List: ");
    displayCircularLinkedList(head);

    convertToCircular(head);

    printf("Circular Linked List:\n");
    displayCircularLinkedList(head);

    return 0;
}
