class solution {
private:
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
		if (par[par_x] < par[par_y]) {
			par[par_x] = par_y;
			sizes[par_y] += sizes[par_x];
		}
		else {
			par[par_y] = par_x;
			sizes[par_x] += sizes[par_y];
		}
	}

public:
	int numProvinces(vector<vector<int>> adj, int n) {
		// code here
		vector<int> par(n), sizes(n, 1);
		iota(par.begin(), par.end(), 0);
		vector<int> g[n];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (adj[i][j] == 1) {
					g[i].push_back(j);
					g[j].push_back(i);

					// In Union(i, j) == (j, i)...
					Union(i, j, par, sizes);
					// Union(j, i, par, sizes);
				}
			}
		}

		// set<int> st;
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			// for (auto &x : g[i]) {
			// 	// Finding all the node's ulimate parent....
			// 	st.insert(Find(x, par));
			// }
			cnt += (par[i] == i);
		}

		// return int(st.size());
		return cnt;
	}
};