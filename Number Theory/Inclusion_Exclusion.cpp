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

void Din() {
    ll k;
    int n;
    cin >> k >> n;

    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int sub = 1 << n;
    ll ans = 0;
    for (int i = 1; i < sub; ++i) {
        ll lcm = 1, cnt = 0;
        bool fail = 0;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                if (lcm > (k / v[j])) {
                    fail = 1;
                    break;
                }
                lcm *= v[j];
                cnt += 1;
            }
        }

        if (fail) {
            dg(fail);
            continue;
        }

        dg(lcm, k / lcm, cnt);

        if (cnt & 1)
            ans += (k / lcm);
        else
            ans -= (k / lcm);
    }

    cout << ans << '\n';
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