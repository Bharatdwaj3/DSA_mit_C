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

void splitLinkedList(Node *head, Node **firstHalf, Node **secondHalf)
{
    if (head == NULL || head->next == NULL)
    {
        *firstHalf = head;
        *secondHalf = NULL;
        return;
    }

    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    *firstHalf = head;
    *secondHalf = slow->next;
    slow->next = NULL; 
}

void displayList(Node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    Node *head = NULL;
    Node *firstHalf = NULL;
    Node *secondHalf = NULL;

    for (int i = 1; i <= 6; i++)
    {
        append(&head, i);
    }

    printf("Original Linked List:\n");
    displayList(head);

    splitLinkedList(head, &firstHalf, &secondHalf);

    printf("First Half:\n");
    displayList(firstHalf);

    printf("Second Half:\n");
    displayList(secondHalf);

    return 0;
}
