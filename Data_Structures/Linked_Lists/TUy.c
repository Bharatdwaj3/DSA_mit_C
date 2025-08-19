#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head=NULL;

void inStart(int value){
    struct Node *newNode = (struct Node *)maloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=head;
    head=newNode;
    printf("Inserted %d at the begining of the list\n",value);
}

void delStart(){
    if(head==NULL){
        printf("List is empty!! Nothing to delete\n");
        return;
    }
    struct Node *temp=head;
    head=head->next;
    printf("Deleted %d from the begining of the list\n",temp->data);
    free(temp);
}

void inEnd(int value){
    struct Node *newNode = (struct Node *)maloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=head;
    if(head==NULL){
        head=newNode;
    }else{
        struct Node*temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newNode;
    }
    printf("Inserted %d at the begining of the list\n",value);
}

void delStart(){
    if(head==NULL){
        printf("List is empty!! Nothing to delete\n");
        return;
    }
    struct Node *temp=head;
    head=head->next;
    printf("Deleted %d from the begining of the list\n",temp->data);
    free(temp);
}

void delEnd(){
    if(head==NULL){
        printf("List is empty!!");
        return;
    }
    if(head->next==NULL){
        printf("Deleted %d from teh end of the list\n");
        free(head);
        head=NULL;
        return;
    }
    struct Node *temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    printf("Deleted %d from the end of the list\n");
    free(temp->next);
    temp->next=NULL;
}

void peek(){
    if(head==NULL){
        printf("List is empty!!");
        return;
    }
    printf("Front element : %d\n",head->data);
}

void displayList(){
    if(head==NULL){
        printf("List is empty!!\n");
        return;
    }
    struct Node *temp=head;
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}