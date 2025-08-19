#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

struct Node *head = NULL;

void insertStart(int value){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=head;
    head=newNode;
    printf("Inserted %d at the begining of the list\n",value);
}

void printfList(){
    struct Node*temp=head;
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

void revList(){
    struct Node *prev=NULL, *curr=head, *next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr->next;
    }
    return head=prev;
}

void findMittel(){
    struct Node*slow=head,*fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    head=slow;

}

int hasLoop(){
    struct Node *slow=head, *fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return 1;
        }
    }
    return 0;
}

void findLoopStart(){
    struct Node*fast=head, *slow=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            slow=head;
            while(slow!=head){
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
    }
    head=NULL;
}

int lengthOFLoop(){
    struct Node*fast=head, *slow=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            int length=1;
            struct NOde*temp=slow->next;
            while(temp!=slow){
                temp=temp->next;
                length++;
            }
            return length;
        }
    }
    return 0;
}

