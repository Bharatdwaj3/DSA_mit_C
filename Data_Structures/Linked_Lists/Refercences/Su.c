#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left,*right;
};

struct Node *createNode(int value){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int value){
    if(root==NULL){
        return createNode(value);
    }
    if (value>root->data){
        root->right=insert(root->right,value);
    }
    if (value<root->data){
        root->left=insert(root->left,value);
    }
    return root;
}

void preorderTraversal(struct Node*root){
    if(root!=NULL){
        printf("%d", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void inorderTraversal(struct Node*root){
    if(root!=NULL){
        inorderTraversal(root->left);
        printf("%d",root->data);
        inorderTraversal(root->right);
    }
}

void postorderTraversal(struct Node*root){
    if(root!=NULL){
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d",root->data);
        
    }
}

int height(struct Node *root){
    if(!root)
        return 0;
    int left = height(root->left);
    int right = height(root->right);
    return 1+(left>right?left:right);
}

int areIdentical(struct Node *root1, struct Node *root2){
    if(!root1 && !root2){
        return 1;
    }
    if(!root1||!root2){
        return 0;
    }
    return (root1->data == root2->data) &&
        areIdentical(root1->left, root2->left) &&
        areIdentical(root1->right, root2->left);
}

