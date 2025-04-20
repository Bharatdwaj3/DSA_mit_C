#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next,*prev;
};

struct Node* head=NULL;

void insertAtEnd(int value){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next= NULL;
    if(head==NULL){
        head=newNode;
    }else{
        struct Node*temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
    printf("Inserted %d in the list\n",value);
}

void insertAtEnd(int value){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    if(head==NULL){
        newNode->prev=NULL;
        head=newNode;
    }else{
        struct Node*temp=head;
        while(temp!=NULL){
            temp=temp->next;
        }
        temp->next=head;
        newNode->prev=temp;
    }
    printf("Inserted %d into the list\n",value);
}

void insertAtEnd(int value){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    if (head == NULL){
        newNode->next=head;
        head = newNode;
        
    }
    else{
        struct Node *temp = head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next=head;
    }
    printf("Inserted %d in the list\n", value);
}