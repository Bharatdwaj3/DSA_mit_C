#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*left,*right;
};

struct Node *inorderSurccessor(struct Node *root, struct Node *target){
    struct Node *successor = NULL;
    while (root)
    {
        if (target->data < root->data)
        {
            successor = root;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return successor;
}

struct Node *preorderSurccessor(struct Node *root, struct Node *target){
    struct Node *successor = NULL;
    while (root)
    {
        if (target->data < root->data)
        {
            successor = root;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return successor;
}