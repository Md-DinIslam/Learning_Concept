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
    int n, q;
    cin >> n >> q;
    int arr[n + 1];
    int forward[n + 1], backward[n + 1];
    forward[0] = backward[n + 1] = 0;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
        forward[i] = __gcd(forward[i - 1], arr[i]);
    for (int i = n; i >= 1; i--)
        backward[i] = __gcd(backward[i + 1], arr[i]);
    while (q--) {
        int lb, rb;
        cin >> lb >> rb;
        int ans = __gcd(forward[lb - 1], backward[rb + 1]);
        cout << ans << endl;
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