#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    int priority;
    struct Node *next;
} Node;

Node *newNode(int value, int priority)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = value;
    temp->priority = priority;
    temp->next = NULL;
    return temp;
}

Node *enqueue(Node *head, int data, int priority)
{
    Node *temp = newNode(data, priority);
    if (!head || priority < head->priority)
    {
        temp->next = head;
        return temp;
    }

    Node *start = head;
    while (start->next && start->next->priority <= priority)
    {
        start = start->next;
    }

    temp->next = start->next;
    start->next = temp;
    return head;
}

Node *dequeue(Node *head)
{
    if (!head)
        return NULL;
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

void printQueue(Node *head)
{
    while (head)
    {
        printf("(%d, P:%d) -> ", head->data, head->priority);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    Node *pq = NULL;

    pq = enqueue(pq, 4, 1);
    pq = enqueue(pq, 5, 2);
    pq = enqueue(pq, 6, 3);
    pq = enqueue(pq, 7, 0);

    printf("Priority Queue:\n");
    printQueue(pq);

    pq = dequeue(pq);
    printf("After Dequeue:\n");
    printQueue(pq);

    return 0;
}
