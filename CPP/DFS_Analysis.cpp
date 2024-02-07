/* GREEN UNIVERSITY OF BANGLADESH
       Md DinIslam, Batch-221 (CSE)
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN = 1e5 + 10;
vector<int> g[mxN], temp;
int vis[mxN];

bool dfs(int src, int par) {
    // if (vis[src]) return true;
    vis[src] = true;
    bool ok = false;
    // if (g[src].size() != 2) ok = false;
    for (auto &child : g[src]) {
        // if (!vis[child]) {
        //     ok &= dfs(child, src); // if declare ok = true;
        // }
        if (vis[child] && child == par) continue;
        if (vis[child]) return true;
        ok |= dfs(child, src);
        // if (dfs(child, src)) {
        //     // return true;
        //     ok = true;
        // }
        // else if (child != par) {
        //     // return true;
        //     ok = true;
        // }
    }
    return ok;
}
void solve() {
    int vertex, edge;
    cin >> vertex >> edge;
    for (int i = 0; i < edge; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int ans = 0;
    for (int i = 1; i <= vertex; ++i) {
        if (!vis[i]) {
            if (dfs(i, -1))
                ans++;
        }
    }

    cout << ans;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif
    int t = 1;
    // cin >> t;
    while (t--) solve();
    // for (int i = 1; i <= t; ++i) { //Kickstart
    //     cout << "Case #" << i << ": "; solve();
    // }
    return 0;
}