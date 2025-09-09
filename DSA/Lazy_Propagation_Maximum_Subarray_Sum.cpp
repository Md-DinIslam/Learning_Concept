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

vector<int> v;

struct Node {
    ll sum, maxSubSum, prefix, suffix;
};

class segTee {
    vector<Node> sg;
    vector<ll> lz;
public:
    segTee(int n) : sg(4 * n + 1), lz(4 * n + 1, 1e18) {}

    void Apply(int s, int e, ll val, int i) {
        ll new_val = 1ll * val * (e - s + 1);
        sg[i].sum = new_val;
        if (val < 0) {
            new_val = 0;
        }
        sg[i].maxSubSum = new_val;
        sg[i].prefix = new_val;
        sg[i].suffix = new_val;
        lz[i] = val;
    }

    void Push(int s, int mid, int e, int i) {
        if (lz[i] != 1e18) {
            Apply(s, mid, lz[i], 2 * i);
            Apply(mid + 1, e, lz[i], 2 * i + 1);
        }
        lz[i] = 1e18;
    }

    Node merge(Node a, Node b) {
        ll maxSubSum = max({a.maxSubSum, b.maxSubSum, a.suffix + b.prefix});
        ll sum = a.sum + b.sum;
        ll prefix = max(a.prefix, a.sum + b.prefix);
        ll suffix = max(b.suffix, b.sum + a.suffix);
        return {sum, maxSubSum, prefix, suffix};
    }

    void upd(int lb, int rb, ll val, int s, int e, int i = 1) {
        if (s > rb || e < lb) return;
        if (s >= lb && e <= rb) {
            Apply(s, e, val, i);
        }
        else {
            int mid = (s + e) / 2;
            Push(s, mid, e, i);
            upd(lb, rb, val, s, mid, 2 * i);
            upd(lb, rb, val, mid + 1, e, 2 * i + 1);
            // sg[i] = min(sg[2 * i], sg[2 * i + 1]);
            sg[i] = merge(sg[2 * i], sg[2 * i + 1]);
        }
    }

    Node qry(int lb, int rb, int s, int e, int i = 1) {
        if (s > rb || e < lb) return {0, 0, 0, 0};
        if (s >= lb && e <= rb) return sg[i];
        int mid = (s + e) / 2;
        Push(s, mid, e, i);
        return merge(qry(lb, rb, s, mid, 2 * i) , qry(lb, rb, mid + 1, e, 2 * i + 1));
    }
};

void Din() {
    int n, q;
    cin >> n >> q;

    segTee t(n);

    while (q--) {
        int lb, rb, val;
        cin >> lb >> rb >> val;
        lb += 1;
        t.upd(lb, rb, val, 1, n);
        cout << t.qry(1, n, 1, n).maxSubSum << '\n';
    }
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