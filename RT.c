#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

struct Node *head=NULL;

void inStart(int value){
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=head;
    head=newNode;
    printf("INserted %d at the begining of the list",value);
}
void inEnd(int value){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    if(head=NULL){
        head=newNode;
    }else{
        struct Node*temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
    printf("Inserted %d into the list\n",value);
}
void delStart(){
    if(head==NULL){
        printf("List is empty!! Nothing to delete\n");
        return;
    } 
    struct Node*temp=head;
    head=head->next;
    printf("Deleted %d from the begining of the list",temp->data);
    free(temp);
}
void delEnd(){
    if(head==NULL){
        printf("List is empty!! NOthing to delete\n");
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
    printf("Deleted 5d from the end of the list",temp->next->data);
    free(temp->next);
    temp->next=NULL;

}