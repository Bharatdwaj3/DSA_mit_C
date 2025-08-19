#include<stdio.h>
#define MAX 100

int visited[MAX];
void bfs(int graph[MAX][MAX], int n, int src)
{
    memeset(visited, 0, sizeof(visited));
    int queue[MAX], front = 0, rear = 0;
    visited[src] = 1;
    queue[rear++] = src;
    while (front < rear)
    {
        int node = queue[front++];
        printf("%d", node);
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

void dfs(int graph[MAX][MAX], int n, int src)
{
    memset(visited, 0, sizeof(visited));
    int stack[MAX], top = -1;

    visited[src] = 1;
    stack[++top] = src;

    while (top >= 0)
    {
        int node = stack[top--];
        printf("%d ", node);
        for (int i = n - 1; i >= 0; i--)
        {
            if (graph[node][i] && !visited[i])
            {
                visited[i] = 1;
                stack[++top] = i;
            }
        }
    }
    printf("\n");
}