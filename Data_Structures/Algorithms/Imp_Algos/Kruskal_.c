#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int src, dest, weight;
} Edge;

typedef struct
{
    int V, E;
    Edge edges[MAX];
} Graph;

int parent[MAX];

// Find function for Union-Find
int find(int i)
{
    if (parent[i] == -1)
        return i;
    return parent[i] = find(parent[i]); // Path compression
}

// Union function for Union-Find
void unionSet(int x, int y)
{
    parent[find(x)] = find(y);
}

// Comparator function for sorting edges
int compareEdges(const void *a, const void *b)
{
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

void kruskal(Graph *g)
{
    qsort(g->edges, g->E, sizeof(Edge), compareEdges);

    for (int i = 0; i < g->V; i++)
        parent[i] = -1;

    printf("Minimum Spanning Tree Edges:\n");
    int count = 0;
    for (int i = 0; i < g->E; i++)
    {
        if (find(g->edges[i].src) != find(g->edges[i].dest))
        {
            printf("Edge %d-%d (%d)\n", g->edges[i].src, g->edges[i].dest, g->edges[i].weight);
            unionSet(g->edges[i].src, g->edges[i].dest);
            count++;
            if (count == g->V - 1)
                break;
        }
    }
}

int main()
{
    Graph g = {4, 5, {{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}}};
    kruskal(&g);
    return 0;
}
