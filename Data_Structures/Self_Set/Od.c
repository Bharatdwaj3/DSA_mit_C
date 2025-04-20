#include<stdio.h>
#include<limits.h>
#include<stdbool.h>

#define V 9

int minDistance(int dist[],bool s_path[]){
    int min=INT_MAX,min_index;
    for(int v=0;v<V;v++)
        if(!s_path[v]&&dist[v]<=min)
            min=dist[v],min_index=v;
    return min_index;
}
int diijkstra(int graph[V][V], int src)
{
    int dist[V];
    bool s_path[V];
    for(int i=0;i<V;i++){
        dist[i] =INT_MAX,s_path[i]=false;
        dist[src]=0; 
    }
    for (int count =0;count<V-1;count++){
        int u=minDistance(dist,s_path);
        s_path[u]=true;
        for(int v=0;v<V;v++){
            if(!s_path[v]&&graph[u][v]&&dist[u]!=INT_MAX&&dist[u]+graph[u][v]<dist[v])
                dist[v]=dist[u]+graph[u][v];
        }
    }
    printf("Vertex \t Distance from the source\n");
    for(int i=0;i<V;i++){
        printf("%d\t%d\n",i,dist[i]);
    }
}

int main(){
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0}, {4, 0, 8, 0, 0, 0, 0, 11, 0}, {0, 8, 0, 7, 0, 4, 0, 0, 2}, {0, 0, 7, 0, 9, 14, 0, 0, 0}, {0, 0, 0, 9, 0, 10, 0, 0, 0}, {0, 0, 4, 14, 10, 0, 2, 0, 0}, {0, 0, 0, 0, 0, 2, 0, 1, 6}, {8, 11, 0, 0, 0, 0, 1, 0, 7}, {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    dijkstra(graph, 0);
    return 0;
}
