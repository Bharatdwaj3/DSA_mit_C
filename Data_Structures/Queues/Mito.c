#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int front=-1,rear=-1;

void enqueue(int value,int queue[]){
    if(rear==MAX-1){
        printf("Full");
        return;
    }
    printf("Enter the value you wanna Insert: ");
    scanf("%d",&value);
    if(front==-1)
        front=0;
        rear++;
    queue[rear]=value;
    printf("Enqueued %d into the queue\n",queue[rear]);
}
void denqueue(int queue[]) {
    if(front==-1||front>rear){
        printf("Empty Queue!!\n");
    }else{
        printf("Dequeued %d",queue[front]);
        front++;
        if(front>rear){
            front=rear=-1;
        }
    }
}
void peek(int queue[]) {
    if(front==-1||front>rear){
        printf("Empty Queue!!");
    }else{
        printf("Front Element:%d",queue[front]);
    }
}
void display(int queue[]) {
    if(front==-1||front>rear){
        printf("Empty Queue\n");
    }else{
        printf("Queue contents: \n");
        for(int i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}