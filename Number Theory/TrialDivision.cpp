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
#define sz(x) int(x.size())

bool isPrime(int n) {
    if (n <= 3) return n > 1;
    if ((n % 2) == 0 || (n % 3) == 0) {
        return 0;
    }

    for (ll i = 5; i * i <= n; i += 6) {
        if ((n % i) == 0 || (n % (i + 2)) == 0) {
            return 0;
        }
    }

    return 1;
}

void Din() {
    int n;
    cin >> n;

    if (isPrime(n))
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        // cout << "Case " << i << ": ";
        Din();
    }
    return 0;
}