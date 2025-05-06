class DSU {
private:
    vector<int> par, sizes;
public:
    DSU(int n) {
        par.resize(n);
        sizes.resize(n, 1);
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

    int getSize(int node) {
        return sizes[node];
    }

    int getCount(int n) {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (par[i] == i) {
                cnt += (getSize(i) > 1);
            }
        }
        return cnt;
    }
};

class Solution {
public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
        int row = 0, col = 0;
        for (auto &x : stones) {
            row = max(row, x[0]);
            col = max(col, x[1]);
        }

        int m = row + col + 1;
        DSU t(m + 1);

        for (auto &x : stones) {
            int i = x[0];
            int j = x[1];
            if (t.Find(i) != t.Find(row + j + 1)) {
                t.Union(i, row + j + 1);
            }
        }

        // return t.getCount(m);
        int cnt = t.getCount(m + 1);
        return n - cnt;
    }
};