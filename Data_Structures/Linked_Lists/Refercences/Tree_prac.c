#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node{
    int data;
    struct Node *left,*right;
};

struct Node *createNode(int value){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int value){
    if(!root)
        return createNode(value);
    if(root<root->data)
        root->left=insert(root->left, value);
    else    
        root->right=insert(root->right, value);
}



int main(){
    return 0;
}