int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

class DSU {
private:
    vector<int> par, sizes;
public:
    DSU(int n, int m) {
        par.resize(n * m);
        sizes.resize(n * m, 1);
        iota(par.begin(), par.end(), 0);
    }

    int Find(int node) {
        if (node == par[node]) return node;
        return par[node] = Find(par[node]);
    }

    void Union(int x, int y) {
        int par_x = Find(x);
        int par_y = Find(y);
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
};

class solution {
public:
    bool ok(int i, int j, int n, int m, vector<vector<bool>> &vis) {
        return (i >= 0 && j >= 0 && i < n && j < m && vis[i][j]);
    }

    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        int k = operators.size();
        // int mk = operators[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, 0));
        DSU t(n, m);
        int cnt = 0;
        vector<int> ans;

        for (int i = 0; i < k; ++i) {
            int x = operators[i][0];
            int y = operators[i][1];

            if (!vis[x][y]) {
                // t.Union(x*m + y, x*m + y);
                vis[x][y] = 1;
                cnt += 1;
            }

            int node = x * m + y;
            for (int d = 0; d < 4; ++d) {
                int ni = x + dx[d];
                int nj = y + dy[d];
                if (ok(ni, nj, n, m, vis)) {
                    int new_node = ni * m + nj;
                    if (t.Find(new_node) != t.Find(node)) {
                        t.Union(node, new_node);
                        cnt -= 1;
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};