#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 5

void dfs(int graph[V][V], int v, bool visited[], int stack[])
{
    visited[v] = true;
    for (int i = 0; i < V; i++)
    {
        if (graph[v][i] && !visited[i])
        {
            dfs(graph, i, visited, stack);
        }
    }
    stack[v] = 1;
}

void reverseDFS(int graph[V][V], int v, bool visited[])
{
    visited[v] = true;
    printf("%d ", v);
    for (int i = 0; i < V; i++)
    {
        if (graph[v][i] && !visited[i])
        {
            reverseDFS(graph, i, visited);
        }
    }
}

void kosaraju(int graph[V][V])
{
    bool visited[V] = {false};
    int stack[V] = {0};

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(graph, i, visited, stack);
        }
    }

    int transposedGraph[V][V] = {0};
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            transposedGraph[i][j] = graph[j][i];
        }
    }

    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    for (int i = V - 1; i >= 0; i--)
    {
        if (!visited[i])
        {
            reverseDFS(transposedGraph, i, visited);
            printf("\n");
        }
    }
}

int main()
{
    int graph[V][V] = {
        {0, 1, 0, 0, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {0, 0, 0, 1, 0}};
    kosaraju(graph);
    return 0;
}
