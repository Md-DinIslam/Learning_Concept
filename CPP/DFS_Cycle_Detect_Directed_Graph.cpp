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
	
	bool dfs(int src, int par, vector<vector<int>> &adj, vector<bool> &vis, vector<bool> & paths) {
		vis[src] = 1;
		paths[src] = 1;
		bool ok = 0;
		for (auto &x : adj[src]) {
			if (!vis[x]) {
				ok |= dfs(x, src, adj, vis, paths);
			}
			else if (paths[x]) {
				return true;
			}
		}
		paths[src] = 0;
		return ok;
	}

	// Function to detect cycle in a directed graph.
	bool isCyclic(int n, vector<vector<int>> adj) {
		// code here
		vector<bool> vis(n, 0);
		vector<bool> paths(n, 0);

		for (int i = 0; i < n; ++i) {
			if (!vis[i]) {
				if (dfs(i, -1, adj, vis, paths)) {
					return true;
				}
			}
		}
		return false;
	}
};