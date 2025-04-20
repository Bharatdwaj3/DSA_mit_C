#include<stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void printList(){
    if(head==NULL){
        printf("List is empty!!");
        return;
    }
    struct Node *temp=head;
    printf("Linked List: ");
    while(temp!=NULL){
       printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
void insertAtBegining(int value){
    struct Node *newNode= (struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=head;
    head=newNode;
    printf("Inserted %d at the beginning of the list.\n", value);
}
void insertAtEnd(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if(head==NULL){
        head=newNode;
    }else{
        struct Node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
    printf("Inserted %d at the end of the list.\n", value);
}
void deleteAtStart(){
    if(head==NULL){
        printf("Empty!!");
        return;
    }
    struct Node *temp=head;
    head=head->next;
    printf("Node with value %d deleted \n",temp->data);
    free(temp);
}
void deleteAtEnd(){
    if (head == NULL)
    {
        printf("Empty!!");
        return;
    }
    if(head->next==NULL){
        printf("Value with %d deleted from the end!!",head->data);
        free(head);
        head=NULL;
        return;
    }

    struct Node*temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    printf("Node with the value %d deleted from the end!!",temp->data);
    free(temp->next);
    temp->next=NULL;
}

struct Node* rev(){
    struct Node*prev,  *next=NULL,*curr=head;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

struct Node* mittel(){
    struct Node* slow=head, *fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

int Loop()
{
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            return 1;
        }
    }
}



int main(){

    insertAtBegining(10);
    insertAtBegining(20);
    insertAtBegining(30);
    insertAtBegining(40);
    insertAtBegining(50);
    printList();

    deleteAtStart();
    printList();

    insertAtEnd(100);
    insertAtEnd(200);
    insertAtEnd(300);
    insertAtEnd(400);
    insertAtEnd(500);
    printList(head);

    deleteAtEnd();
    printList();


    return 0;
}