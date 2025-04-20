#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int graph[MAX][MAX], visited[MAX];
int n;

void DFS(int vertex)
{
    printf("%d ", vertex);
    visited[vertex] = 1;

    for (int i = 0; i < n; i++)
    {
        if (graph[vertex][i] == 1 && !visited[i])
        {
            DFS(i);
        }
    }
}

int main()
{
    int edges, u, v;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Initialize the graph
    for (int i = 0; i < edges; i++)
    {
        printf("Enter the edge (u v): ");
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // Assuming an undirected graph
    }

    printf("DFS starting from vertex 0: ");
    DFS(0);

    return 0;
}
