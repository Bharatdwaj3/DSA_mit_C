#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtBeginning(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    if(head==NULL){
        newNode->next=newNode;
        head=newNode;
    }else{
        struct Node *temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=head;
        head=newNode;
    }
    printf("Inserted %d at the bebining of the list\n", value);
}

void insertAtEnd(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    if(head==NULL){
        newNode->next=newNode;
        head=newNode;
    }else{
        struct Node *temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=head;
    }
    printf("Insrted %d into the list\n", value);
}

void deleteAtBeginning(int value)
{
    if (head == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    if(head->next==head){
        printf("Deleted %d from the list\n",head->data);
        free(head);
        head=NULL;
        return;
    }
    struct Node *temp = head, *last=head;
    while(last->next!=head){
        last=last->next;
    }
    head = head->next;
    last->next=head;
    printf("Deleted %d from the start of the list\n", temp->data);
    free(temp);
}

void deleteAtEnd(int value)
{

    if (head == NULL)
    {
        printf("The list is empty!");
        return;
    }
    if (head->next = head)
    {
        printf("Deleted %d from the end of the list\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head, *prev=NULL;
    while (temp->next != head)
    {
        prev=temp;
        temp = temp->next;
    }
    prev->next=head;
    printf("Deleted %d from the begining of the list\n", temp->data);
    free(temp);
}


void peek()
{
    if (head == NULL)
    {
        printf("List is empty!! Nothing to peek\n");
        return;
    }
    printf("Front element %d\n", head->data);
}

void displayList()
{
    if (head == NULL)
    {
        printf("List is empty!!\n");
        return;
    }
    struct Node *temp = head;
    printf("Circular Linked List: ");
    do{
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    while (temp != head);
    printf("NULL\n");
}

int main()
{
}