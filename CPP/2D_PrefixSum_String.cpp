/* GREEN UNIVERSITY OF BANGLADESH
       Md DinIslam, Batch-221
*/
#include <bits/stdc++.h>
using namespace std;
void solve() {
    int q;
    string s;
    cin >> q >> s;
    int n = s.size();
    vector<vector<int> > pref(n + 1, vector<int> (26, 0));
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i];
        pref[i + 1][s[i] - 'a']++;
    }
    while (q--) {
        int L, R;
        cin >> L >> R;
        char ch;
        int ans = -1;
        for (int j = 0; j < 26; ++j) {
            // pref[R+1][j] - pref[L+1-1][j];
            int curFreq = pref[R + 1][j] - pref[L][j];
            if (curFreq > ans) {
                ans = curFreq;
                ch = (char) j + 'a';
            }
        }
        cout << ch << " " << ans << '\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif
    int t = 1;
    // cin >> t;
    while (t--) solve();
    // fl(i, t) { //Kickstart
    //     cout << "Case #" << i + 1 << ": "; solve();
    // }
    return 0;
}