/* GREEN UNIVERSITY OF BANGLADESH
    Md DinIslam, Batch-221 (CSE)
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// Debug..
#ifdef LOCAL
#include "debug.h"
#endif

#define ll long long
#define all(x) x.begin(), x.end();
#define pb push_back
#define ff first
#define ss second
#define arr array

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(vector<int> &v, int n, int k) {
    deque<int> q;
    vector<int> ans;

    for (int i = 0; i < n; ++i) {
        if (!q.empty() && i >= k) {
            if (q.front() <= v[i - k])
                q.pop_front();
        }

        while (!q.empty() && v[i] >= q.back()) {
            q.pop_back();
        }

        q.push_back(v[i]);

        if (i >= k - 1) {
            cout << q.front() << ' ';
        }
    }
    cout << '\n';
}

void Din() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    oset<arr<int, 2>> st;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        st.insert({v[i], i});

        if (i >= k) {
            st.erase({v[i - k], i - k});
        }

        if (st.size() == k) {
            // arr<int, 2> x = *st.find_by_order((k - 1) / 2);
            arr<int, 2> x = *--st.end();
            cout << x[0] << ' ';
        }

        // debug(st);
    }

    cout << '\n';
    solve(v, n, k);
}
int main() {
    ios_base:: sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) Din();
    // for (int i = 1; i <= t; ++i) {
    //     cout << "Case #" << i << ": "; Din();
    // }
}