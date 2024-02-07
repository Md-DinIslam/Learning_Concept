/* GREEN UNIVERSITY OF BANGLADESH
       Md DinIslam, Batch-221 (CSE)
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
typedef tree<ll, null_type, greater<ll>, rb_tree_tag, tree_order_statistics_node_update> oset;
void solve() {
    int n;
    cin >> n;
    ll v[n + 1];
    map<ll, int> vmp;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        vmp[v[i]];
    }
    int ptr = 1;
    for (auto &pr : vmp) {
        pr.second = ptr++;
    }
    for (int i = 1; i <= n; ++i) {
        v[i] = vmp[v[i]];
    }
    oset st;
    ll cnt = 0;
    for (int i = 1; i <= n; ++i) {
        st.insert(v[i]);
        cnt += st.order_of_key(v[i]);
    }
    cout << cnt << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif
    int t = 1;
    cin >> t;
    while (t--) solve();
    // for (int i = 1; i <= t; ++i) { //Kickstart
    //     cout << "Case #" << i << ": "; solve();
    // }
    return 0;
}