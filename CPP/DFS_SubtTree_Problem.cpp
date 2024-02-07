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
ll subTreeSum[mxN], subTreeEvenCnt[mxN];
void dfs(int curr, int par) {
    if (curr & 1 ^ 1) subTreeEvenCnt[curr]++;
    subTreeSum[curr] += curr;
    for (auto &child : g[curr]) {
        if (child != par) {
            dfs(child, curr);
            subTreeSum[curr] += subTreeSum[child];
            subTreeEvenCnt[curr] += subTreeEvenCnt[child];
        }
    }
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
    for (int i = 1; i <= n; ++i) {
        cout << subTreeSum[i] << " " << subTreeEvenCnt[i] << '\n';
    }
    // int q;
    // cin >> q;
    // while (q--) {
    //     int vertex;
    //     cin >> vertex;
    //     cout << subTreeSum[vertex] << " " << subTreeEvenCnt[vertex] << '\n';
    // }
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