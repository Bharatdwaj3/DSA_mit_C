#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

struct Node* head=NULL;

void insertStart(struct Node *head, int value){
    struct Node * newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=head;
    head=newNode;
}

void printfList(struct Node *head){
    struct Node *temp=head;
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

struct Node *revList(struct Node *head){
   if(head==NULL||head->next==NULL){
    return head;
   }
   struct NOde *rst=revList(head->next);
   head->next->next=head;
   head->next=NULL;
   return rst;
}

struct Node*findMittel(struct Node *head){
    struct Node*slow=head,*fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

