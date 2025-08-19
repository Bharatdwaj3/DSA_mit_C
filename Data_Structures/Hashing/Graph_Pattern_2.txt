#include <bits/stdc++.h>
using namespace std;

// 1. Rotting Oranges - Classic Multi-source BFS
int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    queue<pair<int, int>> q;
    int fresh = 0;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) q.push({i, j});
            else if (grid[i][j] == 1) fresh++;
        }
    }
    
    if (fresh == 0) return 0;
    int minutes = 0;
    vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            auto [x, y] = q.front(); q.pop();
            for (auto [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                    fresh--;
                }
            }
        }
        minutes++;
    }
    
    return fresh == 0 ? minutes - 1 : -1;
}

// 2. Walls and Gates - Multi-source BFS from all gates
void wallsAndGates(vector<vector<int>>& rooms) {
    int m = rooms.size(), n = rooms[0].size();
    queue<pair<int, int>> q;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (rooms[i][j] == 0) q.push({i, j});
        }
    }
    
    vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (auto [dx, dy] : dirs) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && 
                rooms[nx][ny] == INT_MAX) {
                rooms[nx][ny] = rooms[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

// 3. 01 Matrix - Distance to nearest 0
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    queue<pair<int, int>> q;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    
    vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (auto [dx, dy] : dirs) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && 
                dist[nx][ny] > dist[x][y] + 1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    return dist;
}

// 4. As Far from Land as Possible - Multi-source from all land cells
int maxDistance(vector<vector<int>>& grid) {
    int n = grid.size();
    queue<pair<int, int>> q;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) q.push({i, j});
        }
    }
    
    if (q.empty() || q.size() == n * n) return -1;
    
    int maxDist = -1;
    vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            auto [x, y] = q.front(); q.pop();
            for (auto [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                    grid[nx][ny] = grid[x][y] + 1;
                    q.push({nx, ny});
                    maxDist = max(maxDist, grid[nx][ny] - 1);
                }
            }
        }
    }
    
    return maxDist;
}

// 5. Shortest Distance from All Buildings - Multi-source BFS
int shortestDistance(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dist(m, vector<int>(n, 0));
    vector<vector<int>> reach(m, vector<int>(n, 0));
    int buildings = 0;
    
    vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                buildings++;
                queue<pair<int, int>> q;
                vector<vector<bool>> visited(m, vector<bool>(n, false));
                q.push({i, j});
                visited[i][j] = true;
                int level = 0;
                
                while (!q.empty()) {
                    int size = q.size();
                    level++;
                    for (int k = 0; k < size; k++) {
                        auto [x, y] = q.front(); q.pop();
                        for (auto [dx, dy] : dirs) {
                            int nx = x + dx, ny = y + dy;
                            if (nx >= 0 && nx < m && ny >= 0 && ny < n && 
                                !visited[nx][ny] && grid[nx][ny] == 0) {
                                visited[nx][ny] = true;
                                dist[nx][ny] += level;
                                reach[nx][ny]++;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
    }
    
    int result = INT_MAX;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0 && reach[i][j] == buildings) {
                result = min(result, dist[i][j]);
            }
        }
    }
    
    return result == INT_MAX ? -1 : result;
}

// 6. Surrounded Regions - Multi-source from boundary
void solve(vector<vector<char>>& board) {
    int m = board.size(), n = board[0].size();
    queue<pair<int, int>> q;
    
    for (int i = 0; i < m; i++) {
        if (board[i][0] == 'O') { board[i][0] = '#'; q.push({i, 0}); }
        if (board[i][n-1] == 'O') { board[i][n-1] = '#'; q.push({i, n-1}); }
    }
    for (int j = 0; j < n; j++) {
        if (board[0][j] == 'O') { board[0][j] = '#'; q.push({0, j}); }
        if (board[m-1][j] == 'O') { board[m-1][j] = '#'; q.push({m-1, j}); }
    }
    
    vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (auto [dx, dy] : dirs) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] == 'O') {
                board[nx][ny] = '#';
                q.push({nx, ny});
            }
        }
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'O') board[i][j] = 'X';
            else if (board[i][j] == '#') board[i][j] = 'O';
        }
    }
}

