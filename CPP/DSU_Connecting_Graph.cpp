class Solution {
private:
	int Find(int node, vector<int> &par) {
		if (node == par[node]) return node;
		return par[node] = Find(par[node], par);
	}

	void Union(int x, int y, vector<int> &sizes, vector<int> &par) {
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

public:
	int Solve(int n, vector<vector<int>>& edge) {
		// code here
		vector<int> g[n], sizes(n, 1), par(n);
		iota(par.begin(), par.end(), 0);

		int extra_cnt = 0;
		for (auto &x : edge) {
			int u = x[0];
			int v = x[1];
			g[u].push_back(v);

			if (Find(u, par) != Find(v, par)) {
				Union(u, v, sizes, par);
			}
			else {
				// if ultimate parent are same, there have a extra edge...
				extra_cnt += 1;
			}
		}

		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			// counting number of connected component......
			cnt += (par[i] == i);
		}

		cnt -= 1;
		if (extra_cnt >= cnt) return cnt;
		else return -1;
	}
};