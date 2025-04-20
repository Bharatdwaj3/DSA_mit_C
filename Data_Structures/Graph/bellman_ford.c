#include <stdio.h>
#include <limits.h>

#define V 5
#define E 8

typedef struct
{
    int u, v, weight;
} Edge;

void bellmanFord(Edge edges[], int src)
{
    int dist[V];
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    for (int i = 1; i < V; i++)
    {
        for (int j = 0; j < E; j++)
        {
            if (dist[edges[j].u] != INT_MAX && dist[edges[j].u] + edges[j].weight < dist[edges[j].v])
            {
                dist[edges[j].v] = dist[edges[j].u] + edges[j].weight;
            }
        }
    }

    for (int i = 0; i < E; i++)
    {
        if (dist[edges[i].u] != INT_MAX && dist[edges[i].u] + edges[i].weight < dist[edges[i].v])
        {
            printf("Negative weight cycle detected\n");
            return;
        }
    }

    printf("Vertex Distance from Source:\n");
    for (int i = 0; i < V; i++)
    {
        printf("Vertex %d: %d\n", i, dist[i]);
    }
}

int main()
{
    Edge edges[E] = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2}, {3, 1, 1}, {3, 2, 5}, {4, 3, -3}};
    bellmanFord(edges, 0);
    return 0;
}
