#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head =NULL;

void InsertEnd(struct Node ** head,int value){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    newNode ->data=value;
    newNode->next= NULL;

    if(head==NULL){
        head=newNode;
    }else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
}

int main(){
    return 0;
}