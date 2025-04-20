#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node *head=NULL;

void insertAtBegining(int value){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    if(head==NULL){
        newNode->next=newNode;
        head=newNode;
    }else{
        struct Node*temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=head;
        head=newNode;
    }
    printf("Inserted %d at the begining of the list\n",value);
}

void insertAtEnd(int value){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    if(head==NULL){
        newNode->next=newNode;
        head=newNode;
    }else{
        struct Node*temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=head;
    }
    printf("Inserted %d at the end of the list\n",value);
}

void deleteFromBeginning(){
    if(head==NULL){
        printf("List is empty!!Nothing to delete");
        return;
    }
    if(head->next==head){
        printf("Deleted %d from the list\n",head->data);
        free(head);
        head=NULL;
        return;
    }
    struct Node *temp=head,*last=head;
    while(last->next!=head){
        last=last->next;
    }
    head=head->next;
    last->next=head;
    printf("Deleted %d from the beginning of the list\n",temp->data);
    free(temp);
}

void deleteFromEnd(){
    if(head==NULL){
        printf("List is empty!!Nothing to delete\n");
        return;
    }
    if(head->next==head){
        printf("Deleted %d from the list\n",head->data);
        free(head);
        head=NULL;
        return;
    }
    struct Node*temp=head,*prev=NULL;
    while(temp->next!=head){
        prev=temp;
        temp=temp->next;
    }
    prev->next=head;
    printf("Deleted 5d from the end of the list\n",temp->data);
    free(temp);
}

void peek(){
    if(head==NULL){
        printf("List is empty, Nothing to peek!!");
        return;
    }
    struct Node *temp=head;
    printf("Circular Linked List: ");
    do{
        printf("%d-> ",temp->data);
        temp=temp->next;
    }while(temp!=head);
    printf("(head)\n");
}

void display(){

}