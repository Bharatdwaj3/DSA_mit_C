#include<stdlib.h>
#include<stdio.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node*head=NULL;

void insertAtBegining(int value){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    head=newNode;
    printf("Inserted %d at the start of the Node",value);
}

void insertAtBegining(int value){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if(head!=NULL){
        head->prev=newNode;
    }
    head = newNode;
    printf("Inserted %d at the start of the Node", value);
}

void insertAtBeginning(int value){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    if(head!=NULL){
        newNode->next=newNode;
        head=newNode;
    }else{
        struct Node*temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=head;
        newNode->next=head;
        head=newNode;
    }
}