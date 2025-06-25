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

const int mxN = 2e5 + 9, logN = 20;

vector<int> g[mxN], v(mxN), start(mxN), depth(mxN), subTree(mxN), root(mxN), heavy(mxN, -1);
vector<int> parents(mxN), sg(1 << 19);

int n, q;

void upd(int indx, int val) {
    indx += n;
    sg[indx] = val;
    indx /= 2; // already set sg[indx] = val, so move to the next....
    while (indx) {
        sg[indx] = max(sg[2 * indx], sg[2 * indx + 1]);
        indx /= 2;
    }
}

int qry(int lb, int rb) {
    int a = 0, b = 0;
    lb += n, rb += n + 1;
    while (lb < rb) {
        if (lb & 1) {
            a = max(a, sg[lb]);
            lb += 1;
        }
        if (rb & 1) {
            b = max(b, sg[rb - 1]);
            rb -= 1;
        }
        lb /= 2;
        rb /= 2;
    }
    return max(a, b);
}

int dfs(int node, int par) {
    // subTree[node] = 1;
    int subSize = 1, maxChildSize = 0;
    depth[node] = depth[par] +  1;
    parents[node] = par;

    for (auto &child : g[node]) {
        if (child != par) {
            int child_size = dfs(child, node);
            // subTree[node] += subTree[child];
            // if (subTree[child] > subTree[heavy[node]]) {
            //     heavy[node] = child;
            // }
            subSize += child_size;
            if (child_size > maxChildSize) {
                maxChildSize = child_size;
                heavy[node] = child;
            }
        }
    }
    return subSize;
}

int timer = 1;

void dfsHLD(int node, int par, int top) {
    root[node] = top;
    start[node] = timer++;

    if (heavy[node] != -1) { // correct
        dfsHLD(heavy[node], node, top);
    }

    for (auto &child : g[node]) {
        if (child != par && child != heavy[node]) {
            dfsHLD(child, node, child);
        }
    }
}

int getMaxVal(int a, int b) {
    int ans = 0;
    while (root[a] ^ root[b]) {
        if (depth[root[a]] < depth[root[b]])
            swap(a, b);
        ans = max(ans, qry(start[root[a]] , start[a]));
        a = parents[root[a]];
    }

    if (depth[a] > depth[b]) {
        swap(a, b);
    }

    return max(ans, qry(start[a], start[b]));
}

void Din() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }

    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }

    dfs(1, 0);
    dfsHLD(1, 0, 1);

    for (int i = 1; i <= n; ++i) {
        upd(start[i], v[i]);
    }

    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int node, val;
            cin >> node >> val;
            upd(start[node], val);
            v[node] = val;
        }
        else {
            int a, b;
            cin >> a >> b;
            cout << getMaxVal(a, b) << ' ';
            // dg(lca(a, b));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; ++i) { // Kickstart
        // cout << "Case " << i << ": ";
        Din();
    }
    return 0;
}