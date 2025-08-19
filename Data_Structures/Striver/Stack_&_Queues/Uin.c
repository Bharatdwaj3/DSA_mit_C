#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head=NULL;

void insertAtBeginning(int value){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    
}