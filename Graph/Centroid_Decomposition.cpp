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
 
const int mxN = 2e5 + 9;
vector<int> g[mxN], subTree(mxN);
 
void dfs(int node, int par) {
    subTree[node] += 1;
    for (auto &child : g[node]) {
        if (child != par) {
            dfs(child, node);
            subTree[node] += subTree[child];
        }
    }
}
 
int getCentroid (int node, int par, int n) {
    int ans = node;
    for (auto &child : g[node]) {
        if (child != par && subTree[child] * 2 > n) {
            ans = getCentroid(child, node, n);
        }
    }
 
    return ans;
}
 
void Din() {
    int n;
    cin >> n;
 
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
 
    dfs(1, 0);
    cout << getCentroid(1, 0, n) << '\n';
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