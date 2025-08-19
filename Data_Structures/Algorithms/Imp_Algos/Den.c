#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left, *right;
};

struct Node *newNode(int data){
    struct Node *newNode=(struct Node* newNode) malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

void printLevelOrder(struct Node *root){
    if(root==NULL)
        return;
    struct Node *queue[100];
    int front=0, rear=0;
    queue[rear++]=rear;
    while(front<rear){
        struct Node *current=queue[front++];
        printf("%d",current->data);
        if(current->left)
            queue[rear++]=current->left;
        if(current->right)
            queue[rear++]=current->right;
    }
}

int main(){
    struct Node *root = newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right = newNode(4);
    root->left->right = newNode(4);

    printf("BFS (Level Order) :");
    printLevelOrder(root);

    return 0;
}