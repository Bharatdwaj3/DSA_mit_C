#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next,*prev;
};

struct Node *head=NULL;

void insertAtBeginning(int value){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=head;
    newNode->prev=NULL;
    if(head!=NULL){
        head->prev=newNode;
    }
    head=newNode;
    printf("Inserted %d at the begining of the list\n",value);
}

void insertedAtEnd(int value){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    if(head==NULL){
        newNode->prev=NULL;
        head=newNode;
    }else{
        struct Node*temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
    }
    printf("Inserted %d into the list\n",value);
}

void deleteFromBeginning(){
    if(head==NULL){
        printf("List is empty!! NOthing to delete\n");
        return;
    }
    struct Node*temp=head;
    head=head->next;
    if(head!=NULL){
        head->prev=NULL;
    }
    printf("Deleted %d from the beginning of the list\n",temp->data);
    free(temp);
}

void deleteFromEnd(){
    if(head==NULL){
        printf("List is empty!! Nothing to delete\n");
        return;
    }
    if(head->next==NULL){
        printf("Deleted %d from the list\n",head->data);
        free(head);
        head=NULL;
        return;
    }
    struct Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    printf("Deleted %d from the end of the list\n",temp->data);
    temp->prev->next=NULL;
    free(temp);
}

void peek(){
    if(head==NULL){
        printf("List is empty!!Nothing to peek\n");
        return;
    }
    printf("Front element : %d\n",head->data);
}

void displayFwd(){
    if(head==NULL){
        printf("Der List est Empty");
        return;
    }
    struct Node*temp=head;
    printf("Doubly Linked List (Fwd): ");
    while(temp != NULL){
        printf("%d <->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

void displayBwd(){
    if (head == NULL){
        printf("Der List est Empty");
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    printf("Doubly Linked List (Bwd): ");
    while (temp != NULL){
        printf("%d <->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}