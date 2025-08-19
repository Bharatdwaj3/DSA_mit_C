#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *prev, *next;
};

struct Node *head=NULL;

void inStart(int value) {
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=head;
    head=newNode;
    printf("Inserted %d at the starting of the list\n",value);
}
void inEnd(int value) {
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
    }else{
        struct Node*temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newNode;
    }
}
void delStart() {
    if(head==NULL){
        printf("List is empty!!");
        return;
    }else{
        struct Node*temp=head;
        head=head->next;
        printf("Deleted %d from the end of the list",temp->data);
        free(temp);
    }
}
void delEnd() {
    if(head==NULL){
        printf("List is empty!!");
        return;
    }
    if(head->next=NULL){
        printf("Deleted %d from the end of the list",head->data);
        free(head);
        head=NULL;
        return;
    }
    struct Node*temp=head;
    while(temp->next->next!=head){
        temp=temp->next;
    }
    printf("Deleted %d from the end of the list\n",temp->next->data);
    free(temp->next);
    temp->next=NULL;
}
void peek() {
    if(head=NULL){
        printf("List is empty!! Nothing to peek\n");
        return;
    }
    printf("The top element : %d",head->data);
}
void display() {
    if(head==NULL){
        printf("List is empty!!");
        return;
    }
    struct Node*temp=head;
    printf("Linked List: ");
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}