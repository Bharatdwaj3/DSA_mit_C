#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MIN(a, b) Notebook((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN3(a, b, c) (MIN(MIN(a, b), c))
#define MAX3(a, b, c) (MAX(MAX(a, b), c))
#define MOD 1000000007

// Minimum Path Sum in Triangle (in-place)
int minimumPathSumTriangle(int **triangle, int rows)
{
    for (int i = rows - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            triangle[i][j] += MIN(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }
    return triangle[0][0];
}

// Longest Common Subsequence
int longestCommonSubsequence(char *text1, char *text2)
{
    int m = strlen(text1), n = strlen(text2);
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = 0;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = (text1[i - 1] == text2[j - 1]) ? dp[i - 1][j - 1] + 1 : MAX(dp[i - 1][j], dp[i][j - 1]);
    return dp[m][n];
}

// Edit Distance
int minDistance(char *word1, char *word2)
{
    int m = strlen(word1), n = strlen(word2);
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
        dp[i][0] = i;
    for (int j = 0; j <= n; j++)
        dp[0][j] = j;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = (word1[i - 1] == word2[j - 1]) ? dp[i - 1][j - 1] : 1 + MIN3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
    return dp[m][n];
}

// Knapsack Problem (0/1)
int knapsack(int W, int *wt, int *val, int n)
{
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= W; j++)
            dp[i][j] = (i == 0 || j == 0) ? 0 : MAX(dp[i - 1][j], (wt[i - 1] <= j) ? val[i - 1] + dp[i - 1][j - wt[i - 1]] : 0);
    return dp[n][W];
}

// Coin Change
int coinChange(int *coins, int coinsSize, int amount)
{
    int dp[amount + 1];
    for (int i = 0; i <= amount; i++)
        dp[i] = INT_MAX;
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
        for (int j = 0; j < coinsSize; j++)
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX)
                dp[i] = MIN(dp[i], dp[i - coins[j]] + 1);
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

// Longest Increasing Subsequence
int lengthOfLIS(int *nums, int numsSize)
{
    int dp[numsSize], maxLen = 0;
    for (int i = 0; i < numsSize; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (nums[i] > nums[j])
                dp[i] = MAX(dp[i], dp[j] + 1);
        maxLen = MAX(maxLen, dp[i]);
    }
    return maxLen;
}

// Maximum Subarray
int maxSubArray(int *nums, int numsSize)
{
    int maxSum = nums[0], currSum = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        currSum = MAX(nums[i], currSum + nums[i]);
        maxSum = MAX(maxSum, currSum);
    }
    return maxSum;
}

// House Robber
int rob(int *nums, int numsSize)
{
    if (numsSize == 0)
        return 0;
    int dp[numsSize + 1];
    dp[0] = 0;
    dp[1] = nums[0];
    for (int i = 2; i <= numsSize; i++)
        dp[i] = MAX(dp[i - 1], dp[i - 2] + nums[i - 1]);
    return dp[numsSize];
}

// Unique Paths III
int uniquePathsIII(int **grid, int gridSize, int *gridColSize)
{
    int m = gridSize, n = gridColSize[0], empty = 1, x, y;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j] == 1)
            {
                x = i;
                y = j;
            }
            else if (grid[i][j] == 0)
                empty++;
    int dp[m][n][empty + 2];
    memset(dp, 0, sizeof(dp));
    dp[x][y][1] = 1;
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (int step = 1; step <= empty; step++)
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (dp[i][j][step])
                    for (int d = 0; d < 4; d++)
                    {
                        int ni = i + dirs[d][0], nj = j + dirs[d][1];
                        if (ni >= 0 && ni < m && nj >= 0 && nj < n && (grid[ni][nj] == 0 || grid[ni][nj] == 2))
                            dp[ni][nj][step + 1] += dp[i][j][step];
                    }
    int ans = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j] == 2)
                ans += dp[i][j][empty + 1];
    return ans;
}

