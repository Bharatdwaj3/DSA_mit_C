#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//#include<bool.h>

struct Node{
    int data;
    struct Node *left, *right;
};

struct Node *findMIn(struct Node*node){
    if(!node) 
        return NULL;
    if(!node->left) 
        return node;
    return 
        findMIn(node->left);
}

struct Node*inorderSucs(struct Node*root, struct Node *target){
    if(!root) 
        return NULL;
    if(target->data<root->data){
        struct Node *left =inorderSucs(root->left,target);
        return left ? left: root;
    }else if(target->data>root->data){
        return inorderSucs(root->right, target);
    }else{
        if(root->right)
            return findMIn(root->right);
    }
    return NULL;
}

struct Node*postOrderSucs(struct Node*root, struct Node*target){

    struct Node *left = postOrderSucs(root->left, target);
        if(left) 
            return left;
    
    struct Node *right = postOrderSucs(root->right, target);
        if(right) 
            return right;

    if(root==target){
        if(root->right)
            return findMIn(root->right);
    }
    return NULL;
}

struct Node *inOrderSucs(struct Node *root, struct Node *target){

    struct Node *left = inOrderSucs(root->left, target);
    if (left)
        return left;

    if (root == target){
        if (root->right)
            return findMIn(root->right);
    }

    struct Node *right = inOrderSucs(root->right, target);
    if (right)
        return right;

    return NULL;
}

struct Node *preOrderSucs(struct Node *root, struct Node *target){

    if (root == target){
        if (root->right)
            return findMIn(root->right);
    }

    struct Node *left = preOrderSucs(root->left, target);
    if (left)
        return left;

    

    struct Node *right = preOrderSucs(root->right, target);
    if (right)
        return right;

    return NULL;
}