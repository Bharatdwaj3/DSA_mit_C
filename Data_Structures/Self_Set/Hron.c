#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int queue[MAX];

int main()
{

    int n, i,front=-1,rear=-1;

    int *f_ptr=&front;
    int *r_ptr=&rear;

    if(rear==MAX-1){
        printf("Queue ist L'full");
    }else{
        if(front==-1){
            front=0;

        }

            rear++;
            queue[rear] = 10;
            printf("\t");
            rear++;
            queue[rear] = 20;
            printf("\t");
            rear++;
            queue[rear] = 30;
            printf("\t");
            rear++;
            queue[rear] = 40;
            printf("\t");
            rear++;
            queue[rear] = 50;

        }
    

    if(front==-1)
    {
        printf("Queue is empty");
    }else{
        printf("The elements of the queue");
        for(i=front;i<=rear;i++){
            printf("%d",queue[i]);
        }
    }
}