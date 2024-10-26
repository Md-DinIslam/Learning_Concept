class {
private:
    bool ok(int i, int j, int n, int m, vector<vector<char>>& grid, vector<vector<bool>> &vis) {
        return (i >= 0 && j >= 0 && i < n && j < m  && grid[i][j] == '1' && !vis[i][j]);
    }
    
    // DFS.....
    void dfs(int i, int j,int n, int m, vector<vector<char>>& grid, vector<vector<bool>> &vis) {
        vis[i][j] = 1;
        
        int dx[8] = {1, 1, 1, -1, -1, -1, 0, 0};
        int dy[8] = {1, -1, 0, 1, -1, 0, 1, -1};
        
        for(int dd = 0; dd < 8; ++dd) {
            int i2 = i + dx[dd];
            int j2 = j + dy[dd];
            
            if(ok(i2, j2, n, m, grid, vis)) {
                dfs(i2, j2,n, m, grid, vis);
            }
        }
    }
    
    // BFS......
    void bfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>> &vis) {
        vis[i][j] = 1;
        queue<pair<int, int>> q;
        q.push({i, j});

        int n = grid. size();
        int m = grid[0].size();

        while (q.size() > 0) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            // Using 8-direction....
            // for (int di = -1; di < 2; ++di) {
            //     for (int dj = -1; dj < 2; ++dj) {
            //         int i2 = x + di;
            //         int j2 = y + dj;
            //         if (ok(i2, j2, n, m, grid, vis)) {
            //             vis[i2][j2] = 1;
            //             q.push({i2, j2});
            //         }
            //     }
            // }
            
            // Using 8-direction....
            int di[8] = {1, 0, -1, 0, 1, -1, -1, 1};
            int dj[8] = {0, 1, 0, -1, 1, 1, -1, -1};
            
            for(int dd = 0; dd < 8; ++dd) {
                int i2 = x + dx[dd]; 
                int j2 = y + dy[dd];
                if(ok(i2, j2, n, m, grid, vis)) {
                    vis[i2][j2] = 1;
                    q.push({i2, j2});
                }
            }
        }
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    bfs(i, j, grid, vis);
                    ans += 1;
                }
            }
        }
        return ans;
    }
};