// 7. Pacific Atlantic Water Flow - Multi-source from both oceans
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int m = heights.size(), n = heights[0].size();
    vector<vector<bool>> pacific(m, vector<bool>(n, false));
    vector<vector<bool>> atlantic(m, vector<bool>(n, false));
    queue<pair<int, int>> pq, aq;
    
    for (int i = 0; i < m; i++) {
        pacific[i][0] = true; pq.push({i, 0});
        atlantic[i][n-1] = true; aq.push({i, n-1});
    }
    for (int j = 0; j < n; j++) {
        pacific[0][j] = true; pq.push({0, j});
        atlantic[m-1][j] = true; aq.push({m-1, j});
    }
    
    vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    auto bfs = [&](queue<pair<int, int>>& q, vector<vector<bool>>& ocean) {
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (auto [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && 
                    !ocean[nx][ny] && heights[nx][ny] >= heights[x][y]) {
                    ocean[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    };
    
    bfs(pq, pacific);
    bfs(aq, atlantic);
    
    vector<vector<int>> result;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (pacific[i][j] && atlantic[i][j]) {
                result.push_back({i, j});
            }
        }
    }
    return result;
}

// 8. Shortest Bridge - Multi-source BFS after finding first island
int shortestBridge(vector<vector<int>>& grid) {
    int n = grid.size();
    queue<pair<int, int>> q;
    bool found = false;
    
    function<void(int, int)> dfs = [&](int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 1) return;
        grid[i][j] = 2;
        q.push({i, j});
        dfs(i+1, j); dfs(i-1, j); dfs(i, j+1); dfs(i, j-1);
    };
    
    for (int i = 0; i < n && !found; i++) {
        for (int j = 0; j < n && !found; j++) {
            if (grid[i][j] == 1) {
                dfs(i, j);
                found = true;
            }
        }
    }
    
    vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int steps = 0;
    
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            auto [x, y] = q.front(); q.pop();
            for (auto [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    if (grid[nx][ny] == 1) return steps;
                    if (grid[nx][ny] == 0) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                    }
                }
            }
        }
        steps++;
    }
    return steps;
}

// 9. Minimum Effort Path - Multi-source with binary search
int minimumEffortPath(vector<vector<int>>& heights) {
    int m = heights.size(), n = heights[0].size();
    
    auto canReach = [&](int maxEffort) -> bool {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;
        
        vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            if (x == m-1 && y == n-1) return true;
            
            for (auto [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    int effort = abs(heights[nx][ny] - heights[x][y]);
                    if (effort <= maxEffort) {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return false;
    };
    
    int left = 0, right = 1e6;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canReach(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

// 10. Keys and Rooms - Multi-source from available keys
bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = rooms.size();
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    int count = 1;
    
    while (!q.empty()) {
        int room = q.front(); q.pop();
        for (int key : rooms[room]) {
            if (!visited[key]) {
                visited[key] = true;
                q.push(key);
                count++;
            }
        }
    }
    
    return count == n;
}

// 11. Minimum Knight Moves - Multi-source BFS with symmetry
int minKnightMoves(int x, int y) {
    x = abs(x); y = abs(y);
    if (x == 0 && y == 0) return 0;
    if (x == 1 && y == 1) return 2;
    
    queue<pair<int, int>> q;
    set<pair<int, int>> visited;
    q.push({0, 0});
    visited.insert({0, 0});
    
    vector<pair<int, int>> moves = {{2,1}, {2,-1}, {-2,1}, {-2,-1}, 
                                   {1,2}, {1,-2}, {-1,2}, {-1,-2}};
    int steps = 0;
    
    while (!q.empty()) {
        int size = q.size();
        steps++;
        for (int i = 0; i < size; i++) {
            auto [cx, cy] = q.front(); q.pop();
            for (auto [dx, dy] : moves) {
                int nx = cx + dx, ny = cy + dy;
                if (nx == x && ny == y) return steps;
                if (!visited.count({nx, ny}) && nx >= -2 && ny >= -2 && 
                    nx <= x + 2 && ny <= y + 2) {
                    visited.insert({nx, ny});
                    q.push({nx, ny});
                }
            }
        }
    }
    return -1;
}

// 12. Matrix Block Sum - 2D Range Sum with BFS concept
vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            prefix[i][j] = mat[i-1][j-1] + prefix[i-1][j] + 
                          prefix[i][j-1] - prefix[i-1][j-1];
        }
    }
    
    vector<vector<int>> result(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int r1 = max(0, i - K), c1 = max(0, j - K);
            int r2 = min(m - 1, i + K), c2 = min(n - 1, j + K);
            result[i][j] = prefix[r2+1][c2+1] - prefix[r1][c2+1] - 
                          prefix[r2+1][c1] + prefix[r1][c1];
        }
    }
    return result;
}

