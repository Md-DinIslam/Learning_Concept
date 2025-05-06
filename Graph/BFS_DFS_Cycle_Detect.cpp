class Solution {
private:
	bool dfs(int src, int par, vector<vector<int>> &g, vector<bool> &vis) {
		vis[src] = 1;
		bool ok = 0;
		for (auto &x : g[src]) {
			if (!vis[x]) {
				ok |= dfs(x, src, g, vis);
			}
			else if (par != x) {
				return true;
			}
		}
		return ok;
	}

	bool bfs(int src, int par, vector<vector<int>> &g, vector<bool> &vis) {
		queue<array<int, 2>> q;
		q.push({src, par});
		vis[src] = 1;

		while (!q.empty()) {
			array<int, 2> u = q.front();
			q.pop();
			for (auto &x : g[u[0]]) {
				if (!vis[x]) {
					q.push({x, u[0]});
					vis[x] = 1;
				}
				else if (x != u[1]) {
					return true;
				}
			}
		}
		return false;
	}

public:
	// Function to detect cycle in an undirected graph.
	bool isCycle(vector<vector<int>> adj) {
		// Code here
		int n = adj.size();
		int m = adj[0].size();

		vector<bool> vis(n, 0);

		for (int i = 0; i < n; ++i) {
			if (!vis[i]) {
				// if(bfs(i, -1, adj, vis)) {
				//     return true;
				// }
				if (dfs(i, -1, adj, vis)) {
					return true;
				}
			}
		}

		return false;
	}
};
