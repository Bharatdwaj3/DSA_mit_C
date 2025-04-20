#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int front = -1, rear = -1;

void enqueue(int value, int queue[])
{
    if ((rear + 1) % MAX == front)
    {
        printf("Queue is Full!\n");
        return;
    }
    if (front == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % MAX;

    queue[rear] = value;
    printf("Enqueued %d into the queue.\n", value);
}

void dequeue(int queue[])
{
    if (front == -1)
    {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Dequeued %d from the queue.\n", queue[front]);
    if (front == rear)
    {
        front = rear = -1; // Reset queue when empty
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

void peek(int queue[])
{
    if (front == -1)
    {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Front Element: %d\n", queue[front]);
}

void display(int queue[])
{
    if (front == -1)
    {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Queue contents: ");
    int i = front;
    while (1)
    {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main()
{
    int queue[MAX], choice, value;

    while (1)
    {
        printf("\nCircular Queue Operations Menu:\n");
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
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            enqueue(value, queue);
            break;
        case 2:
            dequeue(queue);
            break;
        case 3:
            peek(queue);
            break;
        case 4:
            display(queue);
            break;
        case 5:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}