// 13. Distribute Coins in Binary Tree - Multi-source flow
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int distributeCoins(TreeNode* root) {
    int moves = 0;
    
    function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
        if (!node) return 0;
        
        int left = dfs(node->left);
        int right = dfs(node->right);
        
        moves += abs(left) + abs(right);
        return node->val + left + right - 1;
    };
    
    dfs(root);
    return moves;
}

// 14. Multi-source Dijkstra - Find closest facility
vector<int> findClosestFacilities(int n, vector<vector<int>>& edges, vector<int>& facilities) {
    vector<vector<pair<int, int>>> graph(n);
    for (auto& e : edges) {
        graph[e[0]].push_back({e[1], e[2]});
        graph[e[1]].push_back({e[0], e[2]});
    }
    
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    for (int facility : facilities) {
        dist[facility] = 0;
        pq.push({0, facility});
    }
    
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        
        for (auto [v, w] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist;
}

// 15. Detonate Maximum Bombs - Multi-source explosion
int maximumDetonation(vector<vector<int>>& bombs) {
    int n = bombs.size();
    vector<vector<int>> graph(n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            long long dx = bombs[i][0] - bombs[j][0];
            long long dy = bombs[i][1] - bombs[j][1];
            long long dist = dx * dx + dy * dy;
            long long radius = bombs[i][2];
            if (dist <= radius * radius) {
                graph[i].push_back(j);
            }
        }
    }
    
    int maxDetonated = 0;
    for (int i = 0; i < n; i++) {
        queue<int> q;
        vector<bool> detonated(n, false);
        q.push(i);
        detonated[i] = true;
        int count = 1;
        
        while (!q.empty()) {
            int bomb = q.front(); q.pop();
            for (int next : graph[bomb]) {
                if (!detonated[next]) {
                    detonated[next] = true;
                    q.push(next);
                    count++;
                }
            }
        }
        maxDetonated = max(maxDetonated, count);
    }
    
    return maxDetonated;
}

// 16. Word Ladder II - Multi-source shortest paths
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    if (!wordSet.count(endWord)) return {};
    
    queue<vector<string>> q;
    q.push({beginWord});
    unordered_set<string> visited;
    visited.insert(beginWord);
    vector<vector<string>> result;
    
    while (!q.empty() && result.empty()) {
        int size = q.size();
        unordered_set<string> currentLevel;
        
        for (int i = 0; i < size; i++) {
            vector<string> path = q.front(); q.pop();
            string word = path.back();
            
            for (int j = 0; j < word.length(); j++) {
                char orig = word[j];
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == orig) continue;
                    word[j] = c;
                    
                    if (word == endWord) {
                        path.push_back(word);
                        result.push_back(path);
                        path.pop_back();
                    } else if (wordSet.count(word) && !visited.count(word)) {
                        path.push_back(word);
                        q.push(path);
                        path.pop_back();
                        currentLevel.insert(word);
                    }
                }
                word[j] = orig;
            }
        }
        
        for (const string& w : currentLevel) {
            visited.insert(w);
        }
    }
    
    return result;
}

// 17. Shortest Path to Get Food - Multi-source from all food
int getFood(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size();
    queue<pair<int, int>> q;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '*') {
                q.push({i, j});
                grid[i][j] = '0';
            }
        }
    }
    
    vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int steps = 0;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '#') {
                queue<pair<int, int>> foodQ;
                vector<vector<bool>> visited(m, vector<bool>(n, false));
                foodQ.push({i, j});
                visited[i][j] = true;
                int dist = 0;
                
                while (!foodQ.empty()) {
                    int size = foodQ.size();
                    for (int k = 0; k < size; k++) {
                        auto [x, y] = foodQ.front(); foodQ.pop();
                        if (grid[x][y] == '0') return dist;
                        
                        for (auto [dx, dy] : dirs) {
                            int nx = x + dx, ny = y + dy;
                            if (nx >= 0 && nx < m && ny >= 0 && ny < n && 
                                !visited[nx][ny] && grid[nx][ny] != 'X') {
                                visited[nx][ny] = true;
                                foodQ.push({nx, ny});
                            }
                        }
                    }
                    dist++;
                }
            }
        }
    }
    
    return -1;
}

