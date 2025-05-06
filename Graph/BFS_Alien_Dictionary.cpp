class Solution {
public:
	string findOrder(string dict[], int n, int k) {
		// code here
		vector<int> g[k]; // Starting size....

		// Go through all the string and make Directed Graph
		for (int i = 0; i < n - 1; ++i) {
			int len = min((int)dict[i].size(), (int)dict[i + 1].size());
			for (int j = 0; j < len; ++j) {
				if (dict[i][j] != dict[i + 1][j]) {
					int x = dict[i][j] - 'a';
					int y = dict[i + 1][j] - 'a';
					g[x].push_back(y);
					break;
				}
			}
		}

		// Topological Sort, Khan's Algorithm.......
		vector<int> indegree(k, 0);
		for (int i = 0; i < k; ++i) {
			for (auto &x : g[i]) {
				indegree[x] += 1;
			}
		}

		queue<int> q;
		for (int i = 0; i < k; ++i) {
			if (!indegree[i]) {
				q.push(i);
			}
		}

		string ans = "";
		while (q.size()) {
			int u = q.front();
			q.pop();
			ans.push_back(u + 'a');
			for (auto &x : g[u]) {
				indegree[x] -= 1;
				if (!indegree[x]) {
					q.push(x);
				}
			}
		}
		// cout << ans << "\n";
		// return (int(ans.size()) == k ? ans : "");
		return ans;
	}
};