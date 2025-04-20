#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next, *prev;
};

struct Node *head = NULL;

void deleteAtEnd(int value)
{
    if (head == NULL)
    {
        printf("List is empty!!Nothing to delte!!\n");
        return;
    }
    if(head->next==NULL){
        printf("Deleted %d from the end of the list\n",head->data);
        free(head);
        head=NULL;
        return;
    }
   struct Node* temp=head;
   while(temp->next->next!=NULL){
        temp=temp->next;
   }
   printf("Deleted %d from the end the list",temp->next->data);
   free(temp->next);
   temp->next=NULL;
}

void deleteAtEnd(int value){
    if (head == NULL)
    {
        printf("Deleted %d from the end of the list\n",head->data);
        free(head);
        head=NULL;
        return;
    }
    if(head->next==NULL){
        printf("Deleted %d from the end of the list\n",head->data);
        free(head);
        head=NULL;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    printf("Inserted %d into the list\n", value);
    temp->next->next=NULL;
    free(temp);
}

void deleteAtEnd(int value){    
    if (head == NULL){
        printf("List is empty!! Nothing to delete\n");
       return;
    }
    if(head->next==head){
        printf("Deleted %d from the list!!\n",head->data);
        free(head);
        head=NULL;
        return;
    }
    struct Node *temp=head,*prev=NULL;
    while(temp->next!=head){
        prev=temp;
        temp=temp->next;
    }
    prev->next=head;
    printf("Delete %d from the end the list\n",temp->data);
    free(temp);
}


