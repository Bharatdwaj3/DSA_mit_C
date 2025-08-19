//Doubly Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next, *prev;
};

struct Node *head = NULL;

void inStart(int value)
{
    struct Node *newNode = (struct Node *)maloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    newNode->prev = NULL;
    if(head!=NULL){
        head->next=newNode;
        head=newNode;

    }else{
        struct Node*temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=head;
        head=newNode;
    }
    printf("Inserted %d at the begining of the list\n", value);
}

void delStart()
{
    if (head == NULL)
    {
        printf("List is empty!! Nothing to delete\n");
        return;
    }
    if(head->next==head){
        printf("Deleted %d from the list\n",head->data);
        free(head);
        head=NULL;
        return;
    }
    struct Node*temp=head, *last=head;
    while(last->next!=head){
        last=last->next;
    }
    head=head->next;
    last->next=head;
    printf("Deleted %d from the beginning of the list\n");
    free(temp);
}

void inEnd(int value)
{
    struct Node *newNode = (struct Node *)maloc(sizeof(struct Node));
    newNode->data = value;
    if (head == NULL)
    {
        newNode->next=head;
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next=head;
    }
    printf("Inserted %d at the begining of the list\n", value);
}

void delStart()
{
    if (head == NULL)
    {
        printf("List is empty!! Nothing to delete\n");
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
    head=head->next;
    last->next=head;
    printf("Deleted %d from the begining of the list\n", temp->data);
    free(temp);
}

void delEnd()
{
    if (head == NULL)
    {
        printf("List is empty!!");
        return;
    }
    if (head->next == NULL)
    {
        printf("Deleted %d from teh end of the list\n");
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head, *prev=NULL;
    while (temp->next != NULL)
    {
        prev =temp;
        temp = temp->next;
    }
    prev->next=head;
    printf("Deleted %d from the end of the list\n");
    free(temp);
}

void peek()
{
    if (head == NULL)
    {
        printf("List is empty!!");
        return;
    }
    printf("Front element : %d\n", head->data);
}

void displayFwd()
{
    if (head == NULL)
    {
        printf("List is empty!!\n");
        return;
    }
    struct Node *temp = head;
    printf("Circular Linked List: ");
   do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != NULL);
    printf("NULL\n");
}

