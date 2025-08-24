/* GREEN UNIVERSITY OF BANGLADESH
    Md DinIslam, Batch-221 (CSE)
    Time: 02:13:19
    Date: 24-08-2025
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

// Gaussian Elimination... or Basis Vector....

template<class T, int m = 31>
struct Basis {
    vector<T> gauss;

    Basis() : gauss(m, 0) {}

    void insert(T x) {
        for (int i = m - 1; ~i; --i) {
            if ((x >> i) & 1) {
                if (gauss[i]) {
                    x ^= gauss[i];
                }
                else {
                    gauss[i] = x;
                    break;
                }
            }
        }
    }

    bool can(T x) {
        for (int i = m - 1; ~i; --i) {
            x = min(x, x ^ gauss[i]);
        }
        return x == 0;
    }

    T getMax() {
        T ans = 0;
        for (int i = m - 1; ~i; --i) {
            ans = max(ans, ans ^ gauss[i]);
        }
        return ans;
    }
};

void Din() {
    int n;
    cin >> n;

    Basis<ll, 63> b;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        b.insert(x);
    }

    cout << b.getMax() << "\n";
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