// 18. Escape the Spreading Fire - Multi-source fire spread
int maximumMinutes(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    
    auto simulate = [&](int delay) -> bool {
        vector<vector<int>> fire(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> fireQ;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    fire[i][j] = 0;
                    fireQ.push({i, j});
                }
            }
        }
        
        vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        while (!fireQ.empty()) {
            auto [x, y] = fireQ.front(); fireQ.pop();
            for (auto [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && 
                    grid[nx][ny] == 0 && fire[nx][ny] == INT_MAX) {
                    fire[nx][ny] = fire[x][y] + 1;
                    fireQ.push({nx, ny});
                }
            }
        }
        
        queue<tuple<int, int, int>> personQ;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        personQ.push({0, 0, delay});
        visited[0][0] = true;
        
        while (!personQ.empty()) {
            auto [x, y, time] = personQ.front(); personQ.pop();
            if (x == m-1 && y == n-1) return true;
            
            for (auto [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && 
                    !visited[nx][ny] && grid[nx][ny] == 0) {
                    if (time + 1 < fire[nx][ny] || 
                        (nx == m-1 && ny == n-1 && time + 1 <= fire[nx][ny])) {
                        visited[nx][ny] = true;
                        personQ.push({nx, ny, time + 1});
                    }
                }
            }
        }
        return false;
    };
    
    int left = 0, right = 1e9;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (simulate(mid)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return result >= 1e9 ? 1000000000 : result;
}

// 19. Reachable Nodes in Subdivided Graph - Multi-source with subdivision
int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
    vector<vector<pair<int, int>>> graph(n);
    for (auto& e : edges) {
        graph[e[0]].push_back({e[1], e[2]});
        graph[e[1]].push_back({e[0], e[2]});
    }
    
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>> pq;
    pq.push({maxMoves, 0});
    dist[0] = maxMoves;
    
    while (!pq.empty()) {
        auto [moves, node] = pq.top(); pq.pop();
        if (moves < dist[node]) continue;
        
        for (auto [neighbor, subdivisions] : graph[node]) {
            int newMoves = moves - subdivisions - 1;
            if (newMoves >= 0 && newMoves > dist[neighbor]) {
                dist[neighbor] = newMoves;
                pq.push({newMoves, neighbor});
            }
        }
    }
    
    int result = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] >= 0) result++;
    }
    
    for (auto& e : edges) {
        int subdivisions = e[2];
        int from0 = max(0, dist[e[0]] >= 0 ? dist[e[0]] : 0);
        int from1 = max(0, dist[e[1]] >= 0 ? dist[e[1]] : 0);
        result += min(subdivisions, from0 + from1);
    }
    
    return result;
}

// 20. Cheapest Flights Within K Stops - Multi-source with constraints
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int, int>>> graph(n);
    for (auto& f : flights) {
        graph[f[0]].push_back({f[1], f[2]});
    }
    
    queue<tuple<int, int, int>> q; // {cost, node, stops}
    q.push({0, src, 0});
    vector<vector<int>> minCost(n, vector<int>(k + 2, INT_MAX));
    minCost[src][0] = 0;
    
    while (!q.empty()) {
        auto [cost, node, stops] = q.front(); q.pop();
        if (stops > k) continue;
        
        for (auto [next, price] : graph[node]) {
            int newCost = cost + price;
            if (newCost < minCost[next][stops + 1]) {
                minCost[next][stops + 1] = newCost;
                q.push({newCost, next, stops + 1});
            }
        }
    }
    
    int result = INT_MAX;
    for (int i = 0; i <= k + 1; i++) {
        result = min(result, minCost[dst][i]);
    }
    return result == INT_MAX ? -1 : result;
}

// 21. Bus Routes - Multi-source BFS on bus routes
int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
    if (source == target) return 0;
    
    unordered_map<int, vector<int>> stopToBuses;
    for (int i = 0; i < routes.size(); i++) {
        for (int stop : routes[i]) {
            stopToBuses[stop].push_back(i);
        }
    }
    
    queue<int> q;
    unordered_set<int> visitedStops;
    unordered_set<int> visitedBuses;
    
    for (int bus : stopToBuses[source]) {
        q.push(bus);
        visitedBuses.insert(bus);
    }
    visitedStops.insert(source);
    
    int transfers = 1;
    
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int bus = q.front(); q.pop();
            
            for (int stop : routes[bus]) {
                if (stop == target) return transfers;
                if (!visitedStops.count(stop)) {
                    visitedStops.insert(stop);
                    for (int nextBus : stopToBuses[stop]) {
                        if (!visitedBuses.count(nextBus)) {
                            visitedBuses.insert(nextBus);
                            q.push(nextBus);
                        }
                    }
                }
            }
        }
        transfers++;
    }
    
    return -1;
}

