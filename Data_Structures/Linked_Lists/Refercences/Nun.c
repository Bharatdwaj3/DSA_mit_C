#include<stdio.h>
#include<stdio.h>

struct Node{
    int data;
    struct Node *left, *right;
};

struct Node *newNode(int data){
    struct Node *node=(struct Node*)malloc(sizeof(struct Node));
    node->data=data;
    node->left=node->right=NULL;
    return node;
}

struct Node *findMax(struct Node*node){
    if(!node)
        return NULL;
    if(!node->right)
        return node;
    return findMax(node->right);
}

struct Node *findMax(struct Node *node){
    if(!node)
        return NULL;
    if(!node->right)
        return node;
    return findMax(node->right);
}

struct Node *findMin(struct Node *node){
    if(!node)
        return NULL;
    if(!node->left)
        return node;
    return findMin(node->left);
}

int countTotal(struct Node *root){
    if(!root)
        return 0;
    return 1+countTotal(root->right)+countTotal(root->left);
}

int countRight(struct Node *root){
    if(!root||!root->right)
        return 0;
    return 1+countTotal(root->right);
}

int countLeft(struct Node *root){
    if(!root||!root->left)
        return 0;
    return 1+countTotal(root->left);
}

struct Node *delRChild(struct Node*root, int key){
    if(!root)
        return NULL;
    if(key<root->data)
        root->left=delRChild(root->left, key);
    else if(key>root->data)
        root->right=delRChild(root->right, key);
    else{
        if(root->right&&!root->left){
            struct Node*temp=root->right;
            free(root);
            return temp;
        }
    }
    return root;
}

struct Node *delLeaf(struct Node *root, int key){
    if(!root)
        return NULL;
    if(key<root->data)
        root->left=delLeaf(root->left, key);
    else if(key>root->data)
        root->right=delLeaf(root->right,key);
    else{
        if(!root->left&&!root->right){
            free(root);
            return NULL;
        }
    }
    return root;
}

struct Node *del1Child(struct Node *root, int key){
    if(!root)
        return root;
    if(key<root->data)
        root->left=del1Child(root->left, key);
    else if(key>root->data)
        root->right=del1Child(root->right, key);
    else{
        if(root->left&&!root->right){
            struct Node*temp=root->left;
            free(root);
            return temp;
        }
        else if(root->right&&!root->left){
            struct Node*temp=root->right;
            free(root);
            return temp;
        }
    }
    return root;
}

struct Node*deleteNode(struct Node*root, int key){
    if(!root)
        return NULL;
    if(key<root->data)
        root->left=deleteNode(root->left, key);
    else if(key>root->data){
        root->right=deleteNode(root->right, key);
    }else{
        if(!root->left&&!root->right){
            free(root);
            return NULL;
        }else if(!root->left){
            struct Node *temp=root->right;
            free(root);
            return temp;
        }else if(!root->right){
            struct Node *temp=root->left;
            free(root);
            return temp;
        }
        struct Node*temp=findMin(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right, temp->data);
    }
    return root;
}

struct Node *inorderSuccessor(struct Node*root, struct Node*target){
    struct Node*successor=NULL;
    while(root){
        if(target->data<root->data){
            successor=root;
            root=root->left;
        }else{
            root=root->right;
        }
        return successor;
    }
}


struct Node *LCA(struct Node *root, int n1, int n2){
    if(!root)   
        return NULL;
    if(root->data==n1||root->data==n2)
        return root;
    struct Node *left=LCA(root->left,n1,n2);
    struct Node *right=LCA(root->right, n1,n2);
    if(left&&right)
        return root;
    return left?left:right;
}
