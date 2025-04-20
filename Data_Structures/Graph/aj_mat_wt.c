#include <stdio.h>

#define V 4

void printAdjMatrix(int graph[V][V])
{
    printf("Weighted Adjacency Matrix:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int graph[V][V] = {
        {0, 5, 0, 0}, 
        {5, 0, 3, 2},
        {0, 3, 0, 4}, 
        {0, 2, 4, 0} 
    };

    printAdjMatrix(graph);
    return 0;
}
