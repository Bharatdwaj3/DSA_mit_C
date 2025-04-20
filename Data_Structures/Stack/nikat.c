#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Stack{
    int arr[MAX];
    int top;
};

struct Queue{
    struct Stack s1, s2;
};

void initStack(struct Stack *s){
    s->top = -1;
}
void initQueue(struct Queue *q){
    initStack(&q->s1);
    initStack(&q->s2);
}

int isEmpty(struct Stack *s){
    return s->top == -1;
}

void push(int value, struct Stack *s){
    if (s->top == MAX - 1)
    {
        printf("Full");
        return;
    }
    s->arr[++s->top] = value;
}

void enqueue(int value, struct Queue *q){
    push(&q->s1, value);
}

int pop(struct Stack *s)
{
    if (s->top == MAX - 1)
    {
        printf("Full");
        return -1;
    }
    return s->arr[s->top--];
}

void denqueue(struct Queue *q){
    if (isEmpty(&q->s1) && isEmpty(&q->s2)){
        printf("Underflow!!\n");
        return;
    }
    if(isEmpty(&q->s2)){
        while(!isEmpty(&q->s1)){
           push(&q->s2,pop(&q->s1));
        }
    }
    printf("Dequeudd value: %d",pop(&q->s2));
}

void peek(struct Queue *q){
    if (isEmpty(&q->s1) && isEmpty(&q->s2)){
        printf("Empty!!\n");
        return;
    }

    if (!isEmpty(&q->s2)){
        printf("Front Element: %d\n", q->s2.arr[q->s2.top]);
    }
    else{
        printf("Front Element: %d\n", q->s1.arr[0]);
    }
}

void display(struct Queue *q)
{
    if (isEmpty(&q->s1) && isEmpty(&q->s2))
    {
        printf("Empty!!\n");
        return;
    }
    printf("Queue: ");
    for (int i = 0; i <= q->s2.top; i++){
        printf("%d", q->s2.arr[i]);
    }
    for (int i = q->s1.top;i>=0; i--){
        printf("%d", q->s1.arr[i]);
    }
    printf("\n");
}
