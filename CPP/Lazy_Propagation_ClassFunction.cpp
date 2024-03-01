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
const int mxN = 2e5 + 10;
int n, q;
ll v[mxN];
class segT {
    vector<ll> sg, lz;
    vector<bool> lz2;
public:
    segT() {
        sg.resize(4 * mxN);
        lz.resize(4 * mxN);
        lz2.resize(4 * mxN);
    }
 
    void build(int s = 1, int e = n, int i = 1) {
        if (s == e) sg[i] = v[s];
        else {
            int mid = (s + e) / 2;
            build(s, mid, 2 * i);
            build(mid + 1, e, 2 * i + 1);
            sg[i] = sg[2 * i] + sg[2 * i + 1];
        }
    }
 
    void Apply(int s, int e, ll val, bool ok, int i) {
        if (ok) {
            sg[i] = 0;
            lz[i] = 0;
            lz2[i] = 1;
        }
        sg[i] += val * (e - s + 1);
        lz[i] += val;
    }
 
    void Push(int s, int mid, int e, int i) {
        Apply(s, mid, lz[i], lz2[i], 2 * i);
        Apply(mid + 1, e, lz[i], lz2[i], 2 * i + 1);
        lz[i] = lz2[i] = 0;
    }
 
    void upd(int lb, int rb, ll val, bool ok, int s = 1, int e = n, int i = 1) {
        if (s > rb || e < lb) return;
        if (s >= lb and e <= rb) {
            Apply(s, e, val, ok, i);
        }
        else {
            int mid = (s + e) / 2;
            Push(s, mid, e, i);
            upd(lb, rb, val, ok, s, mid, 2 * i);
            upd(lb, rb, val, ok, mid + 1, e, 2 * i + 1);
            sg[i] = sg[2 * i] + sg[2 * i + 1];
        }
    }
 
    ll qry(int lb, int rb, int s = 1, int e = n, int i = 1) {
        if (s > rb || e < lb) return 0;
        if (s >= lb and e <= rb) return sg[i];
        int mid = (s + e) / 2;
        Push(s, mid, e, i);
        return qry(lb, rb, s, mid, 2 * i) + qry(lb, rb, mid + 1, e, 2 * i + 1);
    }
} t;
void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    t.build();
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 3) {
            int lb, rb;
            cin >> lb >> rb;
            cout << t.qry(lb, rb) << '\n';
        }
        else {
            int lb, rb;
            ll val;
            cin >> lb >> rb >> val;
            if (tp == 1) t.upd(lb, rb, val, 0);
            else t.upd(lb, rb, val, 1);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    // for (int i = 1; i <= t; ++i) { // Kickstart
    //     cout << "Case #" << i << ": "; solve();
    // }
    return 0;
}
