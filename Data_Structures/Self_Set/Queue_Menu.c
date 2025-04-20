#include <stdio.h>
#define MAX_SIZE 100

typedef struct
{
    int arr[MAX_SIZE];
    int front, rear;
} Queue;

void initialize(Queue *queue)
{
    queue->front = -1;
    queue->rear = -1;
}

void enqueue(Queue *queue, int element)
{
    if (queue->rear == MAX_SIZE - 1)
    {
        printf("Queue Overflow! Cannot enqueue element %d\n", element);
        return;
    }
    if (queue->front == -1)
        queue->front = 0;
    queue->arr[++queue->rear] = element;
    printf("Enqueued %d into the queue.\n", element);
}

int dequeue(Queue *queue)
{
    if (queue->front == -1 || queue->front > queue->rear)
    {
        printf("Queue Underflow! Cannot dequeue element.\n");
        return -1;
    }
    return queue->arr[queue->front++];
}

int peek(Queue *queue)
{
    if (queue->front == -1 || queue->front > queue->rear)
    {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->arr[queue->front];
}

void display(Queue *queue)
{
    if (queue->front == -1 || queue->front > queue->rear)
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = queue->front; i <= queue->rear; i++)
    {
        printf("%d ", queue->arr[i]);
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