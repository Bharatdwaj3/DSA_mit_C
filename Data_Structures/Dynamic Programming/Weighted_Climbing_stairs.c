#include <stdio.h>

int weightedClimb(int weights[], int n) {
    int dp[n+1];
    dp[0] = weights[0], dp[1] = weights[1];
    for (int i = 2; i < n; i++)
        dp[i] = weights[i] + (dp[i-1] < dp[i-2] ? dp[i-1] : dp[i-2]);
    return dp[n-1];
}

int main() {
    int weights[] = {1, 100, 1, 1, 100, 1};
    int n = 6;
    printf("Min cost to climb stairs = %d\n", weightedClimb(weights, n));
    return 0;
}