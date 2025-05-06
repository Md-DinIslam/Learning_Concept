class solution {
public:
	int minimumMultiplications(vector<int>& v, int start, int end) {
		// code here
		const int mod = 1e5;
		vector<int> dist(mod, 2e9);
		queue<arr<int, 2>> q;
		// source, steps....
		q.push({start, 0});

		while (sz(q)) {
			int node = q.front()[0];
			int steps = q.front()[1];
			q.pop();

			if (node == end) {
				return steps;
			}

			for (auto &x : v) {
				int a = (x * node) % mod;
				if (dist[a] > steps + 1) {
					dist[a] = steps + 1;
					q.push({a, steps + 1});
				}
			}
		}
		return -1;
	}
};