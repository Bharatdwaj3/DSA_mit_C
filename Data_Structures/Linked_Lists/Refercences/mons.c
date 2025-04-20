#include<stdio.h>
#include<stdio.h>

struct Node{
    int data;
    struct Node*prev;
    struct Node*next;
};

struct Node*head=NULL;

void insertAtBeginning(int value){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=head;
    newNode->prev=NULL;
    if(head!=NULL){
        head->prev=newNode;
    }
    head=newNode;
}
void insertAtEnd(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    if(head==NULL){
        newNode->prev = NULL;
        head=newNode;
    }
    struct Node*temp=head;
    while(temp!= NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
   
}
void deleteAtBeginning() {
    if(head==NULL){
        printf("Empty LIst\n");
        return;    
    }
    struct Node*temp=head;
    head=head->next;
    if(head!=NULL){
        head->prev=NULL;
    }
    printf("Deleted %d from the end of the list",temp->data);
    free(temp);

}
void delteAtEnd() {}
