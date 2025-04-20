#include <stdio.h>

#define INF 99999
#define V 4

void floydWarshall(int graph[V][V])
{
    int dist[V][V], i, j, k;

    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    for (k = 0; k < V; k++)
        for (i = 0; i < V; i++)
            for (j = 0; j < V; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    printf("Shortest distance matrix:\n");
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
            printf("%4d ", (dist[i][j] == INF) ? -1 : dist[i][j]);
        printf("\n");
    }
}

int main()
{
    int graph[V][V] = {{0, 3, INF, 7}, {8, 0, 2, INF}, {5, INF, 0, 1}, {2, INF, INF, 0}};
    floydWarshall(graph);
    return 0;
}
