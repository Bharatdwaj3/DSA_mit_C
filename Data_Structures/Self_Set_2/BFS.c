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

// Queue structure for BFS
typedef struct Queue
{
    int items[MAX_VERTICES];
    int front, rear;
} Queue;

// Function to create a new node
Node *createNode(int v)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the queue
Queue *createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check if the queue is empty
bool isEmpty(Queue *q)
{
    return q->front == -1;
}

// Enqueue an element
void enqueue(Queue *q, int value)
{
    if (q->rear == MAX_VERTICES - 1)
        return;
    if (isEmpty(q))
    {
        q->front = q->rear = 0;
    }
    else
    {
        q->rear++;
    }
    q->items[q->rear] = value;
}

// Dequeue an element
int dequeue(Queue *q)
{
    if (isEmpty(q))
        return -1;
    int item = q->items[q->front];
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front++;
    }
    return item;
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

// BFS traversal function
void BFS(Node *adj[], int V, int res[], int *resSize)
{
    bool visited[MAX_VERTICES] = {false};
    Queue *q = createQueue();

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            enqueue(q, i);

            while (!isEmpty(q))
            {
                int current = dequeue(q);
                res[(*resSize)++] = current;

                Node *temp = adj[current];
                while (temp != NULL)
                {
                    if (!visited[temp->vertex])
                    {
                        visited[temp->vertex] = true;
                        enqueue(q, temp->vertex);
                    }
                    temp = temp->next;
                }
            }
        }
    }

    free(q);
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

    BFS(adj, V, res, &resSize);

    for (int i = 0; i < resSize; i++)
    {
        printf("%d ", res[i]);
    }
    printf("\n");

    return 0;
}
