#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int front=-1,rear=-1;

void enqueueFront(int value,int queue[]){
    if((front==0&&rear==MAX-1)
    ||
    (front==rear+1)){
        printf("Full");
        return;
    }
   if(front==-1){
        front=rear=0;
   }
   else if (front == 0){
       front = MAX-1;
   }
   else{
    front--;
   }
   queue[front]=value;
   printf("Enqueued %d at the front\n",value);
}
void enqueueFront(int value, int queue[])
{
    if ((front == 0 && rear == MAX - 1) ||
        (front == rear + 1))
    {
        printf("Full");
        return;
    }
    if (front == -1)
    {
        front = rear = 0;
    }
    else if (rear == MAX-1)
    {
        rear=0;
    }
    else
    {
        rear++;
    }
    queue[front] = value;
    printf("Enqueued %d at the front\n", value);
}

void denqueueFront(int value, int queue[])
{
    if(front==-1){
        printf("Queue is empty!!");
        return;
    }
    printf("Deleted %d from the front\n",queue[front]);
    if(front==rear){
        front=rear=-1;
    }else if(front==MAX-1){
        front=0;
    }else{
        front++;
    }
}

void denqueueRear(int value, int queue[]){
    if (front == -1){
        printf("Queue is empty!!");
        return;
    }
    printf("Deleted %d from the front\n", queue[rear]);
    if (front == rear){
        front = rear = -1;
    }
    else if (rear==0){
        rear=MAX-1;
    }
    else{
        front--;
    }
}

void peek(int queue[]){
    if(front==-1){
        printf("Queue is empty!!\n");
        return;
    }
    printf("Front element: %d | Rear element %d",queue[front],queue[rear]);
}

void display(int queue[]){
    if(front==-1){
        printf("Empty!!");
        return;
    }
    printf("Queue contents: ");
    for (int i = front; i = (i + 1) % MAX;i++)
    {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
    }
    printf("\n");
}