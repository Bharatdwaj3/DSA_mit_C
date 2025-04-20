#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

struct Node*head=NULL;


void insertAtBeginning(int value){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node*));

    newNode->data=value;
    newNode->next=head;
    head=newNode;
    printf("Inserted %d at the front of the list",value);
}
void insertAtEnd(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node *));
    newNode->data = value;
    newNode->next = head;
    if(head==NULL){
        head=newNode;
    }else{
        struct Node*temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;

    }
    
    printf("Inserted %d at the end of the list", value);
}

void deleteAtBeginning(){
    if(head==NULL){
        printf("Empty!!");
        return;
    }
    struct Node*temp=head;
    head=head->next;
    printf("Deleted %d from the start of the list\n",head->data);
}

void deleteAtEnd(){
    if (head == NULL)
    {
        printf("Empty!!");
        return;
    }
}

