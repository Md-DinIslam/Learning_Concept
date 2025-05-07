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
#define ff "First"
#define ss "Second"
void Din() {
    int n, q;
    cin >> n >> q;
    int dp[n + 1][n + 1] = {};
    
    // Binomial Coefficient....
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (j == i || j == 0) dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    while (q--) {
        int k;
        cin >> k;
        cout << dp[n][k] << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) Din();
    // for (int i = 1; i <= t; ++i) { // Kickstart
    //     cout << "Case #" << i << ": "; Din();
    // }
    return 0;
}