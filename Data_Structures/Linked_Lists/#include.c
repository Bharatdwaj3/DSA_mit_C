#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *front = NULL;
Node *rear = NULL;

void enqueue(){
    int value;
    
    printf("Enter the value: ");
    scanf("%d",&value);

    Node*newNode=(Node *)malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=NULL;

    if(rear==NULL){
        front=rear=newNode;
    }else{
        rear->next=newNode;
        rear=newNode;
    }
    printf("\nEnqueued %d into the queue\n",value);
}

void dequeue(){
    if(front==NULL){
        printf("Queue is empty!!\n");
    }else{
        Node* temp=front;
        printf("Dequeued from the queue %d\n",temp->data);
        front=front->next;
        rear=NULL;
        free(temp);
    }
}

void peek(){    
    if(front==NULL){
        printf("Queue is empty!!");
    }else{
        printf("\nFront element: %d\n", front->data);
    }
}

void display(){
    if (front == NULL)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nQueue contents:\n");
        Node *temp = front;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("\nQueue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    }
    return 0;
}