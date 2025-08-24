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

const int mxN = 1e6 + 1;
vector<ll> freq(mxN, 0), ans(mxN, 0);

inline ll nCr(ll n, ll r) {
    ll N = n * (n - 1);
    ll R = r;
    ll ans = N / R;
    return ans;
}

void preCal() {
    for (int i = 1; i < mxN; ++i) {
        for (int j = i; j < mxN; j += i) {
            ans[i] += freq[j]; // build array with their multiple...
        }
    }

    for (int i = 1; i < mxN; ++i) {
        if (ans[i] < 2) { // now way to choose 2 itmes from ans[i]...
            ans[i] = 0;
        }
        else {
            // how many way we can choose 2 itmes from ans[i]...
            ans[i] = nCr(ans[i], 2);
        }
    }

    for (int i = mxN - 1; i; --i) {
        // subtract all the multiple, rest array will be the final answer...
        for (int j = 2 * i; j < mxN; j += i) {
            ans[i] -= ans[j];
        }
    }
}

void Din() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (auto &x : v) {
        cin >> x;
        freq[x] += 1;
    }

    preCal();

    // for (int i = 1; i < 9; ++i) {
    //     cout << ans[i] << '\n';
    // }
    
    // now, ans array stored with ans[i] = gcd of i, 1 <= i <= 1e6;
    cout << ans[1] << '\n';
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