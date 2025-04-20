#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*prev,*next;
};


 struct Node*head=NULL;
 
void insertAtBeginning(int value){
    struct Node*newNode=(struct Node*)mallloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=head;
    newNode->prev=NULL;
    if(head==NULL){
        head->prev=newNode;
    }
    head=newNode;
    printf("Inserted %d at the begining of the list\n",value);
}


void insertAtEnd(int value){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    if(head==NULL){
        newNode->prev=NULL;
        head=newNode;
    }else{
        struct Node*temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=head;
        newNode->prev=temp;
    }
    printf("Inserted %d at the end of the list\n",value);
}

void deleteFromBegining(){
    if(head==NULL){
        printf("List is empty!");
        return;
    }
    struct Node*temp=head;
    head=head->next;
    if(head!=NULL){
        head->prev=NULL;
    }
    printf("Deleted %d from the begining of the list\n",temp->data);
    free(temp);
}
void deleteFromEnd() {
    if(head==NULL){
        printf("List is empty!!");
        return;
    }
   
    if(head->next==NULL){
        printf("Deleted %d from the end of the list!!\n",head->data);
        free(head);
        head=NULL;
        return;
    }
    struct Node *temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    printf("Deleted %d from the end of the list\n",temp->data);
    temp->prev->next=NULL;
    free(temp);
}

void peek(){
    if(head==NULL){
        printf("The list is empty!!");
        return;
    }
    printf("Front element : %d\n",head->data);
}

void displayFwd(){
    if(head==NULL){
        printf("Empty List!!");
        return;
    }
    struct Node *temp=head;
    printf("Doubly Linked List : ");
    while(temp!=NULL){
        printf("%d <-> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
void displayFwd(){
    if (head == NULL){
        printf("Empty List!!");
        return;
    }
    struct Node *temp = head;

    while (temp->next != NULL){
        temp = temp->next;
    }
    while(temp!=NULL){
        printf("%d <-> ",temp->data);
        temp=temp->prev;
    }

    printf("NULL\n");
}