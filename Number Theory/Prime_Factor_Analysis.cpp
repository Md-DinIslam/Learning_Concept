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
#define ff first
#define ss second

typedef unordered_map<int, int> umii;

const int mod = 1e9 + 7;
const int mxN = 1e6 + 10;

ll binExp(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod, b >>= 1;
    }
    return ans;
}

unordered_map<int, int> sieve(int n) {
    unordered_map<int, int> pfs;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            pfs[i]++;
            n /= i;
        }
    }
    if (n > 1) pfs[n]++;
    return pfs;
}
void solve() {
    int n;
    cin >> n;
    unordered_map<int, int> pfs = sieve(n);

    // Prime Divisor --> Count, Sum and Product......
    ll cnt = 1, sum = 1, prod = 1;
    for (auto &x : pfs) {
        cnt *= (x.ss + 1);
        sum = (sum * (((binExp(x.ff, x.ss + 1) - 1)) * binExp(x.ff - 1, mod - 2) % mod) % mod) % mod;
    }

    ll ok = 0, pw = 1;
    for (auto &x : pfs) {
        if ((x.ss % 2) && !ok)
            pw = (pw * (x.ss + 1) / 2) % (mod - 1), ok = 1;
        else
            pw = (pw * (x.ss + 1)) % (mod - 1);
    }
    if (!ok) {
        for (auto &x : pfs)
            pfs[x.ff] /= 2;
    }
    for (auto &x : pfs)
        prod = (prod * binExp(x.ff, x.ss)) % mod;
    cout << cnt << ' ' << sum << ' ' << prod << '\n';
}

// Harmonic Series......

/*void solve() {
    primes.push_back(2);
    for (int i = 3; i * i <= mxN; i += 2) {
        if (isPrime[i]) {
            // primes.push_back(i);
            for (int j = i * i; j <= mxN; j += i) {
                isPrime[j] = 0;
            }
        }
    }
    for(int i = 3; i < mxN; i += 2){
        if(isPrime[i]) primes.push_back(i);
    }
    for (int i = 0; i < primes.size(); i += 100) {
        cout << primes[i] << '\n';
    }
}*/
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    // for (int i = 1; i <= t; ++i) { // Kickstart
    //     cout << "Case #" << i << ": "; solve();
    // }
    return 0;
}