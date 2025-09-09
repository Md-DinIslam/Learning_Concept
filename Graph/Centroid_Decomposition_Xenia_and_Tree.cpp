/* GREEN UNIVERSITY OF BANGLADESH
    Md DinIslam, Batch-221 (CSE)
    Time: 15:17:51
    Date: 07-09-2025
*/

#include <bits/stdc++.h>
using namespace std;

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

vector<vector<int>> g, parents;
vector<int> subtree, centParent, depth, distRED;
vector<bool> vis;

int logN;

void reset(int n) {
    logN = 32 - __builtin_clz(n);
    // dg(logN);
    parents.assign(n + 1, vector<int> (logN, 0));
    g.assign(n + 1, {});
    subtree.assign(n + 1, 0);
    depth.assign(n + 1, 0);
    distRED.assign(n + 1, 2e9);
    vis.assign(n + 1, 0);
    centParent.assign(n + 1, 0);
}

void dfs(int node, int par) {
    subtree[node] = 1;

    for (auto &child : g[node]) {
        if (child != par && !vis[child]) {
            dfs(child, node);
            subtree[node] += subtree[child];
        }
    }
}

void dfs2(int node, int par) {
    depth[node] = depth[par] + 1;
    parents[node][0] = par;

    for (int i = 1; i < logN; ++i) {
        parents[node][i] = parents[parents[node][i - 1]][i - 1];
    }

    for (auto &child : g[node]) {
        if (child != par) {
            dfs2(child, node);
        }
    }
}

int getCentroid(int node, int par, int new_subtree) {
    int centroid = node;
    for (auto &child : g[node]) {
        if (child != par && !vis[child] && (subtree[child] * 2 > new_subtree)) {
            centroid = getCentroid(child, node, new_subtree);
        }
    }
    return centroid;
}

void buildCentroid(int node, int par) {
    dfs(node, 0);
    int centroid = getCentroid(node, par, subtree[node]);
    vis[centroid] = 1;
    centParent[centroid] = par;

    for (auto &child : g[centroid]) {
        if (!vis[child]) {
            buildCentroid(child, centroid);
        }
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b])
        swap(a, b);

    int diff = depth[a] - depth[b];

    for (int i = 0; i < logN; ++i) {
        if ((diff >> i) & 1) {
            a = parents[a][i];
        }
    }

    if (a == b) return a;

    for (int i = logN - 1; ~i; --i) {
        if (parents[a][i] != parents[b][i]) {
            a = parents[a][i];
            b = parents[b][i];
        }
    }

    return parents[a][0];
}

int distLCA(int a, int b) {
    return depth[a] + depth[b] - 2 * depth[lca(a, b)];
}

void upd(int node) {
    int u = node;
    while (u != 0) {
        distRED[u] = min(distRED[u], distLCA(node, u));
        u = centParent[u];
    }
}

int qry(int node, int n) {
    int ans = n;
    int u = node;
    while (u != 0) {
        ans = min(ans, distRED[u] + distLCA(node, u));
        u = centParent[u];
    }
    return ans;
}

void Din() {
    int n, q;
    cin >> n >> q;

    reset(n);

    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    buildCentroid(1, 0);
    dfs2(1, 0); // for LCA..

    upd(1);

    while (q--) {
        int tp, node;
        cin >> tp >> node;
        if (tp == 1) {
            upd(node);
        }
        else {
            cout << qry(node, n) << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; ++i) {
        // cout << "Case " << i << ": ";
        Din();
    }
    return 0;
}
