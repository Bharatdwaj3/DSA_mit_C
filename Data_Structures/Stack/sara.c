#include<stdio.h>
#include<stdlib.h>

#define MAX 5
struct Queue
{
    int arr[MAX];
    int front, rear;
};

void initQueue(struct Queue *q)
{
    q->front = q->rear = -1;
}


int isEmpty(struct Queue *q){
    return q->front==-1;
}
void enqueue(struct Queue*q,int value){
    if(q->rear==MAX-1){
        printf("Overflow!!");
        return;
    }
    if(q->front==-1){
        q->front=0;
        q->arr[++q->rear]=value;
    }
}
int denqueue(struct Queue *q) {
    if(isEmpty(q)){
        printf("Stack Overflow!!");
        return -1;
    }
    int data=q->arr[q->front];
    if(q->front==q->rear){
        q->front=q->rear-1;
    }else{
        q->front++;
        return data;
    }
}
struct Stack
{

    struct Queue *q;
};
void initStack(struct Queue *s)
{
    initQueue(&s->q);
}
void push(struct Stack *s, int value){
    enqueue(&s->q,value);
}
void pop(struct Stack *s){
    if(isEmpty(&s->q)){
        printf("Stack Underflow!!");
        return ;
    }
    printf("Popped %d \n",denqueue(&s->q));
}
void peek(struct Stack *s){
    if(isEmpty(&s->q)){
        printf("Stack Underflow!!");
        return ;
    }
    printf("Top Element %d \n",s->q->arr[s->q->front]);
}
void displayStack(struct Stack *s){
    if(isEmpty(&s->q)){
        printf("Stack is Empty!!");
        return;
    }
    printf("Stack: ");
    for(int i=s->q->front;i<s->q->rear;i++){
        printf("%d",s->q->arr[i]);
    }
    printf("\n");
}

int main(){

    struct Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    display(&s);

    pop(&s);
    displayStack(&s);

    peek(&s);

    return 0;
}