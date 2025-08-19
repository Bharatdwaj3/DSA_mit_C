#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node{
    int data;
    struct Node*left;
    struct Node*right;
};

struct Node *createNode(int value){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

struct Node *insert(struct Node*root, int value){
    if(!root)
        return createNode(value);
    if(value<root->data){
        root->left=insert(root->left,value);
    }else{
        root->right=insert(root->right,value);
    }
    return root;
}


void preOrderTraversal(struct Node*root){
    if(root!=NULL){
        printf("%d", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}
void inOrderTraversal(struct Node*root){
    if(root!=NULL){
        inorderTraversal(root->left);
        printf("%d",root->data);
        insorderTraversal(root->right);
    }
}

void postOrderTraversal(struct Node*root){
    if(root!=NULL){
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
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

int areIdentical(struct Node *root1, struct Node*root2){
    if(!root1&&!root2)
        return 1;
    if (!root1 || !root2)
        return 0;
    return (root1->data == root2->data) &&
        areIdentical(root1->left, root2->left) &&
        areIdentical(root1->right, root2->right);
}

void mirror(struct Node *root){
    if(!root)
        return;
    mirror(root->left);
    mirror(root->right);
    struct Node *temp=root->left;
    root->right=root->left;
    root->left=temp;
}

int isMirror(struct Node *root1,struct Node *root2){
    if (!root1 && !root2)
        return 1;
    if (!root1 || !root2)
        return 0;
    return (root1->data == root2->data) &&
           isMirror(root1->left, root2->left) &&
           isMirrot(root1->right, root2->right);
}

int isSymmmetric(struct Node *root){
    return isMirror(root, root);
}

int isAssymetric(struct Node *root){
    return !isMirror(root, root);
}
