class solution {
public:
	int findCity(int n, int m, vector<vector<int>>& edges, int distTh) {
		// Your code here
		vector<vector<int>> dist(n, vector<int> (n, 1e9));

		for (auto &it : edges) {
			int u = it[0];
			int v = it[1];
			int cost = it[2];
			dist[u][v] = cost;
			dist[v][u] = cost;
		}

		for (int i = 0; i < n; ++i) {
			dist[i][i] = 0;
		}

		for (int via = 0; via < n; ++via) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
				}
			}
		}

		int min_cnt = n + 1;
		int max_city = -1;

		for (int i = 0; i < n; ++i) {
			int curr_cnt = 0;
			for (int j = 0; j < n; ++j) {
				if (dist[i][j] <= distTh) {
					curr_cnt += 1;
				}
			}
			if (curr_cnt < min_cnt) {
				min_cnt = curr_cnt;
				max_city = i;
			}
			else if (curr_cnt == min_cnt) {
				max_city = max(max_city, i);
			}
		}

		return max_city;
	}
};