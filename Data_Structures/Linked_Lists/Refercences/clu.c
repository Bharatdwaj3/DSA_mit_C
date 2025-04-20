#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node*head=NULL;

void insertAtBeginning(int value){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=head;
    newNode->prev=NULL;
    if(head!=NULL){
        head->prev=newNode;
    }
    head=newNode;
    printf("Inserted %d at the beginning of the list\n",value);
}
void insertAtEnd(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
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
        temp->next=newNode;
        newNode->prev=temp;
    }
    printf("Inserted %d into the list",value);
}


void deleteAtBeginning() {
    if(head==NULL){
        printf("Empty!!");
        return;
    }
    struct Node*temp=head;
    head=head->next;
    if(head!=NULL){
        head->prev=NULL;
    }
    printf("Deleted %d from the beginning of the list.\n", temp->data);
    free(temp);
}
void deleteAtEnd(){
    if(head==NULL){
        printf("Empty!!!\n");
        return;
    }
    if(head->next==NULL){
        printf("Deleted %d from the end of the list\n",head->data);
        free(head);
        head=NULL;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("Deleted %d from the end of the list.\n", temp->data);
    temp->prev->next = NULL;
    free(temp);
}
void peek()
{
    if (head == NULL)
    {
        printf("List is empty. Nothing to peek.\n");
        return;
    }
    printf("Front element: %d\n", head->data);
}
void displayFwd(){
    if(head==NULL){
        printf("Empty!!");
        return;
    }
    struct Node*temp=head;
    printf("Display Fwd: ");
    while(temp!=NULL){
        printf("%d <-> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
void displayFwd(){
    if (head == NULL)
    {
        printf("Empty!!");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("Display Bwd: ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}
int main(){

}