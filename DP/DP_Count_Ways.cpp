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

int dp[20];

// Recursive method.... O(K^N)
int cntWaysRecursive(int n, int k) {
    if (n == 0) return 1;
    if (n < 0) return 0;

    int ans = 0;
    for (int jump = 1; jump <= k; ++jump) {
        ans += cntWaysRecursive(n - jump, k);
    }

    return ans;
}

// Top-Down method.... O(N*K)
int cntWaysTopDown(int n, int k) {
    if (n == 0) return 1;
    if (n < 0) return 0;

    int &ans = dp[n];
    if (ans != 0) return ans;

    for (int jump = 1; jump <= k; ++jump) {
        ans += cntWaysTopDown(n - jump, k);
    }

    return ans;
}

// Bottom-Up method... O(N*K)
int cntWayBotUp(int n, int k) {
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            if (!i) dp[i] = 1;
            else {
                if (i - j >= 0) {
                    dp[i] += dp[i - j];
                }
            }
        }
    }

    return dp[n];
}

// Bottom-Up Optimised..... O(N + K)
int cntWaysBotUpOpt(int n, int k) {
    memset(dp, 0, sizeof(dp));

    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (i <= k)
            dp[i] = 2 * dp[i - 1];
        else
            dp[i] = 2 * dp[i - 1] - dp[i - k - 1];
    }

    // for (int i = 2; i <= k; ++i) {
    //     dp[i] = 2 * dp[i - 1];
    // }

    // for (int i = k + 1; i <= n; ++i) {
    //     dp[i] = 2 * dp[i - 1] - dp[i - k - 1];
    // }

    return dp[n];
}
void Din() {
    // N = size of ladder, K = at most jump......
    int n, k;
    cin >> n >> k;

    // Recursive method....
    cout << cntWaysRecursive(n, k) << '\n';

    // Top-Down method....
    cout << cntWaysTopDown(n, k) << '\n';

    // Bottom-Up method....
    cout << cntWayBotUp(n, k) << '\n';

    // Bottom-Up Optimised method....
    cout << cntWaysBotUpOpt(n, k) << '\n';
    __print(dp);

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


/*

7
3

*/