class Solution {
public:
	void dfs(int src, vector<array<int, 2>> g[], vector<bool> &vis, stack<int> &st) {
		vis[src] = 1;
		for (auto &x : g[src]) {
			int v = x[0];
			if (!vis[v]) {
				dfs(v, g, vis, st);
			}
		}
		st.push(src);
	}

	void bfs(int n, int m, vector<array<int, 2>> g[], vector<int> &v) {
		vector<int> indegree(n, 0);
		for (int i = 0; i < n; ++i) {
			for (auto &x : g[i]) {
				int v = x[0];
				// int wt = x[1];
				indegree[v] += 1;
			}
		}

		queue<int> q;
		for (int i = 0; i < n; ++i) {
			if (!indegree[i]) {
				q.push(i);
			}
		}
		// debug(q);

		while (q.size()) {
			int u = q.front();
			q.pop();
			v.push_back(u);
			for (auto &x : g[u]) {
				indegree[x[0]] -= 1;
				if (!indegree[x[0]]) {
					q.push(x[0]);
				}
			}
		}
	}

	void output(stack<int> st) {
		while (!st.empty()) {
			cout << st.top() << " ";
			st.pop();
		} cout << '\n';
	}

	vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
		// code here
		vector<array<int, 2>> g[n];
		for (int i = 0; i < m; ++i) {
			int u = edges[i][0];
			int v = edges[i][1];
			int wt = edges[i][2];
			g[u].push_back({v, wt});
		}

		vector<bool> vis(n, 0);
		stack<int> st;

		// Using DFS.....
		for (int i = 0; i < n; ++i) {
			if (!vis[i]) {
				// dfs(i, g, vis, st);
			}
		}

		// Using BFS.....
		vector<int> v;
		bfs(n, m, g, v);

		reverse(v.begin(), v.end()); // Topological Sort...
		for (auto &x : v) {
			st.push(x);
			// cout << x << " ";
		}

		// output(st);

		vector<int> dis(n, 1e9);
		dis[0] = 0;
		while (!st.empty()) {
			int src = st.top();
			st.pop();
			for (auto &x : g[src]) {
				int v = x[0];
				int wt = x[1];
				dis[v] = min(dis[v], dis[src] + wt);
			}
		}

		for (auto &x : dis) {
			if (x == 1e9)
				x = -1;
		}
		return dis;
	}
};