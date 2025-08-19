#include<stdio.h>
#include<stdlib.h>

#define MAX_NODES 100

typedef struct Node{
    int vertex;
    struct Node *next;
}Node;

typedef struct Graph{
    int numVertices;
    Node *adjLists[MAX_NODES];
    int visited[MAX_NODES];
}Graph;

typedef struct Queue{
    int items[MAX_NODES];
    int front, rear;
}Queue;


Node *createNode(int vertex){
    Node *no
}