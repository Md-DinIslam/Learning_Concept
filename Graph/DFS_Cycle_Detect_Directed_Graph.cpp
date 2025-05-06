class solution {
public:
	/*
		If we want to find cycle without use extra array 'Paths', we should do the following things....

		dfs(src, par, g[], vis[]) {
			vis[src] = 1; // marking it paths visiting....
			for(x...g[src]) {
				if(!vis[x])
					dfs(......);
				else if(vis[x] == 1)
					return true; // cylce found....
			}
			vis[src] = 2; // marking it visited.....
		}

	*/
	
	bool dfs(int src, int par, vector<vector<int>> &adj, vector<int> &vis, vector<bool> & paths) {
		vis[src] = 1;
		paths[src] = 1;
		bool ok = 0;
		for (auto &x : adj[src]) {
			if (!vis[x]) {
				ok |= dfs(x, src, adj, vis, paths);
			}
			else if (paths[x] == 1) {
				return true;
			}
		}
		paths[src] = 0;
		// vis[src] = 2;
		return ok;
	}

	// Function to detect cycle in a directed graph.
	bool isCyclic(int n, vector<vector<int>> adj) {
		// code here
		vector<int> vis(n, 0);
		vector<bool> paths(n, 0);

		for (int i = 0; i < n; ++i) {
			if (!vis[i]) {
				// if(dfs(i, -1, adj, vis, paths)) {
				//     return true;
				// }
			}
		}

		// Cycle find in Directed Graph using Khan's Algorithm.... BFS technique....
		auto bfs = [&] () {
			vector<int> indegree(n, 0);

			for (int i = 0; i < n; ++i) {
				for (auto &x : adj[i])
					indegree[x] += 1;
			}

			queue<int> q;
			for (int i = 0; i < n; ++i) {
				if (!indegree[i])
					q.push(i);
			}

			int cnt = 0;
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				cnt += 1;
				for (auto &x : adj[u]) {
					indegree[x] -= 1;
					if (!indegree[x])
						q.push(x);
				}
			}
			return (cnt < n);
		};

		if (bfs()) return true;;

		return false;
	}
};
