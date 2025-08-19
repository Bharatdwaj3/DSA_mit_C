#include<stdio.h>
#include<stdlib.h>

#define MIN(a,b) ((a)<(b) ? (a) : (b))

int minPathSum(int grid[][100], int m, int n){
    int dp[100][100];
    dp[0][0]=grid[0][0];

    for(int j=1;j<n;j++)
        dp[0][j]=dp[j-1][0]+dp[j][0];
    for (int i = 1; i < n; i++)
        dp[i][0] = dp[i - 1][0] + dp[i][0];
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            dp[i][j]=grid[i][j]+MIN(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m-1][n-1];
}

int uniquePaths(int m, int n){
    int dp[100][100];
    for(int i=0;i<m;i++)
        dp[i][0]=1;
    for(int j=0;j<n;j++)
        dp[0][j]=1;
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

int uniquePathWithObstacles(int grid[][100], int m, int n){
    int dp[100][100];
    dp[0][0]=grid[0][0] == 0 ? 1 : 0;

    for(int j=1;j<n;j++)
        dp[0][j]=(grid[0][j]==0) ? dp[0][j-1] : 0;
}

int main(){

    int grid[3][100]={{1,3,1},{1,5,1},{4,2,1}};

    printf("Min Path Sum = %d\n",minPathSum(grid, 3, 3));
    printf("Unique Paths = %d\n",uniquePaths(3,7));
    
    
    return 0;
}