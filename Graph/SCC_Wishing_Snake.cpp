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
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()

const int mxN = 1e3 + 9;

vector<int> g[mxN], g2[mxN], scc[mxN], color(mxN), compress(mxN);
vector<bool> vis(mxN);
stack<int> topo;

void dfs(int node) {
    vis[node] = 1;
    for (auto &x : g[node]) {
        if (!vis[x]) {
            dfs(x);
        }
    }
    topo.push(node);
}

void dfs2(int node, int ptr) {
    vis[node] = 1;
    color[node] = ptr;
    for (auto &x : g2[node]) {
        if (!vis[x]) {
            dfs2(x, ptr);
        }
    }
}

bool dfs3(int node) {
    vis[node] = 1;
    bool ok = 0;
    if (sz(scc[node]) > 1)
        return (ok = true);
    for (auto &x : scc[node]) {
        if (!vis[x]) {
            ok |= dfs3(x);
        }
    }
    return ok;
}

void reset() {
    for (int i = 0; i < mxN; ++i) {
        g[i].clear();
        g2[i].clear();
        scc[i].clear();
        vis[i] = 0;
        compress[i] = 0;
        color[i] = 0;
    }
    while (!topo.empty()) {
        topo.pop();
    }
}

void Din() {
    reset();
    int n;
    cin >> n;

    int ptr = 1;
    // Starting position, so it should be 1 (1'base index).....
    compress[1] = ptr++;

    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            ++x, ++y;

            if (!compress[x]) {
                compress[x] = ptr++;
            }
            if (!compress[y]) {
                compress[y] = ptr++;
            }
            x = compress[x];
            y = compress[y];
            g[x].pb(y);
            g2[y].pb(x);
        }
    }

    n = ptr;
    for (int i = 1; i < n; ++i) {
        if (!vis[i]) {
            dfs(i);
        }
    }

    // dg(topo);
    vis.assign(sizeof(vis), 0);
    int scc_cnt = 1;

    while (!topo.empty()) {
        int x = topo.top();
        topo.pop();
        if (!vis[x]) {
            dfs2(x, scc_cnt);
            scc_cnt += 1;
        }
    }

    // dg(scc_cnt);
    for (int i = 1; i < n; ++i) {
        // dg(g[i]);
        for (auto &x : g[i]) {
            if (color[x] ^ color[i]) {
                scc[color[i]].pb(color[x]);
            }
        }
    }

    // for(int i = 1;i < scc_cnt; ++i) {
    //     dg(scc[i]);
    // }

    vis.assign(sizeof(vis), 0);
    // dfs3(color[1]);

    // You can check it here or also can check it into dfs3()...
    // for (int i = 1; i < n; ++i) {
    //     if (sz(scc[i]) > 1) {
    //         cout << "NO\n";
    //         return;
    //     }
    // }

    bool ok = dfs3(color[1]);
    for (int i = 1; i < scc_cnt; ++i) {
        if (!vis[i]) {
            // cout << "NO\n";
            // return;
            ok = 1;
            break;
        }
    }

    // cout << "YES\n";
    cout << (!ok ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i) { // Kickstart
        cout << "Case " << i << ": ";
        Din();
    }
    return 0;
}