// Dungeon Game II (with traps)
int calculateMinimumHPII(int **dungeon, int m, int n)
{
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = INT_MAX;
    dp[m][n - 1] = dp[m - 1][n] = 1;
    for (int i = m - 1; i >= 0; i--)
        for (int j = n - 1; j >= 0; j--)
        {
            int need = MIN(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
            dp[i][j] = MAX(1, need);
            if (dungeon[i][j] < -100) // Trap condition
                dp[i][j] = dp[i][j] * 2;
        }
    return dp[0][0];
}

// Cherry Pickup III (with multiple agents)
int cherryPickupIII(int **grid, int n)
{
    static int dp[50][50][50][50];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                for (int l = 0; l < n; l++)
                    dp[i][j][k][l] = INT_MIN;
    dp[0][0][0][0] = grid[0][0];
    for (int x1 = 0; x1 < n; x1++)
        for (int y1 = 0; y1 < n; y1++)
            for (int x2 = 0; x2 < n; x2++)
                for (int y2 = 0; y2 < n; y2++)
                {
                    if (dp[x1][y1][x2][y2] == INT_MIN)
                        continue;
                    int cherries = (x1 == x2 && y1 == y2) ? grid[x1][y1] : grid[x1][y1] + grid[x2][y2];
                    if (x1 + 1 < n && x2 + 1 < n)
                        dp[x1 + 1][y1][x2 + 1][y2] = MAX(dp[x1 + 1][y1][x2 + 1][y2], dp[x1][y1][x2][y2] + cherries);
                    if (x1 + 1 < n && y2 + 1 < n)
                        dp[x1 + 1][y1][x2][y2 + 1] = MAX(dp[x1 + 1][y1][x2][y2 + 1], dp[x1][y1][x2][y2] + cherries);
                    if (y1 + 1 < n && x2 + 1 < n)
                        dp[x1][y1 + 1][x2 + 1][y2] = MAX(dp[x1][y1 + 1][x2 + 1][y2], dp[x1][y1][x2][y2] + cherries);
                    if (y1 + 1 < n && y2 + 1 < n)
                        dp[x1][y1 + 1][x2][y2 + 1] = MAX(dp[x1][y1 + 1][x2][y2 + 1], dp[x1][y1][x2][y2] + cherries);
                }
    return MAX(0, dp[n - 1][n - 1][n - 1][n - 1]);
}

// Longest Palindromic Substring (length only)
int longestPalindromicSubstring(char *s)
{
    int n = strlen(s), maxLen = 1;
    bool dp[n][n];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
        dp[i][i] = true;
    for (int i = 0; i < n - 1; i++)
        if (s[i] == s[i + 1])
        {
            dp[i][i + 1] = true;
            maxLen = 2;
        }
    for (int len = 3; len <= n; len++)
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1])
            {
                dp[i][j] = true;
                maxLen = len;
            }
        }
    return maxLen;
}

// Word Break
bool wordBreak(char *s, char **wordDict, int wordDictSize)
{
    int n = strlen(s);
    bool dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = true;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < wordDictSize; j++)
        {
            int len = strlen(wordDict[j]);
            if (i >= len && dp[i - len] && strncmp(s + i - len, wordDict[j], len) == 0)
                dp[i] = true;
        }
    return dp[n];
}

