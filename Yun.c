#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next, *prev;
};


struct Node *head=NULL;

void inBegin(int value){
    struct Node* newNode=(struct Node*)mallocs(sizeof(struct Node));
    newNode->data=value;
    newNode->next=head;
    newNode->prev=NULL;
    if(head!=NULL){
        head->prev=newNode;
    }
    head=newNode;
    printf("Inserted %d at the beginning of the list\n",value);
}

void inBegin(int value)
{
    struct Node *newNode = (struct Node *)mallocs(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    newNode->prev = NULL;
    if (head != NULL)
    {
        head->prev = newNode;
        head=newNode;
    }else{
        struct Node *temp=head;
        while(temp!=head){
            temp=temp->next;
        }
        temp->next=head;
        newNode->prev=temp;
    }
    printf("Inserted %d at the beginning of the list\n", value);
}

void delBegin()
{
    if (head == NULL)
    {
        printf("List is empty!! Nothing to delete!\n");
        return;
    }
    struct Node*temp=head;
    head=head->next;
    while(head!=NULL){
        head->prev=NULL;
    }
    printf("Deleted %d at the beginning of the list\n", temp->data);
    free(temp);
}

void delEnd()
{
    if (head == NULL)
    {
        printf("List is empty!! Nothing to delete!\n");
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
    printf("Deleted %d at the beginning of the list\n", temp->data);
    temp->prev->next = NULL;
    free(temp);
}