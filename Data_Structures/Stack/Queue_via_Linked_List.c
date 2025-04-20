#include <stdio.h>
#include <stdlib.h>

// Node structure to represent each element in the queue
struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL; // Pointer to the front of the queue
struct Node *rear = NULL;  // Pointer to the rear of the queue

// Enqueue an element into the queue
void enqueue(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) // If queue is empty
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued into queue\n", value);
}

// Dequeue an element from the queue
int dequeue()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    struct Node *temp = front;
    int dequeuedValue = front->data;
    front = front->next;
    if (front == NULL) // If queue becomes empty after dequeue
    {
        rear = NULL;
    }
    free(temp);
    return dequeuedValue;
}

// Peek at the front element without removing it
int peek()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    return front->data;
}

// Check if the queue is empty
int isEmpty()
{
    return front == NULL;
}

// Display the elements in the queue
void display()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        struct Node *temp = front;
        printf("Queue: ");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int choice, value;
    while (1)
    {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Check if Empty\n");
        printf("5. Display Queue\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            value = dequeue();
            if (value != -1)
            {
                printf("Dequeued: %d\n", value);
            }
            break;
        case 3:
            value = peek();
            if (value != -1)
            {
                printf("Front element: %d\n", value);
            }
            break;
        case 4:
            if (isEmpty())
            {
                printf("Queue is empty\n");
            }
            else
            {
                printf("Queue is not empty\n");
            }
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
