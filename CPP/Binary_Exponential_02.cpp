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
const ll mod = 1e9 + 7;

ll binExpo(ll a, ll b, ll mod) {
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
ll binMul(ll a, ll b) {
    ll ans = 0;
    while (b) {
        if (b & 1) ans = (ans + a) % mod;
        a = (a + a) % mod;
        // a = (a << 1) % mod;
        b >>= 1;
    }
    return ans;
}
ll binExMul(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans = binMul(ans, a);
        }
        a = binMul(a, a);
        b >>= 1;
    }
    return ans;
}
void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    cout << binExpo(a, binExpo(b, c, mod - 1), mod) << '\n';
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