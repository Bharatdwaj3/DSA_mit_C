#include <stdio.h>
#include <stdlib.h>

// Tree node structure
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Queue node for BFS (renamed from QueueNode to Queue)
struct Queue
{
    struct Node *curr;
    struct Queue *next;
};

struct Queue *front = NULL, *rear = NULL;

// Queue functions for BFS
void enqueue(struct Node *node)
{
    struct Queue *newNode = (struct Queue *)malloc(sizeof(struct Queue));
    newNode->curr = node;
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

struct Node *dequeue()
{
    if (front == NULL)
        return NULL;

    struct Queue *newNode = front;
    struct Node *node = newNode->curr;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    free(newNode);
    return node;
}

int isQueueEmpty()
{
    return front == NULL;
}

// Tree node creation
struct Node *createNode(int value)
{
    struct Node *curr = (struct Node *)malloc(sizeof(struct Node));
    curr->data = value;
    curr->left = curr->right = NULL;
    return curr;
}

// BFS traversal
void bfsTraversal(struct Node *root)
{
    if (root == NULL)
    {
        printf("Tree is empty.\n");
        return;
    }

    enqueue(root);

    printf("BFS Traversal: ");
    while (!isQueueEmpty())
    {
        struct Node *current = dequeue();
        printf("%d ", current->data);

        if (current->left)
            enqueue(current->left);
        if (current->right)
            enqueue(current->right);
    }
    printf("\n");
}

int main()
{
    // Manually creating a binary tree
    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    bfsTraversal(root);

    return 0;
}
