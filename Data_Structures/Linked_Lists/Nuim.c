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
        head->prev=newNode;

    }
    head = newNode;
    printf("Inserted %d at the begining of the list\n", value);
}

void delStart()
{
    if (head == NULL)
    {
        printf("List is empty!! Nothing to delete\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    if(head!=NULL){
        head->prev=NULL;
    }
    printf("Deleted %d from the begining of the list\n", temp->data);
    free(temp);
}

void inEnd(int value)
{
    struct Node *newNode = (struct Node *)maloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    if (head == NULL)
    {
        newNode->prev=NULL;
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
        newNode->prev=temp;
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
    struct Node *temp = head;
    head = head->next;
    if(head!=NULL){
        head->prev=NULL;
    }
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
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("Deleted %d from the end of the list\n");
    temp->prev->next = NULL;
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
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void displayBwd()
{
    if (head == NULL)
    {
        printf("List is empty!!\n");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
    }
    printf("Doubly Linked List __Backward: \n");
    while (temp != NULL)
    {
        printf("%d <->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}