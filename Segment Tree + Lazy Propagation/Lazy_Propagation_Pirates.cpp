/* GREEN UNIVERSITY OF BANGLADESH
    Md DinIslam, Batch-221 (CSE)
*/
#include <bits/stdc++.h>
using namespace std;

// Debug..
#ifdef LOCAL
#include "debug.h"
#else
#define debug(x...)
#endif

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()

const int mxN = 2e6 + 9;
vector<int> v(mxN);
int n;

void reset() {
    v.assign(mxN, 0);
}

class segT {
    vector<int> sg, lz;
public:
    segT() {
        sg.resize(4 * mxN);
        lz.resize(4 * mxN);
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

    void Apply(int s, int e, int tp, int i) {
        if (tp == 1) {
            sg[i] = (e - s + 1);
            // lz[i] = 1;
        }
        else if (tp == 2) {
            sg[i] = 0;
            // lz[i] = 0;
        }
        else if (tp == 3) {
            sg[i] = (e - s + 1) - sg[i];
        }

        // Fliping in type = 'I'...
        if (tp == 3) {
            if (lz[i] == 1) {
                lz[i] = 2;
            }
            else if (lz[i] == 2) {
                lz[i] = 1;
            }
            else if (lz[i] == 3) {
                lz[i] = 0;
            }
            else if (lz[i] == 0) {
                lz[i] = 3;
            }
        }
        else {
            lz[i] = tp;
        }
    }

    void Push(int s, int mid, int e, int i) {
        if (lz[i]) {
            Apply(s, mid, lz[i], 2 * i);
            Apply(mid + 1, e, lz[i], 2 * i + 1);
        }
        lz[i] = 0;
    }

    void upd(int lb, int rb, int tp, int s = 1, int e = n, int i = 1) {
        if (s > rb || e < lb) return;
        if (s >= lb && e <= rb) {
            Apply(s, e, tp, i);
        }
        else {
            int mid = (s + e) / 2;
            Push(s, mid, e, i);
            upd(lb, rb, tp, s, mid, 2 * i);
            upd(lb, rb, tp, mid + 1, e, 2 * i + 1);
            sg[i] = sg[2 * i] + sg[2 * i + 1];
        }
    }

    int qry(int lb, int rb, int s = 1, int e = n, int i = 1) {
        if (s > rb || e < lb) return 0;
        if (s >= lb && e <= rb) return sg[i];
        int mid = (s + e) / 2;
        Push(s, mid, e, i);
        return (qry(lb, rb, s, mid, 2 * i) + qry(lb, rb, mid + 1, e, 2 * i + 1));
    }
};


void Din() {
    reset();
    segT t;

    int k;
    cin >> k;
    n = 1;
    for (int i = 0; i < k; ++i) {
        int m;
        string s;
        cin >> m >> s;
        while (m--) {
            for (auto &x : s) {
                v[n++] = (x - '0');
            }
        }
    }

    // for (int i = 1; i <= n; ++i) {
    //     cout << v[i];
    // }
    // debug(n);

    t.build();

    int q;
    cin >> q;
    int cnt = 1;
    while (q--) {
        char ch;
        int lb, rb;
        cin >> ch >> lb >> rb;
        lb += 1, rb += 1;
        if (ch == 'F') {
            t.upd(lb, rb, 1);
        }
        else if (ch == 'E') {
            t.upd(lb, rb, 2);
        }
        else if (ch == 'I') {
            t.upd(lb, rb, 3);
        }
        else {
            cout << "Q" << cnt++ << ": " << t.qry(lb, rb) << '\n';
        }
    }

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i) { // Kickstart
        cout << "Case " << i << ":\n";
        Din();
    }
    return 0;
}