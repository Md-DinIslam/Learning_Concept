class solution {
public:
	bool dfs(int src, int par, vector<int> adj[], vector<int> &vis, vector<int> &check, vector<int> &safeNodes)
	{
		vis[src] = 1;
		check[src] = 0;
		for (auto &x : adj[src]) {
			if (!vis[x]) {
				if (dfs(x, par, adj, vis, check, safeNodes)) {
					return true;
				}
			}
			else if (vis[x] == 1) {
				return true;
			}
		}
		safeNodes.push_back(src);
		// check[src] = 1;
		vis[src] = 2;
		return false;
	}

	vector<int> eventualSafeNodes(int n, vector<int> adj[]) {
		// code here
		vector<int> vis(n, 0), check(n, 0), safeNodes;

		for (int i = 0; i < n; ++i) {
			if (!vis[i]) {
				dfs(i, -1, adj, vis, check, safeNodes);
			}
		}
		sort(safeNodes.begin(), safeNodes.end());
		// for(int i = 0;i < n; ++i) {
		//     if(check[i] == 1) {
		//         safeNodes.push_back(i);
		//     }
		// }
		return safeNodes;
	}
};