// Partition Equal Subset Sum
bool canPartition(int *nums, int numsSize)
{
    int sum = 0;
    for (int i = 0; i < numsSize; i++)
        sum += nums[i];
    if (sum % 2)
        return false;
    sum /= 2;
    bool dp[sum + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = true;
    for (int i = 0; i < numsSize; i++)
        for (int j = sum; j >= nums[i]; j--)
            dp[j] |= dp[j - nums[i]];
    return dp[sum];
}

// Minimum Cost for Tickets
int mincostTickets(int *days, int daysSize, int *costs, int costsSize)
{
    int dp[366];
    bool travel[366] = {0};
    for (int i = 0; i < daysSize; i++)
        travel[days[i]] = true;
    dp[0] = 0;
    for (int i = 1; i <= 365; i++)
    {
        if (!travel[i])
        {
            dp[i] = dp[i - 1];
            continue;
        }
        dp[i] = INT_MAX;
        dp[i] = MIN(dp[i], dp[i - 1] + costs[0]);
        dp[i] = MIN(dp[i], dp[MAX(0, i - 7)] + costs[1]);
        dp[i] = MIN(dp[i], dp[MAX(0, i - 30)] + costs[2]);
    }
    return dp[days[daysSize - 1]];
}

// Burst Balloons
int maxCoins(int *nums, int numsSize)
{
    int n = numsSize + 2;
    int arr[n];
    arr[0] = arr[n - 1] = 1;
    for (int i = 0; i < numsSize; i++)
        arr[i + 1] = nums[i];
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for (int len = 1; len <= numsSize; len++)
        for (int i = 1; i <= numsSize - len + 1; i++)
        {
            int j = i + len - 1;
            for (int k = i; k <= j; k++)
                dp[i][j] = MAX(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j + 1]);
        }
    return dp[1][numsSize];
}

// Regular Expression Matching
bool isMatch(char *s, char *p)
{
    int m = strlen(s), n = strlen(p);
    bool dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = true;
    for (int j = 2; j <= n; j++)
        if (p[j - 1] == '*')
            dp[0][j] = dp[0][j - 2];
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            if (p[j - 1] == '*')
                dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
            else
                dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
        }
    return dp[m][n];
}

// Maximum Path Sum in Binary Tree
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxPathSumHelper(struct TreeNode *root, int *maxSum)
{
    if (!root)
        return 0;
    int left = MAX(0, maxPathSumHelper(root->left, maxSum));
    int right = MAX(0, maxPathSumHelper(root->right, maxSum));
    *maxSum = MAX(*maxSum, left + right + root->val);
    return MAX(left, right) + root->val;
}

int maxPathSum(struct TreeNode *root)
{
    int maxSum = INT_MIN;
    maxPathSumHelper(root, &maxSum);
    return maxSum;
}

// Maximal Rectangle in Histogram
int maximalRectangleHistogram(int *heights, int n)
{
    int stack[n], top = -1, maxArea = 0;
    for (int i = 0; i <= n; i++)
    {
        int h = (i == n) ? 0 : heights[i];
        while (top >= 0 && h < heights[stack[top]])
        {
            int height = heights[stack[top--]];
            int width = (top == -1) ? i : i - stack[top] - 1;
            maxArea = MAX(maxArea, height * width);
        }
        stack[++top] = i;
    }
    return maxArea;
}

// Shortest Path in Weighted Grid
int shortestPathWeightedGrid(int **grid, int m, int n)
{
    int dp[m][n];
    dp[0][0] = grid[0][0];
    for (int i = 1; i < m; i++)
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    for (int j = 1; j < n; j++)
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            dp[i][j] = grid[i][j] + MIN(dp[i - 1][j], dp[i][j - 1]);
    return dp[m - 1][n - 1];
}

