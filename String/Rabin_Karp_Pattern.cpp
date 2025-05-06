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
const int prime = 31, mod = 1e9 + 7;
int polyHash(string s) {
    int hsh = 0;
    ll powr = 1;
    for (int i = 0; i < s.size(); ++i) {
        hsh += (s[i] - 'a' + 1) * powr;
        powr *= prime;
        powr %= mod;
        hsh %= mod;
    }
    return hsh;
}
ll PowrInv(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans *= a;
        a *= a;
        ans %= mod, a %= mod;
        b >>= 1;
    }
    return ans;
}
ll Inverse(ll n) {
    return PowrInv(n, mod - 2);
}
void getAns(string &s, string &p) {
    int n = s.size(), m = p.size();
    ll pat_Hash = polyHash(p);
    ll text_Hash = polyHash(s.substr(0, m));
    if (pat_Hash == text_Hash) {
        cout << 0 << '\n';
    }
    for (int i = 1; i + m <= n; ++i) {
        text_Hash = (text_Hash - (s[i - 1] - 'a' + 1) + mod) % mod;
        text_Hash = (text_Hash * Inverse(prime)) % mod;
        text_Hash = (text_Hash + (s[i + m - 1] - 'a' + 1) * PowrInv(prime, m - 1)) % mod;
        // cout<<pat_Hash<<" "<<text_Hash;nn
        if (text_Hash == pat_Hash) {
            cout << i << '\n';
        }
    }
}
void solve()
{
    string s, p;
    cin >> s >> p;
    getAns(s, p);
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
