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
#define vvl vector<vector<ll>>

const int mod = 1e9 + 7;

vvl matExp(const vvl &a, const vvl &b) {
    vvl ans = {{0, 0}, {0, 0}};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int via = 0; via < 2; ++via) {
                ans[i][j] += (a[i][via] * b[via][j]);
                ans[i][j] %= mod;
            }
        }
    }
    return ans;
}

void Din() {
    ll n;
    cin >> n;

    vvl mat = {{19, 7}, {6, 20}};
    vvl ans = {{1, 0}, {0, 1}};

    ll b = n;
    while (b) {
        if (b & 1) {
            ans = matExp(ans, mat);
        }

        mat = matExp(mat, mat);
        b >>= 1;
    }
    
    // dg(ans);
    cout << ans[0][0] << '\n';
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


/*

https://codeforces.com/gym/102644/problem/A

*/
