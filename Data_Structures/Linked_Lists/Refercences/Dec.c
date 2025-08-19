struct Node * findMax(struct Node *node){
    while(node && node->right!=NULL){
        node=node->right;
    }
    return node;
}

struct Node *findMIn(struct Node*node){
    while(node && node->left!=NULL){
        node=node->left;
    }
}

struct countLeft(struct Node *root){
    if(!root||!root->left)
        return 0;
    return countTotal(root->left);
}

int countRight(struct Node*root){
    if(!root||!root->right)
    return 0;
    return countTotal(root->right);
}

int countLeaf(struct Node *root){
    if(!root)
        return 0;
    if(!root->left&& !root->right)
        return 1;
    return countLeaf(root->left)+countLeaf(root->right);
}

