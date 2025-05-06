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
    bool flag = false;

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    void Put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* getNext(char ch) {
        return links[ch - 'a'];
    }

    bool isEnd() {
        return flag;
    }

    void setEnd() {
        flag = true;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void Insert(string &s) {
        Node* node = root;
        for (auto &ch : s) {
            if (!node->containsKey(ch)) {
                node->Put(ch, new Node());
            }
            node = node->getNext(ch);
        }
        node->setEnd();
    }

    bool checkPrefixExists(string &s) {
        Node* node = root;
        for (auto &ch : s) {
            if (!node->containsKey(ch)) {
                return false;
            }
            node = node->getNext(ch);
            if (node->isEnd() == false)
                return false;
        }
        return true;
    }
};

string completeString(int n, vector<string> &s) {
    Trie t;

    for (auto &x : s) {
        t.Insert(x);
    }

    string ans = "";
    for (auto &x : s) {
        int len = sz(x);
        if (t.checkPrefixExists(x)) {
            // debug(x);
            if (len > sz(ans)) {
                ans = x;
                // debug(x);
            }
            else if (len == sz(ans) && x < ans) {
                ans = x;
            }
        }
    }

    if (ans.empty())
        ans = "None";
    return ans;
}

void Din() {
    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    cout << string(completeString(n, s)) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i) { // Kickstart
        // cout << "Case " << i << ": ";
        Din();
    }
    return 0;
}