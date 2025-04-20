#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next,*prev;
};

struct Node *head=NULL;

void insertAtBegining(int value) {
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=head;
    newNode->prev=NULL;
    if(head==NULL){
        head->prev=newNode;
    }
    head=newNode;
    printf("Inserted %d at the begining of the list\n",value);
}

void insertAtEnd(int value) {
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    if(head==NULL){
        newNode->prev=NULL;
        head=newNode;
    }else{
        struct Node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
    }
    printf("Inserted %d at the end of the List\n",value);
}

void deleteAtBegining() {
    if(head==NULL){
        printf("List is empty!!");
        return;
    }
    struct Node *temp=head;
    head=head->next;
    if(head!=NULL){
        head->prev=NULL;
    }
    printf("Deleted %d from the beginning of the list\n",temp->data);
    free(temp);
}
void deleteAtEnd() {
    if(head==NULL){
        printf("The list is empty!!");
        return ;
    }
    if(head->next=NULL){
        printf("Deleted %d from the end of the list\n",head->data);
        free(head);
        head=NULL;
        return;
    }
    struct Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    printf("Deleted %d from the end of the list\n",temp->data);
    temp->prev->next=NULL;
    free(temp->next);
    
}

void peek(){
    if(head==NULL){
        printf("List is emptY!!Nothing to peek!!\n");
        return;
    }
    printf("Front element: %d\n",head->data);
}

void displaytLis_tFwd(){
    if(head==NULL){
        printf("Empty List!!");
        return;
    }
    struct Node*temp=head;
    printf("Linked List: ");
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

void displaytLis_tFwd()
{
    if (head == NULL)
    {
        printf("Empty List!!");
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("Linked List Bwd: ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}