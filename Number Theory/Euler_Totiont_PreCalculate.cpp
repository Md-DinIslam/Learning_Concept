/* GREEN UNIVERSITY OF BANGLADESH
    Md DinIslam, Batch-221 (CSE)
    Time: 03:45:55
    Date: 04-08-2025
*/

#include <bits/stdc++.h>
using namespace std;

// Debug..
#ifdef LOCAL
#include "debug.h"
#else
#define dg(x...)
#endif

#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) int(x.size())
#define ll long long

const int mxN = 1e6 + 1;

vector<ll> phi(mxN);

void preCal() {
    iota(all(phi), 0);
    for (int i = 2; i < mxN; ++i) {
        // i is prime...
        if (phi[i] == i) {
            for (int j = i; j < mxN; j += i) {
                phi[j] -= (phi[j] / i);
            }
        }
    }

    // for (int i = 1; i < 20; ++i) {
    //     cout << phi[i] << " " << spf[i] << '\n';
    // }
}

vector<int> getDivisors(int n) {
    vector<int> divisors;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if ((n / i) != i) {
                divisors.push_back(n / i);
            }
        }
    }

    return divisors;
}

void Din() {
    int n;
    cin >> n;

    auto divisors = getDivisors(n);
    // dg(n, divisors);

    ll ans = 0;
    for (auto &x : divisors) {
        ans += (1ll * phi[x] * x);
    }
    ans = n * (ans + 1) / 2;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    preCal();
    for (int i = 1; i <= t; ++i) { // Kickstart
        // cout << "Case " << i << ": ";
        Din();
    }
    return 0;
}