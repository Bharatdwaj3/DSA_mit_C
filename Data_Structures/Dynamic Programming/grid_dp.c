#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN3(a, b, c) (MIN(MIN(a, b), c))
#define MAX3(a, b, c) (MAX(MAX(a, b), c))
#define MOD 1000000007

int minPathSum(int **grid, int m, int n)
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

int uniquePaths(int m, int n)
{
    int dp[m][n];
    for (int i = 0; i < m; i++)
        dp[i][0] = 1;
    for (int j = 0; j < n; j++)
        dp[0][j] = 1;
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    return dp[m - 1][n - 1];
}

int uniquePathsWithObstacles(int **grid, int m, int n)
{
    int dp[m][n];
    if (grid[0][0] == 1)
        return 0;
    dp[0][0] = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
                dp[i][j] = 0;
            else if (i == 0 && j == 0)
                continue;
            else
            {
                int up = (i > 0) ? dp[i - 1][j] : 0;
                int left = (j > 0) ? dp[i][j - 1] : 0;
                dp[i][j] = up + left;
            }
        }
    }
    return dp[m - 1][n - 1];
}

int calculateMinimumHP(int **dungeon, int m, int n)
{
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = INT_MAX;
    dp[m][n - 1] = dp[m - 1][n] = 1;
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            int need = MIN(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
            dp[i][j] = MAX(1, need);
        }
    }
    return dp[0][0];
}

int cherryPickupHelper(int **grid, int n, int x1, int y1, int x2, int dp[n][n][n])
{
    int y2 = x1 + y1 - x2;
    if (x1 >= n || y1 >= n || x2 >= n || y2 >= n || grid[x1][y1] == -1 || grid[x2][y2] == -1)
        return INT_MIN / 2;
    if (x1 == n - 1 && y1 == n - 1)
        return grid[x1][y1];
    if (dp[x1][y1][x2] != INT_MIN)
        return dp[x1][y1][x2];
    int cherries = (x1 == x2 && y1 == y2) ? grid[x1][y1] : grid[x1][y1] + grid[x2][y2];
    int best = MAX(
        MAX(cherryPickupHelper(grid, n, x1 + 1, y1, x2 + 1, dp),
            cherryPickupHelper(grid, n, x1, y1 + 1, x2, dp)),
        MAX(cherryPickupHelper(grid, n, x1 + 1, y1, x2, dp),
            cherryPickupHelper(grid, n, x1, y1 + 1, x2 + 1, dp)));
    cherries += best;
    dp[x1][y1][x2] = cherries;
    return cherries;
}

int cherryPickup(int **grid, int n)
{
    static int dp[50][50][50];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                dp[i][j][k] = INT_MIN;
    return MAX(0, cherryPickupHelper(grid, n, 0, 0, 0, dp));
}

int cherryPickupIIHelper(int **grid, int m, int n, int row, int c1, int c2, int dp[m][n][n])
{
    if (c1 < 0 || c2 < 0 || c1 >= n || c2 >= n)
        return INT_MIN / 2;
    if (row == m)
        return 0;
    if (dp[row][c1][c2] != INT_MIN)
        return dp[row][c1][c2];
    int cherries = (c1 == c2) ? grid[row][c1] : grid[row][c1] + grid[row][c2];
    int best = INT_MIN;
    for (int dc1 = -1; dc1 <= 1; dc1++)
        for (int dc2 = -1; dc2 <= 1; dc2++)
            best = MAX(best, cherryPickupIIHelper(grid, m, n, row + 1, c1 + dc1, c2 + dc2, dp));
    return dp[row][c1][c2] = cherries + best;
}

int cherryPickupII(int **grid, int m, int n)
{
    static int dp[70][70][70];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                dp[i][j][k] = INT_MIN;
    return cherryPickupIIHelper(grid, m, n, 0, 0, n - 1, dp);
}

int maxPathSumMatrix(int **grid, int m, int n)
{
    int dp[m][n];
    for (int j = 0; j < n; j++)
        dp[0][j] = grid[0][j];
    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int left = (j > 0) ? dp[i - 1][j - 1] : 0;
            int up = dp[i - 1][j];
            int right = (j < n - 1) ? dp[i - 1][j + 1] : 0;
            dp[i][j] = grid[i][j] + MAX3(left, up, right);
        }
    }
    int ans = dp[m - 1][0];
    for (int j = 1; j < n; j++)
        if (dp[m - 1][j] > ans)
            ans = dp[m - 1][j];
    return ans;
}

int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int dfsLIP(int **grid, int m, int n, int i, int j, int dp[m][n])
{
    if (dp[i][j] != 0)
        return dp[i][j];
    int best = 1;
    for (int d = 0; d < 4; d++)
    {
        int ni = i + dirs[d][0], nj = j + dirs[d][1];
        if (ni >= 0 && nj >= 0 && ni < m && nj < n && grid[ni][nj] > grid[i][j])
            if (1 + dfsLIP(grid, m, n, ni, nj, dp) > best)
                best = 1 + dfsLIP(grid, m, n, ni, nj, dp);
    }
    dp[i][j] = best;
    return best;
}

