class solution {
public:
	int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
		// Code here
		vector<arr<int, 2>> adj[n];
		for (auto &it : flights) {
			// U --> V, Wt......
			adj[it[0]].pb({it[1], it[2]});
		}

		vector<int> dist(n, 2e9);
		dist[src] = 0;
		queue<arr<int, 3>> q;
		// stops, source, distance....
		q.push({0, src, 0});

		while (sz(q)) {
			auto it = q.front();
			q.pop();

			int stops = it[0];
			int node = it[1];
			int node_dist = it[2];

			if (stops > k) {
				// continue;
				break;
			}

			for (auto &x :  adj[node]) {
				int edge_node = x[0];
				int edge_dist = x[1];
				int curr_dist = edge_dist + node_dist;
				if (dist[edge_node] > curr_dist) {
					dist[edge_node] = curr_dist;
					q.push({stops + 1, edge_node, curr_dist});
				}
			}
		}

		if (dist[dst] == 2e9) return -1;
		return dist[dst];
	}
};