#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *front, *rear;
} Queue;

void initialize(Queue *queue)
{
    queue->front = queue->rear = NULL;
}

void enqueue(Queue *queue, int element)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed! Cannot enqueue element %d\n", element);
        return;
    }
    newNode->data = element;
    newNode->next = NULL;
    if (queue->rear == NULL)
    {
        queue->front = queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("Enqueued %d into the queue.\n", element);
}

int dequeue(Queue *queue)
{
    if (queue->front == NULL)
    {
        printf("Queue Underflow! Cannot dequeue element.\n");
        return -1;
    }
    int value = queue->front->data;
    Node *temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL)
        queue->rear = NULL;
    free(temp);
    return value;
}

int peek(Queue *queue)
{
    if (queue->front == NULL)
    {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->front->data;
}

void display(Queue *queue)
{
    if (queue->front == NULL)
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    Node *current = queue->front;
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    Queue queue;
    initialize(&queue);
    int choice, value;

    do
    {
        printf("\nQueue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to enqueue: ");
            scanf("%d", &value);
            enqueue(&queue, value);
            break;
        case 2:
            value = dequeue(&queue);
            if (value != -1)
                printf("Dequeued element: %d\n", value);
            break;
        case 3:
            value = peek(&queue);
            if (value != -1)
                printf("Front element: %d\n", value);
            break;
        case 4:
            display(&queue);
            break;
        case 5:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
