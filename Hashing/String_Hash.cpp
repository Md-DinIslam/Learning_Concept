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

class Hash {
    vector<ll> pow, pow2, hsh, hsh2;
    ll mod = 1e7 + 9, mod2 = 1e7 + 19;
    ll prime = 31, prime2 = 37;
public:
    Hash(int n) {
        pow.resize(n + 1);      pow2.resize(n + 1);
        hsh.resize(n + 1);      hsh2.resize(n + 1);
        pow[0] = 1;
        pow2[0] = 1;

        for (int i = 1; i <= n; ++i) {
            pow[i] = (pow[i - 1] * prime) % mod;
            pow2[i] = (pow2[i - 1] * prime2) % mod2;
        }

    }

    vector<int> getHash(string &pat, string &s) {
        int n = sz(s), m = sz(pat);
        for (int i = 0; i < n; ++i) {
            hsh[i + 1] = (hsh[i] + (s[i] * pow[i])) % mod;
            hsh2[i + 1] = (hsh2[i] + (s[i] * pow2[i])) % mod2;
        }

        // 2 different hash for reducing the collison....
        arr<ll, 2> pat_hsh{0, 0};
        for (int i = 0; i < m; ++i) {
            pat_hsh[0] = (pat_hsh[0] + pat[i] * pow[i]) % mod;
            pat_hsh[1] = (pat_hsh[1] + pat[i] * pow2[i]) % mod2;
        }

        // dg(pat_hsh);

        vector<int> ans;
        for (int i = 0; i < n - m + 1; ++i) {
            // dg(s[i]);
            arr<ll, 2> curr_hsh{0, 0};
            curr_hsh[0] = (hsh[i + m] - hsh[i] + mod) % mod;
            curr_hsh[1] = (hsh2[i + m] - hsh2[i] + mod2) % mod2;
            // dg(pat_hsh, curr_hsh);

            if (curr_hsh[0] == (pat_hsh[0] * pow[i] % mod) && (curr_hsh[1] == (pat_hsh[1] * pow2[i] % mod2))) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

void Din() {
    int n;
    string pat, s;
    while (cin >> n >> pat >> s) {
        if (sz(s) < n)
            cout << '\n';
        else {
            int m = sz(s);
            Hash h(m);
            auto ans = h.getHash(pat, s);
            for (auto &x : ans)
                cout << x << '\n';
        }
    }
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