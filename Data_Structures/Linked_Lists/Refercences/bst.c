#include <stdio.h>
#include <stdlib.h>

// Define tree_type alias using typedef
typedef struct Node {
    int info;
    struct Node *left, *right;
} tree_type;

// Insert function using pointer-to-pointer
void insert(tree_type **rt, int n) {
    tree_type *p;

    if (*rt == NULL) {
        p = (tree_type *)malloc(sizeof(tree_type));
        if (p != NULL) {
            p->info = n;
            p->left = NULL;
            p->right = NULL;
            *rt = p;
        }
    } else {
        if (n < (*rt)->info)
            insert(&((*rt)->left), n);
        else
            insert(&((*rt)->right), n);
    }
}

// Inorder traversal
void inorder(tree_type *rt) {
    if (rt != NULL) {
        inorder(rt->left);
        printf("%d ", rt->info);
        inorder(rt->right);
    }
}

// Preorder traversal
void preorder(tree_type *rt) {
    if (rt != NULL) {
        printf("%d ", rt->info);
        preorder(rt->left);
        preorder(rt->right);
    }
}

// Postorder traversal
void postorder(tree_type *rt) {
    if (rt != NULL) {
        postorder(rt->left);
        postorder(rt->right);
        printf("%d ", rt->info);
    }
}

// Count total number of nodes (call by reference)
void countTotalNodes(tree_type *rt, int *count) {
    if (rt == NULL)
        return;
    (*count)++;
    countTotalNodes(rt->left, count);
    countTotalNodes(rt->right, count);
}

// Count number of leaf nodes
int countLeafNodes(tree_type *rt) {
    if (rt == NULL)
        return 0;
    if (rt->left == NULL && rt->right == NULL)
        return 1;
    return countLeafNodes(rt->left) + countLeafNodes(rt->right);
}

// Count nodes with only one child
int countOneChildNodes(tree_type *rt) {
    if (rt == NULL)
        return 0;
    int count = 0;
    if ((rt->left == NULL && rt->right != NULL) || (rt->left != NULL && rt->right == NULL))
        count = 1;
    return count + countOneChildNodes(rt->left) + countOneChildNodes(rt->right);
}

// Count nodes with only left child
int countOnlyLeftChildNodes(tree_type *rt) {
    if (rt == NULL)
        return 0;
    int count = 0;
    if (rt->left != NULL && rt->right == NULL)
        count = 1;
    return count + countOnlyLeftChildNodes(rt->left) + countOnlyLeftChildNodes(rt->right);
}

// Main menu-driven program
int main() {
    tree_type *root = NULL;
    int choice, value;

    do {
        printf("\n===== BST Operations Menu =====");
        printf("\n1. Insert");
        printf("\n2. Inorder Traversal");
        printf("\n3. Preorder Traversal");
        printf("\n4. Postorder Traversal");
        printf("\n5. Count Total Nodes");
        printf("\n6. Count Leaf Nodes");
        printf("\n7. Count One-Child Nodes");
        printf("\n8. Count Only Left-Child Nodes");
        printf("\n9. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&root, value);
                break;

            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 5: {
                int total = 0;
                countTotalNodes(root, &total);
                printf("Total Number of Nodes: %d\n", total);
                break;
            }

            case 6:
                printf("Number of Leaf Nodes: %d\n", countLeafNodes(root));
                break;

            case 7:
                printf("Number of One-Child Nodes: %d\n", countOneChildNodes(root));
                break;

            case 8:
                printf("Number of Only Left-Child Nodes: %d\n", countOnlyLeftChildNodes(root));
                break;

            case 9:
                printf("Exiting program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 9);

    return 0;
}
