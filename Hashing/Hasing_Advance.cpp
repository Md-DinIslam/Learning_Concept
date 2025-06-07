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

#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) int(x.size())
#define arr array
#define ll long long
#define ull uint64_t

struct Hash {
    ull x;
    Hash(ull x = 0) : x(x) {};

    Hash operator+(Hash op) {
        return x + op.x + (x + op.x < x);
    }

    Hash operator-(Hash op) {
        return *this + ~op.x;
    }

    Hash operator*(Hash op) {
        auto m = (__uint128_t) x * op.x;
        return Hash((ull) m) + (ull) (m >> 64);
    }

    ull get() const {
        return x + !~x;
    }

    bool operator==(Hash op) {
        return get() == op.get();
    }

    // just for output the stored hash
    friend ostream& operator<<(ostream &out, Hash op) {
        return out << op.x;
    }
};

static const Hash prime = (ll) 1e11 + 3;

struct hashInterval {
    vector<Hash> hsh, pw;
    hashInterval (string &s) : hsh(sz(s) + 1), pw(hsh) {
        int n = sz(s);
        pw[0] = 1;
        for (int i = 1; i <= n; ++i) {
            hsh[i] = hsh[i - 1] * prime + s[i - 1];
            pw[i] = pw[i - 1] * prime;
        }
    }
    Hash hashRange(int a, int b) { // hash [a, b)...
        return (hsh[b] - hsh[a] * pw[b - a]);
    }
};

void Din() {
    string s;
    cin >> s;
    int n = sz(s);

    // string temp = s;
    // temp.pop_back();
    // s = s + temp;
    hashInterval h(s);
    reverse(all(s));
    hashInterval h2(s);

    int ans = 1;
    for (int i = 1; i <= sz(s); ++i) {
        // cout << h.hashRange(0, i) << " ";
        if (h.hashRange(n - i, n) == h2.hashRange(0, i)) {
            ans = i;
            // break;
        }
    }

    cout << 2 * n - ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case " << i << ": ";
        Din();
    }
    return 0;
}
