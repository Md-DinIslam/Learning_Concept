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
const int mxN = 2e5 + 10, logM = 19;
int spT[logM][mxN], binLog[mxN];

int qry(int lb, int rb) { // O(1)...
    int len = rb - lb + 1;
    int i = binLog[len];
    return min(spT[i][lb], spT[i][rb - (1 << i) + 1]);
}
void solve() {
    int n, q;
    cin >> n >> q;
    ++n;
    int v[n];
    
    // Reading Input.....
    for (int i = 1; i < n; ++i) {
        cin >> v[i];
        spT[0][i] = v[i];
    }
    for (int i = 2; i <= n; ++i)
        binLog[i] = binLog[i / 2] + 1;

    // Preporcessing.....
    for (int i = 1; i < logM; ++i) {
        for (int j = 1; j + (1 << i) <= n; ++j) {
            spT[i][j] = min(spT[i - 1][j], spT[i - 1][j + (1 << (i - 1))]);
        }
    }
    // __print(spT);
    while (q--) {
        int lb, rb;
        cin >> lb >> rb; // 1'based index.....
        cout << qry(lb, rb) << '\n';
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