// 22. Sliding Puzzle - Multi-state BFS
int slidingPuzzle(vector<vector<int>>& board) {
    string target = "123450";
    string start = "";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            start += to_string(board[i][j]);
        }
    }
    
    if (start == target) return 0;
    
    vector<vector<int>> neighbors = {{1, 3}, {0, 2, 4}, {1, 5}, 
                                    {0, 4}, {1, 3, 5}, {2, 4}};
    queue<string> q;
    unordered_set<string> visited;
    q.push(start);
    visited.insert(start);
    int moves = 0;
    
    while (!q.empty()) {
        int size = q.size();
        moves++;
        for (int i = 0; i < size; i++) {
            string curr = q.front(); q.pop();
            int zeroPos = curr.find('0');
            
            for (int neighbor : neighbors[zeroPos]) {
                string next = curr;
                swap(next[zeroPos], next[neighbor]);
                if (next == target) return moves;
                if (!visited.count(next)) {
                    visited.insert(next);
                    q.push(next);
                }
            }
        }
    }
    
    return -1;
}

// 23. Shortest Path in Grid with Obstacles Elimination - Multi-source with state
int shortestPath(vector<vector<int>>& grid, int k) {
    int m = grid.size(), n = grid[0].size();
    if (k >= m + n - 2) return m + n - 2;
    
    queue<tuple<int, int, int, int>> q; // {x, y, obstacles, steps}
    set<tuple<int, int, int>> visited;
    q.push({0, 0, 0, 0});
    visited.insert({0, 0, 0});
    
    vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    while (!q.empty()) {
        auto [x, y, obstacles, steps] = q.front(); q.pop();
        if (x == m-1 && y == n-1) return steps;
        
        for (auto [dx, dy] : dirs) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                int newObstacles = obstacles + grid[nx][ny];
                if (newObstacles <= k && !visited.count({nx, ny, newObstacles})) {
                    visited.insert({nx, ny, newObstacles});
                    q.push({nx, ny, newObstacles, steps + 1});
                }
            }
        }
    }
    
    return -1;
}

// 24. Race Car - Multi-state BFS
int racecar(int target) {
    queue<tuple<int, int, int>> q; // {position, speed, instructions}
    set<pair<int, int>> visited;
    q.push({0, 1, 0});
    visited.insert({0, 1});
    
    while (!q.empty()) {
        auto [pos, speed, instructions] = q.front(); q.pop();
        if (pos == target) return instructions;
        
        // Action A: accelerate
        int newPos = pos + speed;
        int newSpeed = speed * 2;
        if (abs(newPos - target) < target && !visited.count({newPos, newSpeed})) {
            visited.insert({newPos, newSpeed});
            q.push({newPos, newSpeed, instructions + 1});
        }
        
        // Action R: reverse
        int reverseSpeed = speed > 0 ? -1 : 1;
        if (!visited.count({pos, reverseSpeed})) {
            visited.insert({pos, reverseSpeed});
            q.push({pos, reverseSpeed, instructions + 1});
        }
    }
    
    return -1;
}

// 25. Minimum Cost to Make at Least One Valid Path - Multi-source Dijkstra
int minCost(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
    
    pq.push({0, 0, 0});
    cost[0][0] = 0;
    
    while (!pq.empty()) {
        auto [c, x, y] = pq.top(); pq.pop();
        if (c > cost[x][y]) continue;
        if (x == m-1 && y == n-1) return c;
        
        for (int d = 0; d < 4; d++) {
            int nx = x + dirs[d].first;
            int ny = y + dirs[d].second;
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                int newCost = c + (grid[x][y] - 1 != d ? 1 : 0);
                if (newCost < cost[nx][ny]) {
                    cost[nx][ny] = newCost;
                    pq.push({newCost, nx, ny});
                }
            }
        }
    }
    
    return -1;
}

// 26. Maximum Candies You Can Get from Boxes - Multi-source collection
int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, 
               vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
    queue<int> q;
    unordered_set<int> hasBox;
    unordered_set<int> canOpen;
    
    for (int box : initialBoxes) {
        hasBox.insert(box);
        if (status[box] == 1) {
            q.push(box);
            canOpen.insert(box);
        }
    }
    
    int totalCandies = 0;
    
    while (!q.empty()) {
        int box = q.front(); q.pop();
        totalCandies += candies[box];
        
        for (int key : keys[box]) {
            if (status[key] == 0) {
                status[key] = 1;
                if (hasBox.count(key) && !canOpen.count(key)) {
                    canOpen.insert(key);
                    q.push(key);
                }
            }
        }
        
        for (int newBox : containedBoxes[box]) {
            hasBox.insert(newBox);
            if (status[newBox] == 1 && !canOpen.count(newBox)) {
                canOpen.insert(newBox);
                q.push(newBox);
            }
        }
    }
    
    return totalCandies;
}

