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
#define all(x) x.begin(), x.end()
#define pb push_back
#define ff first
#define ss second
#define ld double
#define setP() cout << fixed << setprecision(15)

ld L, N, C, L2;

bool ok(ld R) {
    // [Arc Length] Arc = smooth curve of two endpoint....
    // S = R * (theta)...
    ld S = 2.0 * R * asin(L / (2.0 * R));
    return S < L2;
}

void Din() {
    cin >> L >> N >> C;

    L2 = (1.0 + (N * C)) * L;

    ld lb = 0, rb = 1e18;

    for (int i = 0; i < 100; ++i) {
        ld mid = lb + (rb - lb) / 2;

        if (ok(mid))
            rb = mid;
        else
            lb = mid;
    }

    L /= 2;

    // A^2 +  B^2 = C^2.... (Pythagoras)
    ld ans = lb - sqrt((lb * lb) - (L * L));

    setP();
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    // while (t--) Din();
    for (int i = 1; i <= t; ++i) { // Kickstart
        cout << "Case " << i << ": ";
        Din();
    }
    return 0;
}