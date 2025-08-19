#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head=NULL;

void inStart(int value) {
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    if(head==NULL){
        newNode->next=newNode;
        newNode=head;
    }else{
        struct Node*temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=newNode;
        newNode=head;
    }
    printf("Inserted %d the beginning of the list\n",value);
}
void endStart(int value) {
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
void delStart() {
    if(head==NULL){
        printf("List is empty!! Nothing to delete\n");
        return;
    }
    if(head->next==head){
        printf("Deleted %d from the end of the list\n",head->data);
        free(head);
        head=NULL;
        return;
    }
    struct Node*temp=head,*last=head;
    while(last->next!=head){
        last=last->next;
    }
    head=head->next;
    last->next=head;
    printf("Deleted %d from the beginning of the list\n",temp->data);
    free(temp);
}
void delSEnd() {
    if(head==NULL){
        printf("The list is empty!!");
        return ;
    }
    if(head->next==head){
        printf("Deleted 5d from the list\n",head->data);
        free(head);
        head=NULL;
        return;
    }
    struct Node *temp=head, *prev=NULL;
    while(temp->next!=head){
        prev=prev->next;
        temp=temp->next;
    }
    prev=prev->next;
    printf("Deleted 5d from the end of the list\n",temp->data);
    free(temp);
}
