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
#define pb push_back

const int mxN = 1e6 + 10;
vector<bool> isPrime(mxN, 1);

void sieve () { // Sieve Generating.....
    for (int i = 2; i * i < mxN; ++i) {
        if (isPrime[i])
            for (int j = i * i; j < mxN; j += i)
                isPrime[j] = 0;
    }
}
void solve() {
    int lb, rb;
    cin >> lb >> rb;
    vector<int> primes;
    for (int i = 2; i * i <= rb; ++i) {
        if (isPrime[i])
            primes.pb(i); // Taking all primes till sqrt(rb)....
    }
    // debug(primes);
    vector<bool> ans(rb - lb + 1, 1);
    for (auto &i : primes) {
        int k = (lb / i) * i; // First Multiple of J......
        if (k < lb) k += i;
        for (int j = max(k, i * i); j <= rb; j += i) {
            ans[j - lb] = 0;
        }
    }
    // if (lb == 1) ans[1 - lb] = 0;

    // For lb = 1 is not prime, so (i) will start from max(2,lb)......
    for (int i = max(lb, 2); i <= rb; ++i) {
        if (ans[i - lb]) cout << i << '\n';
    }
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    sieve();
    while (t--) solve();
    // for (int i = 1; i <= t; ++i) { // Kickstart
    //     cout << "Case #" << i << ": "; solve();
    // }
    return 0;
}