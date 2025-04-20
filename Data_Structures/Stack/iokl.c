#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Queue {
    int arr[MAX];
    int front, rear;
};

struct Stack {
    struct Queue q;
};

void initQueue(struct Queue *q) {
    q->front = q->rear = -1;
}

void initStack(struct Stack *s) {
    initQueue(&s->q);
}

int isEmpty(struct Queue *q) {
    return q->front == -1;
}

void enqueue(struct Queue *q, int value) {
    if (q->rear == MAX - 1) {
        printf("Overflow!!\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->arr[++q->rear] = value;
}

int denqueue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Underflow\n");
        return -1;
    }
    int data = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return data;
}

void push(struct Stack *s, int value) {
    enqueue(&s->q, value);
    for (int i = 0; i < s->q.rear - s->q.front; i++) {
        enqueue(&s->q, denqueue(&s->q));
    }
}

void pop(struct Stack *s) {
    if (isEmpty(&s->q)) {
        printf("Empty Stack!!\n");
        return;
    }
    printf("Popped element: %d\n", denqueue(&s->q));
}

int peek(struct Stack *s) {
    if (isEmpty(&s->q)) {
        printf("Stack is empty!!\n");
        return -1;
    }
    return s->q.arr[s->q.front];
}

int main() {
    struct Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top element: %d\n", peek(&s));

    pop(&s);
    printf("Top element after pop: %d\n", peek(&s));

    pop(&s);
    pop(&s);
    pop(&s); // Stack underflow test

    return 0;
}
