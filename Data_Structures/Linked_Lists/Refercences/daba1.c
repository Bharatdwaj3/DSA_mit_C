#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtBegining(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    if(head==NULL){
        newNode->next=newNode;
        head=newNode;
    }else{
        struct Node*temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=head;
        head=newNode;
    }
    printf("Inserted %d at the beginning of the list\n", value);
}

void insertAtEnd(value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    if (head == NULL)
    {
        newNode->next=newNode;
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next=head;
    }
}

void deleteAtBegining()
{
    if (head == NULL)
    {
        printf("List is empty!! NOthing to delete\n");
        return;
    }
    if(head->next==head){
        printf("Deleted %d from the list\n",head->data);
        free(head);
        head=NULL;
        return;
    }
    struct Node *temp = head,*last=head;
    while(last->next!=head){
        last=last->next;
    }
    head = head->next;
    last->next=head;
    printf("Deleted %d from the beginning of the list\n", temp->data);
    free(temp);
}
void deleteAtEnd()
{
    if (head == NULL)
    {
        printf("List is empty!!\n");
        return;
    }
    if (head->next == NULL)
    {
        printf("Deleted %d from the end of the list\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head,*prev=NULL;
    while (temp->next != NULL)
    {
        prev=temp;
        temp = temp->next;
    }
    prev->next=head;
    printf("Deleted %d from the end of the list\n", temp->next->data);
    free(temp);
}

void peek()
{
    if (head == NULL)
    {
        printf("List is empty!!");
        return;
    }
    printf("Front element: %d\n", head->data);
}
void displayList()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
   
    do{
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    while (temp != head);
    printf("NULL\n");
}