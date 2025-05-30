#include <stdio.h>

int tribonacci(int n) {
    int dp[n+1];
    dp[0] = 0, dp[1] = 1, dp[2] = 1;
    for (int i = 3; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    return dp[n];
}

int main() {
    int n = 10;
    printf("Tribonacci(%d) = %d\n", n, tribonacci(n));
    return 0;
}