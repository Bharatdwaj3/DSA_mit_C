#include <stdio.h>
#include <stdlib.h>

#define MAX 5

void enqueue(int queue[], int *front, int *rear)
{
    int value;
    if (*rear == MAX - 1)
    {
        printf("\nQueue is full!\n");
        return;
    }
    printf("Enter the value you wanna enqueue: ");
    scanf("%d", &value);
    if (*front == -1)
        *front = 0;
    queue[++(*rear)] = value;
    printf("\nEnqueued %d into the queue!!\n", queue[*rear]);
}

void dequeue(int queue[], int *front, int *rear)
{
    if (*front == -1 || *front > *rear)
    {
        printf("\nQueue is empty!!\n");
    }
    else
    {
        printf("\nDequeued from the queue: %d\n", queue[*front]);
        (*front)++;
        if (*front > *rear)
        {
            *front = *rear = -1;
        }
    }
}

void peek(int queue[], int front, int rear)
{
    if (front == -1 || front > rear)
    {
        printf("\nQueue is empty!!\n");
    }
    else
    {
        printf("\nFront element: %d\n", queue[front]);
    }
}

void display(int queue[], int front, int rear)
{
    if (front == -1 || front > rear)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nQueue contents:\n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int queue[MAX], front = -1, rear = -1;
    int choice;

    while (1)
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
            enqueue(queue, &front, &rear);
            break;
        case 2:
            dequeue(queue, &front, &rear);
            break;
        case 3:
            peek(queue, front, rear);
            break;
        case 4:
            display(queue, front, rear);
            break;
        case 5:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    }
    return 0;
}
