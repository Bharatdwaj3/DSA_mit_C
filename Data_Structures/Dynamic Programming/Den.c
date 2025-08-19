#include<stdio.h>
#include<limits.h>
#include<string.h>
#include<stdbool.h>

#define MIN(a,b)((a)<(b)?(a):(b))
#define MAX(a, b)((a)>(b)) ? ((a):(b))
#define MIN3(a,b,c)(MIN(MIN(a,b),c))
#define MAX3(a, b, c) (MAX(MAX(a,b),c))
#define MOD 1000000007

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
    for(int j=0;j<n;j++)
        dp[0][j]=1;
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
            if(grid[i][j]==1)
                dp[i][j]=0;
            else if(i==0 && j == 0)
                continue;
            else{
                int up=(i>0)?dp[i-1][j]:0;
                int left=(j>0) ? dp[i][j-1]:0;
                dp[i][j]=up+left;
            }
        }
    }
    return dp[m-1][n-1];
}

int calculateMinimumHP(int **dungeon, int m, int n){
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
        for(int j=0;j<=n;j++)
            dp[i][j]=INT_MAX;
    dp[m][n-1]=dp[m-1][n]=1;
    for(int i=m-1;i>=0;i--){
        for(int j = n-1;j>=0;j--){
            int need = MIN(dp[i+1][j], dp[i][j+1])-dungeon[i][j];
            dp[i][j] = MAX(1, need);
        }
    }
    return dp[0][0];
}

int cherryPickupHelper(int **grid, int n,int x1,  int y1, int x2, int dp[n][n][n]){
    int y2=x1+y1-x2;
    if(x1 >= n || y1 >= n || x2 >= n || y2 >= n || grid[x1][y1] == -1 || grid[x2][y2]==-1)
        return INT_MIN /2;
    if(x1==n-1 && y1 == n-1)
        return grid[x1][y1];
    if(dp[x1][y1][x2] != INT_MIN)
        return dp[x1][y2][x2];
    int cherries = (x1==x2 && y1 == y2) ? grid[x1][y1] : grid[x1][y1] + grid[x2][y2];
    int best =MAX(
        MAX(cherryPickupHelper(grid, n, x1+1, x2+1, dp),
            cherryPickupHelper(grid, n, x1, y1+1, x2, dp)),
        MAX(cherryPickupHelper(grid, n, x1+1, y1, x2, dp),
            cherryPickupHelper(grid, n, x1, y1 + 1, x2 + 1, dp)));
        cherries += best;
        dp[x1][y1][x2]=cherries;
        return cherries;
}

int cherryPickup(int **grid, int n){
    static int dp[50][50][50];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                dp[i][j][k]=INT_MIN;
    return MAX(0, cherryPickupHelper(grid, n, 0, 0, dp));
}

int cherryPickupIIHelper(int **grid, int m, int n, int row, int c1, int c2, int dp[m][n][n]){
    if(c1 < 0 || c2<0 || c1 >= n ||  c2 >= n)
        return INT_MIN/2;
    if(row == m)
        return 0;
    if(dp[row][c1][c2] != INT_MIN)
        return dp[row][c1][c2];
        
}