/* GREEN UNIVERSITY OF BANGLADESH
    Md DinIslam, Batch-221 (CSE)
*/
#include <bits/stdc++.h>
using namespace std;

// Debug..
#ifdef LOCAL
#include "debug.h"
#endif

#define ll long long
#define pb push_back
const int mxN = 1e4 + 10, logN = 15;
vector<int> g[mxN];
int depth[mxN], allPar[mxN][logN];

// O(N * logN).....
void dfs(int curr, int par) {
    // depth[curr] = depth[par] + 1;

    allPar[curr][0] = par;

    // allParr[curr][j] is the 2^j-th ancestor of curr.....
    for (int j = 1; j < logN; ++j) {
        allPar[curr][j] = allPar[allPar[curr][j - 1]][j - 1];
    }

    // Running DFS.....
    for (auto &child : g[curr]) {
        if (child != par) {
            depth[child] = depth[curr] + 1;
            dfs(child, curr);
        }
    }
}

// O(logN) == 15......
int LCA(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    int diff = depth[a] - depth[b];

    // Equalizing size both a and b....
    for (int j = logN - 1; j >= 0; --j) {
        // j-th bit of diff is set....
        if ((diff >> j) & 1)
            a = allPar[a][j];
    }

    // if same after 1st performing, then return....
    if (a == b) return a;
    
    // a and b are on the same level......
    for (int j = logN - 1; j >= 0; --j) {
        if (allPar[a][j] != allPar[b][j]) {
            a = allPar[a][j];
            b = allPar[b][j];
        }
    }

    return allPar[a][0]; // also allPar[b][0] is right.....
}
void print(int n, int mode) {
    if (mode) {
        for (int i = 1; i <= n; ++i) {
            cout << depth[i] << '\n';
        }
    }
    else {
        for (int i = 1; i <= n; ++i) {
            cout << i << " --> ";
            for (int j = 0; j < 5; ++j) {
                cout << allPar[i][j] << " ";
            }
            cout << '\n';
        }
    }
}

int lenghtAtoB(int a, int b) {
    int lca = LCA(a, b);
    return depth[a] + depth[b] - 2 * depth[lca];
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1, 0);

    // print(n, 0);

    int q;
    cin >> q;
    
    // O(Q * logN).....
    while (q--) {
        int a, b;
        cin >> a >> b;
        // cout << LCA(a, b) << "\n";
        cout << lenghtAtoB(a, b) << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    // for (int i = 1; i <= t; ++i) { // Kickstart
    //     cout << "Case #" << i << ": "; solve();
    // }
    return 0;
}