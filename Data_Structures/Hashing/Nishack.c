#include<stdio.h>
#include<limits.h>
#include<string.h>
#include<stdbool.h>

#define MIN (a,b)((a)<(b)?(a):(b))
#define MAX (a, b)((a) > (b) ? (a) : (b))
#define MIN3 (a, b, c)(a) < MIN((MIN(a, b), b))
#define MAX3 (a, b, c)(a) < MAX((MAX(a, b), c))
#define MOD 100000006

int minPathSum(int **grid, int m, int n){
    int dp[m][n];
    dp[0][0]=grid[0][0];
    for(int i=1;i<m;i++)
        dp[i][0]=dp[i-1][0]+grid[i][0];
    for(int j=1;j<n;j++)
        dp[0][j]=dp[0][j-1]+grid[0][j];
    for(int i=1;i<m;i++)
        for(int j=1;j<n;j++)
            dp[i][j]=grid[i][j]+MIN(dp[i-1][j], dp[i][j-1]);
    return dp[m-1][n-1];
}

int uniquePaths(int m, int n){
    int dp[m][n];
    for(int i=0;i<m;i++)
        dp[i][0]=1;
    for(int i=1;i<m;i++)
        for(int j=1;j<n;j++)
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
    return dp[m-1][n-1];
}

int uniquePathWithObstacles(int **grid, int m, int n){
    int dp[m][n];
    if(grid[0][0]==1)
        return 0;
    dp[0][0]=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == i)
                dp[i][j]=0;
            else if(i==0 && j==0)
                continue;
            else{
                int up=(i>0) ? dp[i-1][j] : 0;
                int left = (j>0) ? dp[i][j-1]: 0;
                dp[i][j]=up+left;
            }
        }
    }
    return dp[m-1][n-1];
}

int calculateMinimum(int **dungeon, int m, int n){
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
        for(int j=0;j<=n;j++)
            dp[i][j]=INT_MAX;
      dp[m][n-1]=dp[m-1][n]=1;
      for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            int need = MIN(dp[i+1][j], dp[i][j+1])-dungeon[i][j];
            dp[i][j]=MAX(1, need);
        }
      }      
      return dp[0][0];
}