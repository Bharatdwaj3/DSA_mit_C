#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*left,*right;
};

struct Node*createNode(int value){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->left=newNode->right=NULL;
    return newNode;
}

struct Node* insert(struct Node*root,int value){
    if(root==NULL){
        return createNode(value);
    }if(value<root->data){
        root->left=insert(root->left,value);
    }else{
        root->right=insert(root->right,value);
    }
    return root;
}

void preorderTraversal(struct Node *root) {
    if(root!=NULL){
        printf("%d-> ",root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
void inorderTraversal(struct Node *root) {
    if(root!=NULL){
       
        inorderTraversal(root->left);
        printf("%d-> ", root->data);
        inorderTraversal(root->right);
    }

}
void postorderTraversal(struct Node *root) {
    if(root!=NULL){
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d-> ", root->data);
    }
}

int main(){
    struct Node*root=NULL;

    root=insert(root,50);
    
    insert(root, 60);
    insert(root, 70);
    insert(root, 80);
    insert(root, 90);
    insert(root, 100);
    insert(root, 110);

    printf("PreOrder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("InOrder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("PostOrder Traversal: ");
    inorderTraversal(root);
    printf("\n");
}