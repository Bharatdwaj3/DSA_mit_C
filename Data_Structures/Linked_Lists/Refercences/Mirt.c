#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtBegining(int value){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=head;
    head=newNode;
    printf("Inserted % at the begining of the list\n",value);
}

void insertAtEnd(int value){
    struct Node *newNode=(struct Node * )malloc(sizeof(struct Node));
    if(head==NULL){
        head=newNode;
    }else{
        struct Node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
    printf("Inserted %d into the list\n",value);
}

void deleteFromBeginning(){
    if(head==NULL){
        printf("List is empty!! Nothing to delete! \n");
        return;
    }
    struct Node*temp=head;
    head=head->next;
    printf("Deleted %d from the beginning of the list\n",temp->data);
}

void deleteFromEnd(){
    if(head==NULL){
        printf("List is empty!!  Nothing to delete\n");
        return;
    }
    if(head->next==NULL){
        printf("Deleted 5d from the end of the ;ist\n",head->data);
        free(head);
        head=NULL;
        return;
    }
    struct Node*temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    printf("Deleted %d from the end of the list\n",temp->next->data);
    free(temp->next);
    temp->next=NULL;
}
