#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
    struct Node*prev;
};

struct Node*head=NULL;

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
void insertAtEnd(int value) {
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    if(head==NULL){
        head->prev=NULL;
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
void deleteAtBeginning(int value) {

}
void deleteAtEnd(int value) {}