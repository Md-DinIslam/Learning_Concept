class Solution {
	// Using Kruskal Algorithm.....
	int Find(int node, vector<int> &par) {
		if (node == par[node]) {
			return node;
		}
		return par[node] = Find(par[node], par);
	}

	void Union(int x, int y, vector<int> &par, vector<int> &sizes) {
		int par_x = Find(x, par);
		int par_y = Find(y, par);
		if (par_x == par_y) return;

		if (sizes[par_x] < sizes[par_y]) {
			par[par_x] = par_y;
			sizes[par_y] += sizes[par_x];
		}
		else {
			par[par_y] = par_x;
			sizes[par_x] += sizes[par_y];
		}
	}

	int mstKruskalDSU(int n, vector<vector<int>> adj[]) {
		vector<int> sizes(n, 1), par(n);
		iota(all(par), 0);

		vector<arr<int, 3>> g;
		for (int i = 0; i < n; ++i) {
			for (auto &x : adj[i]) {
				int u = i;
				int v = x[0];
				int wt = x[1];
				g.pb({wt, u, v});
				g.pb({wt, v, u});
			}
		}

		sort(all(g)); // Nver forget to sorting by weight.....
		int sum = 0;

		for (auto &x : g) {
			int wt = x[0];
			int u = x[1];
			int v = x[2];
			// If there parent not same, they are not taken before... so we can take it and make their union...
			if (Find(u, par) != Find(v, par)) {
				Union(u, v, par, sizes);
				sum += wt;
			}
		}

		return sum;
	}
};