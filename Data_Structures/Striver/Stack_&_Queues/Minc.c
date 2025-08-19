#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head;

bool isPallindrome(int n){
    int org=n;
    int rev=0;
    while(n!=0){
        int digit=n%10;
        rev=rev*10+digit;
        n/=10;
    }
    return org==rev;
}



void displayList(struct Node*head){
    if(head==NULL){
        printf("List is empty!!\n");
        return;
    }
    struct Node*temp=head;
    printf("Pallindrome Nodes: ");
    while(temp!=NULL){
        if(isPallindrome(temp->data)){
            printf("%d ->",temp->data);
        }
        temp=temp->next;
    }
    printf("NULL\n");
}