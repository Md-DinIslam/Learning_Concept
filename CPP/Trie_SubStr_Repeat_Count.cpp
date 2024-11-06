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
#define ff first
#define ss second

struct Node {
    Node* links[5];
    int cntSubStr = 0;

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    Node* getNext(char ch) {
        return links[ch - 'a'];
    }

    void Put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    void increaseCnt() {
        cntSubStr += 1;
    }

    int getCount() {
        return cntSubStr;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void Insert(int n, string &s) {
        for (int i = 0; i < n; ++i) {
            Node* node = root;
            for (int j = i; j < n; ++j) {
                if (!node->containsKey(s[j])) {
                    node->Put(s[j], new Node());
                }
                node = node->getNext(s[j]);
                node->increaseCnt();
            }
        }
    }

    pair<string, int> getMaxRepeat(int n, string &s) {
        int max_cnt = 0;
        string ans = "";

        for (int i = 0; i < n; ++i) {
            string temp = "";
            Node* node = root;
            for (int j = i; j < n; ++j) {
                temp.pb(s[j]);
                if (node->containsKey(s[j])) {
                    // debug(temp);
                    node = node->getNext(s[j]);
                    int curr_cnt = node->getCount();
                    int max_len = sz(ans), curr_len = sz(temp);
                    if (curr_cnt > 1) {
                        if (max_len < curr_len) {
                            ans = temp;
                            max_cnt = curr_cnt;
                        }
                        else if (max_cnt == curr_cnt) {
                            if (sz(ans) == sz(temp)) {
                                ans = min(ans, temp);
                            }
                            else if (max_len < curr_len) {
                                ans = temp;
                            }
                            max_cnt = curr_cnt;
                        }
                        // ans = min(ans, temp);
                    }
                }
            }
        }

        return {ans, max_cnt};
    }
};


void Din() {
    Trie t;

    string s;
    cin >> s;
    int n = sz(s);

    map<char, char> cnt, revCnt;
    string temp = "ACGT", temp_low = "abcd";

    for (int i = 0; i < 4; ++i) {
        cnt[temp[i]] = temp_low[i];
        revCnt[temp_low[i]] = temp[i];
    }

    // debug(cnt, revCnt);
    for (auto &x : s) {
        x = tolower(cnt[x]);
    }

    // debug(s);

    t.Insert(n, s);

    auto ans = t.getMaxRepeat(n, s);

    if (ans.ff.empty()) {
        cout << "No repetitions found!\n";
    }
    else {
        // debug(ans.ff);
        for (auto &x : ans.ff) {
            x = toupper(revCnt[x]);
        }
        cout << ans.ff << ' ' << ans.ss << '\n';
    }
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