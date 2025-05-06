/* GREEN UNIVERSITY OF BANGLADESH
    Md DinIslam, Batch-221 (CSE)
*/
#include <bits/stdc++.h>
using namespace std;

// Debug..
#ifdef LOCAL
#include "debug.h"
#else
#define debug(x...)
#endif

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()

const int mxN = 1e6 + 9;
const int mod = 1e9 + 7;
ll prime = 63;
vector<ll> pow_prime(mxN);

void preCal() {
    pow_prime[0] = 1ll;
    for (int i = 1; i < mxN; ++i) {
        pow_prime[i] = pow_prime[i - 1] * prime;
        pow_prime[i] %= mod;
    }
    // debug(pow_prime);
}

ll getHash(string &s) {
    int n = sz(s);
    ll hsh = 0;
    for (int i = 0; i < n; ++i) {
        // (s[i] - 'a' + 1) for 1'base multiplication....
        hsh = hsh + (s[i] - 'a' + 1) * pow_prime[i];
        // hsh = hsh + int(s[i]) * pow_prime[i]; // Also we can use this sequence.....
        hsh %= mod;
    }
    return hsh;
}

ll getPow(ll a, ll b, ll m = mod) {
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans = (ans * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

void Din() {
    preCal();
    string s, pat;
    cin >> s >> pat;

    int n = sz(s), m = sz(pat);
    string temp = s.substr(0, m);

    ll s_hsh = getHash(temp);
    ll pat_hsh = getHash(pat);
    debug(s_hsh, pat_hsh, temp);

    int ans = (s_hsh == pat_hsh);
    for (int i = 1; i + m <= n; ++i) {
        // Deleting previous character.... moving like sliding window...
        s_hsh = (s_hsh - (s[i - 1] - 'a' + 1) + mod) % mod;
        // s_hsh = (s_hsh - int(s[i - 1]) + mod) % mod; // Also we can use this sequence in the all part...
        // Also divide by power of Prime or (s_hsh/p or s_hsh * p^-1)...
        s_hsh = (s_hsh * getPow(prime, mod - 2)) % mod;
        // Now add the current character.....
        s_hsh = (s_hsh + (s[i + m - 1] - 'a' + 1) * getPow(prime, m - 1)) % mod;
        // s_hsh = (s_hsh + int(s[i + m - 1]) * getPow(prime, m - 1)) % mod; // Also we can use this sequence of the all part.....

        if (s_hsh == pat_hsh) {
            ans += 1;
        }
        // debug(ans);
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
