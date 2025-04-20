#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Queue
{
    int arr[MAX];
    int front, rear;
};

struct Stack
{
    struct Queue q1; // Primary queue for push
    struct Queue q2; // Secondary queue for pop
};

void initQueue(struct Queue *q)
{
    q->front = q->rear = -1;
}

void initStack(struct Stack *s)
{
    initQueue(&s->q1);
    initQueue(&s->q2);
}

int isEmpty(struct Queue *q){
    return q->front == -1;
}

void enqueue(struct Queue *q, int value)
{
    if (q->rear == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->arr[++q->rear] = value;
}

int dequeue(struct Queue *q){
    if (isEmpty(q)){
        printf("Stack Underflow\n");
        return -1;
    }
    int data = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return data;
}

void push(struct Stack *s, int value)
{
    enqueue(&s->q1, value);
    printf("Pushed: %d\n", value);
}

void pop(struct Stack *s)
{
    if (isEmpty(&s->q1))
    {
        printf("Stack Underflow!!\n");
        return;
    }

    // Move elements to q2 except last one
    while (s->q1.front != s->q1.rear)
    {
        enqueue(&s->q2, dequeue(&s->q1));
    }

    // Last element to pop
    printf("Popped: %d\n", dequeue(&s->q1));

    // Swap queues
    struct Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
}

void peek(struct Stack *s)
{
    if (isEmpty(&s->q1))
    {
        printf("Stack is Empty\n");
        return;
    }

    printf("Top Element: %d\n", s->q1.arr[s->q1.rear]);
}

void printStack(struct Stack *s)
{
    if (isEmpty(&s->q1))
    {
        printf("Stack is empty!\n");
        return;
    }

    printf("Stack elements: ");
    for (int i = s->q1.front; i <= s->q1.rear; i++)
    {
        printf("%d ", s->q1.arr[i]);
    }
    printf("\n");
}

int main()
{
    struct Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printStack(&s); // Output: Stack elements: 10 20 30

    pop(&s);        // Should pop 30
    printStack(&s); // Output: Stack elements: 10 20

    push(&s, 40);
    push(&s, 50);

    printStack(&s); // Output: Stack elements: 10 20 40 50

    pop(&s); // Should pop 50
    pop(&s); // Should pop 40
    pop(&s); // Should pop 20
    pop(&s); // Should pop 10

    printStack(&s); // Output: Stack is empty!

    pop(&s); // Should print "Stack Underflow!!"

    return 0;
}
