#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>

#define MAX(a, b)((a) > (b) ? (a) : (b))
#define MIN(a, b)((a) < (b) ? (a) : (b))
#define MIN3(a, b, c)(MIN(MIN(a, b), c))
#define MAX3(a, b, c)(MAX(MAX(a, b), c))



int uniquePath(int m, int n){
    int dp[m][n];
    for(int i=0;i<m;i++){
        dp[i][0]=1;
    }
    for(int j=0;j<n;j++){
        dp[0][j]=1;
    }

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            dp[i][j]=(dp[i-1][j]+dp[i][j-1]);
        }
    }
    return dp[m-1][n-1];
}

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>

#define MAX(a, b)((a) > (b) ? (a) : (b))
#define MIN(a, b)((a) < (b) ? (a) : (b))
#define MIN3(a, b, c)(MIN(MIN(a, b), c))
#define Min3(a, b, c)(MAX(MAX(a, b), c))

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>

#define MAX(a, b)((a) > (b) ? (a) : (b))
#define MIN(a, b)((a) < (b) ? (a) : (b))
#define MIN3(a, b, c)(MIN(MIN(a, b), c))
#define Min3(a, b, c)(MAX(MAX(a, b), c))



int uniquePath(int m, int n){
    int dp[m][n];
    for(int i=0;i<m;i++){
        dp[i][0]=1;
    }
    for(int j=0;j<n;j++){
        dp[0][j]=1;
    }

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            dp[i][j]=(dp[i-1][j]+dp[i][j-1]);
        }
    }
    return dp[m-1][n-1];
}

int TriangularPath(int m, int n){
    int dp[m][n];
    for(int i=0;i<m;i++){
        dp[i][0]=1;
    }
    for(int j=0;j<n;j++){
        dp[0][j]=1;
    }

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            dp[i][j]=(dp[i-1][j]+dp[i][j-1]+dp[i-1][j-1]);
        }
    }
    return dp[m-1][n-1];
}


int MaxPathTriangular(int **grid, int m, int n){
    int dp[m][n];
    dp[0][0]=grid[0][0];

    for(int i=0;i<m;i++){
        dp[i][0]=dp[i-1][0]+grid[i][0];
    }
    for(int j=0;j<n;j++){
        dp[0][j]=dp[0][j-1]+grid[0][j];
    }

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            dp[i][j]=grid[i][j]+MAX3(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]);
        }
    }
    return dp[m-1][n-1];
}

int MinPathTriangular(int **grid, int m, int n){
    int dp[m][n];
    dp[0][0]=grid[0][0];

    for(int i=0;i<m;i++){
        dp[i][0]=dp[i-1][0]+grid[i][0];
    }
    for(int j=0;j<n;j++){
        dp[0][j]=dp[0][j-1]+grid[0][j];
    }

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            dp[i][j]=grid[i][j]+MIN3(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]);
        }
    }
    return dp[m - 1][n - 1];
}
    