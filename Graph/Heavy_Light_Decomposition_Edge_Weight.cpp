/* GREEN UNIVERSITY OF BANGLADESH
    Md DinIslam, Batch-221 (CSE)
*/
#include <bits/stdc++.h>
using namespace std;

// Debug..
#ifdef LOCAL
#include "debug.h"
#else
#define dg(x...)
#endif

#define ll long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define sz(x) int(x.size())
#define arr array

const int mxN = 1e5 + 9;

vector<int> g[mxN], depth(mxN), parents(mxN), heavy(mxN), root(mxN), start(mxN), weigth(mxN);

int timer = 0;

void reset(int n) {
    for (int i = 0; i <= n; ++i) {
        g[i].clear();
        depth[i] = 0;
        parents[i] = 0;
        heavy[i] = -1;
        root[i] = 0;
        start[i] = 0;
        weigth[i] = 0;
    }
    timer = 0;
}

int dfs(int node, int par) {
    int subTree = 1, maxChildSize = 0;
    depth[node] = depth[par] + 1;
    parents[node] = par;

    for (auto &child : g[node]) {
        if (child ^ par) {
            int childSize = dfs(child, node);
            subTree += childSize;
            if (childSize > maxChildSize) {
                maxChildSize = childSize;
                heavy[node] = child;
            }
        }
    }
    return subTree;
}

void HLD(int node, int par, int top) {
    root[node] = top;
    start[node] = timer++;

    if (heavy[node] != -1) {
        HLD(heavy[node], node, top);
    }

    for (auto &child : g[node]) {
        if (child != par && child != heavy[node]) {
            HLD(child, node, child);
        }
    }
}

class segTree { // also can use recursive, mxN <= 1e4...
    vector<int> sg;
public:
    segTree(int n) : sg(4 * n + 1) {}

    void upd(int indx, int val, int n) {
        // sg[indx += n] = val;
        indx += n;
        sg[indx] = val;
        indx /= 2;

        while (indx) {
            sg[indx] = max(sg[2 * indx], sg[2 * indx + 1]);
            indx /= 2;
        }
    }

    int qry(int lb, int rb, int n) {
        lb += n, rb += n + 1;
        int max_a = 0, max_b = 0;

        while (lb < rb) {
            if (lb & 1) {
                max_a = max(max_a, sg[lb]);
                lb += 1;
            }
            if (rb & 1) {
                rb -= 1;
                max_b = max(max_b, sg[rb]);
            }
            lb /= 2, rb /= 2;
        }
        return max(max_a, max_b);
    }
};

int getMax(int a, int b, int n, segTree &t) {
    int ans = 0;
    while (root[a] ^ root[b]) {
        if (depth[root[a]] < depth[root[b]]) {
            swap(a, b);
        }
        ans = max(ans, t.qry(start[root[a]], start[a], n));
        a = parents[root[a]];
    }
    if (depth[a] > depth[b]) {
        swap(a, b);
    }

    if (a != b) {
        // start[a] + 1 is for excluding LCA, because of Edge Weight...
        ans = max(ans, t.qry(start[a] + 1, start[b], n));
    }
    
    return ans;
}

void Din() {
    int n;
    cin >> n;

    reset(n);

    vector<int> u(n + 1), v(n + 1), cost(n + 1);
    for (int i = 1; i < n; ++i) {
        cin >> u[i] >> v[i] >> cost[i];
        int x = u[i];
        int y = v[i];
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1, 0);
    HLD(1, 0, 1);

    for (int i = 1; i < n; ++i) {
        int x = u[i];
        int y = v[i];

        if (parents[x] == y) {
            weigth[x] = cost[i];
        }
        else {
            weigth[y] = cost[i];
        }
    }

    segTree t(n); // also can use 'Timer' instead 'N'..

    for (int i = 1; i <= n; ++i) {
        t.upd(start[i], weigth[i], n);
    }

    while (true) {
        string tp;
        cin >> tp;
        if (tp[0] == 'D') return;
        if (tp[0] == 'Q') {
            int a, b;
            cin >> a >> b;
            cout << getMax(a, b, n, t) << '\n';
        }
        else {
            int indx, val;
            cin >> indx >> val;

            int x = u[indx];
            int y = v[indx];

            if (parents[x] == y) {
                indx = start[x];
            }
            else {
                indx = start[y];
            }

            t.upd(indx, val, n);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        // cout << "Case " << i << ": ";
        Din();
    }
    return 0;
}


/*
Question: https://www.spoj.com/problems/QTREE/
*/