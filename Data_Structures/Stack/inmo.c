#include<stdio.h>
#include<stdlib.h>

#define MAX 5

struct Stack{
    int arr[MAX];
    int top;
};

struct Queue{
    struct Stack s;
};

void initStack(struct Stack *s){
    s->top=-1;
}
void initQueue(struct Queue *q){
    initStack(&q->s);
}

int isEmpty(struct Stack *s)
{
    return s->top==-1;
}

void push(int value, struct Stack *s)
{
    if(s->top==MAX-1){
        printf("Full");
        return;
    }
    s->arr[++s->top]=value;
}

void enqueue(int value, struct Queue *q){
    push(&q->s,value);
}

int pop(struct Stack *s)
{
    if (s->top == MAX - 1){
        printf("Full");
        return -1;
    }
    return s->arr[s->top--];
}

void denqueue(struct Queue *q){
    if(isEmpty(&q->s)){
        printf("Underflow!!\n");
        return;
    }
    printf("Dequeued Element %d\n",dequeued(&q->s));
}

void peek(struct Queue *q)
{
    if (isEmpty(&q->s))
    {
        printf("Empty!!\n");
        return;
    }
    printf("Front Element %d\n", dequeued(&q->s.arr[0]));
}

void display(struct Queue *q){
    if (isEmpty(&q->s)){
        printf("Empty!!\n");
        return;
    }
    printf("Queue: ");
    for(int i=0;i<=q->s.top;i++){
        printf("%d",q->s.arr[i]);
    }
    printf("\n");
}

