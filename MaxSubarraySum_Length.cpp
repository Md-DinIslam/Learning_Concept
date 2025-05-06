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

void Din() {
    
    vector<int> v = {2, 3, -1, 2, 44, -6, 52};

    int n = v.size(), last = 0;
    ll mxSum = -1e18, currSum = -1e18, len = 0;

    for (int i = 0; i < n; ++i) {
        if (v[i] >= currSum + v[i]) {
            currSum = v[i];
            last = i;
        }
        else {
            currSum += v[i];
        }

        if (mxSum <= currSum) {
            mxSum = currSum;
            len = i - last + 1;
        }
    }

    cout << mxSum << " " << len << '\n';

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