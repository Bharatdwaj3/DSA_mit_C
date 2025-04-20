#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

struct Node*head=NULL;

struct Node*head=NULL;

void insertAtBeginning(int value){
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
        head=newNode;
    }
    printf("Inserted %d at the beginning of the list",value);
}

void insertAtEnd(int value) {
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

void deleteAtBeginning(){
   
    if (head == NULL){
       printf("List is empty!!");
       return;
    }
    if(head->next==NULL){
        printf("Deleted %d from the list\n",head->next);
        free(head);
        head=NULL;
        return;
    }
    struct Node*temp=head, *last=head;
    while(last->next!=head){
        last=last->next;
    }
    head=head->next;
    last->next=head;
    printf("Deleted %d from the beginning of the list\n",temp->data);
    free(temp);
}

void insertAtEnd(int value)
{
    
    if (head == NULL){
        printf("Empty List!!");
        return;
    }
    if(head->next=head){
        printf("Deleted %d from the list\n",head);
    }
    struct Node *temp=head,*prev=NULL;
    while (temp->next != head){
            prev=temp;
            temp = temp->next;
        }
    prev->next=head;
    printf("Deleted %d from the end of the list\n",temp->data);
    free(temp);
}

void peek(){
    if(head==NULL){
        printf("List is empty!! Nothing to peek!!");
        return;
    }
    printf("Front element: %d\n",head->data);
}

void displayList(){
    if(head==NULL){
        printf("Empty List!!");
        return;
    }
    struct Node*temp=head;
    printf("Circular Linked List: \n");
    while (temp != head)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

