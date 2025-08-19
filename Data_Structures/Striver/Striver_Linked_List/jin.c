#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*left,*right;
};

struct Node* head=NULL;

struct Node* findMax(struct Node *node){
    while(node&&node->right!=NULL){
        node=node->right;
    }
    return node;
}

struct Node* findMin(struct Node *node){
    while(node&&node->left!=NULL){
        node=node->left;
    }
    return node;
}

int countTotal(struct Node*root){
    if(!root)
        return 0;
        return 1+countTotal(root->right)+countTotal(root->left);
}

int countLeft(struct Node*root){
    if(!root||!root->left)
    return 0;
    return countTotal(root->left);
}

int countRight(struct Node*root){
    if(!root||!root->right)
    return 0;
    return countTotal(root->right);
}

int countLeaf(struct Node*root){
    if(!root)
        return 0;
    if(!root->left&&!root->right)
        return 1;
    return countLeaf(root->left) + countLeaf(root->right);
}

int countLeafOne(struct Node*root){
    if(!root)
        return 0;
        int count=0;
    if((!root->left&&root->right)||(root->left&&!root->right))
        count =1;
        return 1;
    return count + countLeafOne(root->left) + countLeafOne(root->right);
}

struct Node* deleteLeaf(struct Node*root, int key){
    if(!root)
        return NULL;
    if(key<root->data)
        root->left=deleteLeaf(root->left, key);
    else if(key>root->data)
        root->right=deleteLeaf(root->right, key);
    else{
        if(!root->left&&!root->right){
            free(root);
            return NULL;
        }
    }
    return root;
}
struct Node* deleteLeafRightChildOnly(struct Node*root, int key){
    if(!root)
        return NULL;
    if(key<root->data)
        root->left=deleteLeaf(root->left, key);
    else if(key>root->data)
        root->right=deleteLeaf(root->right, key);
    else{
        if(!root->left&&root->right){
            struct Node *temp = root->right;
            free(root);
            return NULL;
        }
    }
    return root;
}

struct Node* deleteLeafLeftChildOnly(struct Node*root, int key){
    if(!root)
        return NULL;
    if(key<root->data)
        root->left=deleteLeaf(root->left, key);
    else if(key>root->data)
        root->right=deleteLeaf(root->right, key);
    else{
        if(root->left&&!root->right){
            struct Node* temp=root->right;
            free(root);
            return NULL;
        }
    }
    return root;
}