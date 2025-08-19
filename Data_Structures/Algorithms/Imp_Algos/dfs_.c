#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Structure for adjacency list node
typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

// Function to create a new node
Node *createNode(int v)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the undirected graph
void addEdge(Node *adj[], int s, int t)
{
    Node *newNode = createNode(t);
    newNode->next = adj[s];
    adj[s] = newNode;

    newNode = createNode(s);
    newNode->next = adj[t];
    adj[t] = newNode;
}

// Recursive DFS function
void dfsRec(Node *adj[], bool visited[], int s, int res[], int *idx)
{
    visited[s] = true;
    res[(*idx)++] = s;

    Node *temp = adj[s];
    while (temp != NULL)
    {
        if (!visited[temp->vertex])
            dfsRec(adj, visited, temp->vertex, res, idx);
        temp = temp->next;
    }
}

// DFS traversal for the entire graph (handles disconnected components)
void DFS(Node *adj[], int V, int res[], int *resSize)
{
    bool visited[MAX_VERTICES] = {false};
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfsRec(adj, visited, i, res, resSize);
        }
    }
}

int main()
{
    int V = 6;
    Node *adj[MAX_VERTICES] = {NULL};

    // List of edges
    int edges[][2] = {{1, 2}, {2, 0}, {0, 3}, {4, 5}};
    int numEdges = sizeof(edges) / sizeof(edges[0]);

    // Add edges to the graph
    for (int i = 0; i < numEdges; i++)
    {
        addEdge(adj, edges[i][0], edges[i][1]);
    }

    int res[MAX_VERTICES];
    int resSize = 0;

    DFS(adj, V, res, &resSize);

    for (int i = 0; i < resSize; i++)
    {
        printf("%d ", res[i]);
    }
    printf("\n");

    return 0;
}