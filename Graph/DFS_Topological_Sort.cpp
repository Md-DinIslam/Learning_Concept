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
const int mxN = 1e5 + 10;

vector<int> g[mxN], order(mxN);
bool vis[mxN];

// In Topological Sort (Directed Acyclic Graph)....
// Vertex U comes before V....
void dfs(int curr, int par) {
    vis[curr] = 1;
    for (auto &child : g[curr]) {
        if (!vis[child])
            dfs(child, curr);
    }

    // Storing in the reverse oreder.....
    order.pb(curr);
}
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;

        // Directed Graph.....
        g[x].pb(y);
        // g[y].pb(x);
    }

    for (int i = 1; i <= n; ++i) {
        if (!vis[i])
            dfs(i, 0);
    }
    reverse(begin(order), end(order));

    // Topological Order...
    for (int i = 0; i < n; ++i) {
        cout << order[i] << " \n"[i == n - 1];
    }
}

/*

5 6
3 2
3 1
1 2
1 5
2 5
2 4
1 5

*/

int main() {
    ios_base :: sync_with_stdio(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    // for (int i = 1; i <= t; ++i) { // Kickstart
    //     cout << "Case #" << i << ": "; solve();
    // }
    return 0;
}