#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

void insertStart(struct Node **head, int value){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=*head;
    *head=newNode;
}

void printList(struct Node*head){
    struct Node*temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

struct Node *reverseListIterative(struct Node*head){
    struct Node *prev = NULL, *current = head, *next = NULL;
    while(current!=NULL){
        next=current!=NULL;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;
}

struct NOde *findMiddle(struct Node*head){
    struct Node*slow=head, *fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

int hasLoop(struct Node*head){
    struct Node*slow=head, *fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return 1;
        }
        return 0;
    }
}

struct Node*findLoopStart(struct Node*head){
    struct NOde*slow=head, *fast=head;
    while(fast!=NULL&& fast->next!=NULL){
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

int lengthOfLoop(struct Node *head){
    struct Node*slow=head, *fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            int length=1;
            struct Node*temp=slow->next;
            while(temp!=slow){
                temp=temp->next;
                length++;
            }
            return length;
        }
    }
    return 0;
}

int isPallindrome(struct Node*head){
    struct NOde *slow = head, *fast = head;
    struct NOde *prev = NULL, *next = NULL;
    while(fast!=NULL&& fast->next!=NULL){
        fast=fast->next->next;
        next=slow->next;
        slow->next=prev;
        prev=slow;
        slow=next;
    }
    if(fast!=NULL){
        slow=slow->next;
    }
    while(slow!=NULL){
        if(slow->dala!=prev->data){
            return 0;
        }
        slow=slow->next;
        prev=prev->next;
    }
    return 1;
}

void segregateOddEven(struct Node**head){
    struct
}