#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node{
    int data;
    struct Node *left, *right;
};

struct Node *createNode(int data){
    struct Node *node=(struct Node*)malloc(sizeof(struct Node));
    node->data=data;
    node->left=node->right=NULL;
    return node;
}

struct Node* insert(struct Node*root, int data){
    if(!root)
        return createNode(data);
    if(data<root->data)
        root->left=insert(root->left, data);
    else 
        root->right=insert(root->right, data);
    return root;
}

int height(struct Node*root){
    if(!root)
        return 0;
    int left=height(root->left);
    int right = height(root->right);
    return 1+(left>right?left:right);
}

int areIdentical(struct Node*root1, struct Node*root2){
    if(!root1 &&!root2){
        return 1;
    }
    if(!root1 || !root2)
        return 0;
    return (root1->data==root2->data)&&
        areIdentical(root1->left, root2->left)&&
        areIdentical(root1->right, root2->right);
}

void mirror(struct Node *root){
    if(!root)
        return;
    mirror(root->left);
    mirror(root->right);
    struct NOde *temp=root->left;
    root->left=root->right;
    root->right=temp;
}

int isMirror(struct Node*root1, struct Node*root2){
    if(!root1&&!root2)
        return 1;
    if(!root1||!root2)
        return 0;
    return (root1->data==root2->data)&&
        isMirror(root1->left, root2->right)&&
        isMirror(root1->right, root2->left);
}

int isSymmetric(struct Node *root){
    return isMirrot(root, root);
}

int isAssymetric(struct Node *root){
    return !isMirrot(root, root);
}

int diameter(struct Node* root, int *height){
    if(!root){
        *height=0;
        return 0;
    }
    int leftHeight=0, rightHeight=0;
    int leftDia=diameter(root->left, &leftHeight);
    int rightDia=diameter(root->right, &rightHeight);
    *height=1+(leftHeight>rightHeight)
}

int isBalanced(){}
int isBST_Check() {}
int isBST(){}
void findMaxAtEachLevel(){}