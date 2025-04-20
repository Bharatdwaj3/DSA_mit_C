#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Queue{
    int arr[MAX];
    int front, rear;
};

// Initialize queue
void initQueue(struct Queue *q){
    q->front = q->rear = -1;
}

// Check if queue is empty
int isEmpty(struct Queue *q){
    return q->front == -1;
}

// Enqueue
void enqueue(struct Queue *q, int value){
    if (q->rear == MAX - 1)
    {
        printf("Stack Overflow!\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->arr[++q->rear] = value;
}

// Dequeue
int dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Stack Underflow!\n");
        return -1;
    }
    int data = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return data;
}

// Stack using single queue
struct Stack{
    struct Queue q;
};

// Initialize stack
void initStack(struct Stack *s){
    initQueue(&s->q);
}

// Push operation
void push(struct Stack *s, int value)
{
    enqueue(&s->q, value);

    // Rotate elements
    for (int i = 0; i < s->q.rear - s->q.front; i++)
    {
        enqueue(&s->q, dequeue(&s->q));
    }
}

// Pop operation
void pop(struct Stack *s)
{
    if (isEmpty(&s->q))
    {
        printf("Stack Underflow!\n");
        return;
    }
    printf("Popped: %d\n", dequeue(&s->q));
}

// Peek operation
void peek(struct Stack *s)
{
    if (isEmpty(&s->q))
    {
        printf("Stack is empty!\n");
        return;
    }
    printf("Top Element: %d\n", s->q.arr[s->q.front]);
}

// Display stack
void displayStack(struct Stack *s)
{
    if (isEmpty(&s->q))
    {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack: ");
    for (int i = s->q.front; i <= s->q.rear; i++)
    {
        printf("%d ", s->q.arr[i]);
    }
    printf("\n");
}

// Main function
int main()
{
    struct Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    displayStack(&s);

    pop(&s);
    displayStack(&s);

    peek(&s);

    return 0;
}
