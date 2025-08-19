#include<stdio.h>
#include<stdlib.h>

#define MAX 100 

typedef struct{
    int src, dest, weight;
}Edge;

typedef struct{
    int V, E;
    Edge edges[MAX];
}Graph;

int parent[MAX];

int find(int i){
    if (parent[i]==-1)
        return i;
    return parent[i] =find(parent[i]);
}

void unionSet(int x, int y){
    parent[find(x)]=find(y);
}

int compareEdges(const void*a, const void *b){
    return ((Edge*)a)->weight-((Edge*)b)->weight;
}

void kruskal(Graph *g){
    qsort(g->edges, g->E, sizeof(Edge), compareEdges);
    for(int i=0;i<g->V;i++)
        parent[i]=-1;
    printf("Minimum spanning Tree Edges:\n");
    int count=0;
    for(int i=0;i<g->E;i++){
        if(find(g->edges[i].src)!=find(g->edges[i].dest)){
            printf("Edge %d-%d (%d)\n", g->edges[i].src, g->edges[i].dest, g->edges[i].weight);
            unionSet(g->edges[i].src, g->edges[i].dest);
            count++;
            if(count == g->V-1)
                break;
        }
    }
}