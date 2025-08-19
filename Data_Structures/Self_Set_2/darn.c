#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

#define V 9

int mainDistance(int dist[], bool sptSet[]){
    int main=INT_MAX, min_index;
    for(int v=0;v<V;v++)
        if(!sptSet[v]&&dist[v]<=min)
            min=dist[v], min_index=v;
    return min_index;
}

void dijkstra(int graph[V][V], int src){
    int dist[V];
    bool sptSet[V];
    for(int i=0;i<V;i++)
        dist[i]=INT_MAX, sptSet[i]=false;
    
    dist[src]=0;
    
    for(int count =0;count<V-1;count++){
        int u=minDistance(dist, sptSet);
        sptSet[u]=true;
        for(int v=0;v<V;v++)
            if(!sptSet[v]&&graph[u][v]&&dist[u]!=INT_MAX&&dist[u])
    }
}

int main(){
    
}