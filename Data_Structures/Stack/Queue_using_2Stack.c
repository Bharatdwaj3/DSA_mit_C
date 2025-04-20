#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Stack
{
    int arr[MAX];
    int top;
};

struct Queue
{
    struct Stack s1; // Stack for enqueue
    struct Stack s2; // Stack for dequeue
};

void initStack(struct Stack *s)
{
    s->top = -1;
}

int isEmpty(struct Stack *s)
{
    return s->top == -1;
}

int push(struct Stack *s, int value)
{
    if (s->top == MAX - 1)
    {
        printf("Overflow\n");
        return -1;
    }
    return s->arr[++s->top] = value;
}

int pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Underflow\n");
        return -1;
    }
    return s->arr[s->top--];
}

void initQueue(struct Queue *q)
{
    initStack(&q->s1);
    initStack(&q->s2);
}

void enQueue(struct Queue *q, int value)
{
    push(&q->s1, value);
    printf("Enqueued: %d\n", value);
}

void deQueue(struct Queue *q)
{
    if (isEmpty(&q->s2))
    {
        if (isEmpty(&q->s1))
        {
            printf("Underflow!!\n");
            return;
        }
        // Move all elements from s1 to s2
        while (!isEmpty(&q->s1))
        {
            push(&q->s2, pop(&q->s1));
        }
    }
    printf("Dequeued: %d\n", pop(&q->s2));
}

// Function to print the queue elements in FIFO order
void printList(struct Queue *q)
{
    if (isEmpty(&q->s1) && isEmpty(&q->s2))
    {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");

    // Print elements in s2 (front of the queue)
    for (int i = q->s2.top; i >= 0; i--)
    {
        printf("%d ", q->s2.arr[i]);
    }

    // Print elements in s1 in reverse order
    for (int i = 0; i <= q->s1.top; i++)
    {
        printf("%d ", q->s1.arr[i]);
    }

    printf("\n");
}

int main()
{
    struct Queue q;
    initQueue(&q);

    enQueue(&q, 10);
    enQueue(&q, 20);
    enQueue(&q, 30);

    printList(&q); // Output: Queue elements: 10 20 30

    deQueue(&q);   // Should dequeue 10
    printList(&q); // Output: Queue elements: 20 30

    deQueue(&q);   // Should dequeue 20
    printList(&q); // Output: Queue elements: 30

    enQueue(&q, 40);
    enQueue(&q, 50);

    printList(&q); // Output: Queue elements: 30 40 50

    deQueue(&q); // Should dequeue 30
    deQueue(&q); // Should dequeue 40
    deQueue(&q); // Should dequeue 50

    printList(&q); // Output: Queue is empty!

    deQueue(&q); // Should print "Underflow!!"

    return 0;
}
