class solution {
public:
	// Using Khan's Algorihtm........
	void bfs(int n, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &order, vector<int> &indegree)
	{
		queue<int> q;
		for (int i = 0; i < n; ++i) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}

		while (q.size()) {
			int u = q.front();
			q.pop();
			order.push_back(u);

			for (auto &x : adj[u]) {
				indegree[x] -= 1;
				if (!indegree[x]) {
					q.push(x);
				}
			}
		}
	}

	void dfs(int src, int par, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &order)
	{
		vis[src] = 1;
		for (auto &x : adj[src]) {
			if (!vis[x]) {
				dfs(x, src, adj, vis, order);
			}
		}
		order.push_back(src);
	}

	// Function to return list containing vertices in Topological order.
	vector<int> topologicalSort(vector<vector<int>>& adj) {
		// Your code here
		int n = adj.size();
		vector<bool> vis(n, 0);
		vector<int> order, indegree(n, 0);

		for (int i = 0; i < n; ++i) {
			for (auto &x : adj[i]) {
				indegree[x] += 1;
			}
		}

		bfs(n, adj, vis, order, indegree);

		for (int i = 0; i < n; ++i) {
			if (!vis[i]) {
				// dfs(i, -1, adj, vis, order);
			}
		}

		// If use dfs then reverse it.....
		// reverse(order.begin(), order.end());

		return order;
	}
};