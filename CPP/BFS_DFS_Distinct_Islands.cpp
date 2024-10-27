class Solution {
private:
	bool ok(int i, int j, int n, int m, vector<vector<int>> &grid, vector<vector<bool>> &vis)
	{
		return (i < n && j < m && i >= 0 && j >= 0 && grid[i][j] == 1 && !vis[i][j]);
	}

	void dfs(int i, int j, int n, int m, vector<vector<int>> &grid, vector<array<int, 2>> &ls, vector<vector<bool>> &vis, int baseR, int baseC)
	{
		vis[i][j] = 1;
		ls.push_back({i - baseR, j - baseC});

		int dx[4] = {0, 0, 1, -1};
		int dy[4] = {1, -1, 0, 0};

		for (int d = 0; d < 4; ++d) {
			int x = i + dx[d];
			int y = j + dy[d];
			if (ok(x, y, n, m, grid, vis)) {
				dfs(x, y, n, m, grid, ls, vis, baseR, baseC);
			}
		}
	}

	void bfs(int i, int j, int n, int m, vector<vector<int>> &grid, vector<array<int, 2>> &ls, vector<vector<bool>> &vis, int baseR, int baseC)
	{
		queue<array<int, 2>> q;
		q.push({i, j});
		vis[i][j] = 1;
		ls.push_back({i - baseR, j - baseC});

		int dx[4] = {0, 0, 1, -1};
		int dy[4] = {1, -1, 0, 0};

		while (!q.empty()) {
			auto u = q.front();
			q.pop();
			ls.push_back({u[0] - baseR, u[1] - baseC});

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

public:
	int countDistinctIslands(vector<vector<int>>& grid) {
		// code here
		int n = grid.size();
		int m = grid[0].size();

		vector<vector<bool>> vis(n, vector<bool> (m, 0));
		set<vector<array<int, 2>>> dist;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				vector<array<int, 2>> temp;
				if (grid[i][j] == 1 && !vis[i][j]) {
					// dfs(i, j, n, m, grid, temp, vis, i, j);
					bfs(i, j, n, m, grid, temp, vis, i, j);
					dist.insert(temp);
				}
			}
		}

		return int(dist.size());
	}
};
