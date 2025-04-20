#include<stdio.h>
#include<stdlib.h>

#define MAX 5

struct Queue{
    int arr[MAX];
    int front, rear;
};


struct Stack{
    struct Queue q1;
    struct Queue q2;
};

void initQueue(struct Queue *q){
    q->front = q->rear = -1;
}

void initStack(struct Stack *s){
    initQueue(&s->q1);
    initQueue(&s->q2);
}
int isEmpty(struct Queue *q){
    return q->front == -1;
}

void enqueue(struct Queue *q,int value){
    if(q->rear==MAX-1){
        printf("Overflow!!");
        return;
    }
    if(q->front==-1)
    q->front=0;
    q->arr[++q->rear]=value;
}

int dequeue(struct Queue *q){
    if(isEmpty(q)){
        printf("Underflow");
        return -1;
    }
    int data=q->arr[q->front];
    if(q->front==q->rear)
        q->front=q->rear=-1;
    else
        q->front++;
    return data;
}

void push(struct Stack *s) {
    enqueue(&s->q1);
   
}
void peek(struct Stack *s) {
    if(isEmpty(&s->q)){
        printf("Empty Stack!!");
        return;
    }
    printf("The element : %d\n",s->q.arr[s->q.front]);
}
void pop(struct Stack *s){
    if(isEmpty(&s->q1)){
        printf("Empty!!\n");
        return;
    }
    while(s->q1.front!=s->q2.rear){
        enqueue(&s->q2,dequeue(&s->q1));
    }
    printf("Popped element: %d\n", denqueue(&s->q1));

    struct Queue
}
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