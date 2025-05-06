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
vector<int> g[mxN];
bool vis[mxN], isCycle = 0;
void dfs(int curr, int par) {
    // if (vis[curr]) return;
    vis[curr] = 1;
    cout << curr << "\n";
    for (auto &child : g[curr]) {
        if (!vis[child])
            dfs(child, curr);
        else if (child != par) { // Cycle or Not......
            // cout << child << " " << curr << "\n";
            isCycle = true;
        }
    }
    // return isCycle;
}
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    
    // for (int i = 1; i <= n; ++i) {
    //     for (auto &x : g[i])
    //         cout << x << " ";
    //     cout << '\n';
    // }

    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs(i, 0);
        }
    }

    cout << (isCycle ? "Has Cycle" : "No Cycle");

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
