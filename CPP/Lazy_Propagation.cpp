/* GREEN UNIVERSITY OF BANGLADESH
       Md DinIslam, Batch-221
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN = 2e5 + 12;
ll v[mxN], sg[4 * mxN], lz[4 * mxN];
void build(int s, int e, int i = 1) {
    if (s == e) sg[i] = v[s];
    else {
        int mid = (s + e) / 2;
        build(s, mid, 2 * i);
        build(mid + 1, e, 2 * i + 1);
        sg[i] = sg[i * 2] + sg[i * 2 + 1];
    }
}
ll qry(int s, int e, int lb, int rb, int i = 1) {
    if (lz[i]) {
        sg[i] += lz[i] * (e - s + 1);
        if (s != e) {
            lz[2 * i] += lz[i], lz[2 * i + 1] += lz[i];
        }
        lz[i] = 0;
    }
    if (s > rb || e < lb) return 0ll;
    if (s >= lb && e <= rb) return sg[i];
    int mid = (s + e) / 2;
    ll a = qry(s, mid, lb, rb, 2 * i);
    ll b = qry(mid + 1, e, lb, rb, 2 * i + 1);
    return a + b;
}
void upd(int s, int e, int lb, int rb, ll val, int i = 1) {
    if (lz[i]) {
        sg[i] += lz[i] * (e - s + 1);
        if (s != e) {
            lz[2 * i] += lz[i], lz[2 * i + 1] += lz[i];
        }
        lz[i] = 0;
    }
    if (s > rb || e < lb) return;
    if (s >= lb && e <= rb) {
        sg[i] += val * (e - s + 1);
        if (s != e) {
            lz[2 * i] += val, lz[2 * i + 1] += val;
        }
    }
    else {
        int mid = (s + e) / 2;
        upd(s, mid, lb, rb, val, 2 * i);
        upd(mid + 1, e, lb, rb, val, 2 * i + 1);
        sg[i] = sg[2 * i] + sg[2 * i + 1];
    }
}
void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    build(1, n);
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            ll lb, rb, val;
            cin >> lb >> rb >> val;
            upd(1, n, lb, rb, val);
        }
        else {
            int indx;
            cin >> indx;
            cout << qry(1, n, indx, indx) << '\n';
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    // fl(i, t) { //Kickstart
    //     cout << "Case #" << i + 1 << ": "; solve();
    // }
    return 0;
}
