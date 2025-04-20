#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_NODES 100

// Structure for adjacency list node
typedef struct Node
{
    int dest;
    struct Node *next;
} Node;

// Structure for adjacency list
typedef struct Graph
{
    int V;
    Node *adj[MAX_NODES];
} Graph;

// Queue structure for BFS
typedef struct Queue
{
    int items[MAX_NODES];
    int front, rear;
} Queue;

Queue *createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = -1;
    return q;
}

bool isEmpty(Queue *q)
{
    return q->front == -1;
}

void enqueue(Queue *q, int value)
{
    if (q->rear == MAX_NODES - 1)
        return;
    if (q->front == -1)
        q->front = 0;
    q->items[++q->rear] = value;
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
        return -1;
    int item = q->items[q->front];
    if (q->front >= q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return item;
}

// Graph functions
Graph *createGraph(int vertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = vertices;
    for (int i = 0; i < vertices; i++)
        graph->adj[i] = NULL;
    return graph;
}

void addEdge(Graph *graph, int src, int dest)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = graph->adj[src];
    graph->adj[src] = newNode;
}

// BFS Traversal
void BFS(Graph *graph, int startVertex)
{
    bool visited[MAX_NODES] = {false};
    Queue *q = createQueue();
    enqueue(q, startVertex);
    visited[startVertex] = true;

    while (!isEmpty(q))
    {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        Node *temp = graph->adj[currentVertex];
        while (temp)
        {
            int adjVertex = temp->dest;
            if (!visited[adjVertex])
            {
                visited[adjVertex] = true;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

// DFS Traversal
void DFSUtil(Graph *graph, int vertex, bool visited[])
{
    visited[vertex] = true;
    printf("%d ", vertex);
    Node *temp = graph->adj[vertex];
    while (temp)
    {
        int adjVertex = temp->dest;
        if (!visited[adjVertex])
            DFSUtil(graph, adjVertex, visited);
        temp = temp->next;
    }
}

void DFS(Graph *graph, int startVertex)
{
    bool visited[MAX_NODES] = {false};
    DFSUtil(graph, startVertex, visited);
    printf("\n");
}

int main()
{
    Graph *graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);

    printf("BFS Traversal: ");
    BFS(graph, 0);

    printf("DFS Traversal: ");
    DFS(graph, 0);

    return 0;
}
