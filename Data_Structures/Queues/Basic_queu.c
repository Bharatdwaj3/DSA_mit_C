#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum size of the queue (we can hold 5 items in the queue)

int main()
{
    // Declare an array to represent the queue.
    // The size of the queue is defined by MAX (5 in this case).
    int queue[MAX];

    // 'front' and 'rear' are pointers to track where the first and last elements are.
    // Initially set to -1 to indicate the queue is empty.
    int front = -1, rear = -1;
    int value; // Variable to hold values when dequeuing.

    // Enqueue operation (adding elements to the queue)

    // Check if the queue is full.
    if (rear == MAX - 1)
    {
        // If 'rear' reaches MAX-1, the queue is full and we cannot add more items.
        printf("Queue is full\n");
    }
    else
    {
        // If the queue is empty, set 'front' to 0 (this is the first item in the queue).
        if (front == -1)
        {
            front = 0;
        }

        // Increment 'rear' and add an item at the 'rear' position in the queue.
        rear++;           // Move 'rear' to the next position.
        queue[rear] = 10; // Add the value 10 to the queue.
        printf("%d enqueued to the queue\n", 10);

        rear++;           // Move 'rear' to the next position.
        queue[rear] = 20; // Add the value 20 to the queue.
        printf("%d enqueued to the queue\n", 20);

        rear++;           // Move 'rear' to the next position.
        queue[rear] = 30; // Add the value 30 to the queue.
        printf("%d enqueued to the queue\n", 30);

        rear++;           // Move 'rear' to the next position.
        queue[rear] = 40; // Add the value 40 to the queue.
        printf("%d enqueued to the queue\n", 40);

        rear++;           // Move 'rear' to the next position.
        queue[rear] = 50; // Add the value 50 to the queue.
        printf("%d enqueued to the queue\n", 50);
    }

    // Display the queue after enqueuing items

    // If 'front' is -1, the queue is empty, so we print a message.
    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        // Otherwise, print each item from 'front' to 'rear' in the queue.
        printf("Queue: ");
        for (int i = front; i <= rear; i++)
        {                            // Loop from 'front' to 'rear' (inclusive)
            printf("%d ", queue[i]); // Print each element in the queue.
        }
        printf("\n");
    }

    // Dequeue operation (removing an element from the queue)

    // If 'front' is -1, the queue is empty, and we can't remove any items.
    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        // 'value' gets the item at the 'front' position in the queue.
        value = queue[front];
        printf("Dequeued: %d\n", value); // Print the dequeued value.

        // If 'front' and 'rear' are the same, it means there was only one element.
        // We reset both to -1 to indicate the queue is empty.
        if (front == rear)
        {
            front = rear = -1; // Reset the queue to empty state.
        }
        else
        {
            front++; // Move 'front' to the next position in the queue.
        }
    }

    // Display the queue after dequeuing an item.

    // If 'front' is -1, the queue is empty, so we print a message.
    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        // Otherwise, print each item from 'front' to 'rear' in the queue.
        printf("Queue: ");
        for (int i = front; i <= rear; i++)
        {                            // Loop from 'front' to 'rear' (inclusive)
            printf("%d ", queue[i]); // Print each element in the queue.
        }
        printf("\n");
    }

    return 0; // End of the program.
}
