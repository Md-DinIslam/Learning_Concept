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
int a[mxN], b[mxN];
class segT {
    vector<int> sg;
public:
    segT (int n) {
        sg.resize(4 * n + 1);
    }
    void upd(int indx, int val, int s, int e, int i = 1) {
        if (s == e) sg[i] = val;
        else {
            int mid = (s + e) / 2;
            if (indx <= mid) upd(indx, val, s, mid, 2 * i);
            else upd(indx, val, mid + 1, e, 2 * i + 1);
            sg[i] = sg[2 * i] + sg[2 * i + 1];
        }
    }
    ll qry(int lb, int rb, int s, int e, int i = 1) {
        if (s > rb || e < lb) return 0;
        if (s >= lb & e <= rb) return sg[i];
        int mid = (s + e) / 2;
        return qry(lb, rb, s, mid, 2 * i) + qry(lb, rb, mid + 1, e, 2 * i);
    }
};
void solve() {
    int n;
    cin >> n;
    segT T(n);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        T.upd(i, a[i], 1, n);
    }
    int m;
    cin >> m;
    segT T2(m);
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
        T2.upd(i, b[i], 1, m);
    }
    int q;
    cin >> q;
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int lb1, rb1, lb2, rb2;
            cin >> lb1 >> rb1 >> lb2 >> rb2;
            int ans1 = T.qry(lb1, rb2, 1, n);
            int ans2 = T2.qry(lb2, rb2, 1, n);
            // debug(ans1);
            cout << ans1 + ans2 << '\n';
        }
        else {
            int arrNo, indx, val;
            cin >> arrNo >> indx >> val;
            if (arrNo == 1) {
                T.upd(indx, val, 1, n);
                a[indx] = val;
            }
            else {
                T.upd(indx, val, 1, n);
                b[indx] = val;
            }
        }
    }
}


/*

5
1 2 3 4 5
5
6 7 8 9 10
3
1 1 5 1 5
2 1 1 46
1 1 5 1 5

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