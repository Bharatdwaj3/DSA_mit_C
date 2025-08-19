// dp_patterns.c
// Large collection of DP pattern implementations (C).
// Compile: gcc -O2 -std=c11 dp_patterns.c -o dp_patterns
// Run: ./dp_patterns

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

// 1) Fibonacci (iterative)
long long fib(int n)
{
    if (n <= 1)
        return n;
    long long a = 0, b = 1;
    for (int i = 2; i <= n; ++i)
    {
        long long c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// 2) Tribonacci (T0=0, T1=1, T2=1 typical)
long long trib(int n)
{
    if (n == 0)
        return 0;
    if (n <= 2)
        return 1;
    long long a = 0, b = 1, c = 1;
    for (int i = 3; i <= n; ++i)
    {
        long long d = a + b + c;
        a = b;
        b = c;
        c = d;
    }
    return c;
}

// 3) Lucas numbers (L0=2, L1=1)
long long lucas(int n)
{
    if (n == 0)
        return 2;
    if (n == 1)
        return 1;
    long long a = 2, b = 1;
    for (int i = 2; i <= n; ++i)
    {
        long long c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// 4) Climbing Stairs (1 or 2 steps)
int climbStairs(int n)
{
    if (n <= 1)
        return 1;
    int *dp = malloc((n + 1) * sizeof(int));
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i)
        dp[i] = dp[i - 1] + dp[i - 2];
    int ans = dp[n];
    free(dp);
    return ans;
}

// 5) Climbing Stairs with 3 Moves (1,2,3)
int climbStairs3(int n)
{
    if (n == 0)
        return 1;
    int *dp = calloc(n + 1, sizeof(int));
    dp[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = (i - 1 >= 0 ? dp[i - 1] : 0) + (i - 2 >= 0 ? dp[i - 2] : 0) + (i - 3 >= 0 ? dp[i - 3] : 0);
    }
    int ans = dp[n];
    free(dp);
    return ans;
}

// 6) Weighted Climbing Stairs (max sum path with steps 1 or 2), arr of weights of steps 1..n
long long weightedClimbMax(int n, long long weights[])
{
    if (n == 0)
        return 0;
    if (n == 1)
        return weights[1];
    long long *dp = malloc((n + 1) * sizeof(long long));
    dp[0] = 0;
    dp[1] = weights[1];
    for (int i = 2; i <= n; ++i)
        dp[i] = weights[i] + ((dp[i - 1] > dp[i - 2]) ? dp[i - 1] : dp[i - 2]);
    long long ans = dp[n];
    free(dp);
    return ans;
}

// 7) Maximum Segments (maximize number of pieces of lengths a,b,c to cut length n)
int maxSegments(int n, int a, int b, int c)
{
    int *dp = malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; ++i)
        dp[i] = INT_MIN / 2;
    dp[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (i - a >= 0)
            dp[i] = (dp[i] > 1 + dp[i - a]) ? dp[i] : 1 + dp[i - a];
        if (i - b >= 0)
            dp[i] = (dp[i] > 1 + dp[i - b]) ? dp[i] : 1 + dp[i - b];
        if (i - c >= 0)
            dp[i] = (dp[i] > 1 + dp[i - c]) ? dp[i] : 1 + dp[i - c];
    }
    int ans = dp[n] < 0 ? 0 : dp[n];
    free(dp);
    return ans;
}

// 8) nth Catalan number (DP) - careful with overflow; using long long
long long catalan(int n)
{
    long long *cat = calloc(n + 1, sizeof(long long));
    cat[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        cat[i] = 0;
        for (int j = 0; j < i; ++j)
            cat[i] += cat[j] * cat[i - 1 - j];
    }
    long long ans = cat[n];
    free(cat);
    return ans;
}

// 9) Count Unique BSTs = Catalan(n) (wrap)
long long countUniqueBSTs(int n) { return catalan(n); }

// 10) Count valid parentheses configurations for n pairs = Catalan(n)
long long countValidParentheses(int pairs) { return catalan(pairs); }

// 11) Min sum in triangle (triangle given as array of arrays heights rows)
int minTriangleSum(int rows, int **tri)
{
    // bottom-up DP modifying last row
    int *dp = malloc(rows * sizeof(int));
    for (int j = 0; j < rows; ++j)
        dp[j] = tri[rows - 1][j];
    for (int i = rows - 2; i >= 0; --i)
    {
        for (int j = 0; j <= i; ++j)
        {
            int down = dp[j];
            int diag = dp[j + 1];
            dp[j] = tri[i][j] + ((down < diag) ? down : diag);
        }
    }
    int ans = dp[0];
    free(dp);
    return ans;
}

// 12) Minimum perfect squares (classic DP)
int minPerfectSquares(int n)
{
    int *dp = malloc((n + 1) * sizeof(int));
    dp[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = INT_MAX / 2;
        for (int s = 1; s * s <= i; ++s)
            dp[i] = (dp[i] < 1 + dp[i - s * s]) ? dp[i] : 1 + dp[i - s * s];
    }
    int ans = dp[n];
    free(dp);
    return ans;
}

// 13) Ways to partition a set (Bell numbers using Bell triangle)
long long bellNumber(int n)
{
    long long *bell_prev = calloc(n + 1, sizeof(long long));
    long long *bell_cur = calloc(n + 1, sizeof(long long));
    bell_prev[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        bell_cur[0] = bell_prev[i - 1];
        for (int j = 1; j <= i; ++j)
            bell_cur[j] = bell_cur[j - 1] + bell_prev[j - 1];
        // copy
        for (int j = 0; j <= i; ++j)
            bell_prev[j] = bell_cur[j];
    }
    long long ans = bell_prev[0];
    free(bell_prev);
    free(bell_cur);
    return ans;
}

// 14) Binomial Coefficient nCr via DP (Pascal)
long long nCr(int n, int r)
{
    if (r < 0 || r > n)
        return 0;
    long long *row = calloc(r + 1, sizeof(long long));
    row[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = (i < r ? i : r); j > 0; --j)
            row[j] = row[j] + row[j - 1];
    }
    long long ans = row[r];
    free(row);
    return ans;
}

// 15) Nth row of Pascal triangle (0-indexed)
long long *pascalRow(int n)
{
    long long *row = calloc(n + 1, sizeof(long long));
    row[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i; j > 0; --j)
            row[j] = row[j] + row[j - 1];
    }
    return row; // caller must free
}