int longestIncreasingPath(int **grid, int m, int n)
{
    int dp[m][n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = 0;
    int ans = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (dfsLIP(grid, m, n, i, j, dp) > ans)
                ans = dfsLIP(grid, m, n, i, j, dp);
    return ans;
}

int minFallingPathSum(int **grid, int m, int n)
{
    int dp[m][n];
    for (int j = 0; j < n; j++)
        dp[0][j] = grid[0][j];
    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int left = (j > 0) ? dp[i - 1][j - 1] : INT_MAX / 2;
            int up = dp[i - 1][j];
            int right = (j < n - 1) ? dp[i - 1][j + 1] : INT_MAX / 2;
            dp[i][j] = grid[i][j] + MIN3(left, up, right);
        }
    }
    int ans = dp[m - 1][0];
    for (int j = 1; j < n; j++)
        if (dp[m - 1][j] < ans)
            ans = dp[m - 1][j];
    return ans;
}

int maximalSquare(char **matrix, int m, int n)
{
    int dp[m][n], maxSide = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == '1')
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = 1 + MIN(MIN(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
                if (dp[i][j] > maxSide)
                    maxSide = dp[i][j];
            }
            else
                dp[i][j] = 0;
        }
    }
    return maxSide * maxSide;
}

int maxHistArea(int *heights, int n)
{
    int stack[n], top = -1, maxArea = 0;
    for (int i = 0; i <= n; i++)
    {
        int h = (i == n) ? 0 : heights[i];
        while (top >= 0 && h < heights[stack[top]])
        {
            int height = heights[stack[top--]];
            int width = (top == -1) ? i : i - stack[top] - 1;
            int area = height * width;
            if (area > maxArea)
                maxArea = area;
        }
        stack[++top] = i;
    }
    return maxArea;
}

int maximalRectangle(char **matrix, int m, int n)
{
    if (m == 0)
        return 0;
    int heights[n];
    memset(heights, 0, sizeof(heights));
    int maxArea = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
        int area = maxHistArea(heights, n);
        if (area > maxArea)
            maxArea = area;
    }
    return maxArea;
}

int numOfWaysPaint(int n)
{
    long same = 6, diff = 6;
    for (int i = 2; i <= n; i++)
    {
        long nsame = (same * 3 + diff * 2) % MOD;
        long ndiff = (same * 2 + diff * 2) % MOD;
        same = nsame;
        diff = ndiff;
    }
    return (same + diff) % MOD;
}

int minimumTotal(int **triangle, int rows)
{
    for (int i = rows - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            int down = triangle[i + 1][j];
            int diag = triangle[i + 1][j + 1];
            triangle[i][j] += (down < diag ? down : diag);
        }
    }
    return triangle[0][0];
}

int findPaths(int m, int n, int maxMove, int startRow, int startCol)
{
    int dp[maxMove + 1][m][n];
    memset(dp, 0, sizeof(dp));
    dp[0][startRow][startCol] = 1;
    long ans = 0;
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (int step = 0; step < maxMove; step++)
    {
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (!dp[step][i][j])
                    continue;
                for (int d = 0; d < 4; d++)
                {
                    int ni = i + dirs[d][0], nj = j + dirs[d][1];
                    if (ni < 0 || nj < 0 || ni >= m || nj >= n)
                        ans = (ans + dp[step][i][j]) % MOD;
                    else
                        dp[step + 1][ni][nj] = (dp[step + 1][ni][nj] + dp[step][i][j]) % MOD;
                }
            }
    }
    return (int)ans;
}

int maxKilledEnemies(char **grid, int m, int n)
{
    int rowHits = 0, colHits[n], maxKills = 0;
    memset(colHits, 0, sizeof(colHits));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == 0 || grid[i][j - 1] == 'W')
            {
                rowHits = 0;
                for (int k = j; k < n && grid[i][k] != 'W'; k++)
                    if (grid[i][k] == 'E')
                        rowHits++;
            }
            if (i == 0 || grid[i - 1][j] == 'W')
            {
                colHits[j] = 0;
                for (int k = i; k < m && grid[k][j] != 'W'; k++)
                    if (grid[k][j] == 'E')
                        colHits[j]++;
            }
            if (grid[i][j] == '0')
            {
                int total = rowHits + colHits[j];
                if (total > maxKills)
                    maxKills = total;
            }
        }
    }
    return maxKills;
}

int minCostCut(int *cuts, int c, int len)
{
    int arr[c + 2];
    arr[0] = 0;
    arr[c + 1] = len;
    for (int i = 1; i <= c; i++)
        arr[i] = cuts[i - 1];
    for (int i = 0; i < c + 2; i++)
        for (int j = i + 1; j < c + 2; j++)
            if (arr[i] > arr[j])
            {
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
    int dp[c + 2][c + 2];
    for (int lenSeg = 2; lenSeg < c + 2; lenSeg++)
    {
        for (int i = 0; i + lenSeg < c + 2; i++)
        {
            int j = i + lenSeg;
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k < j; k++)
                dp[i][j] = MIN(dp[i][j], dp[i][k] + dp[k][j] + arr[j] - arr[i]);
            if (dp[i][j] == INT_MAX)
                dp[i][j] = 0;
        }
    }
    return dp[0][c + 1];
}

