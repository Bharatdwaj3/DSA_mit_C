#include<string.h>
#include<string.h>
#include<stdlib.h>

#define MOD 1000007
#define MAX_N 100

long long addMod(long long a, long long b){
    return (a+b)%MOD;
}

long long housePainting(int n, int k){
    long long dp[MAX_N][MAX_N];
    memset(dp, 0, sizeof(dp));
    for(int c=0;c<k;c++)
        dp[0][c]=1;
    for(int i=1;i<n;i++){
        for(int c=0;c<k;c++){
            for(int pc=0;pc<k;pc++){
                if(c!=pc)
                dp[i][c]=addMod(dp[i][c], dp[i-1][pc]);
            }
        }
    }
    long long result =0;
    for(int c=0;c<k;c++)
        result=addMod(result, dp[n-1][c]);
    return result;
}

long long fencePainting(int n, int k){
    return housePainting(n, k);
}

long long gridColoring(int m, int n, int k){
    long long dp[MAX_N][MAX_N];
    memset(dp, 0, sizeof(dp));
    for(int c=0;c<k;c++)
        dp[0][0]=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j == 0)
                continue;
            for(int c=0;c<k;c++)
                dp[0][0]=1;
                for(int j=0;j<n;j++){
                    if(i==0&& j==0)
                        continue;
                    for(int c=0;c<k;c++){
                        if(j>0 && c!=dp[i-1][j]) dp[i][j] =addMod(dp[i][j], dp[i-1][j]);
                        if(j>0 && c!=dp[i][j-1]) dp[i][j]=addMod(dp[i][j], dp[i][j-1]);
                    }
                }
        }
        return dp[m-1][n-1];
    }
}

long long circularHousePainting(int n, int k){
    long long dp[MAX_N][MAX_N];
    memset(dp, 0, sizeof(dp));
    for(int c=0;c<k;c++)
        dp[0][c]=1;
    for(int i=1;i<n;i++){
        for(int c=0;c<k;c++){
            for(int pc=0;pc<k;pc++){
                if(c!=pc) dp[i][c]=addMod(dp[i][c], dp[i-1][pc]);
            }
        }
    }
    long long i, result = 0;
    for(int c=0;c<k;c++){
        for(int fc=0;fc<k;fc++){
            if(c!=fc && (i==n-1 ? c!=dp[0][fc] : 1)) result =addMod(result, dp[n-1][c]);
        }
    }
    return result;
}

long long treeColoring(int n, int k){
    return housePainting(n, k);
}

int graphColoring(int n, int k){
    return 1;
}

long long binaryTreeColoring(int n, int k){
    return housePainting(n, k);
}

long long pathColoring(int n, int k){
    return housePainting(n, k);
}

long long cycleGraphColoring(int n, int k){
    return circularHousePainting(n, k);
}

long long tilingWithColors(int n, int k){
    return housePainting(n, k);
}

long long ringColoring(int n, int k){
    return 
}