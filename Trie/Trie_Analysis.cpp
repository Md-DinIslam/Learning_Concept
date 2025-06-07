/* GREEN UNIVERSITY OF BANGLADESH
       Md DinIslam, Batch-221
*/
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

// Aliases
using ll = long long;
using lld = long double;
using ull = unsigned long long;

// TypeDEf
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef vector<vll> mat;
typedef unordered_map<ll, ll> umpll;
typedef unordered_map<int, int> umpi;
typedef map<ll, ll> mpll;
// template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Macros
#define speed ios_base::sync_with_stdio(0), cin.tie(0)
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)
#define rep1(i, n) for(int i = 0; i < int(n); ++i)
#define rep2(i, a, n) for(int i = int(a); i <= int(n); ++i)
#define prf(x) printf("%d\n", x)
#define pfl(x) printf("%lld\n", x)
#define sc(x) scanf("%d", &x)
#define scl(x) scanf("%lld", &x)
#define scf(x) scanf("%lf", &x)
#define ff first
#define ss second
#define in insert
#define pb push_back
#define eb emplace_back
#define pp pop_back
#define mp make_pair
#define py cout << "YES\n"
#define pm cout << "-1\n"
#define pn cout << "NO\n"
#define nl cout << '\n'
#define bitcnt __builtin_popcountll
#define endl '\n'
#define arr array
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()

// Debug..
#ifdef LOCAL
#include "debug.h"
#else
#define debug(x...)
#endif

// Constants
const lld PI = 3.141592653589793238;
const ll INF = 1e18 + 9;
const ll mod = 1e9 + 7;

// R, D, L, U......
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int di[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int dj[8] = {1, -1, 0, 1, -1, 0, 1, -1};

int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

struct Node {
    Node* links[26];
    bool is_end = false;
    int cntEndWith = 0;
    int cntPrefix = 0;

    Node() {
        for (int i = 0; i < 26; ++i) {
            links[i] = NULL;
        }
        is_end = false;
    }

    bool ContainsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    void Put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* getNext(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        is_end = true;
    }

    bool isEnd() {
        return is_end;
    }

    void increaseCntEnd() {
        cntEndWith += 1;
    }

    void increasePrefix() {
        cntPrefix += 1;
    }

    void deleteEnd() {
        cntEndWith -= 1;
    }

    void decreasePrefix() {
        cntPrefix -= 1;
    }

    int getCntEnd() {
        return cntEndWith;
    }

    int getCntPrefix() {
        return cntPrefix;
    }

};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    // O(size of word).....
    void Insert(string &word) {
        Node* node = root;

        for (int i = 0; i < sz(word); ++i) {
            // If it is Null, then create new refference...
            if (!node->ContainsKey(word[i])) {
                // if (!node->links[word[i] - 'a']) {
                node->Put(word[i], new Node());
            }
            // Jump to the next refference....
            node = node->getNext(word[i]);
            // Coount how many word in prefix.....
            node->increasePrefix();
        }

        // At the end, make it true means this word is ended.....
        node->setEnd();
        // Count how many words end with....
        node->increaseCntEnd();
    }

    bool Search(string &word) {
        Node* node = root;

        for (int i = 0; i < sz(word); ++i) {
            // If it is Null, so not found any word like this....
            if (!node->ContainsKey(word[i])) {
                return false;
            }
            // Jump to the next refference....
            node = node->getNext(word[i]);
        }

        return node->isEnd();
    }

    int countWordEqualTo(string &word) {
        Node* node = root;

        for (int i = 0; i < sz(word); ++i) {
            if (!node->ContainsKey(word[i])) {
                return 0;
            }
            node = node->getNext(word[i]);
        }

        return node->getCntEnd();
    }

    int countWordStartWith(string &word) {
        Node* node = root;

        for (int i = 0; i < sz(word); ++i) {
            if (!node->ContainsKey(word[i])) {
                return 0;
            }
            node = node->getNext(word[i]);
        }

        return node->getCntPrefix();
    }

    void eraseWord(string &word) {
        Node* node = root;
        // If this word doesn't exist....
        if (Search(word) == 0) {
            return;
        }

        for (int i = 0; i < sz(word); ++i) {
            if (!node->ContainsKey(word[i])) {
                return;
            }
            node = node->getNext(word[i]);
            node->decreasePrefix();
        }

        node->deleteEnd();
    }

    bool StartWith(string &word) {
        Node* node = root;

        for (int i = 0; i < sz(word); ++i) {
            // If it is Null, so not match with this word....
            if (!node->ContainsKey(word[i])) {
                return false;
            }
            node = node->getNext(word[i]);
        }

        return true;
    }
} t;

void Din() {
    int n;
    cin >> n;

    rep(i, n) {
        string s;
        cin >> s;
        t.Insert(s);
    }

    string pat = "din";
    string s = "r";

    cout << t.countWordEqualTo(pat) << "\n";
    cout << t.countWordStartWith(s) << '\n';

    if (t.StartWith(pat)) {
        cout << "Found\n";
    }
    else {
        cout << "Not Found\n";
    }
}
// Main
int main() {
    speed;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; ++i) { // Kickstart
        // cout << "Case " << i << ": ";
        Din();
    }
    return 0;
}

/*

5
din
ratul
fahim
rahim
elma


*/