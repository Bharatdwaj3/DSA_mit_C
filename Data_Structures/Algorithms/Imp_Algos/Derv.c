#include<stdio.h>

#define INF 999999
#define V 4

void floydWarshall(int graph[V][V]){
    int dist[V][V], i, j, k;
    for(i=0;i<V;i++)
        for(j=0;j<V;j++)
            dist[i][j]=graph[i][j];
    for(k=0;k<V;k++)
        for(i=0;i<V;i++)
            for(j=0;j<V;j++)
            if(dist[i][k]+dist[k][j] < dist[i][j])
                dist[i][j]=dist[i][k]+dist[k][j];
    printf("Shortest distance matrix: \n");
    for(i=0;i<V;i++){
        for(j=0;j<V;j++){
            printf("%d",(dist[i][j]==INF) ? -1 : dist[i][j]);
        }
        printf("\n");
    }
}

