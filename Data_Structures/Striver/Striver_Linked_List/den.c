#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*left,*right;
};

struct Node*newNode(int data){
    struct Node *node=(struct Node*)malloc(sizeof(struct Node));
    node->data=data;
    node->left=node->right=NULL;
    return node;
}

struct Node*findMIn(struct Node*node){
    if(!node) return NULL;
    if(!node->left) return node;
    return findMin(node->left);
}

struct Node*inorderSuccessorRecursive(struct Node*root, struct Node*target){
   if(!root)
   return NULL;
   if(target->data<root->data){
        struct Node *left=inorderSuccessorRecursive(root->left,target);
        return left?left:root;
   }else if(target->data>root->data){
        return inorderSuccessorRecursive(root->right, target);
   }else{
        if(root->right)
            return findMin(root->right);
   }
   return NULL;
}

struct Node*deleteWithRightChildOnly(struct Node *root, int key){
    if(!root)
    return NULL;
    if(key<root->data){
        root->left=deleteWithRightChildOnly(root->left, key);
    }else if(key>root->data){
        root->right = deleteWithRightChildOnly(root->right, key);
    }else{
        if(root->right&&!root->left){
            struct Node*temp=root->right;
            free(root);
            return temp;
        }
    }
    return root;
}


struct Node*deleteWithLeftChildOnly(struct Node *root, int key){
    if(!root)
     return NULL;
    if(key<root->data){
        root->left=deleteWithRightChildOnly(root->left, key);
    }else if(key>root->data){
        root->right = deleteWithRightChildOnly(root->right, key);
    }else{
        if(!root->right&&root->left){
            struct Node*temp=root->left;
            free(root);
            return temp;
        }
    }
    return root;
}

struct Node*deleteWithLeftChildOnly(struct Node *root, int key){
    if(!root)
     return NULL;
    if(key<root->data){
        root->left=deleteWithLeftChildOnly(root->left, key);
    }else if(key>root->data){
        root->right = deleteWithLeftChildOnly(root->right, key);
    }else{
        if(!root->right&&root->left){
            struct Node*temp=root->left;
            free(root);
            return temp;
        }
    }
    return root;
}

struct Node*deleteWithLeaf(struct Node *root, int key){
    if(!root)
     return NULL;
    if(key<root->data){
        root->left=deleteWithleaf(root->left, key);
    }else if(key>root->data){
        root->right = deleteWithLeaf(root->right, key);
    }else{
            if(!root->left&&!root->right){
                free(root);
                return NULL;
            }            
        }
    return root;
}

struct Node*deleteWithOnlyChild(struct Node *root, int key){
    if(!root)
     return NULL;
    if(key<root->data){
        root->left=deleteWithLeftdOnlyChild(root->left, key);
    }else if(key>root->data){
        root->right = deleteWithOnlyChild(root->right, key);
    }else{
        if(!root->right&&root->left){
            struct Node*temp=root->left;
            free(root);
            return temp;
        }
        else if(root->right&&!root->left){
            struct Node*temp=root->left;
            free(root);
            return temp;
        }
    }
    return root;
}

struct Node*deleteWithTwoChild(struct Node *root, int key){
    if(!root)
     return NULL;
    if(key<root->data){
        root->left=deleteWithLeftdTwoChild(root->left, key);
    }else if(key>root->data){
        root->right = deleteWithTwoChild(root->right, key);
    }else{
        if (!root->right && !root->left)
        {

            free(root);
            return NULL;
        }
        else if(!root->right&&root->left){
            struct Node*temp=root->left;
            free(root);
            return temp;
        }
        else if(root->right&&!root->left){
            struct Node*temp=root->left;
            free(root);
            return temp;
        }
    }
    return root;
}

int countTotal(struct Node *root){
    if(!root){
        return 0;
    }
    return 1+countTotal(root->left)+countTotal(root->right);
}
int countTotalLeft(struct Node *root){
    if(!root||root->left){
        return 0;
    }
    return 1+countTotal(root->left);
}

int countTotalright(struct Node *root){
    if(!root||root->right){
        return 0;
    }
    return 1+countTotal(root->right);
}
