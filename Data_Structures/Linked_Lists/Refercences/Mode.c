#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

struct Node *head=NULL;

void findMiddle(){
    struct Node *slow=head,*fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

int hasLoop(){
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            return 1;
        }
    }
    return 0;
}

void findLoopStart(){
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast){
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

void findLoopStart(){
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast){
            slow = head;
            while (slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}

void findLoopStart(){
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast){
            int length=1;
            struct Node *temp=slow->next;
            while (temp != fast){
                temp = temp->next;
                length++;
            }
            return length;
        }
    }
    return 0;
}

int countNodes() {
    int count = 0;
    struct Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Total Nodes: ",count);
}

int Odd_Even_countNodes(){
    int count = 0, odd=0, even=0;
    struct Node *temp = head;
    while (temp != NULL){
        if(temp->data%2==0){
            even++;
        }else{
            odd++;
        }
        temp = temp->next;
    }
    printf("Total Nodes: %d", count);
    printf("Odd Nodes: %d", odd);
    printf("Even Nodes: %d", even);
}


