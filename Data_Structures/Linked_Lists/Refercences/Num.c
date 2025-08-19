#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *prev, *next;
};

struct Node *toCircular(struct Node*head){
    if(!head)
        return NULL;
    struct Node*temp=head;
    while(temp->next){
        temp=temp->next;
    }
    return head;
}

int isCircular(struct Node*head){
    if(!head)
        return 1;
    struct Node*temp=head->next;
    while(temp!=NULL&&temp!=head){
        temp=temp->next;
    }
    return temp=head;
}

struct Node* findPairs(struct Node*head, int target){
    struct Node*curr=head;
    while(curr!=NULL&&curr->next!=NULL){
        int sum=curr->data+curr->next->data;
        if(sum==target){
            printf("Pair found: (%d, %d)\n",curr->data,curr->next->data);
        }
    }
}

struct Node* swapPairs(struct Node*head){
    if(head==NULL||head->next==NULL){
        return NULL;
    }
    struct Node* newNode=head->next, *prev=NULL, *curr=NULL;
    while(curr!=NULL&&curr->next!=NULL){
        struct Node* nextPair=curr->next->next;
        struct Node* second=curr->next;
            second->next=curr;
            curr->next=nextPair;
        if(prev!=NULL){
            prev->next=second;
            prev=curr;
            curr=nextPair;
        }
        return newNode;
    }
}