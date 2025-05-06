/* GREEN UNIVERSITY OF BANGLADESH
       Md DinIslam, Batch-221
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN = 2 * 1e5;
ll v[mxN + 1], ans[4 * mxN];
void build(int s, int e, int rt) {
    if (s == e) {
        ans[rt] = v[s]; return;
    }
    int mid = (s + e) >> 1;
    build(s, mid, 2 * rt);
    build(mid + 1, e, 2 * rt + 1);
    ans[rt] = ans[rt << 1] + ans[(rt << 1) + 1];
}
ll query(int s, int e, int l, int r, int rt) {
    if (s > r || e < l) return 0;
    if (s >= l && e <= r) return ans[rt];
    int mid = (s + e) / 2;
    ll a = query(s, mid, l, r, 2 * rt);
    ll b = query(mid + 1, e, l, r, 2 * rt + 1);
    return a + b;
}
void update(int s, int e, int indx, ll val, int rt) {
    if (s == e) ans[rt] = val;
    else {
        int mid = (s + e) >> 1;
        if (indx <= mid) update(s, mid, indx, val, 2 * rt);
        else update(mid + 1, e, indx, val, 2 * rt + 1);
        ans[rt] = ans[2 * rt] + ans[2 * rt + 1];
    }
}
void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> v[i];
    build(1, n, 1);
    while (q--) {
        int k, l, r;
        cin >> k >> l >> r;
        if (k == 2) {
            cout << query(1, n, l, r, 1) << "\n";
        }
        else {
            update(1, n, l, r, 1);
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    // fl(i, t) { //Kickstart
    //     cout << "Case #" << i + 1 << ": "; solve();
    // }
    return 0;
}
