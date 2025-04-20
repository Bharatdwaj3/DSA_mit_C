#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int front = -1, rear = -1;

void enqueueFront(int value, int queue[])
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Queue is Full!\n");
        return;
    }
    if (front == -1)
    {
        front = rear = 0;
    }
    else if (front == 0)
    {
        front = MAX - 1;
    }
    else
    {
        front--;
    }
    queue[front] = value;
    printf("Enqueued %d at the front.\n", value);
}

void enqueueRear(int value, int queue[])
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Queue is Full!\n");
        return;
    }
    if (front == -1)
    {
        front = rear = 0;
    }
    else if (rear == MAX - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = value;
    printf("Enqueued %d at the rear.\n", value);
}

void dequeueFront(int queue[])
{
    if (front == -1)
    {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Dequeued %d from the front.\n", queue[front]);
    if (front == rear)
    {
        front = rear = -1; // Reset when empty
    }
    else if (front == MAX - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

void dequeueRear(int queue[])
{
    if (front == -1)
    {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Dequeued %d from the rear.\n", queue[rear]);
    if (front == rear)
    {
        front = rear = -1; // Reset when empty
    }
    else if (rear == 0)
    {
        rear = MAX - 1;
    }
    else
    {
        rear--;
    }
}

void peek(int queue[])
{
    if (front == -1)
    {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Front Element: %d | Rear Element: %d\n", queue[front], queue[rear]);
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
        printf("\nDouble-Ended Queue (Deque) Menu:\n");
        printf("1. Enqueue at Front\n");
        printf("2. Enqueue at Rear\n");
        printf("3. Dequeue from Front\n");
        printf("4. Dequeue from Rear\n");
        printf("5. Peek\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to insert at front: ");
            scanf("%d", &value);
            enqueueFront(value, queue);
            break;
        case 2:
            printf("Enter the value to insert at rear: ");
            scanf("%d", &value);
            enqueueRear(value, queue);
            break;
        case 3:
            dequeueFront(queue);
            break;
        case 4:
            dequeueRear(queue);
            break;
        case 5:
            peek(queue);
            break;
        case 6:
            display(queue);
            break;
        case 7:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
