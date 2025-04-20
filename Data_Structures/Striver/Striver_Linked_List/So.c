#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

struct Node *revList(struct Node *head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    struct Node *rest=revList(head->next);
    head->next->next=head;
    head->next=NULL;
    return rest;
}

struct Node *findMittel(struct Node*head){
    struct Node *slow=head,*fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int hasLoop(struct Node*head){
    struct Node *slow=head,*fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return 1;
        }
    }
    return 0;
}

struct Node*findLoopStart(struct Node *head){
    struct Node*slow=head,*fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            slow=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
    }
    return NULL;
}

