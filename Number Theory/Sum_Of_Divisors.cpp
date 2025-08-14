/* GREEN UNIVERSITY OF BANGLADESH
    Md DinIslam, Batch-221 (CSE)
    Time: 03:41:53
    Date: 15-08-2025
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

const int mod = 1e9 + 7;

ll binExp(ll a, ll b) {
    ll ans = 1;
    a %= mod;
    while (b) {
        if (b & 1) {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

ll getSum(ll n) {
    ll ans = (n % mod) * ((n + 1) % mod);
    ans %= mod;
    ans = (ans * binExp(2, mod - 2));
    ans %= mod;
    return ans;
}

ll add(ll a, ll b) {
    a = getSum(a);
    b = getSum(b);
    ll ans = a - b + mod;
    ans %= mod;
    return ans;
}

void Din() {
    ll n;
    cin >> n;

    // dg(binExp(2, 3));
    // dg(getSum(5));

    ll ans = 0;
    ll curr_n = n;
    while (curr_n > 0) {
        ll contribution = n / curr_n;
        ll next = contribution + 1;
        ll jump = n / next;
        ans += contribution * add(curr_n, jump);
        ans %= mod;
        curr_n = jump;
    }

    cout << ans << '\n';
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
