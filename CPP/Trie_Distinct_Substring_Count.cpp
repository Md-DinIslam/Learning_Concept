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

struct Node {
    Node* links[26];

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    Node* getNext(char ch) {
        return links[ch - 'a'];
    }

    void Put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

};

// class Trie {
// private:
//     Node* root;
// public:
//     Trie() {
//         root = new Node();
//     }

//     void Insert(string &s) {
//         ;
//     }
// };

int countDistinctSubstrings(string &s) {
    Node* root = new Node();
    int cnt = 0;
    for (int i = 0; i < s.size(); ++i) {
        Node* node = root;
        for (int j = i; j < s.size(); ++j) {
            if (!node->containsKey(s[j])) {
                cnt += 1;
                node->Put(s[j], new Node());
            }
            node = node->getNext(s[j]);
        }
    }
    return cnt + 1;
}

void Din() {
    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        cout << countDistinctSubstrings(s[i]) << '\n';
    }

}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; ++i) { // Kickstart
        // cout << "Case " << i << ": ";
        Din();
    }
    return 0;
}