int main()
{
    // Example usage for minimumPathSumTriangle
    int triangle[4][4] = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    int *triangle_ptr[4];
    for (int i = 0; i < 4; i++)
        triangle_ptr[i] = triangle[i];
    printf("Minimum Path Sum in Triangle: %d\n", minimumPathSumTriangle(triangle_ptr, 4));

    // Example usage for longestCommonSubsequence
    char text1[] = "abcde", text2[] = "ace";
    printf("Longest Common Subsequence: %d\n", longestCommonSubsequence(text1, text2));

    // Example usage for minDistance
    char word1[] = "horse", word2[] = "ros";
    printf("Edit Distance: %d\n", minDistance(word1, word2));

    // Example usage for knapsack
    int wt[] = {1, 3, 4, 5}, val[] = {1, 4, 5, 7}, W = 7;
    printf("Knapsack Max Value: %d\n", knapsack(W, wt, val, 4));

    // Example usage for coinChange
    int coins[] = {1, 2, 5}, amount = 11;
    printf("Coin Change: %d\n", coinChange(coins, 3, amount));

    // Example usage for lengthOfLIS
    int nums[] = {10, 9, 2, 5, 3, 7, 101, 18};
    printf("Longest Increasing Subsequence: %d\n", lengthOfLIS(nums, 8));

    // Example usage for maxSubArray
    int subarray[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    printf("Maximum Subarray Sum: %d\n", maxSubArray(subarray, 9));

    // Example usage for rob
    int houses[] = {2, 7, 9, 3, 1};
    printf("House Robber Max: %d\n", rob(houses, 5));

    // Example usage for uniquePathsIII
    int grid[3][3] = {{1, 0, 0}, {0, 0, 0}, {0, 0, 2}};
    int *grid_ptr[3], gridColSize[3] = {3, 3, 3};
    for (int i = 0; i < 3; i++)
        grid_ptr[i] = grid[i];
    printf("Unique Paths III: %d\n", uniquePathsIII(grid_ptr, 3, gridColSize));

    // Example usage for calculateMinimumHPII
    int dungeon[3][3] = {{-2, -3, 3}, {-5, -101, 1}, {10, 30, -5}};
    int *dungeon_ptr[3];
    for (int i = 0; i < 3; i++)
        dungeon_ptr[i] = dungeon[i];
    printf("Dungeon Game II (with traps): %d\n", calculateMinimumHPII(dungeon_ptr, 3, 3));

    // Example usage for cherryPickupIII
    int cherryGrid[3][3] = {{3, 1, 1}, {2, 5, 1}, {1, 5, 3}};
    int *cherry_ptr[3];
    for (int i = 0; i < 3; i++)
        cherry_ptr[i] = cherryGrid[i];
    printf("Cherry Pickup III: %d\n", cherryPickupIII(cherry_ptr, 3));

    // Example usage for longestPalindromicSubstring
    char s[] = "babad";
    printf("Longest Palindromic Substring Length: %d\n", longestPalindromicSubstring(s));

    // Example usage for wordBreak
    char s2[] = "leetcode";
    char *wordDict[] = {"leet", "code"};
    printf("Word Break: %d\n", wordBreak(s2, wordDict, 2));

    // Example usage for canPartition
    int numsPartition[] = {1, 5, 11, 5};
    printf("Can Partition: %d\n", canPartition(numsPartition, 4));

    // Example usage for mincostTickets
    int days[] = {1, 4, 6, 7, 8, 20}, costs[] = {2, 7, 15};
    printf("Minimum Cost for Tickets: %d\n", mincostTickets(days, 6, costs, 3));

    // Example usage for maxCoins
    int balloons[] = {3, 1, 5, 8};
    printf("Burst Balloons Max Coins: %d\n", maxCoins(balloons, 4));

    // Example usage for isMatch
    char s3[] = "aab", p[] = "c*a*b";
    printf("Regular Expression Matching: %d\n", isMatch(s3, p));

    // Example usage for maximalRectangleHistogram
    int heights[] = {2, 1, 5, 6, 2, 3};
    printf("Maximal Rectangle in Histogram: %d\n", maximalRectangleHistogram(heights, 6));

    // Example usage for shortestPathWeightedGrid
    int weightedGrid[3][3] = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    int *weightedGrid_ptr[3];
    for (int i = 0; i < 3; i++)
        weightedGrid_ptr[i] = weightedGrid[i];
    printf("Shortest Path in Weighted Grid: %d\n", shortestPathWeightedGrid(weightedGrid_ptr, 3, 3));

    return 0;
}