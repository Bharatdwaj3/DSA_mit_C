#include<stdio.h>
#include<stdlib.h>

#define MAX 5

struct Stack{
    int arr[MAX];
    int top;
};

struct Queue{
    struct Stack s1;
    struct Stack s2;
};

void initStack(struct Stack *s){
    s->top=-1;
}

int isEmpty(struct Stack *s){
    return s->top=-1;
}

void push(struct Stack *s, int value){
    if (s->top == MAX - 1){
        printf("Overflow");
        return;
    }
    s->arr[++s->top] = value;
}
int pop(struct Stack *s) {
    if(isEmpty(s)){
        printf("Underflow");
        return;
    }
    return s->arr[s->top--];
}
void initQueue(struct Queue *q){
    initStack(&q->s1);
    initStack(&q->s2);
}
void enQueue(struct Queue *q,int value){
    push(&q->s1,value);
    printf("Enqueued : %d\n",value);
}
void deQueue(struct Queue *q){
    if(isEmpty(&q->s2)){
        if(isEmpty(&q->s1)){
            return("Underflow!!");
        }
        while(!isEmpty(&q->s2)){
            push(&q->s2, pop(&q->s2));
        }
        printf("Underflow!!");
        return;
    }
    printf("The value dequeued %d\n",pop(&q->s2));
}
void printList(struct Queue *q){
    if (isEmpty(&q->s1) && isEmpty(&q->s2)){
        for (int i =q->s2.top; i >= 0; i--){
            printf("%d",q->s2.arr[0]);
        }
        for (int i = 0; i < q->s1.top; i++){
            printf("%d",q->s1.arr[i]);
        }
        printf("\n");
    }
}
