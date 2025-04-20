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
void push(struct Stack *s,int value){
    if(s->top==MAX-1){
        printf("Overflow");
        return;
    }
    s->arr[++s->top]=value;
}
 
int isEmpty(struct Stack *s){
    s->top=-1;
}

int pop(struct Stack *s) {
    if(isEmpty(s)){
        printf("Underflow");
        return;
    }
    return s->arr[s->top--];
}
void initQueue(struct Queue *q){
    initStack(&q->s);
}
void enQueue(struct Queue *q,int value){
    push(&q->s,value);
}
void deQueue(struct Queue *q){
    if(isEmpty(&q->s)){
        printf("Underflow!!");
        return;
    }
    printf("The value dequeued %d\n",pop(&q->s));
}
void printList(struct Queue *q)
{
    if (isEmpty(&q->s))
    {
        for (int i = q->s.top; i >= 0; i--)
        {
            printf("%d", q->s.arr[0]);
        }
        printf("\n");
    }
}