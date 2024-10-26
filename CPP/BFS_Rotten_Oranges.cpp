class {
private:
	bool ok(int i, int j, int n, int m, vector<vector<int>>& ans, vector<vector<bool>>& vis) {
		return (i < n && j < m && i >= 0 && j >= 0 && ans[i][j] == 1 && !vis[i][j]);
	}

	int bfs(int n, int m, vector<vector<int>>& ans, vector<vector<bool>>& vis) {
		// {{row, col}, time}....
		queue<pair<array<int, 2>, int>> q;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (ans[i][j] == 2) {
					q.push({{i, j}, 0});
					vis[i][j] = 1;
				}
			}
		}

		int ans_time = 0;
		while (!q.empty()) {
			int row = q.front().first[0];
			int col = q.front().first[1];
			int curr_time = q.front().second;
			q.pop();
			ans_time = max(ans_time, curr_time);

			int dx[4] = {0, 0, 1, -1};
			int dy[4] = {1, -1, 0, 0};

			for (int d = 0; d < 4; ++d) {
				int nrow = row + dx[d];
				int ncol = col + dy[d];

				if (ok(nrow, ncol, n, m, ans, vis)) {
					q.push({{nrow, ncol}, curr_time + 1});
					vis[nrow][ncol] = 1;
					ans[nrow][ncol] = 2;
				}
			}
		}

		return ans_time;
	}
public:
	// Function to find minimum time required to rot all oranges.
	int orangesRotting(vector<vector<int>>& mat) {
		// Code here
		int n = mat.size();
		int m = mat[0].size();

		vector<vector<int>> ans = mat;
		vector<vector<bool>> vis(n, vector<bool> (m, 0));

		int ans_time = bfs(n, m, ans, vis);

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (ans[i][j] == 1) {
					return -1;
				}
			}
		}

		return ans_time;
	}
};

// Using 3-dimansion array......
class {
public:
	// Function to find minimum time required to rot all oranges.
	int orangesRotting(vector<vector<int>>& mat) {
		// Code here
		queue<array<int, 3>> q;

		int n = mat.size();
		int m = mat[0].size();

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (mat[i][j] == 2) {
					q.push({i, j, 0});
				}
			}
		}

		vector<vector<bool>> vis(n, vector<bool> (m, 0));

		auto ok = [&](int i, int j) {
			return (i < n && j < m && i >= 0 && j >= 0 && mat[i][j] == 1 && !vis[i][j]);
		};

		int ans = 0;
		while (!q.empty()) {
			array<int, 3> u = q.front();
			// int curr_time = q.front()[2];
			q.pop();
			ans = max(ans, u[2]);

			int dx[4] = {0, 0, 1, -1};
			int dy[4] = {1, -1, 0, 0};

			for (int d = 0; d < 4; ++d) {
				int x = u[0] + dx[d];
				int y = u[1] + dy[d];

				if (ok(x, y)) {
					q.push({x, y , u[2] + 1});
					vis[x][y] = 1;
					mat[x][y] = 2;
				}
			}
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (mat[i][j] == 1) {
					return -1;
				}
			}
		}

		return ans;
	}
};