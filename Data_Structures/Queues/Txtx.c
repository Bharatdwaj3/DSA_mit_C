#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1, rear=-1;


void insertFront(int value){
    if((front==0&&rear == MAX-1)||(front == rear+1)){
        printf("DE-queue is full\n");
    }else{
        if(front==-1){
            front=rear=0;
        }else if(front==0){
            front=MAX-1;
        }else{
            front--;
        }
        queue[front]=value;
        printf("%d inserted at front\n",value);
    }
}


void insertRear(int value){
    if((front == 0 && rear ==MAX-1)||(front==rear+1)){
        printf("DE is full\n");
    }else{
        if(front==-1){
            front=rear=0;
        }else if(rear==MAX-1){
            rear=0;
        }else{
            rear++;
        }
        queue[rear] = value;
        printf("%d inserted at front\n", value);
    }
}

int deleteFront(){
    if(front==-1){
        printf("Dequeue is empty\n");
        return -1;
    }else{
        int deletedValue=queue[front];
        if(front==rear){
            front=rear-1;
        }else if(front==MAX-1){
            front=0;
        }else{
            front++;
        }
        return deletedValue;
    }
}

int deleteRear(){
    if(front==-1){
        printf("DE-queue is empty\n");
        return -1;
    }else{
        int deletedValue=queue[rear];
        if(front==rear){
            front=rear=-1;
        }else if(rear==0){
            rear=MAX-1;
        }else{
            rear--;
        }
        return deletedValue;
    }
}

void display(){
    if(front==-1){
        printf("DE-queue is empty\n");
    }else{
        int i=front;
        printf("DE-Queue: ");
        while(i!=rear){
            printf("%d",queue[i]);
            i=(i+1)%MAX;
        }
        printf("%d\n",queue[rear]);
    }
}

int main()
{
    insertRear(10);
    insertRear(20);
    insertFront(5);
    display();

    printf("Deleted from front: %d\n", deleteFront());
    display();

    printf("Deleted from rear: %d\n", deleteRear());
    display();

    return 0;
}