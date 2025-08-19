#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head=NULL;

void insertAtBeginning(int value){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=head;
    head=newNode;
    printf("Inserted %d at the bebining of the list\n", value);
}

void insertAtEnd(int value){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
    }else{
        struct Node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
    printf("Insrted %d into the list\n",value);
}

void deleteAtEnd(int value){
  
    if(head==NULL){
        printf("The list is empty!");
        return;
    }
    if(head->next=NULL){
        printf("Deleted %d from the end of the list\n",head->data);
        free(head);
        head=NULL;
        return;
    }
    struct Node*temp=head;
    while(temp->next=head){
        temp=temp->next;
    }
    printf("Deleted %d from the begining of the list\n",temp->data);
    free(temp);
    temp->next = NULL;
}

void deleteAtBeginning(int value){
    if(head==NULL){
        printf("The list is empty\n");
        return;
    }
    struct Node *temp=head;
    head=head->next;
    printf("Deleted %d from the start of the list\n",value);
    free(temp);
}

void peek(){
    if(head==NULL){
        printf("List is empty!! Nothing to peek\n");
        return;
    }
    printf("Front element %d\n",head->data);
}

void displayList(){
    if(head==NULL){
        printf("List is empty!!\n");
        return;
    }
    struct Node *temp=head;
    printf("Linked List: ");
    while(temp!=head){
        printf("%d -> ",temp->data);
        temp=temp->next;
    } 
    printf("NULL\n");
}

int main(){

}