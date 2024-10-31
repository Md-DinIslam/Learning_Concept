class solution {
	int MinimumEffort(int n, int m, vector<vector<int>> &heights) {
		vector<vector<int>> dist(n, vector<int>(m, 2e9));
		priority_queue<arr<int, 3>, vector<arr<int, 3>>, greater<arr<int, 3>>> q;
		q.push({0, 0, 0});
		dist[0][0] = 0;

		auto ok = [&](int i, int j) {
			return (i < n && j < m && i >= 0 && j >= 0);
		};

		while (sz(q)) {
			auto it = q.top();
			q.pop();
			int diff = it[0];
			int row = it[1];
			int col = it[2];

			// if (row == n - 1 && col == m - 1)
			//     return diff;

			for (int k = 0; k < 4; ++k) {
				int nrow = row + dx[k];
				int ncol = col + dy[k];

				if (ok(nrow, ncol)) {
					// Answer will be the maximum consecutive cell two cell distance, so need to take minimum distance of maximum differences....
					
					int newEffort = max(abs(heights[nrow][ncol] - heights[row][col]), diff);

					if (dist[nrow][ncol] > newEffort) {
						dist[nrow][ncol] = newEffort;
						q.push({newEffort, nrow, ncol});
					}
				}

			}
		}

		return dist[n - 1][m - 1];
	}
};