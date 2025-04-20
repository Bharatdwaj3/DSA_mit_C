#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int front = -1, rear = -1;

void enqueue(int value, int queue[])
{
    if (rear == MAX - 1)
    {
        printf("Queue is Full!\n");
        return;
    }
    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = value;
    printf("Enqueued %d into the queue.\n", queue[rear]);
}

void dequeue(int queue[])
{
    if (front == -1 || front > rear)
    {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Dequeued %d from the queue.\n", queue[front]);
    front++;
    if (front > rear)
    {
        front = rear = -1; // Reset queue when empty
    }
}

void peek(int queue[])
{
    if (front == -1 || front > rear)
    {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Front Element: %d\n", queue[front]);
}

void display(int queue[])
{
    if (front == -1 || front > rear)
    {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Queue contents: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    int queue[MAX], choice, value;

    while (1)
    {
        printf("\nQueue Operations Menu:\n");
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
