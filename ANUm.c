#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next, *prev;
};

struct Node *head=NULL;

void inStart(int value){
    struct Node*newNode=(struct  Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=head;
    newNode->prev=NULL;
    if(head!=NULL){
        head->prev=newNode;
    }
    head=newNode;
    printf("Inserted 5d at the begining of the list\n",value);
}
void delStart() {
    if(head==NULL){
        printf("The list is empty!!");
        return;
    }
    struct Node*temp=head;
    head=head->next;
    if(head!=NULL){
        head->prev=NULL;
    }
    printf("Deleted %d from the begining of the list\n",temp->data);
    free(temp);
}
void inEnd(int value) {
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
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
void delEnd() {
    if(head==NULL){
        printf("Empty List");
        return;
    }
    if(head->next==NULL){
        printf("Deleted 5d from the end of the list\n",head->data);
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