// 27. Minimum Number of Days to Disconnect Island - Multi-source connectivity check
int minDays(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    
    auto countIslands = [&]() -> int {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int count = 0;
        
        function<void(int, int)> dfs = [&](int i, int j) {
            if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || grid[i][j] == 0) return;
            visited[i][j] = true;
            dfs(i+1, j); dfs(i-1, j); dfs(i, j+1); dfs(i, j-1);
        };
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    count++;
                    dfs(i, j);
                }
            }
        }
        return count;
    };
    
    if (countIslands() != 1) return 0;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                grid[i][j] = 0;
                if (countIslands() != 1) return 1;
                grid[i][j] = 1;
            }
        }
    }
    
    return 2;
}

// 28. Critical Connections in a Network - Multi-source bridge finding
vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<vector<int>> graph(n);
    for (auto& conn : connections) {
        graph[conn[0]].push_back(conn[1]);
        graph[conn[1]].push_back(conn[0]);
    }
    
    vector<int> disc(n, -1), low(n, -1);
    vector<bool> visited(n, false);
    vector<vector<int>> bridges;
    int timer = 0;
    
    function<void(int, int)> dfs = [&](int u, int parent) {
        visited[u] = true;
        disc[u] = low[u] = timer++;
        
        for (int v : graph[u]) {
            if (v == parent) continue;
            if (visited[v]) {
                low[u] = min(low[u], disc[v]);
            } else {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] > disc[u]) {
                    bridges.push_back({u, v});
                }
            }
        }
    };
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, -1);
        }
    }
    
    return bridges;
}

