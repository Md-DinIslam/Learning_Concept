/* GREEN UNIVERSITY OF BANGLADESH
       Md DinIslam, Batch-221
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef vector<vector<ll>> vvl;
const int mod = 1e9 + 7;
vvl mul(vvl &a, vvl &b) {
    vvl ans = {{0, 0}, {0, 0}};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                ans[i][j] += a[i][k] * b[k][j];
                ans[i][j] %= mod;
            }
        }
    }
    return ans;
}
void solve() {
    ll n;
    cin >> n;
    vvl T = {{1, 1}, {1, 0}};
    vvl ans = {{1, 0}, {0, 1}};
    while (n) {
        if (n & 1) ans = mul(ans, T);
        T = mul(T, T);
        n /= 2;
    }
    cout << ans[0][1];
}
int main()
{
    ios_base :: sync_with_stdio(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    // fl(i, t) { //Kickstart
    //     cout << "Case #" << i + 1 << ": "; solve();
    // }
    return 0;
}