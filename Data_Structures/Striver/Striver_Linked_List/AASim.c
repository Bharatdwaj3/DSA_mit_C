#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

struct Node*head=NULL;

void insertAtBeginning(int value){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=head;
    head=newNode;
    printf("%d inserted at start of the list",value);
}

void insertAtEnd(int value){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if(head==NULL){
        head = newNode;
    }else{
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
    }
    printf("%d inserted at end of the list", value);
}

void deleteAtBeginning(){
    if (head == NULL)
    {
        printf("Empty!!");
        return;
    }
    struct Node *temp = head;
    head=head->next;
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
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    printf("Deleted %d from the end of the list\n",temp->next->data);
    free(temp->next);
    temp->next=NULL;
}

void displayList(){
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

void peek(){
    if(head==NULL){
        printf("Empty!!\n");
        return;
    }
    printf("Front element: %d\n",head->data);
}

