#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtBegining(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    head = newNode;
    printf("Inserted %d at the beginning of the list\n", value);
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
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node *revList(struct Node *head){
    struct Node*prev=NULL, *curr=head,*next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}