#include<stdio.h>
#include<stdlib.h>

#define MAX 100

struct BSTNode{
    int data;
    struct BSTNode*left,*right;
};

struct BSTNode *newBSTNode(int data){
    struct BSTNode *node = (struct BSTNode*)malloc(sizeof(struct BSTNode));
    node->data=data;
    node->left=node->right=NULL;
    return node;
}

int countLessThan(struct BSTNode* root, int key){
    if(!root)
        return 0;
    if(root->data<key)
        return 1 + countLessThan(root->left, key) + countLessThan(root->right, key);
    else
        return countLessThan(root->left, key);
}

struct ListNode{
    int data;
    struct ListNode *next;
};

struct ListNode *newListNode(int data){
    struct ListNode*node=(struct ListNode*)malloc(sizeof(struct ListNode));
        node->data=data;
        node->next=NULL;
        return node;
}

void sumLinkedLists(struct ListNode *l1, struct ListNode *l2){
    while(l1||l2){
        int val1=l1?l2->data:0;
        int val2=l2?l2->data:0;
        printf("%d",val1+val2);
        if(l1)
            l1=l1->next;
        if(l2)
            l2=l2->next;
    }
    printf("\n");
}

struct Stack{
    int arr[MAX];
    int top;
};

void initStack(struct Stack *s, int val){
    if(s->top<MAX-1)
    s->arr[++s->top]=val;
}

int pop(struct Stack *s){
    return (s->top>=0)?s->arr[s->top--]:-1;
}

void printStackAsQueue(struct Stack *s){
    if(s->top==-1)
        return;
    int temp=pop(s);
    printStackQueue(s);
    printf("%d",temp);
    push(s,temp);
}

int visited[MAX];
void bfs(int graph[MAX][MAX], int n, int src){
    memeset(visited, 0, sizeof(visited));
    int queue[MAX],front=0,rear=0;
    visited[src]=1;
    queue[rear++]=src;
    while(front<rear){
        int node=queue[front++];
        printf("%d",node);
        for(int i=0;i<n;i++){
            if(graph[node][i]&&!visited[i]){
                visited[i]=1;
                queue[rear++]=i;
            }
        }
    }
    printf("\n");
}

void dfs(int graph[MAX][MAX],int n, int src){
    memeset(visited, 0, sizeof(visited));
    int stack[MAX], top=-1;
    visited[src]=1;
    stack[++top]=src;
    while(top>=0){
        int node=stack[top--];
        printf("%d",node);

        for(int i=n-1;i>=0;i--){
            if(graph[node][i]&&!visited[i]){
                visited[i]=1;
                stack[++top]=i;
            }
        }
    }
    printf("\n");
}