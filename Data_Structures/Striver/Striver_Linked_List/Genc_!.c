#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node* findMax(struct Node*node){
    while(node&&node->right!=NULL){
        node=node->right;
    }
    return node;
}

struct Node *findMin(struct Node *node){
    while (node && node->left != NULL){
        node = node->left;
    }    
    return node;
}

int countTotal(struct Node *root){
    if(!root)
        return 0;
        return 1+countTotal(root->left)+countTotal(root->right);
}

int countLeft(struct Node*root){
    if(!root||!root->left)
        return 0;
        return countTotal(root->left);
}

int countRight(struct Node *root){
    if (!root || !root->right)
        return 0;
        return countTotal(root->right);
}

int countLeaf(struct Node* root){
    if(!root)
        return 0;
    if(!root->left&&!root->right)
        return 1;
    return countLeaf(root->left)+countLeaf(root->right);
}

int countLeafOne(struct Node *root){
    if (!root)
        return 0;
    int count=0;
    if ((!root->left && root->right)||(root->left && !root->right))
        count =1;
    return count+countLeafOne(root->left) + countLeafOne(root->right);
}

struct Node* deleteLeaf(struct Node* root, int key){
    if(!root) return NULL;
    if(key<root->data)
        root->left=deleteLeaf(root->left,key);
    else if(key>root->data)
        root->right=deleteLeaf(root->right,key);
    else{
        if(!root->left&&!root->right){
            free(root);
            return NULL;
        }
    }
    return root;
}

struct Node* deleteWithRightChild(struct Node*root,int key){
    if(!root)
        return NULL;
    if(key<root->data)
        root->left=deleteWithRightChild(root->left,key);
    else if(key>root->data)
        root->right=deleteWithRightChild(root->right, key);
    else{
        if(root->right&&!root->left){
            struct Node*temp=root->right;
            free(root);
            return temp;
        }
    }
    return root;
}

struct Node* deleteWithLeftChild(struct Node*root,int key){
    if(!root)
        return NULL;
    if(key<root->data)
        root->left=deleteWithLeftChild(root->left,key);
    else if(key>root->data)
        root->right=deleteWithLeftChild(root->right, key);
    else{
        if(root->left&&!root->right){
            struct Node*temp=root->left;
            free(root);
            return temp;
        }
    }
    return root;
}

struct Node* delNode(struct Node* root, int key){
    if(!root) 
        return NULL;
    if(key<root->data)
        root->left=delNode(root->left,key);
    else if(key>root->data)
        root->right=delNode(root->right, key);
    else{
        if(!root->left&&!root->right){
            free(root);
            return NULL;
        }else if(!root->left){
            struct Node* temp=root->right;
            free(root);
            return temp;
        }else if(!root->right){
            struct Node* temp=root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->data=temp->data;
        root->right=delNode(root->right,temp->data);
    }
    return root;
}

struct Node* replaceChildWithParent(struct Node* root, int key){
    if(!root)
        return NULL;
    if(key<root->data)
        root->left=replaceChildWithParent(root->left, key);
    else if(key>root->data){
        root->right = replaceChildWithParent(root->right, key);
    }
    else{
        if(root->left && !root->right){
            struct Node* temp = root->left;
            free(root);
            return temp;
        }else if(root->right&&!root->left){
            struct Node* temp=root->right;
            free(root);
            return temp;
        }else{
            printf("Node with two children cannot replace directly with one child");
        }
    }
    return root;
}

struct Node* deletePredecessor(struct Node*root, int key){
    if(!root) 
        return NULL;
    if(key<root->data)
        root->left=deletePredecessor(root->left,key);
    else if(key>root->data)
        root->right=deletePredecessor(root->right, key);
    else{
        if(root->left&&root->right){
            struct Node* pred=findMax(root->left);
            root->data=pred->data;
            root->left=deletePredecessor(root->left, pred->data);
        }else{
            struct Node* temp = root->left?root->left:root->right;
            free(root);
            return temp; 
        }
    }
    return root;
}

struct Node *deleteSuccessor(struct Node *root, int key)
{
    if (!root)
        return NULL;
    if (key < root->data)
        root->left = deleteSuccessor(root->left, key);
    else if (key > root->data)
        root->right = deleteSuccessor(root->right, key);
    else
    {
        if (root->left && root->right)
        {
            struct Node *suc = findMax(root->right);
            root->data = suc->data;
            root->right = deleteSuccessor(root->right, suc->data);
        }
        else
        {
            struct Node *temp = root->left ? root->left : root->right;
            free(root);
            return temp;
        }
    }
    return root;
}