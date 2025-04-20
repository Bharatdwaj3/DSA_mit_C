#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int stack1[MAX];
    int stack2[MAX];
    int top1;
    int top2;
} QueueUsingStack;

void initQueue(QueueUsingStack *q)
{
    q->top1 = -1;
    q->top2 = -1;
}

void push(int stack[], int *top, int value)
{
    stack[++(*top)] = value;
}

int pop(int stack[], int *top)
{
    return stack[(*top)--];
}

void enqueue(QueueUsingStack *q, int value)
{
    push(q->stack1, &q->top1, value);
}

int dequeue(QueueUsingStack *q)
{
    if (q->top2 == -1)
    {
        while (q->top1 != -1)
        {
            push(q->stack2, &q->top2, pop(q->stack1, &q->top1));
        }
    }
    if (q->top2 == -1)
    {
        printf("Queue is empty\n");
        return -1;
    }
    return pop(q->stack2, &q->top2);
}

int main()
{
    QueueUsingStack q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    return 0;
}
