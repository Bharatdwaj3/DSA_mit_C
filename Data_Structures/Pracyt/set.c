#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int queue[MAX];
int front=-1, rear=-1;

void enqueue(int value){
    if((rear+1)%MAX==front){
        printf("Queue is full!!");
    }else{
        if (front==-1)
            front=0;
            rear=(rear+1)%MAX;
            queue[rear]=value;
            printf("%d enqueued \n",value);
        
       
    }
}

int dequeue(){
    if(front==-1){
        printf("Queue is empty!!");
        return -1;
    }else{
        int dVal=queue[front];
        if(front==rear){
            front=rear=-1;
        }else{
            front=(front+1)%MAX;
        }return dVal;
    }
}

void display(){
    if(front==-1){
        printf("Empty!!");
    }else{
        int i=front;
        printf("Queue : ");
        while(i!=rear){
            printf("%d ",queue[i]);
            i=(i+1)%MAX;
        }
        printf("%d\n",queue[rear]);
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    printf("Dequeued: %d\n", dequeue());
    display();

    return 0;
}