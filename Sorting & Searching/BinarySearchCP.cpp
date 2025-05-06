/* GREEN UNIVERSITY OF BANGLADESH
       Md DinIslam, Batch-221
*/
#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, k;
    cin >> n >> k;
    int v[n];
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    sort(v, v + n);
    int lb = 0, rb = n;
    while (lb < rb) {
        int mid = lb + (rb - lb) / 2;
        if (k <= v[mid]) rb = mid;
        else lb = mid + 1;
    }
    cout << ((v[lb] == k) ? "YES\n" : "NO\n");
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif
    int t = 1;
    // cin >> t;
    while (t--) solve();
    // fl(i, t) { //Kickstart
    //     cout << "Case #" << i + 1 << ": "; solve();
    // }
    return 0;
}