#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue is full\n");
    } else {
        if (front == -1) front = 0;  // Empty queue
        rear++;
        int i = rear;
        // Insert the new element in sorted order (highest priority first)
        while (i > 0 && queue[i - 1] < value) {
            queue[i] = queue[i - 1];
            i--;
        }
        queue[i] = value;
        printf("%d enqueued\n", value);
    }
}

int dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
        return -1;
    } else {
        return queue[front++];
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    enqueue(10);
    enqueue(30);
    enqueue(20);
    display(); // Should show: Queue: 30 20 10
    
    printf("Dequeued: %d\n", dequeue());
    display(); // Should show: Queue: 20 10
    
    return 0;
}
