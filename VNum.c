#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *prev,*next;
};

struct Node*head=NULL;

void insertAtBeginning(int value){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    if(head==NULL){
        newNode->next=newNode;
        newNode=head;
    }else{
        struct Node*temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=head;
        head=newNode;
    }
    printf("Inserted %d at the beginning of the list\n",value);
}

void insertAtEnd(int value){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    if(head==NULL){
        newNode->next=newNode;
        head=newNode;
    }else{
        struct Node *temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=head;
        head=newNode;
    }
    printf("Inserted 5d at the end of the list\n",value);
}

void delStart(){
    if(head==NULL){
        printf("List is empty!! Nothing to delete\n");
        return;
    }
    if(head->next==head){
        printf("Deleted %d from the list\n",head->data);
        free(head);
        head=NULL;
        return;
    }
    struct Node*temp=head,*last=head;
    while(temp->next!=head){
        last=last->next;
    }
    head=head->next;
    last->next=head;
    printf("Deleted %d from the beginning of the list",temp->data);
    free(temp);
}

void delEnd()
{
    if (head == NULL)
    {
        printf("List is empty!! Nothing to delete\n");
        return;
    }
    if (head->next == head)
    {
        printf("Deleted %d from the list\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head, *prev = NULL;
    while (temp->next != head)
    {
        prev=temp;
        temp = temp->next;
    }
    prev->next = head;
    printf("Deleted %d from the beginning of the list", temp->data);
    free(temp);
}