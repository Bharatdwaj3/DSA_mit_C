#include<stdio.h>
#include<limits.h>
#include<stdbool.h>

#define V 5

int minKey(int key[], bool mstSet[]){
    int min=INT_MAX, minIdx;
    for(int v=0;v<V;v++)
        if((!mstSet[v] && key[v] < min))
            min=key[v], minIdx=v;
    return minIdx;
}

void primMST(int graph[V][V]){
    int parent[V];
    int key[V];
    bool mstSet[V];

    for(int i=0;i<V;i++)
        key[i]=INT_MAX, mstSet[i]=false;
    key[0]=0;
    parent[0]=-1;

    for(int count=0;count<V-1;count++){
        int u=minKey(key, mstSet);
        mstSet[u]=true;
        for(int v=0;v<V;v++)
            if(graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                parent[v]=u, key[v]=graph[u][v];
    }
    printf("Edge \tWeight\n");
    for(int i=1;i<V;i++)
        printf("%d=%d \t%d\n", parent[i], i, graph[i][parent[i]]);
    
}