class solution {
public:
	// Function to find the shortest distance of all the vertices
	// from the source vertex src.
	vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
		// Code here
		int n = sz(adj);
		// Using min heap.....
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		vector<int> dist(n, 2e9), path(n + 1);

		iota(all(path), 0);
		dist[src] = 0;
		pq.push({0, src});

		while (pq.size()) {
			int wt = pq.top().ff;
			int node = pq.top().ss;
			pq.pop();
			/*
				for using set<arr<int, 2>> st,
					auto it = st.begin();
					st.erase(it);
					int wt = (*it)[0];
					int node = (*it)[1];
			*/

			if (dist[node] < wt) {
				continue;
			}

			for (auto &x : adj[node]) {
				int edge_node = x.ff;
				int edge_wt = x.ss;
				// Taking always better distance....
				if (dist[edge_node] > edge_wt + wt) {
					dist[edge_node] = edge_wt + wt;
					pair[edge_node] = node; // Storing path of shortest path....
					pq.push({dist[edge_node], edge_node});
				}
			}
		}
		
		vector<int> ans;
		int u = n; // path from 1 to N....
		while (u != path[u]) {
			ans.pb(u);
			u = path[u];
		}

		ans.pb(1);
		reverser(all(ans));

		return dist;
	}
};