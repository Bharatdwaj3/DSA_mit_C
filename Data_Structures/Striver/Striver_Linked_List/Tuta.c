#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
    struct Node*prev;
};

struct Node*head=NULL;

void insertAtBeginning(int value){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=head;
    newNode->prev=NULL;
    if(head!=NULL){
        head->prev= newNode;
    }
    head=newNode;
    printf("%d inserted at start of the list",value);
}

void insertAtEnd(int value){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if(head==NULL){
        newNode->prev=NULL;
        head = newNode;
    }else{
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
    }
    printf("%d inserted at end of the list", value);
}

void deleteAtBeginning(){
    if (head == NULL){
        printf("Empty!!");
        return;
    }
    struct Node *temp = head;
    head=head->next;
    if(head!=NULL){
        head->prev=NULL;
    }
    printf("%d deleted at end of the list", temp->data);
    free(temp);
}

void deleteAtEnd()
{
    if (head == NULL)
    {
        printf("Empty!!");
        return;
    }
    if(head->next==NULL){
        printf("Deleted %d from the end of the list\n",head->data);
        free(head);
        head=NULL;
        return;
    }
    struct Node *temp = head;
    while (temp->next!= NULL){
        temp = temp->next;
    }
    printf("Deleted %d from the end of the list\n",temp->next->data);
    temp->prev->next=NULL;
    free(temp);
}

void peek(){
    if (head == NULL){
        printf("Empty!!\n");
        return;
    }
    printf("Front element: %d\n", head->data);
}

void displayFwd(){
    if(head==NULL){
        printf("List is empty!!");
        return;
    }
    struct Node*temp=head;
    printf("Linked List: ");
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

void displayBwd(){
    if (head == NULL){
        printf("List is empty!!");
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("Doubly Linked List Printed Backward: \n");
    while (temp != NULL)
    {
        printf("%d<-> ",temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}
