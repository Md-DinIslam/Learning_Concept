class {
private:
	bool ok(int i, int j, int n, int m, vector<vector<char>> &mat, vector<vector<bool>> &vis)
	{
		return (i < n && j < m && i >= 0 && j >= 0 && mat[i][j] == 'O' && !vis[i][j]);
	}

	void dfs(int i, int j, int n, int m, vector<vector<char>> &mat, vector<vector<char>> &ans, vector<vector<bool>> &vis)
	{
		vis[i][j] = 1;
		ans[i][j] = 'O';

		int dx[4] = {0, 0, 1, -1};
		int dy[4] = {1, -1, 0, 0};

		for (int d = 0; d < 4; ++d) {
			int x = i + dx[d];
			int y = j + dy[d];

			if (ok(x, y, n, m, mat, vis)) {
				dfs(x, y, n, m, mat, ans, vis);
			}
		}
	}

	void bfs(int i, int j, int n, int m, vector<vector<char>> &mat, vector<vector<char>> &ans, vector<vector<bool>> &vis)
	{
		queue<array<int, 2>> q;
		q.push({i, j});
		vis[i][j] = 1;

		while (!q.empty()) {
			auto u = q.front();
			q.pop();
			ans[u[0]][u[1]] = 'O';

			int dx[4] = {0, 0, 1, -1};
			int dy[4] = {1, -1, 0, 0};

			for (int d = 0; d < 4; ++d) {
				int x = u[0] + dx[d];
				int y = u[1] + dy[d];

				if (ok(x, y, n, m, mat, vis)) {
					q.push({x, y});
					vis[x][y] = 1;
				}
			}
		}
	}

public:
	vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
	{
		// code here
		vector<vector<char>> ans(n, vector<char> (m, 'X'));
		vector<vector<bool>> vis(n, vector<bool> (m, 0));

		for (int i = 0; i < n; ++i) {
			if (!i || i == n - 1) {
				for (int j = 0; j < m; ++j) {
					if (mat[i][j] == 'O') {
						dfs(i, j, n, m, mat, ans, vis);
						// bfs(i, j, n, m, mat, ans, vis);
					}
				}
			}
			else {
				if (mat[i][0] == 'O') {
					dfs(i, 0, n, m, mat, ans, vis);
					// bfs(i, 0, n, m, mat, ans, vis);
				}
				if (mat[i][m - 1] == 'O') {
					dfs(i, m - 1, n, m, mat, ans, vis);
					// bfs(i, m - 1, n, m, mat, ans, vis);
				}
			}
		}

		return ans;
	}
};