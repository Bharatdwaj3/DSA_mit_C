#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

int main(){
    struct Node* head = NULL;
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));

    if(newNode==NULL){
        printf("Memory allocation faliure");
        return 1;
    }

    int value;
    printf("Enter the Linked list element: ");
    scanf("%d",&value);

    newNode->data=value;
    newNode->next=NULL;

    if(head==NULL){
        head=newNode;
        }else{
            struct Node* temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
    }
    struct Node* temp=head;
    printf("Linked List: ");
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");

}