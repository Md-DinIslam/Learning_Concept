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
const int mxN = 2e5;
vector<int> g[mxN], sub(mxN);

void dfs(int curr, int par = -1) {
    // sub[curr] = 1;
    sub[curr]++;
    for (auto &child : g[curr]) {
        if (child != par) {
            dfs(child, curr);
            sub[curr] += sub[child];
        }
    }
}
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x;
        // --x;
        g[x].pb(i + 1);
    }
    dfs(1);
    for (int i = 1; i <= n; ++i) {
        cout << sub[i] - 1 << ' ';
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