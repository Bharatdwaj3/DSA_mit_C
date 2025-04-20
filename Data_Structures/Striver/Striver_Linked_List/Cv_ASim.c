#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

struct Node*head=NULL;

void insertStart(struct Node *head, int value){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=head;
    head=newNode;
}

void printList(struct Node *head){
    struct Node *temp=head;
    while(temp!=NULL){
        printf("%d-> ",temp->data);
        temp=temp->data;
    }
    printf("NULL\n");
}

void *revList(struct Node *head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    struct Node*rest=revList(head->next);
    head->next->next=head;
    head->next=NULL;
    return rest;
}

struct Node *findMittel(struct Node*head){
    struct Node*slow=head, *fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

struct Node *delMittel(struct Node *head){
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void segregateOddEven(struct Node *head){
    struct Node *odd=NULL,*even =NULL, *oddTail=NULL, *evenTail=NULL,*temp=head;
    while(temp!=NULL){
        if(temp->data%2==0){
            if(even==NULL){
                even=temp;
                evenTail=even;
            }else{
                even->next=temp;
                evenTail=evenTail->next;
            }
        }else{
            if (odd == NULL){
                odd = temp;
                oddTail = odd;
            }else{
                odd->next= temp;
                oddTail = oddTail->next;
            }
        }
        temp=temp->next;
    }
    if(odd!=NULL){
        head=odd;
        oddTail->next=even;
    }else{
        head=even;
    }
    if(evenTail!=NULL){
        evenTail->next=NULL;
    }
}

void removeNthFromEnd(struct Node*head, int n){
    struct Node*fast=head,*slow=head;
    for(int i=0;i<n;i++){
        fast=fast->next;
    }if(fast==NULL){
        head=(head)->next;
        return;
    }while(fast->next!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=slow->next->next;
}
