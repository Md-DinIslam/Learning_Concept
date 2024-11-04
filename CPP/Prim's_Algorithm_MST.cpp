class solution {
public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int spanningTree(int n, vector<vector<int>> adj[])
	{
		// code here
		vector<bool> vis(n, 0);
		
		// If we want to find the path of MST, then we need to store {cost, src, par} into the queue.....
		
		priority_queue<arr<int, 2>> q;
		q.push({0, 0});
		int sum = 0;

		while (sz(q)) {
			int cost = q.top()[0] * -1;
			int node = q.top()[1];
			q.pop();

			// If visited, don't need to do any farther operation....
			if (vis[node]) {
				continue;
			}

			vis[node] = 1;
			sum += cost;

			// Visit all the adjacent node, and if it is not visited then put it into the queue......
			for (auto &x : adj[node]) {
				int edge_node = x[0];
				int edge_cost = x[1];

				if (!vis[edge_node]) {
					q.push({ -edge_cost, edge_node});
				}
			}
		}
		return sum;
	}
};