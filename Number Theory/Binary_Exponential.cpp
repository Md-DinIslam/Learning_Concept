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
const int mod = 1e9 + 7;
// int binExpoRecur(int a, int p) {
//     if (p == 0) return 1;
//     int result = binExpoRecur(a, p / 2);
//     /* ODD Check */
//     if (p & 1) return (a * (result * 1LL * result) % mod) % mod;
//     /* Otherwise EVEN */
//     else return (result * 1LL * result) % mod;
// }

ll binExRecu(ll a, ll b) {
    if (!b) return 1;
    ll ans = binExRecu(a, b / 2);
    if (b & 1) return (a * (ans * ans) % mod) % mod;
    else return (ans * ans) % mod;
}
ll binExpo(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % mod;
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
        if (b & 1) ans = binMul(ans, a);
        a = binMul(a, a);
        b >>= 1;
    }
    return ans;
}

void solve()
{
    ll a, b;
    cin >> a >> b;
    cout << binExpo(a, b) << '\n';
    cout << binExMul(a, b) << '\n';
    // cout<<pow(a,b); nn
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