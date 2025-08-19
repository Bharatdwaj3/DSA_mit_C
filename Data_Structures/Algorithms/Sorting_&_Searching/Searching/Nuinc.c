#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

/********** BST Node and Count Function **********/
struct BSTNode
{
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
};

struct BSTNode *newBSTNode(int data)
{
    struct BSTNode *node = (struct BSTNode *)malloc(sizeof(struct BSTNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int countLessThan(struct BSTNode *root, int key)
{
    if (!root)
        return 0;
    if (root->data < key)
        return 1 + countLessThan(root->left, key) + countLessThan(root->right, key);
    else
        return countLessThan(root->left, key);
}

/********** Linked List Node and Sum Function **********/
struct ListNode
{
    int data;
    struct ListNode *next;
};

struct ListNode *newListNode(int data)
{
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->data = data;
    node->next = NULL;
    return node;
}

void sumLinkedLists(struct ListNode *l1, struct ListNode *l2)
{
    while (l1 || l2)
    {
        int val1 = l1 ? l1->data : 0;
        int val2 = l2 ? l2->data : 0;
        printf("%d ", val1 + val2);
        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }
    printf("\n");
}

/********** Stack as Queue **********/
struct Stack
{
    int arr[MAX];
    int top;
};

void initStack(struct Stack *s)
{
    s->top = -1;
}

void push(struct Stack *s, int val)
{
    if (s->top < MAX - 1)
        s->arr[++s->top] = val;
}

int pop(struct Stack *s)
{
    return (s->top >= 0) ? s->arr[s->top--] : -1;
}

void printStackAsQueue(struct Stack *s)
{
    if (s->top == -1)
        return;

    int temp = pop(s);
    printStackAsQueue(s);
    printf("%d ", temp);
    push(s, temp); // restore stack
}

/********** Graph BFS **********/
int visited[MAX];

void bfs(int graph[MAX][MAX], int n, int src)
{
    memset(visited, 0, sizeof(visited));
    int queue[MAX], front = 0, rear = 0;
    visited[src] = 1;
    queue[rear++] = src;

    while (front < rear)
    {
        int node = queue[front++];
        printf("%d ", node);
        for (int i = 0; i < n; i++)
        {
            if (graph[node][i] && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

/********** Main for Testing **********/
int main()
{
    // BST Test
    struct BSTNode *root = newBSTNode(10);
    root->left = newBSTNode(5);
    root->right = newBSTNode(15);
    root->left->left = newBSTNode(2);
    root->left->right = newBSTNode(7);
    printf("Count less than 10 in BST: %d\n", countLessThan(root, 10));

    // Linked List Sum Test
    struct ListNode *l1 = newListNode(1);
    l1->next = newListNode(2);
    l1->next->next = newListNode(3);

    struct ListNode *l2 = newListNode(4);
    l2->next = newListNode(5);
    l2->next->next = newListNode(6);
    printf("Sum of Linked Lists: ");
    sumLinkedLists(l1, l2);

    // Stack as Queue Test
    struct Stack s;
    initStack(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    printf("Stack as Queue: ");
    printStackAsQueue(&s);
    printf("\n");

    // Graph BFS Test
    int graph[MAX][MAX] = {0};
    int n = 5; // nodes 0-4
    graph[0][1] = graph[0][2] = 1;
    graph[1][3] = graph[2][4] = 1;
    printf("BFS from node 0: ");
    bfs(graph, n, 0);

    return 0;
}