// 29. Swim in Rising Water - Multi-source binary search with BFS
int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    
    auto canReach = [&](int limit) -> bool {
        if (grid[0][0] > limit) return false;
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;
        
        vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            if (x == n-1 && y == n-1) return true;
            
            for (auto [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && 
                    !visited[nx][ny] && grid[nx][ny] <= limit) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        return false;
    };
    
    int left = 0, right = n * n - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canReach(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

// 30. Cherry Pickup II - Multi-source DP with BFS concept
int cherryPickup(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    
    map<tuple<int, int, int>, int> memo;
    
    function<int(int, int, int)> dp = [&](int row, int col1, int col2) -> int {
        if (row == m) return 0;
        if (col1 < 0 || col1 >= n || col2 < 0 || col2 >= n) return 0;
        
        auto key = make_tuple(row, col1, col2);
        if (memo.count(key)) return memo[key];
        
        int cherries = grid[row][col1];
        if (col1 != col2) cherries += grid[row][col2];
        
        int maxNext = 0;
        for (int dc1 = -1; dc1 <= 1; dc1++) {
            for (int dc2 = -1; dc2 <= 1; dc2++) {
                maxNext = max(maxNext, dp(row + 1, col1 + dc1, col2 + dc2));
            }
        }
        
        return memo[key] = cherries + maxNext;
    };
    
    return dp(0, 0, n - 1);
}

// 31-40: Additional Multi-source BFS Problems

// 31. Find All People With Secret - Multi-source time-based propagation
vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
    vector<bool> hasSecret(n, false);
    hasSecret[0] = hasSecret[firstPerson] = true;
    
    map<int, vector<pair<int, int>>> timeToMeetings;
    for (auto& m : meetings) {
        timeToMeetings[m[2]].push_back({m[0], m[1]});
    }
    
    for (auto& [time, meetingList] : timeToMeetings) {
        unordered_map<int, vector<int>> graph;
        set<int> people;
        
        for (auto& [a, b] : meetingList) {
            graph[a].push_back(b);
            graph[b].push_back(a);
            people.insert(a);
            people.insert(b);
        }
        
        queue<int> q;
        for (int person : people) {
            if (hasSecret[person]) q.push(person);
        }
        
        while (!q.empty()) {
            int person = q.front(); q.pop();
            for (int neighbor : graph[person]) {
                if (!hasSecret[neighbor]) {
                    hasSecret[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
    
    vector<int> result;
    for (int i = 0; i < n; i++) {
        if (hasSecret[i]) result.push_back(i);
    }
    return result;
}

// 32. Water and Jug Problem - Multi-state BFS
bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
    if (targetCapacity > jug1Capacity + jug2Capacity) return false;
    if (targetCapacity == 0) return true;
    
    queue<pair<int, int>> q;
    set<pair<int, int>> visited;
    q.push({0, 0});
    visited.insert({0, 0});
    
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (x + y == targetCapacity) return true;
        
        vector<pair<int, int>> nextStates = {
            {jug1Capacity, y},  // Fill jug1
            {x, jug2Capacity},  // Fill jug2
            {0, y},             // Empty jug1
            {x, 0},             // Empty jug2
            {x - min(x, jug2Capacity - y), y + min(x, jug2Capacity - y)}, // Pour jug1 to jug2
            {x + min(y, jug1Capacity - x), y - min(y, jug1Capacity - x)}  // Pour jug2 to jug1
        };
        
        for (auto& state : nextStates) {
            if (!visited.count(state)) {
                visited.insert(state);
                q.push(state);
            }
        }
    }
    
    return false;
}

// 33. Prison Cells After N Days - Multi-state cycle detection
vector<int> prisonAfterNDays(vector<int>& cells, int N) {
    if (N == 0) return cells;
    
    map<vector<int>, int> seen;
    vector<vector<int>> history;
    
    while (N > 0) {
        if (seen.count(cells)) {
            int cycleStart = seen[cells];
            int cycleLength = history.size() - cycleStart;
            return history[cycleStart + (N - 1) % cycleLength];
        }
        
        seen[cells] = history.size();
        history.push_back(cells);
        
        vector<int> next(8, 0);
        for (int i = 1; i < 7; i++) {
            next[i] = cells[i-1] == cells[i+1] ? 1 : 0;
        }
        cells = next;
        N--;
    }
    
    return cells;
}

// 34. Snakes and Ladders - Multi-source board game BFS
int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size();
    vector<int> arr(n * n + 1);
    
    int idx = 1;
    bool leftToRight = true;
    for (int i = n - 1; i >= 0; i--) {
        if (leftToRight) {
            for (int j = 0; j < n; j++) {
                arr[idx++] = board[i][j];
            }
        } else {
            for (int j = n - 1; j >= 0; j--) {
                arr[idx++] = board[i][j];
            }
        }
        leftToRight = !leftToRight;
    }
    
    queue<int> q;
    vector<bool> visited(n * n + 1, false);
    q.push(1);
    visited[1] = true;
    int moves = 0;
    
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int curr = q.front(); q.pop();
            if (curr == n * n) return moves;
            
            for (int k = 1; k <= 6; k++) {
                int next = curr + k;
                if (next > n * n) break;
                
                if (arr[next] != -1) {
                    next = arr[next];
                }
                
                if (!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
        moves++;
    }
    
    return -1;
}

// 35. Minimum Moves to Reach Target Array - Multi-source reduction
int minMoves(vector<int>& target) {
    priority_queue<long long> pq;
    long long total = 0;
    
    for (int x : target) {
        pq.push(x);
        total += x;
    }
    
    int moves = 0;
    while (pq.top() != 1) {
        long long largest = pq.top(); pq.pop();
        long long rest = total - largest;
        
        if (rest == 1) {
            moves += largest - 1;
            break;
        }
        
        long long rounds = largest / rest;
        if (largest % rest == 0) rounds--;
        
        moves += rounds;
        largest -= rounds * rest;
        total = rest + largest;
        pq.push(largest);
    }
    
    return moves;
}

// 36. Jump Game IV - Multi-source BFS with same values
int minJumps(vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return 0;
    
    unordered_map<int, vector<int>> valueToIndices;
    for (int i = 0; i < n; i++) {
        valueToIndices[arr[i]].push_back(i);
    }
    
    queue<int> q;
    vector<bool> visited(n, false);
    q.push(0);
    visited[0] = true;
    int steps = 0;
    
    while (!q.empty()) {
        int size = q.size();
        steps++;
        for (int i = 0; i < size; i++) {
            int curr = q.front(); q.pop();
            
            // Jump to adjacent indices
            vector<int> nextIndices = {curr - 1, curr + 1};
            
            // Jump to indices with same value
            if (valueToIndices.count(arr[curr])) {
                for (int idx : valueToIndices[arr[curr]]) {
                    nextIndices.push_back(idx);
                }
                valueToIndices.erase(arr[curr]); // Avoid revisiting
            }
            
            for (int next : nextIndices) {
                if (next == n - 1) return steps;
                if (next >= 0 && next < n && !visited[next]) {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
    }
    
    return -1;
}

// 37. Minimum Cost to Connect Sticks - Multi-source greedy with priority queue
int connectSticks(vector<int>& sticks) {
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int stick : sticks) {
        pq.push(stick);
    }
    
    long long totalCost = 0;
    while (pq.size() > 1) {
        long long first = pq.top(); pq.pop();
        long long second = pq.top(); pq.pop();
        long long cost = first + second;
        totalCost += cost;
        pq.push(cost);
    }
    
    return totalCost;
}

// 38. Cut Off Trees for Golf Event - Multi-source BFS between trees
int cutOffTree(vector<vector<int>>& forest) {
    int m = forest.size(), n = forest[0].size();
    vector<tuple<int, int, int>> trees;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (forest[i][j] > 1) {
                trees.push_back({forest[i][j], i, j});
            }
        }
    }
    
    sort(trees.begin(), trees.end());
    
    auto bfs = [&](int sr, int sc, int er, int ec) -> int {
        if (sr == er && sc == ec) return 0;
        
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        q.push({sr, sc});
        visited[sr][sc] = true;
        
        vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int steps = 0;
        
        while (!q.empty()) {
            int size = q.size();
            steps++;
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front(); q.pop();
                for (auto [dx, dy] : dirs) {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && 
                        !visited[nx][ny] && forest[nx][ny] != 0) {
                        if (nx == er && ny == ec) return steps;
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return -1;
    };
    
    int totalSteps = 0;
    int currR = 0, currC = 0;
    
    for (auto& [height, r, c] : trees) {
        int steps = bfs(currR, currC, r, c);
        if (steps == -1) return -1;
        totalSteps += steps;
        currR = r;
        currC = c;
    }
    
    return totalSteps;
}

// 39. Shortest Path Visiting All Nodes - Multi-source with bitmask
int shortestPathLength(vector<vector<int>>& graph) {
    int n = graph.size();
    if (n == 1) return 0;
    
    int target = (1 << n) - 1;
    queue<tuple<int, int, int>> q; // {node, mask, dist}
    set<pair<int, int>> visited;
    
    for (int i = 0; i < n; i++) {
        q.push({i, 1 << i, 0});
        visited.insert({i, 1 << i});
    }
    
    while (!q.empty()) {
        auto [node, mask, dist] = q.front(); q.pop();
        
        for (int next : graph[node]) {
            int newMask = mask | (1 << next);
            if (newMask == target) return dist + 1;
            
            if (!visited.count({next, newMask})) {
                visited.insert({next, newMask});
                q.push({next, newMask, dist + 1});
            }
        }
    }
    
    return -1;
}

// 40. Minimum Operations to Convert Number - Multi-source BFS with operations
int minimumOperations(vector<int>& nums, int start, int goal) {
    if (start == goal) return 0;
    
    queue<int> q;
    unordered_set<int> visited;
    q.push(start);
    visited.insert(start);
    int operations = 0;
    
    while (!q.empty()) {
        int size = q.size();
        operations++;
        
        for (int i = 0; i < size; i++) {
            int curr = q.front(); q.pop();
            
            for (int num : nums) {
                vector<int> nextVals = {curr + num, curr - num, curr ^ num};
                
                for (int next : nextVals) {
                    if (next == goal) return operations;
                    
                    if (next >= 0 && next <= 1000 && !visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
        }
    }
    
    return -1;
}

// Testing framework for Multi-source BFS
class MultiSourceBFSTester {
public:
    static void runAllTests() {
        cout << "Running Multi-source BFS Pattern Tests...\n";
        
        // Test 1: Rotting Oranges
        vector<vector<int>> grid1 = {{2,1,1},{1,1,0},{0,1,1}};
        cout << "Test 1 - Rotting Oranges: " << orangesRotting(grid1) << " (Expected: 4)\n";
        
        // Test 3: 01 Matrix
        vector<vector<int>> mat = {{0,0,0},{0,1,0},{1,1,1}};
        auto result = updateMatrix(mat);
        cout << "Test 3 - 01 Matrix completed\n";
        
        // Test 4: Max Distance from Land
        vector<vector<int>> grid2 = {{1,0,1},{0,0,0},{1,0,1}};
        cout << "Test 4 - Max Distance: " << maxDistance(grid2) << " (Expected: 2)\n";
        
        cout << "All Multi-source BFS tests completed!\n";
    }
};