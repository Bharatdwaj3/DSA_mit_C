#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if ((rear + 1) % MAX == front) {
        printf("Queue is full\n");
    } else {
        if (front == -1) front = 0; // First element in the queue
        rear = (rear + 1) % MAX;
        queue[rear] = value;
        printf("%d enqueued\n", value);
    }
}

int dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
        return -1;
    } else {
        int dequeuedValue = queue[front];
        if (front == rear) {  // Queue has only one element
            front = rear = -1; // Reset queue
        } else {
            front = (front + 1) % MAX;
        }
        return dequeuedValue;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        int i = front;
        printf("Queue: ");
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", queue[rear]);  // Print the last element
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    printf("Dequeued: %d\n", dequeue());
    display();
    
    return 0;
}
