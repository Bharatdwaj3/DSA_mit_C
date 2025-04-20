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
    struct Stack s;
};

void initStack(struct Stack *s)
{
    s->top = -1;
}

int isEmpty(struct Stack *s)
{
    return s->top == -1;
}

void push(struct Stack *s, int value)
{
    if (s->top == MAX - 1)
    {
        printf("Overflow\n");
        return;
    }
    s->arr[++s->top] = value;
}

int pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Underflow\n");
        return -1; // Return an error value
    }
    return s->arr[s->top--];
}

void initQueue(struct Queue *q)
{
    initStack(&q->s);
}

void enQueue(struct Queue *q, int value)
{
    push(&q->s, value);
}

void deQueue(struct Queue *q)
{
    if (isEmpty(&q->s))
    {
        printf("Underflow!!\n");
        return;
    }
    printf("Dequeued: %d\n", pop(&q->s));
}

// Function to print the queue contents
void printQueue(struct Queue *q)
{
    if (isEmpty(&q->s))
    {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue contents: ");
    for (int i = q->s.top; i >= 0; i--)
    {
        printf("%d ", q->s.arr[i]);
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

    printQueue(&q); // Print queue (LIFO order)

    deQueue(&q);    // Should remove 30
    printQueue(&q); // Print queue

    deQueue(&q);
    printQueue(&q);

    deQueue(&q);
    printQueue(&q); // Should print "Queue is empty!"

    deQueue(&q); // Should print "Underflow!!"

    return 0;
}