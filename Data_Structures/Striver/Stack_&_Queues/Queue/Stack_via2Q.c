#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int queue1[MAX];
    int queue2[MAX];
    int front1, rear1, front2, rear2;
} StackUsingQueues;

void initStack(StackUsingQueues *s)
{
    s->front1 = s->rear1 = -1;
    s->front2 = s->rear2 = -1;
}

void enqueue(int queue[], int *rear, int value)
{
    queue[++(*rear)] = value;
}

int dequeue(int queue[], int *front, int rear)
{
    return queue[++(*front)];
}

void push(StackUsingQueues *s, int value)
{
    enqueue(s->queue1, &s->rear1, value);
}

int pop(StackUsingQueues *s)
{
    if (s->front1 == s->rear1)
    {
        printf("Stack is empty\n");
        return -1;
    }

    while (s->front1 < s->rear1 - 1)
    {
        enqueue(s->queue2, &s->rear2, dequeue(s->queue1, &s->front1, s->rear1));
    }

    int popped = dequeue(s->queue1, &s->front1, s->rear1);

    while (s->front2 < s->rear2)
    {
        enqueue(s->queue1, &s->rear1, dequeue(s->queue2, &s->front2, s->rear2));
    }

    return popped;
}

int main()
{
    StackUsingQueues s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));

    return 0;
}
