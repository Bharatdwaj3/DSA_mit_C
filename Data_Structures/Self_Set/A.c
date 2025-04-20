#include<stdio.h>
#include<stdlib.h>

#define N 3

int main(){

    int adj_mat[N][N]={0};

    adj_mat[0][1] = 1;
    adj_mat[0][2] = 1;

    adj_mat[1][0] = 1;
    adj_mat[1][2] = 1;

    adj_mat[2][0] = 1;
    adj_mat[2][1] = 1;

    printf("Adjacency Matrix:\n");
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d ",adj_mat[i][j]);
        }
        printf("\n");
    }

    printf("Adjacency Matrix:\n");
    for (int i = 0; i < N; i++)
    { 
          printf("Vertex %d: ",i);
        for (int j = 0; j < N; j++)
        {
            if(adj_mat[i][j]==1){
                printf("%d ",j);
            }
        }
        printf("\n");
    }

    return 0;
}