// 16) House Robber (max non-adjacent sum)
long long houseRobber(int n, long long arr[])
{
    if (n == 0)
        return 0;
    if (n == 1)
        return arr[0];
    long long incl = arr[0], excl = 0;
    for (int i = 1; i < n; ++i)
    {
        long long new_excl = (incl > excl) ? incl : excl;
        incl = excl + arr[i];
        excl = new_excl;
    }
    return (incl > excl) ? incl : excl;
}

// 17) Min cost path in grid (assuming only right & down) - m x n grid
int minCostPath(int r, int c, int cost[r][c])
{
    int dp[r][c];
    dp[0][0] = cost[0][0];
    for (int j = 1; j < c; ++j)
        dp[0][j] = dp[0][j - 1] + cost[0][j];
    for (int i = 1; i < r; ++i)
        dp[i][0] = dp[i - 1][0] + cost[i][0];
    for (int i = 1; i < r; ++i)
        for (int j = 1; j < c; ++j)
            dp[i][j] = cost[i][j] + ((dp[i - 1][j] < dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1]);
    return dp[r - 1][c - 1];
}

// 18) Decode Ways (count decodings of digit string, '1'->A ... '26'->Z)
int decodeWays(const char *s)
{
    int n = strlen(s);
    if (n == 0)
        return 0;
    int *dp = calloc(n + 1, sizeof(int));
    dp[0] = 1; // empty string
    for (int i = 1; i <= n; ++i)
    {
        // single digit
        if (s[i - 1] != '0')
            dp[i] += dp[i - 1];
        // two digits
        if (i >= 2)
        {
            int tens = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (tens >= 10 && tens <= 26)
                dp[i] += dp[i - 2];
        }
    }
    int ans = dp[n];
    free(dp);
    return ans;
}

// 19) Subset Sum problem: existence (classic) + count ways
bool subsetSumExists(int n, int arr[], int sum)
{
    bool *dp = calloc(sum + 1, sizeof(bool));
    dp[0] = true;
    for (int i = 0; i < n; ++i)
    {
        for (int s = sum; s >= arr[i]; --s)
            dp[s] = dp[s] || dp[s - arr[i]];
    }
    bool ans = dp[sum];
    free(dp);
    return ans;
}
long long subsetSumCount(int n, int arr[], int sum)
{
    long long *dp = calloc(sum + 1, sizeof(long long));
    dp[0] = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int s = sum; s >= arr[i]; --s)
            dp[s] += dp[s - arr[i]];
    }
    long long ans = dp[sum];
    free(dp);
    return ans;
}

