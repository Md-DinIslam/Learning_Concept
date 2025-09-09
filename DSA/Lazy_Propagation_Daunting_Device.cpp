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
#define pb push_back
#define sz(x) int(x.size())
#define arr array

class segTreeLazy {
    vector<int> sg, lz;
    vector<bool> lz2;
public:
    segTreeLazy (int n) : sg(4 * n + 1, 1), lz(sg), lz2(4 * n + 1, 1) {};

    void Apply(int s, int e, int val, int i) {
        sg[i] = val;
        lz[i] = val;
        lz2[i] = 1;
    }

    void Push(int s, int mid, int e, int i) {
        if (lz[i]) {
            Apply(s, mid, lz[i], 2 * i);
            Apply(mid + 1, e, lz[i], 2 * i + 1);
        }
        lz[i] = 0;
        lz2[i] = 0;
    }

    void upd (int lb, int rb, int val, int s, int e, int i = 1) {
        if (s > rb || e < lb) return;
        if (s >= lb && e <= rb) {
            Apply(s, e, val, i);
        }
        else {
            int mid = (s + e) / 2;
            Push(s, mid, e, i);
            upd(lb, rb, val, s, mid, 2 * i);
            upd(lb, rb, val, mid + 1, e, 2 * i + 1);

            sg[i] = (sg[2 * i] == sg[2 * i + 1] ? sg[2 * i] : 0);
        }
    }

    int qry(int lb, int rb, int color, int s, int e, int i = 1) {
        if (s > rb || e < lb) return 0;
        if (s >= lb && e <= rb) {
            if (lz2[i]) {
                // if (sg[i] == color) return (e - s + 1);
                // else return 0;
                return (sg[i] == color ? (e - s + 1) : 0);
            }
        }

        int mid = (s + e) / 2;
        Push(s, mid, e, i);
        return qry(lb, rb, color, s, mid, 2 * i) + qry(lb, rb, color, mid + 1, e, 2 * i + 1);
    }
};

void Din() {
    int len, color, step;
    cin >> len >> color >> step;

    segTreeLazy t(len);

    for (int i = 1; i <= step; ++i) {
        int p, x, a, b;
        cin >> p >> x >> a >> b;

        int s = t.qry(1, len, p, 1, len);

        // dg(s);

        int lb = (a + (1ll * s * s % len)) % len + 1;
        int rb = (a + (1ll * (s + b) * (s + b) % len)) % len + 1;
        if (lb > rb)
            swap(lb, rb);

        // dg(lb, rb);

        t.upd(lb, rb, x, 1, len);
    }

    int ans = 0;
    for (int i = 1; i <= color; ++i) {
        // dg(t.qry(1, len, i, 1, len));
        int cnt = t.qry(1, len, i, 1, len);
        ans = max(ans, cnt);
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; ++i) {
        // cout << "Case " << i << ": ";
        Din();
    }
    return 0;
}