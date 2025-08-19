#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

struct Node*head=NULL;

void insertNode(int value){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    if(head==NULL){
        head = newNode;
    }else{
        struct Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
    
}

void display(){
    struct Node*temp=head;
    if(temp==NULL){
        printf("Empty List\n");
        return;
    }
    
    while(temp!=NULL){
        printf("%d -> ", temp->data);
        temp=temp->next;
    }
    printf("NULL!!\n");
}

void revList(){
    struct Node*prev=NULL, *curr=head, *next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
}

void mittel(){
    struct Node* slow=head, *fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    if(slow!=NULL){
        printf("The list's middle node : %d",slow->data);
    }
}

int hasLoop(){
    struct Node* slow=head, *fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if (slow == fast){
            return 1;
        }
    }
    return 0;
}

struct Node* loopStart(){
    struct Node* slow=head, *fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if (slow == fast){
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
    }
    return NULL;
}

void freeList(){
    struct Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
        free(temp);
    }
}

int main(){
    printf("Nodes in the list\n");
    insertNode(10);
    insertNode(20);
    insertNode(30);
    display();

    printf("Before Reversal: ");
    display();

    printf("After Reversal: ");
    revList();
    display();

    mittel();

    if(hasLoop()){
        printf("\nThe list has a Loop!!");
        struct Node*loopNode=loopStart();
        if(loopNode!=NULL){
           printf("\nThe loop start : %d!!",loopNode->data);
        }
    }else{
        printf("\nThe list has no Loop!!");
    }

    


}