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
const int mxN = 2e5 + 10;

// cndComp = Condensed Component;
// g = Main Graph;
// g2 = Reverse Graph;
// ord = Topological Order;
// component = Where storing all the SCC....

vector<int> g[mxN], g2[mxN], component[mxN], CndComp(mxN), ord;
bool vis[mxN];

// DFS-01 --> Topological Sort...
void dfs(int curr) {
    vis[curr] = 1;
    for (auto &x : g[curr]) {
        if (!vis[x])
            dfs(x);
    }
    ord.pb(curr);
}

// DFS-02 --> Traversing Condensed Component for SCC.....
void dfs2(int curr, int comp) {
    vis[curr] = 1;
    CndComp[curr] = comp;
    component[comp].pb(curr);
    for (auto &x : g2[curr]) {
        if (!vis[x])
            dfs2(x, comp);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    // Directed Graph (SCC)....
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y); // Main Graph input....
        g2[y].pb(x); // Reverse Graph input....
    }

    // DFS 01 in Main Graph (g)...
    for (int i = 1; i <= n; ++i) {
        if (!vis[i])
            dfs(i);
    }
    reverse(begin(ord), end(ord));
    // debug(ord);

    // DFS 02 in Reverse Graph (g2)...
    memset(vis, 0, sizeof(vis));
    int comp = 1;
    for (int i = 1; i <= n; ++i) {
        if (!vis[ord[i]])
            dfs2(ord[i], comp++);
    }

    for (int i = 1; i <= n; ++i)
        cout << i << " " << CndComp[i] << '\n';

    cout << "Total SCC: " << comp - 1 << '\n';

    // All Condenesed Component....
    for (int i = 1; i < comp; ++i) {
        cout << "Group: " << i << '\n';
        for (auto &x : component[i])
            cout << x << " ";
        cout << '\n';
    }
}
/*

4 4
1 2
2 3
3 1
3 4

*/
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
