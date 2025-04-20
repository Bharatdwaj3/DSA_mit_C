struct Node* deleteSuccessor(struct Node*root, int key){
    if(!root) 
        return NULL;
    if(key<root->data)
        root->left=deleteSuccessor(root->left,key);
    else if(key>root->data)
        root->right=deleteSuccessor(root->right, key);
    else{
        if(root->left&&root->right){
            struct Node* suc=findMax(root->left);
            root->data=suc->data;
            root->left=deleteSuccessor(root->left, suc->data);
        }else{
            struct Node* temp = root->left?root->left:root->right;
            free(root);
            return temp; 
        }
    }
    return root;
}