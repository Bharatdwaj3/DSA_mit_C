#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next,*prev;
};

struct Node *head = NULL;

void insertAtBegining(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev=NULL;
    if(head!=NULL){
        head->prev=newNode;
    }
    head = newNode;
    printf("Inserted %d at the beginning of the list\n", value);
}

void insertAtEnd(value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL)
    {
        newNode->prev=NULL;
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
    printf("Inserted %d into the list\n",value);
}

void deleteAtBegining()
{
    if (head == NULL)
    {
        printf("List is empty!! NOthing to delete\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
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
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("Deleted %d from the end of the list\n", temp->data);
    temp->prev->next = NULL;
    free(temp->next);
    
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
void displayFWD()
{
    if (head == NULL)
    {
        printf("List is empty\n");
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
void displayBWD()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}