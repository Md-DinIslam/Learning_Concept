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
typedef vector<int> vi;
const int mxN = 1e5 + 10;
vi g[mxN], allPar(mxN), depth(mxN);
void dfs(int curr, int par) {
    allPar[curr] = par;
    depth[curr] = depth[par] + 1; // intial parent should be 0...
    // cout << curr << " ";
    for (auto &child : g[curr]) {
        if (child != par) {
            // depth[child] = depth[curr] + 1;
            dfs(child, curr);
        }
    }
}
// Findind path from Source Node to Depth Node....
vi path(int node) {
    vi ans;
    while (node) {
        ans.pb(node);
        node = allPar[node];
    }
    reverse(begin(ans), end(ans));
    return ans;
}
int LCA(int a, int b) {
    if (a == b) return a;
    if (depth[a] < depth[b]) swap(a, b);
    int diff = depth[a] - depth[b];

    // making both depth same.....
    while (diff--) {
        a = allPar[a];
    }

    // Finding same parent of both Node.....
    while (a != b) {
        a = allPar[a];
        b = allPar[b];
    }
    return a;
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
    int a, b;
    cin >> a >> b;

    // Using storing all the path of two node into vector, then finding their LCA.....
    vi x = path(a);
    vi y = path(b);
    int len = min(x.size(), y.size()), ans = 0;
    for (int i = 0; i < len; ++i) {
        if (x[i] == y[i]) ans = x[i];
        else break;
    }
    // LCA finding type: 01.....
    cout << ans << '\n';
    
    // LCA finding type: 02.....
    cout << LCA(a, b) << "\n";

    cout << lenghtAtoB(a, b) << '\n';
    
    // for (int i = 1; i <= n; ++i)
    //     cout << i << " --> " << depth[i] << '\n';

    // Time Complexity --> O(N)
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
