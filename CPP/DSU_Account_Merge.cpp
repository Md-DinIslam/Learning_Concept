class solution {
private:
	int Find(int node, vector<int> &par) {
		if (node == par[node]) {
			return node;
		}
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
	vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
		int n = accounts.size();
		map<string, int> mailNode;
		vector<int> sizes(n, 1), par(n);
		iota(par.begin(), par.end(), 0);

		for (int i = 0; i < n; ++i) {
			int m = accounts[i].size();
			for (int j = 1; j < m; ++j) {
				string mail = accounts[i][j];
				if (mailNode.find(mail) == mailNode.end()) {
					mailNode[mail] = i;
				}
				else {
					Union(i, mailNode[mail], sizes, par);
				}
			}
		}

		vector<string> mergedMail[n];
		for (auto &x : mailNode) {
			string mail = x.first;
			int node = x.second;
			int parNode = Find(node, par);
			mergedMail[parNode].push_back(mail);
		}

		vector<vector<string>> ans;
		for (int i = 0; i < n; ++i) {
			if (mergedMail[i].size()) {
				vector<string> temp;
				temp.push_back(accounts[i][0]);
				for (auto &x : mergedMail[i]) {
					temp.push_back(x);
				}
				ans.push_back(temp);
			}
		}

		return ans;
	}
};