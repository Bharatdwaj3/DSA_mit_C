#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

struct Node *head = NULL;

void insertAtBeginning(int value){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    if(head==NULL){
        newNode->next=newNode;
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
    printf("Inserted %d at the beginning of the list.\n", value);
}
void insertAtBeginning(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    if (head == NULL)
    {
        newNode->next = newNode;
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
        newNode->next = head;
    }
    printf("Inserted %d at the beginning of the list.\n", value);
}

void deleteFromBeginning(){
    if(head==NULL){
        printf("List is empty");
        return;
    }
    if(head->next==head){
        printf("Deleted %d from the list",head->data);
        free(head);
        head=NULL;
        return;
    }
    struct Node*temp=head,*prev=NULL;
    while(temp->next!=head){
        prev=temp;
        temp=temp->next;
    }
    prev->next;

}
int main(){
    return 0;
}
