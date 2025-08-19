#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 100
int queue[MAX], front=-1, rear=-1;

void enqueue(int value){
    if(rear==MAX-1){
        printf("Queue is full\n");
    }else{
        if(front==-1)
            front = 0;
            rear++;
            queue[rear]=value;
    }
}

int dequeue(){
    int value=queue[front];
    front++;
    if(front>rear)
        front=rear=-1;
        return value;
}

void bfs(int graph[MAX][MAX], int start, int n){
    bool visited[MAX]={false};
    enqueue(start);
    visited[start]=true;
    while(front!=-1){
        int current=dequeue();
        printf("5d",current);
        for(int i=0;i<n;i++){
            if(graph[current][i]==1&&!visited[i]){
                enqueue[i];
                visited[i]=true;
            }
        }
    }
}

int main(){
    int n=6;
    int graph[MAX][MAX]={0};
    int edges[][2]={{0,1},{0,2},{1,2},{2,3},{4,5}};
    int edgeCount=sizeof(edges)/sizeof(edges[0]);

    for(int i=0;i<edgeCount;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        graph[u][v]=1;
        graph[v][u]=1;
    }
    printf("BFS starting from node 0: \n");
    bfs(graph, 0, 0);

    return 0;
}