#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

struct Node*head= NULL;

void insertAtBeginning(int value){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=head;
    head=newNode;
    printf("Inserted %d at the beginning of the list\n",value);
}

void insertAtEnd(int value){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;

    if(head==NULL){
        head=newNode;
    }else{
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Inserted %d at the end of the list\n", value);
}

void deleteAtStart(){
    if(head==NULL){
        printf("Empty!!");
        return;
    }
    struct Node*temp=head;
    head=temp->next;
    printf("Deleted %d from the beginning of the list.\n", temp->data);
    free(temp);
}

void deleteAtEnd(){
    if(head==NULL){
        printf("Empty!!");
        return;
    }
    if(head->next==NULL){
        printf("Deleted %d from the end of the list",head->data);
        free(head);
        head=NULL;
        return;
    }
    struct Node*temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    printf("Deleted %d from the end of the list",temp->next->data);
    free(temp->next);
    temp->next=NULL;
}