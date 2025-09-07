/* GREEN UNIVERSITY OF BANGLADESH
    Md DinIslam, Batch-221 (CSE)
    Time: 15:17:51
    Date: 07-09-2025
*/

#include <bits/stdc++.h>
using namespace std;

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

vector<vector<int>> g;
vector<int> subtree, centParent;
vector<bool> vis;

void reset(int n) {
    g.resize(n + 1);
    subtree.assign(n + 1, 0);
    vis.assign(n + 1, 0);
    centParent.assign(n + 1, 0);
}

void dfs(int node, int par) {
    subtree[node] = 1;
    for (auto &child : g[node]) {
        if (child != par && !vis[child]) {
            dfs(child, node);
            subtree[node] += subtree[child];
        }
    }
}

int getCentroid(int node, int par, int new_subtree) {
    int centroid = node;
    for (auto &child : g[node]) {
        if (child != par && !vis[child] && (subtree[child] * 2 > new_subtree)) {
            centroid = getCentroid(child, node, new_subtree);
        }
    }
    return centroid;
}

void makeResult(int node, int par, vector<char> &ans, char ch) {
    dfs(node, 0);
    int centroid = getCentroid(node, 0, subtree[node]);
    vis[centroid] = 1;
    ans[centroid] = ch;
    centParent[centroid] = par; // storing centroid parents...

    for (auto &child : g[centroid]) {
        if (!vis[child]) {
            makeResult(child, centroid, ans, ch + 1);
        }
    }
    // dg(centroid);
}

void Din() {
    int n;
    cin >> n;

    reset(n);

    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<char> ans(n + 1);
    makeResult(1, 0, ans, 'A');

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " \n"[i == n]; // level of centroid..
    }
    
    // for (int i = 1; i <= n; ++i) {
    //     cout << centParent[i] << ' '; // parents of centroid...
    // }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; ++i) {
        // cout << "Case " << i << ": ";
        Din();
    }
    return 0;
}
