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
public:
    segT (int n) {
        sg.resize(4 * n + 1);
        lz.resize(4 * n + 1);
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

    void pushLazy(int s, int e, int i) {
        if (lz[i]) {
            sg[i] += lz[i] * (e - s + 1);
            if (s ^ e) {
                lz[2 * i] += lz[i];
                lz[2 * i + 1] += lz[i];
            }
            lz[i] = 0;
        }
    }
    void upd(int lb, int rb, ll val, int s = 1, int e = n, int i = 1) {
        pushLazy(s, e, i);
        if (s > rb or e < lb) return;
        if (s >= lb && e <= rb) {
            lz[i] += val;
            pushLazy(s, e, i);
            // sg[i] += val * (e - s + 1);
            // if (s ^ e) {
            //     lz[2 * i] += val;
            //     lz[2 * i + 1] += val;
            // }
        }
        else {
            int mid = (e + s) / 2;
            upd(lb, rb, val, s, mid, 2 * i);
            upd(lb, rb, val, mid + 1, e, 2 * i + 1);
            sg[i] = sg[2 * i] + sg[2 * i + 1];
        }
    }
    ll qry(int lb, int rb, int s = 1, int e = n, int i = 1) {
        pushLazy(s, e, i);
        if (s > rb or e < lb) return 0;
        if (s >= lb && e <= rb) return sg[i];
        int mid = (s + e) / 2;
        return qry(lb, rb, s, mid, 2 * i) + qry(lb, rb, mid + 1, e, 2 * i + 1);
    }
};
void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    segT T(n);
    T.build();
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int lb, rb;
            ll val;
            cin >> lb >> rb >> val;
            T.upd(lb, rb, val);
        }
        else {
            int indx;
            cin >> indx;
            cout << T.qry(indx, indx) << '\n';
        }
    }
}

/*

8 5
3 2 4 5 1 1 5 3
2 4
1 2 5 1
2 4
1 2 5 1
2 4

*/

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