/* GREEN UNIVERSITY OF BANGLADESH
    Md DinIslam, Batch-221 (CSE)
    Time: 03:45:55
    Date: 04-08-2025
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

ll phi(ll n) {
    ll ans = n;
    if (n == 1) return ans;

    vector<ll> pfs;
    if (n % 2 == 0) {
        pfs.push_back(2);
        while (n % 2 == 0) {
            n /= 2;
        }
    }

    for (ll i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            pfs.push_back(i);
            while (n % i == 0) {
                n /= i;
            }
        }
    }

    if (n > 1) {
        pfs.push_back(n);
    }

    for (auto &x : pfs) {
        ans -= (ans / x); // like --> ans *= (x - 1), ans /= x;
    }
    // dg(pfs);
    return ans;
}

void Din() {
    // dg(phi(1e14+9));
    ll a, b;
    cin >> a >> b;

    b /= __gcd(a, b);

    cout << phi(b) << '\n';
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
