#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Structure to represent a node in the adjacency list
typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

// Structure to represent a graph
typedef struct Graph
{
    int numVertices;
    Node *adjLists[MAX_NODES];
    int visited[MAX_NODES];
} Graph;

// Queue structure for BFS
typedef struct Queue
{
    int items[MAX_NODES];
    int front, rear;
} Queue;

// Function to create a new node
Node *createNode(int vertex)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with n vertices
Graph *createGraph(int vertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph *graph, int src, int dest)
{
    // Add edge from src to dest
    Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src (for an undirected graph)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to create and initialize a queue
Queue *createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Check if the queue is empty
int isEmpty(Queue *queue)
{
    return queue->front == -1;
}

// Enqueue operation
void enqueue(Queue *queue, int value)
{
    if (queue->rear == MAX_NODES - 1)
        return;

    if (queue->front == -1)
        queue->front = 0;

    queue->items[++queue->rear] = value;
}

// Dequeue operation
int dequeue(Queue *queue)
{
    if (isEmpty(queue))
        return -1;

    int item = queue->items[queue->front];

    if (queue->front >= queue->rear)
    {
        queue->front = queue->rear = -1;
    }
    else
    {
        queue->front++;
    }

    return item;
}

// Breadth-First Search (BFS)
void bfs(Graph *graph, int startVertex)
{
    Queue *queue = createQueue();
    graph->visited[startVertex] = 1;
    enqueue(queue, startVertex);

    printf("BFS Traversal: ");

    while (!isEmpty(queue))
    {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        Node *temp = graph->adjLists[currentVertex];
        while (temp)
        {
            int adjVertex = temp->vertex;

            if (!graph->visited[adjVertex])
            {
                graph->visited[adjVertex] = 1;
                enqueue(queue, adjVertex);
            }
            temp = temp->next;
        }
    }
    printf("\n");

    free(queue);
}

// Driver Code
int main()
{
    int vertices = 6;
    Graph *graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);

    bfs(graph, 0); // Start BFS from vertex 0

    return 0;
}
