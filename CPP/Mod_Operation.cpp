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
#define all(x) x.begin(), x.end()
#define pb push_back
#define ff first
#define ss second

ll Power(ll a, ll b, ll mod) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

ll binEx(ll a, ll b, ll mod) {
    ll ans = 0;
    while (b) {
        if (b & 1) ans = (ans + a) % mod;
        a = (a + a) % mod;
        // a = (a << 1) % mod;
        b >>= 1;
    }
    return ans;
}

ll binExMul(ll a, ll b, ll mod) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = binEx(ans, a, mod);
        a = binEx(a, a, mod);
        b >>= 1;
    }
    return ans;
}

ll modInv(ll a, ll mod) {
    return Power(a, mod - 2, mod);
}

ll modAdd(ll a, ll b, ll mod) {
    // return ((a % mod) + (b % mod)) % mod;
    return ((a + b) % mod + mod) % mod;
}

ll modSub(ll a, ll b, ll mod) {
    // ll result = (a - b) % mod;
    // return result >= 0 ? result : result + mod;
    ll ans = ((a - b) % mod + mod ) % mod;
    return ans;

}

ll modDivi(ll a, ll b, ll mod) {
    ll inv = modInv(b, mod);
    return (a * inv) % mod;
}

void Din() {
    ll a, b, mod;
    cin >> a >> b >> mod; // mod should be prime....

    // Calculating (a ^ b).... (a or b) < 1e9
    cout << Power(a, b, mod) << '\n';

    // Calculating (a ^ b)... if (a or b) > 1e9....
    cout << binExMul(a, b, mod) << '\n';

    // Calculating (a / b)....
    cout << modDivi(a, b, mod) << '\n';

    // Mod Additon...
    cout << modAdd(a, b, mod) << '\n';

    // Mod Subtraction.....
    cout << modSub(-a, b, mod) << '\n';

}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) Din();
    // for (int i = 1; i <= t; ++i) { // Kickstart
    //     cout << "Case #" << i << ": "; Din();
    // }
    return 0;
}