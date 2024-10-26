class {
private:
    bool ok(int i, int j, int n, int m, vector<vector<int>>& ans, vector<vector<bool>> &vis, int color) {
        return (i < n && j < m && i >= 0 && j >= 0 && ans[i][j] == color && !vis[i][j]);
    }

    void dfs(int i, int j, int n, int m, vector<vector<int>>& ans, vector<vector<bool>> &vis, int newColor, int color) {
        vis[i][j] = 1;
        ans[i][j] = newColor;

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        for (int d = 0; d < 4; ++d) {
            int x = i + dx[d];
            int y = j + dy[d];
            if (ok(x, y, n, m, ans, vis, color)) {
                dfs(x, y, n, m, ans, vis, newColor, color);
            }
        }
    }

    void bfs(int i, int j, int n, int m, vector<vector<int>>& ans, vector<vector<bool>> &vis, int newColor, int color) {
        queue<array<int, 2>> q;
        q.push({i, j});
        vis[i][j] = 1;
        ans[i][j] = newColor;

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        while (q.size() > 0) {
            array<int, 2> u = q.front();
            q.pop();
            for (int d = 0; d < 4; ++d) {
                int x = u[0] + dx[d];
                int y = u[1] + dy[d];
                if (ok(x, y, n, m, ans, vis, color)) {
                    q.push({x, y});
                    ans[x][y] = newColor;
                    vis[x][y] = 1;
                }
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
    int newColor) {
        // Code here
        int n = image.size();
        int m = image[0].size();
        int color = image[sr][sc];
        vector<vector<int>>& ans = image;
        vector<vector<bool>> vis(n, vector<bool>(m, 0));

        bfs(sr, sc, n, m, ans, vis, newColor, color);
        // dfs(sr, sc, n, m, ans, vis, newColor, color);

        return ans;
    }
};