int numTilings2xN(int n)
{
    long dp[n + 2];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
        dp[i] = (2 * dp[i - 1] + dp[i - 3]) % MOD;
    return dp[n];
}

int knightDialer(int n)
{
    int moves[10][3] = {
        {4, 6, -1}, {6, 8, -1}, {7, 9, -1}, {4, 8, -1}, {0, 3, 9}, {-1, -1, -1}, {0, 1, 7}, {2, 6, -1}, {1, 3, -1}, {2, 4, -1}};
    long dp[10], next[10];
    for (int i = 0; i < 10; i++)
        dp[i] = 1;
    for (int step = 2; step <= n; step++)
    {
        for (int i = 0; i < 10; i++)
        {
            next[i] = 0;
            for (int k = 0; moves[i][k] != -1; k++)
                next[i] = (next[i] + dp[moves[i][k]]) % MOD;
        }
        for (int i = 0; i < 10; i++)
            dp[i] = next[i];
    }
    long ans = 0;
    for (int i = 0; i < 10; i++)
        ans = (ans + dp[i]) % MOD;
    return (int)ans;
}

bool *gridIllumination(int N, int **lamps, int lampsSize, int **queries, int queriesSize, int *returnSize)
{
    static bool ans[100000];
    bool grid[N][N];
    memset(grid, 0, sizeof(grid));
    for (int i = 0; i < lampsSize; i++)
        grid[lamps[i][0]][lamps[i][1]] = true;
    *returnSize = queriesSize;
    for (int q = 0; q < queriesSize; q++)
    {
        int r = queries[q][0], c = queries[q][1];
        bool lit = false;
        for (int i = 0; i < N && !lit; i++)
            if (grid[r][i] || grid[i][c])
                lit = true;
        for (int i = 0; i < N && !lit; i++)
            if (r + i < N && c + i < N && grid[r + i][c + i])
                lit = true;
        ans[q] = lit;
        for (int dr = -1; dr <= 1; dr++)
            for (int dc = -1; dc <= 1; dc++)
            {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nc >= 0 && nr < N && nc < N)
                    grid[nr][nc] = false;
            }
    }
    return ans;
}

void dfsFill(int **image, int m, int n, int r, int c, int oldColor, int newColor)
{
    if (r < 0 || c < 0 || r >= m || c >= n || image[r][c] != oldColor)
        return;
    image[r][c] = newColor;
    dfsFill(image, m, n, r + 1, c, oldColor, newColor);
    dfsFill(image, m, n, r - 1, c, oldColor, newColor);
    dfsFill(image, m, n, r, c + 1, oldColor, newColor);
    dfsFill(image, m, n, r, c - 1, oldColor, newColor);
}

int **floodFill(int **image, int m, int n, int sr, int sc, int color, int *returnSize, int **returnColumnSizes)
{
    int oldColor = image[sr][sc];
    if (oldColor != color)
        dfsFill(image, m, n, sr, sc, oldColor, color);
    *returnSize = m;
    *returnColumnSizes = malloc(m * sizeof(int));
    for (int i = 0; i < m; i++)
        (*returnColumnSizes)[i] = n;
    return image;
}

int main()
{
    // Example usage for minPathSum
    int grid[3][3] = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    int **grid_ptr = malloc(3 * sizeof(int *));
    for (int i = 0; i < 3; i++)
        grid_ptr[i] = grid[i];
    printf("Min Path Sum: %d\n", minPathSum(grid_ptr, 3, 3));

    // Example usage for uniquePaths
    printf("Unique Paths (3x2): %d\n", uniquePaths(3, 2));

    // Example usage for uniquePathsWithObstacles
    int obstacleGrid[3][3] = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    int **obstacleGrid_ptr = malloc(3 * sizeof(int *));
    for (int i = 0; i < 3; i++)
        obstacleGrid_ptr[i] = obstacleGrid[i];
    printf("Unique Paths with Obstacles: %d\n", uniquePathsWithObstacles(obstacleGrid_ptr, 3, 3));

    // Example usage for calculateMinimumHP
    int dungeon[3][3] = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    int **dungeon_ptr = malloc(3 * sizeof(int *));
    for (int i = 0; i < 3; i++)
        dungeon_ptr[i] = dungeon[i];
    printf("Minimum HP: %d\n", calculateMinimumHP(dungeon_ptr, 3, 3));

    // Example usage for numTilings2xN
    printf("2xN Tilings (n=3): %d\n", numTilings2xN(3));

    // Free allocated memory
    free(grid_ptr);
    free(obstacleGrid_ptr);
    free(dungeon_ptr);

    return 0;
}