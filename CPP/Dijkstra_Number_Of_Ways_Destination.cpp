class solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        const int mod = 1e9 + 7;
        vector<arr<int, 2>> adj[n];
        for (auto &it : roads) {
            int u = it[0];
            int v = it[1];
            int cost = it[2];
            adj[u].pb({v, cost});
            adj[v].pb({u, cost});
        }

        vector<int> dist(n, 2e9), ways(n, 0);
        priority_queue<arr<int, 2>> q;
        q.push({ -0, 0});
        dist[0] = 0;
        ways[0] = 1;

        while (sz(q)) {
            int node = q.top()[1];
            int cost = -q.top()[0];
            q.pop();

            for (auto &x : adj[node]) {
                int edge_node = x[0];
                int edge_cost = x[1];
                int curr_cost = cost + edge_cost;

                if (dist[edge_node] > curr_cost) {
                    dist[edge_node] = curr_cost;
                    ways[edge_node] = ways[node];
                    ways[edge_node] %= mod;
                    q.push({ -curr_cost, edge_node});
                }
                else if (dist[edge_node] == curr_cost) {
                    ways[edge_node] += ways[node];
                    ways[edge_node] %= mod;
                }
            }
        }

        // if(dist[n-1] == 2e9) return -1;
        return ways[n - 1];
    }
};