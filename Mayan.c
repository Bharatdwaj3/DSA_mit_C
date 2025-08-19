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
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    if(head!=NULL){
        head->next=newNode;
    }
    head = newNode;
    printf("INserted %d at the begining of the list", value);
}
void inEnd(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL)
    {
        newNode->prev=head;
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
        newNode->prev=temp;
    }
    printf("Inserted %d into the list\n", value);
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
    printf("Deleted %d from the begining of the list", temp->data);
    free(temp);
}
void delEnd()
{
    if (head == NULL)
    {
        printf("List is empty!! NOthing to delete\n");
        return;
    }
    if (head->next == NULL)
    {
        printf("Deleted %d from the end of the list", head->data);
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("Deleted %d from the end of the list", temp->data);
    temp->prev->next = NULL;
    free(temp->prev);
}