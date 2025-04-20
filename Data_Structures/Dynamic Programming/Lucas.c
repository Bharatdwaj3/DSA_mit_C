
#include <stdio.h>

int lucas(int n) {
    int dp[n+1];
    dp[0] = 2, dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}

int main() {
    int n = 10;
    printf("Lucas(%d) = %d\n", n, lucas(n));
    return 0;
}