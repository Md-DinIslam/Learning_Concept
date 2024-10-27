class Solution {
private:
	bool ok(int i, int j, int n, int m, vector<vector<int>> &grid, vector<vector<bool>> &vis)
	{
		return (i < n && j < m && i >= 0 && j >= 0 && grid[i][j] == 1 && !vis[i][j]);
	}

	void bfs(int i, int j, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &ans, vector<vector<bool>> &vis)
	{
		queue<array<int, 2>> q;
		q.push({i, j});
		vis[i][j] = 1;
		ans[i][j] = 0;

		int dx[4] = {0, 0, 1, -1};
		int dy[4] = {1, -1, 0, 0};

		while (!q.empty()) {
			auto u = q.front();
			q.pop();
			ans[u[0]][u[1]] = 0;

			for (int d = 0; d < 4; ++d) {
				int x = u[0] + dx[d];
				int y = u[1] + dy[d];

				if (ok(x, y, n, m, grid, vis)) {
					q.push({x, y});
					vis[x][y] = 1;
				}
			}
		}
	}

	void dfs(int i, int j, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &ans, vector<vector<bool>> &vis)
	{
		vis[i][j] = 1;
		ans[i][j] = 0;

		int dx[4] = {0, 0, 1, -1};
		int dy[4] = {1, -1, 0, 0};

		for (int d = 0; d < 4; ++d) {
			int x = i + dx[d];
			int y = j + dy[d];

			if (ok(x, y, n, m, grid, vis)) {
				dfs(x, y, n, m, grid, ans, vis);
			}
		}
	}

public:
	int numberOfEnclaves(vector<vector<int>> &grid) {
		// Code here
		int n = grid.size();
		int m = grid[0].size();

		vector<vector<int>> ans = grid;
		vector<vector<bool>> vis(n, vector<bool> (m, 0));

		for (int i = 0; i < n; ++i) {
			if (!i || i == n - 1) {
				for (int j = 0; j < m; ++j) {
					if (grid[i][j] == 1) {
						// bfs(i, j, n, m, grid, ans, vis);
						dfs(i, j, n, m, grid, ans, vis);
					}
				}
			}
			else {
				if (grid[i][0] == 1) {
					// bfs(i, 0, n, m, grid, ans, vis);
					dfs(i, 0, n, m, grid, ans, vis);
				}
				if (grid[i][m - 1]) {
					// bfs(i, m-1, n, m, grid, ans, vis);
					dfs(i, m - 1, n, m, grid, ans, vis);
				}
			}
		}

		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cnt += (ans[i][j] == 1);
			}
		}

		return cnt;
	}
};
