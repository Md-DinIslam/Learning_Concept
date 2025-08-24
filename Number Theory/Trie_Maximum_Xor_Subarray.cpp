/* GREEN UNIVERSITY OF BANGLADESH
    Md DinIslam, Batch-221 (CSE)
    Time: 17:47:19
    Date: 23-08-2025
*/
 
#include <bits/stdc++.h>
using namespace std;
 
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
 
struct Node {
    Node* bit[2];
    Node () {
        bit[0] = NULL;
        bit[1] = NULL;
    }
};
 
class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
 
    void insert(int val) {
        Node* curr_root = root;
        for (int i = 30; ~i; --i) {
            int curr_bit = (val >> i) & 1;
            // dg(curr_bit, val);
            if (curr_root->bit[curr_bit] == NULL) {
                curr_root->bit[curr_bit] = new Node();
            }
            curr_root = curr_root->bit[curr_bit];
        }
    }
 
    int qry(int val) {
        int ans = 0;
        Node* curr_root = root;
        for (int i = 30; ~i; --i) {
            int curr_bit = (val >> i) & 1;
            int flip_bit = curr_bit ^ 1; // same as 1 - curr_bit..
            // dg(curr_bit, i);
            if (curr_root->bit[flip_bit] != NULL) {
                ans |= (1 << i);
                curr_root = curr_root->bit[flip_bit];
                // dg(i, val);
            }
            // else if (curr_root->bit[curr_bit] != NULL) {
            //     curr_root = curr_root->bit[curr_bit];
            // }
            // else {
            //     return ans;
            // }
            else {
                curr_root = curr_root->bit[curr_bit];
            }
        }
        return ans;
    }
};
 
void Din() {
    int n;
    cin >> n;
 
    Trie t;
    t.insert(0); // base prefix....
    
    dg(1 << 30);
 
    vector<int> v(n);
    int curr_xor = 0, ans = 0;
    for (auto &x : v) {
        cin >> x;
        curr_xor ^= x;
        dg(t.qry(curr_xor));
        ans = max(ans, t.qry(curr_xor));
        t.insert(curr_xor);
    }
 
    cout << ans << '\n';
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