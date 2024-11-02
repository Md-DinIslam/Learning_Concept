class solution {
public:
	/*  Function to implement Bellman Ford
	 *   edges: vector of vectors which represents the graph
	 *   src: source vertex to start traversing graph with
	 *   n: number of vertices
	 */
	vector<int> bellmanFord(int n, vector<vector<int>>& edges, int src) {
		vector<int> dist(n, 1e8);
		dist[src] = 0;

		// Relaxation....
		for (int i = 0; i < n - 1; ++i) {
			for (auto &it : edges) {
				int u = it[0];
				int v = it[1];
				int cost = it[2];

				if (dist[u] != 1e8 && dist[v] > dist[u] + cost) {
					dist[v] = dist[u] + cost;
				}
			}
		}

		// N-th relaxation for checking negative cycle.....
		for (auto &it : edges) {
			int u = it[0];
			int v = it[1];
			int cost = it[2];
			if (dist[u] != 1e8 && dist[v] > dist[u] + cost) {
				return { -1};
			}
		}

		return dist;
	}
};