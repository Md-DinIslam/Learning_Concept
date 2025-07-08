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
#define sz(x) int(x.size())

ll binMul(ll a, ll b, ll mod) {
    ll ans = 0;
    while (b) {
        if (b & 1) {
            ans = (ans + a) % mod;
        }
        a = (a + a) % mod;
        b >>= 1;
    }
    return ans;
}

ll binExp(ll a, ll b, ll mod) { // a^b upto 1e18, mod <= 1e18..
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans = binMul(ans, a, mod);
            ans %= mod;
        }
        a = binMul(a, a, mod);
        a %= mod;
        b >>= 1;
    }
    return ans;
}

/*

In miller rabin, it holds....
    a^d = 1 (mod N) or,
    a^(2^s*d) = n - 1 (mod n)
Used for prime number check upto 7e18.

*/
bool millerRabin(ll n) {
    if (n == 2 || n == 3) return 1;
    if (n <= 1 || n % 2 == 0) return 0;

    ll d = n - 1; // need [ n-1 = a^s*d 1<a<n-1, d is Odd ]
    while (d % 2 == 0) {
        d >>= 1;
    }
    // check for multiple sequence of co-prime of N....
    vector<ll> pfs = {2, 3, 5, 7, 11, 13, 29, 37, 43};
    for (auto &x : pfs) {
        if (x >= n) return 1; // also can break...
        ll curr_d = d;
        // Farmets Little Theorem (a^n-1 = 1 % n [n is prime])...
        // first check a^d, it will return 1 if it is prime...
        ll mod = binExp(x, curr_d, n);
        if (mod != 1) {
            // if first check failed, then check square of this function, and if
            while (curr_d != n - 1 && mod != n - 1) {
                mod = binMul(mod, mod, n);
                curr_d *= 2;
            }

            if (mod != n - 1) return 0;
        }
    }

    return 1;
}

void Din() {
    ll n;
    cin >> n;

    if (millerRabin(n)) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        // cout << "Case " << i << ": ";
        Din();
    }
    return 0;
}
