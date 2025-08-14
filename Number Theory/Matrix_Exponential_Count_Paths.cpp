/* GREEN UNIVERSITY OF BANGLADESH
    Md DinIslam, Batch-221 (CSE)
    Time: 00:00:01
    Date: 15-08-2025
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
#define vvl vector<vector<ll>>

const int mod = 1e9 + 7;
const ll inf = 1e18;

vvl matExp(const vvl &a, const vvl &b) {
    int n = a.size();
    int m = b.size();
    // dg(n, m);
    vvl ans(n, vector<ll>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int via = 0; via < m; ++via) {
                ans[i][j] += (a[i][via] * b[via][j]);
                ans[i][j] %= mod;
            }
        }
    }
    return ans;
}

struct Matrix {
    vvl mat;
} t[35];

void Din() {
    int n, m, q;
    cin >> n >> m >> q;

    vvl g(n, vector<ll> (n, 0));

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x -= 1, y -= 1;
        g[x][y] = 1;
    }

    t[0].mat = g;
    // for (int i = 1; i < 5; ++i) {
    //     t[i] = t[i - 1];
    //     dg(t[i].mat);
    // }
    // dg(g);

    for (int i = 1; i < 32; ++i) {
        t[i].mat = matExp(t[i - 1].mat, t[i - 1].mat);
        // if (i < 5) {
        //     dg(t[i].mat);
        // }
    }

    while (q--) {
        int s, e, k;
        cin >> s >> e >> k;
        s -= 1, e -= 1;

        vvl ans(1, vector<ll> (n, 0));
        ans[0][s] = 1;
        // dg(ans);
        
        for (int i = 0; i < 31; ++i) {
            if ((k >> i) & 1) {
                // [1 * n], [n * n] matrix...
                ans = matExp(ans, t[i].mat);
                // dg(ans, t[i].mat, i);
            }
        }

        // dg(ans);

        // int cnt = 0;
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         cnt += ans[i][j];
        //         cnt %= mod;
        //     }
        // }

        cout << ans[0][e] << '\n';
        // cout << cnt << '\n';
    }
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
