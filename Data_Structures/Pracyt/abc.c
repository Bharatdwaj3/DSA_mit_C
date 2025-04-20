#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Structure for Deque
struct Deque
{
    int *arr;
    int front, rear, size, capacity;
};

struct Deque *createDeque(int capacity)
{
    struct Deque *deque = (struct Deque *)malloc(sizeof(struct Deque));
    deque->capacity = capacity;
    deque->size = 0;
    deque->front = 0;
    deque->rear = -1;
    deque->arr = (int *)malloc(capacity * sizeof(int));
    return deque;
}

bool isFull(struct Deque *deque) { return deque->size == deque->capacity; }
bool isEmpty(struct Deque *deque) { return deque->size == 0; }

void insertFront(struct Deque *deque, int value)
{
    if (isFull(deque))
        return;
    deque->front = (deque->front - 1 + deque->capacity) % deque->capacity;
    deque->arr[deque->front] = value;
    deque->size++;
}

void insertRear(struct Deque *deque, int value)
{
    if (isFull(deque))
        return;
    deque->rear = (deque->rear + 1) % deque->capacity;
    deque->arr[deque->rear] = value;
    deque->size++;
}

int deleteFront(struct Deque *deque)
{
    if (isEmpty(deque))
        return INT_MIN;
    int value = deque->arr[deque->front];
    deque->front = (deque->front + 1) % deque->capacity;
    deque->size--;
    return value;
}

int deleteRear(struct Deque *deque)
{
    if (isEmpty(deque))
        return INT_MIN;
    int value = deque->arr[deque->rear];
    deque->rear = (deque->rear - 1 + deque->capacity) % deque->capacity;
    deque->size--;
    return value;
}

// Structure for Circular Queue
struct CircularQueue
{
    int *arr;
    int front, rear, size, capacity;
};

struct CircularQueue *createQueue(int capacity)
{
    struct CircularQueue *queue = (struct CircularQueue *)malloc(sizeof(struct CircularQueue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->arr = (int *)malloc(capacity * sizeof(int));
    return queue;
}

bool isQueueFull(struct CircularQueue *queue) { return queue->size == queue->capacity; }
bool isQueueEmpty(struct CircularQueue *queue) { return queue->size == 0; }

void enqueue(struct CircularQueue *queue, int value)
{
    if (isQueueFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->arr[queue->rear] = value;
    queue->size++;
}

int dequeue(struct CircularQueue *queue)
{
    if (isQueueEmpty(queue))
        return INT_MIN;
    int value = queue->arr[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return value;
}

// Stack using Two Queues
struct QueueStack
{
    struct CircularQueue *q1, *q2;
};

struct QueueStack *createStack(int capacity)
{
    struct QueueStack *stack = (struct QueueStack *)malloc(sizeof(struct QueueStack));
    stack->q1 = createQueue(capacity);
    stack->q2 = createQueue(capacity);
    return stack;
}

void push(struct QueueStack *stack, int value)
{
    enqueue(stack->q2, value);
    while (!isQueueEmpty(stack->q1))
    {
        enqueue(stack->q2, dequeue(stack->q1));
    }
    struct CircularQueue *temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;
}

int pop(struct QueueStack *stack)
{
    if (isQueueEmpty(stack->q1))
        return INT_MIN;
    return dequeue(stack->q1);
}

// Function to detect cycle in an undirected graph using BFS
bool isCyclic(int V, int adj[V][V])
{
    int parent[V], visited[V];
    for (int i = 0; i < V; i++)
    {
        parent[i] = -1;
        visited[i] = 0;
    }
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            int queue[V], front = 0, rear = 0;
            queue[rear++] = i;
            while (front < rear)
            {
                int u = queue[front++];
                for (int v = 0; v < V; v++)
                {
                    if (adj[u][v])
                    {
                        if (!visited[v])
                        {
                            visited[v] = 1;
                            queue[rear++] = v;
                            parent[v] = u;
                        }
                        else if (parent[u] != v)
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

// Additional methods for other problems can be implemented here

int main()
{
    struct Deque *deque = createDeque(5);
    insertFront(deque, 10);
    insertRear(deque, 20);
    printf("Deque Front: %d\n", deleteFront(deque));
    printf("Deque Rear: %d\n", deleteRear(deque));

    struct CircularQueue *queue = createQueue(5);
    enqueue(queue, 30);
    printf("Dequeued: %d\n", dequeue(queue));

    struct QueueStack *stack = createStack(5);
    push(stack, 40);
    printf("Popped: %d\n", pop(stack));

    return 0;
}
