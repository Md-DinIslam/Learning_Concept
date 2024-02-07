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
void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    sort(begin(v), end(v));
    // debug(v);
    int q;
    cin >> q;
    while (q--) {
        int leftVal, rightVal;
        cin >> leftVal >> rightVal;
        int lb = 0, rb = n - 1;

        // Lower Bound....
        while (lb <= rb) {
            int mid = lb + (rb - lb) / 2;
            if (leftVal <= v[mid]) rb = mid - 1;
            else lb = mid + 1;
        }
        int ans = lb;
        lb = 0, rb = n - 1;

        // Upper Bound....
        while (lb <= rb) {
            int mid = lb + (rb - lb) / 2;
            if (rightVal < v[mid]) rb = mid - 1;
            else lb = mid + 1;
        }
        ans = lb - ans;
        cout << ans << ' ';
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