// 20) Coin change - count ways (unlimited coins)
long long coinChangeCount(int coins[], int m, int sum)
{
    long long *dp = calloc(sum + 1, sizeof(long long));
    dp[0] = 1;
    for (int i = 0; i < m; ++i)
    {
        for (int s = coins[i]; s <= sum; ++s)
            dp[s] += dp[s - coins[i]];
    }
    long long ans = dp[sum];
    free(dp);
    return ans;
}

// 21) Coin Change – Minimum Coins to Make Sum
int coinChangeMinCoins(int coins[], int m, int sum)
{
    int *dp = malloc((sum + 1) * sizeof(int));
    for (int i = 0; i <= sum; ++i)
        dp[i] = INT_MAX / 2;
    dp[0] = 0;
    for (int i = 1; i <= sum; ++i)
    {
        for (int j = 0; j < m; ++j)
            if (coins[j] <= i)
                dp[i] = (dp[i] < 1 + dp[i - coins[j]]) ? dp[i] : 1 + dp[i - coins[j]];
    }
    int ans = dp[sum];
    free(dp);
    return (ans >= INT_MAX / 2) ? -1 : ans;
}

// 22) 0/1 Knapsack (values[], weights[], n items, capacity W)
int knap01(int W, int n, int weights[], int values[])
{
    int *dp = calloc(W + 1, sizeof(int));
    for (int i = 0; i < n; ++i)
    {
        for (int w = W; w >= weights[i]; --w)
            dp[w] = (dp[w] > dp[w - weights[i]] + values[i]) ? dp[w] : dp[w - weights[i]] + values[i];
    }
    int ans = dp[W];
    free(dp);
    return ans;
}

// 23) Unbounded Knapsack
int unboundedKnapsack(int W, int n, int weights[], int values[])
{
    int *dp = calloc(W + 1, sizeof(int));
    for (int w = 0; w <= W; ++w)
    {
        for (int i = 0; i < n; ++i)
            if (weights[i] <= w)
                dp[w] = (dp[w] > dp[w - weights[i]] + values[i]) ? dp[w] : dp[w - weights[i]] + values[i];
    }
    int ans = dp[W];
    free(dp);
    return ans;
}

// 24) Jump Game (can reach last index)
bool canJump(int *nums, int n)
{
    int reach = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i > reach)
            return false;
        reach = (reach > i + nums[i]) ? reach : i + nums[i];
    }
    return true;
}

// 25) Longest Common Subsequence (LCS) - returns length
int lcs(const char *a, const char *b)
{
    int n = strlen(a), m = strlen(b);
    int **dp = malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; ++i)
    {
        dp[i] = calloc(m + 1, sizeof(int));
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
    int ans = dp[n][m];
    for (int i = 0; i <= n; ++i)
        free(dp[i]);
    free(dp);
    return ans;
}

// 26) Longest Increasing Subsequence (O(n^2) DP)
int lis(int arr[], int n)
{
    if (n == 0)
        return 0;
    int *dp = malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
        dp[i] = 1;
    int best = 1;
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
            if (arr[j] < arr[i])
            {
                if (dp[j] + 1 > dp[i])
                    dp[i] = dp[j] + 1;
            }
        if (dp[i] > best)
            best = dp[i];
    }
    free(dp);
    return best;
}

// 27) Edit Distance (Levenshtein)
int editDistance(const char *a, const char *b)
{
    int n = strlen(a), m = strlen(b);
    int **dp = malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; ++i)
    {
        dp[i] = malloc((m + 1) * sizeof(int));
    }
    for (int i = 0; i <= n; ++i)
        dp[i][0] = i;
    for (int j = 0; j <= m; ++j)
        dp[0][j] = j;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
            {
                int ins = dp[i][j - 1] + 1;
                int del = dp[i - 1][j] + 1;
                int rep = dp[i - 1][j - 1] + 1;
                dp[i][j] = ins < del ? (ins < rep ? ins : rep) : (del < rep ? del : rep);
            }
        }
    int ans = dp[n][m];
    for (int i = 0; i <= n; ++i)
        free(dp[i]);
    free(dp);
    return ans;
}

