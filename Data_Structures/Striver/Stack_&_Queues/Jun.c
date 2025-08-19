#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head=NULL;

void insertNode(int value){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=head;
    head=newNode;
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

void display(){
    if(head==NULL){
        printf("List is empty!!\n");
        return;
    }

    struct Node*temp=head;
    while(temp!=NULL){
        printf("%d-> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

void findMiddle(){
    struct Node*slow=head,*fast=head;
    if(head==NULL){
        printf("List is empty!!");
        return;
    }
    while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
    }
    printf("Middle Element: %d",slow->data);
}

int hasLoop(){
    struct Node*slow=head,*fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return 1;
        }
    }
    return 0;
}


int main(){

    printf("\n\n");

    printf("Orignal List: ");
    insertNode(11);
    insertNode(12);
    insertNode(13);
    display();

    printf("Reversed List: ");
    revList();
    display();

    findMiddle();

    if(hasLoop()){
        printf("\n\t Loop Detected!!");
    }else{
        printf("\n\t No Loop detected!!");
    }

    printf("\n\n");
}