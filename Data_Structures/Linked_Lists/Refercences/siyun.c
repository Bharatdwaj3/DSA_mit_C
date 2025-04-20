#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next, *prev;
};

struct Node *head = NULL;

void deleteFromStart(){
   
    if (head == NULL){
        printf("List is empty!!");
        return;
    }
    struct Node *temp = head;
    head=head->next;
    printf("Deleted %d from the begining of the list\n",temp->data);
    free(temp);
}

void deleteFromStart(){
    if (head == NULL){
        printf("List is empty!!!Nothing to delete\n");
       return;
    }
    struct Node*temp=head;
    head=head->next;
    if(head!=NULL){
        head->prev=NULL;
    }
    printf("Delted %d from the list\n",temp->data);
}

void deleteFromStart(){
    
    if (head == NULL){
        printf("List is empty!!Nothing to delete\n");
        return;
    }
    if(head->next==head){
        printf("Deleted from the start of the list\n",head->data);
        free(head);
        head=NULL;
        return;
    }
        struct Node *temp = head,*last=head;
        while (last->next != head){
            last = last->next;
        }
        head=head->next;
        last->next=head;
        printf("deleteted %d in the list\n", temp->data);
        free(temp);
}