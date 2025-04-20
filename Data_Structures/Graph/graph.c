#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 3

int main()
{
    // Create a 3x3 adjacency matrix, initialized to 0 (no edges)
    int adjMatrix[MAX_VERTICES][MAX_VERTICES] = {0};

    // Add edges to the graph
    adjMatrix[0][1] = 1; // Edge between vertex 0 and 1
    adjMatrix[1][0] = 1; // Undirected graph, so also mark edge 1-0
    adjMatrix[1][2] = 1; // Edge between vertex 1 and 2
    adjMatrix[2][1] = 1; // Undirected graph, so also mark edge 2-1

    // Print the adjacency matrix
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        for (int j = 0; j < MAX_VERTICES; j++)
        {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    // Print the adjacency list representation (based on the adjacency matrix)
    printf("\nAdjacency List:\n");
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        printf("Vertex %d: ", i);
        for (int j = 0; j < MAX_VERTICES; j++)
        {
            if (adjMatrix[i][j] == 1)
            {
                printf("%d ", j);
            }
        }
        printf("\n");
    }

    return 0;
}
