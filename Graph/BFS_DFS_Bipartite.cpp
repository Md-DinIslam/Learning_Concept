class Solution {
public:
	bool dfs(int src, int color, int n, vector<int>adj[], vector<int> &vis) {
		vis[src] = color;

		for (auto &x : adj[src]) {
			if (vis[x] < 0) {
				if (!dfs(x, !color, n, adj, vis)) {
					return false;
				}
			}
			else if (vis[x] == color) {
				return false;
			}
		}
		return true;
	}

	bool bfs(int src, int n, vector<int>adj[], vector<int> &vis) {
		queue<array<int, 2>> q;
		q.push({src, 0});

		vis[src] = 0;

		while (q.size()) {
			auto u = q.front();
			q.pop();

			for (auto &x : adj[u[0]]) {
				if (vis[x] < 0) {
					vis[x] = u[1] ^ 1;
					q.push({x, u[1] ^ 1});
				}
				else if (vis[x] == u[1]) {
					return false;
				}
			}
		}
		return true;
	}

	bool isBipartite(int n, vector<int>adj[]) {
		// Code here
		vector<int> vis(n, -1);

		for (int i = 0; i < n; ++i) {
			if (vis[i] < 0) {
				// if(!bfs(i, n, adj, vis)) {
				//     return false;
				// }
				if (!dfs(i, 0, n, adj, vis)) {
					return false;
				}
			}
		}
		return true;
	}
};