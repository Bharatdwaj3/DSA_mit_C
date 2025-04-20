#include<stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
}

struct Node *insert(struct Node *root, int value){
    if(root==NULL){
        root=createNode(value);
    }

    if(value<root->data){
        root->left=insert(root->left,value);
    }else
    {
        root->right = insert(root->right,value);
    }

    return root;
}

void inorderTraversal(struct Node*root){
    if(root!=NULL){
        inorderTraversal(root->left);
        printf("Inserted value at node: %d", root->data);
        inorderTraversal(root->right);
    }
}
void preorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        printf("Inserted value at node: %d", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
void postorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("Inserted value at node: %d", root->data);
    }
}

int main(){
    struct Node*root=NULL;
    root=insert(root,50);
    insert(root, 30);
    insert(root, 60);
    insert(root, 90);
    insert(root, 120);
    insert(root, 150);

    printf("Inorder Traversal  : ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder Traversal : ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}