

-- -

   ## 🔍 1. Find Minimum in BST

```c struct Node *
   findMin(struct Node *node)
{
    if (!node)
        return NULL;
    if (!node->left)
        return node;
    return findMin(node->left);
}
```

    -- -

    ## 🔁 2. Inorder
    Successor(Recursive)

```c
    struct Node *inorderSuccessorRecursive(struct Node *root, struct Node *target)
{
    if (!root)
        return NULL;

    if (target->data < root->data)
    {
        struct Node *left = inorderSuccessorRecursive(root->left, target);
        return left ? left : root;
    }
    else if (target->data > root->data)
    {
        return inorderSuccessorRecursive(root->right, target);
    }
    else
    {
        if (root->right)
            return findMin(root->right);
    }
    return NULL;
}
```

    -- -

    ## 📊 3. Count
    Nodes(Total, Left, Right)

```c
    int countTotal(struct Node *root)
{
    if (!root)
        return 0;
    return 1 + countTotal(root->left) + countTotal(root->right);
}

int countLeft(struct Node *root)
{
    if (!root || !root->left)
        return 0;
    return 1 + countTotal(root->left);
}

int countRight(struct Node *root)
{
    if (!root || !root->right)
        return 0;
    return 1 + countTotal(root->right);
}
```

    -- -

    ## ❌ 4. Delete Node with :## # ➤ Only Right Child
```c struct Node *deleteWithRightChild(struct Node *root, int key)
{
    if (!root)
        return NULL;
    if (key < root->data)
        root->left = deleteWithRightChild(root->left, key);
    else if (key > root->data)
        root->right = deleteWithRightChild(root->right, key);
    else
    {
        if (root->right && !root->left)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
    }
    return root;
}
```

    ## # ➤ No
    Child(Leaf)

```c
    struct Node *deleteLeaf(struct Node *root, int key)
{
    if (!root)
        return NULL;
    if (key < root->data)
        root->left = deleteLeaf(root->left, key);
    else if (key > root->data)
        root->right = deleteLeaf(root->right, key);
    else
    {
        if (!root->left && !root->right)
        {
            free(root);
            return NULL;
        }
    }
    return root;
}
```

    ## # ➤ One
    Child(Left or Right)

```c
    struct Node *deleteWithOneChild(struct Node *root, int key)
{
    if (!root)
        return NULL;
    if (key < root->data)
        root->left = deleteWithOneChild(root->left, key);
    else if (key > root->data)
        root->right = deleteWithOneChild(root->right, key);
    else
    {
        if (root->left && !root->right)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        else if (root->right && !root->left)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
    }
    return root;
}
```

    -- -

    ## 🔃 5. Replace Node with 2 Children(Using Successor)

```c
    struct Node *deleteNode(struct Node *root, int key)
{
    if (!root)
        return NULL;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        if (!root->left && !root->right)
        {
            free(root);
            return NULL;
        }
        else if (!root->left)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (!root->right)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        struct Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
```

        -- -

        ## 🗑️ 6. Delete Successor /
        Predecessor

        (Same as delete node with 2 children — see previous section)

            -- -

    ## 🔁 7. Replace Child with Parent

```c
    struct Node *replaceWithChild(struct Node *root, int key)
{
    if (!root)
        return NULL;

    if (key < root->data)
        root->left = replaceWithChild(root->left, key);
    else if (key > root->data)
        root->right = replaceWithChild(root->right, key);
    else
    {
        if (root->left && !root->right)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        else if (root->right && !root->left)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else
        {
            printf("Node with two children — cannot replace directly with one child.
");
        }
    }

    return root;
}
```

    -- -

    ## ✅ End of Genc Ques
