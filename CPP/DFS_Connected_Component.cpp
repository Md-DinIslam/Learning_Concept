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
vector<vector<int>> conComp;
bool vis[mxN];
vector<int> dfs(int curr, vector<int> &v) {
    vis[curr] = 1;
    v.pb(curr);
    for (auto &child : g[curr]) {
        if (!vis[child]) {
            dfs(child, v);
        }
    }
    return v;
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
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        vector<int> v;
        if (!vis[i]) {
            conComp.pb(dfs(i, v));
            cnt++;
        }
    }
    cout << cnt << "\n";
    for (auto &x : conComp) {
        for (auto &child : x)
            cout << child << " ";
        cout << '\n';
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