// ---- main: quick tests for several functions ----
int main()
{
    printf("---- DP Patterns Collection (sample outputs) ----\n");

    // Fibonacci
    printf("fib(10) = %lld\n", fib(10)); // 55

    // Tribonacci
    printf("trib(10) = %lld\n", trib(10)); // example

    // Lucas
    printf("lucas(10) = %lld\n", lucas(10));

    // Climbing stairs
    printf("climbStairs(10) = %d\n", climbStairs(10));
    printf("climbStairs3(10) = %d\n", climbStairs3(10));

    // Weighted climb (example weights index from 1..n)
    int n = 5;
    long long weightsArr[] = {0, 2, 3, 1, 5, 4}; // ignore index 0
    printf("weightedClimbMax(n=5) = %lld\n", weightedClimbMax(5, weightsArr));

    // Max segments
    printf("maxSegments(23, 11,9,12) = %d\n", maxSegments(23, 11, 9, 12));

    // Catalan
    printf("catalan(10) = %lld\n", catalan(10));

    // Min triangle sum - example
    int rows = 4;
    int *tri[4];
    int t0[] = {2};
    int t1[] = {3, 4};
    int t2[] = {6, 5, 7};
    int t3[] = {4, 1, 8, 3};
    tri[0] = t0;
    tri[1] = t1;
    tri[2] = t2;
    tri[3] = t3;
    printf("minTriangleSum(example) = %d\n", minTriangleSum(4, tri));

    // Min perfect squares
    printf("minPerfectSquares(12) = %d\n", minPerfectSquares(12));

    // Bell numbers
    printf("bellNumber(5) = %lld\n", bellNumber(5)); // partitions of set size 5

    // nCr
    printf("nCr(10,3) = %lld\n", nCr(10, 3));

    // Pascal row 5
    long long *prow = pascalRow(5);
    printf("pascalRow(5): ");
    for (int i = 0; i <= 5; ++i)
        printf("%lld ", prow[i]);
    printf("\n");
    free(prow);

    // House Robber
    long long houses[] = {6, 7, 1, 30, 8, 2, 4};
    printf("houseRobber = %lld\n", houseRobber(7, houses));

    // Min cost path
    int cost[3][3] = {{1, 2, 3}, {4, 8, 2}, {1, 5, 3}};
    printf("minCostPath 3x3 = %d\n", minCostPath(3, 3, cost));

    // Decode ways
    printf("decodeWays(\"226\") = %d\n", decodeWays("226")); // 3

    // Subset sum
    int arr[] = {3, 34, 4, 12, 5, 2};
    printf("subsetSumExists -> sum=9 : %s\n", subsetSumExists(6, arr, 9) ? "true" : "false");
    printf("subsetSumCount -> sum=9 : %lld\n", subsetSumCount(6, arr, 9));

    // Coin change count/min
    int coins[] = {1, 2, 5};
    printf("coinChangeCount sum=11 = %lld\n", coinChangeCount(coins, 3, 11));
    printf("coinChangeMinCoins sum=11 = %d\n", coinChangeMinCoins(coins, 3, 11));

    // 0/1 knapsack
    int vals[] = {60, 100, 120}, wts[] = {10, 20, 30};
    printf("0/1 knap W=50 = %d\n", knap01(50, 3, wts, vals));

    // Unbounded knapsack
    printf("unbounded knap W=100 = %d (example)\n", unboundedKnapsack(100, 3, wts, vals));

    // Jump game
    int jumps[] = {2, 3, 1, 1, 4};
    printf("canJump [2,3,1,1,4] = %s\n", canJump(jumps, 5) ? "true" : "false");

    // LCS
    printf("lcs(\"AGGTAB\",\"GXTXAYB\") = %d\n", lcs("AGGTAB", "GXTXAYB")); // 4

    // LIS
    int seq[] = {10, 9, 2, 5, 3, 7, 101, 18};
    printf("lis = %d\n", lis(seq, 8));

    // Edit distance
    printf("editDistance(\"sunday\",\"saturday\") = %d\n", editDistance("sunday", "saturday"));

    printf("---- End of sample outputs ----\n");
    return 0;
}
