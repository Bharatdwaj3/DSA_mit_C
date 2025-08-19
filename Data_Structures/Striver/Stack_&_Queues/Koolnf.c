#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*left, *right;
};
struct Node*findMin(struct Node*node){
    if(!node)
        return NULL;
    if(!node->left)
        return node;
    return 
        findMin(node->left);
}
struct Node*findMax(struct Node*node){
    if(!node)
        return NULL;
    if(!node->right)
        return node;
    return 
        findMin(node->right);
}

struct Node* inorderSucs(struct Node*root, struct Node*target){
    if(!root)
        return  NULL;
    if(target->data<root->data){
        struct Node*left=inorderSucs(root->left,target);
        return left?left:root;
    }else if(target->data>root->data){
        return inorderSucs(root->right, target);
    }else{
        if(root->right)
            return findMin(root->right);
    }
    return NULL;
}

struct Node*postOrderSucs(struct Node*root, struct Node*target){
    struct Node*left=postOrderSucs(root->left, target);
    if(left) return left;
    struct Node* right=postOrderSucs(root->right, target);
    if(right) return right;

    if(root==target){
        if(root->right)
            return findMin(root->right);
    }
}

