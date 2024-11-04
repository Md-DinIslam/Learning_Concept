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


class DSU {
    // we need two component, rank and parent......
    vector<int> rank, par, sizes;
public:
    DSU(int n) {
        rank.resize(n + 1, 0); // Make sure to initialize by 0...
        par.resize(n + 1); // Make sure to initialize it's parent by itself....
        iota(all(par), 0);
        sizes.resize(n + 1, 1); // Make sure to initialize by 1....
    }

    // Return the ultimate parent of the given Node....
    int Find(int node) {
        if (node == par[node]) {
            return node;
        }
        return par[node] = Find(par[node]);
    }

    // Unior By Rank......
    void UnionByRank(int u, int v) {
        int par_u = Find(u);
        int par_v = Find(v);

        // If they're same don't need to do anything.....
        if (par_u == par_v)
            return;

        // If rank of par_u is less than par_v, then connect par_u with larger rank par_v......
        if (rank[par_u] < rank[par_v]) {
            par[par_u] = par_v;
        }
        // If rank of par_v is less than par_u, then connect par_v with larger rank par_u.....
        else if (rank[par_v] < rank[par_u]) {
            par[par_v] == par_u;
        }
        // If same rank, then connect anyone, and increase the value of rank.....
        else {
            par[par_u] = par_v;
            rank[par_v] += 1;
        }
    }

    // Union By Size....
    void UnionBySize(int u, int v) {
        int par_u = Find(u);
        int par_v = Find(v);
        if (par_v == par_u)
            return;

        if (sizes[par_u] < sizes[par_v]) {
            par[par_u] = par_v;
            sizes[par_v] += sizes[par_u];
        }
        else {
            par[par_v] = par_u;
            sizes[par_u] += sizes[par_v];
        }
    }
};

void Din() {
    DSU dsu(7);

    dsu.UnionBySize(1, 2);
    dsu.UnionBySize(2, 3);
    dsu.UnionBySize(4, 5);
    dsu.UnionBySize(6, 7);
    dsu.UnionBySize(5, 6);
    dsu.UnionBySize(2, 3);

    // if 3 and 7, same or not.....
    if (dsu.Find(3) == dsu.Find(7))
        cout << "Same Component\n";
    else
        cout << "Not Same Component\n";

    dsu.UnionBySize(3, 7);
    // After adding 3 and 7, now check same or not....
    if (dsu.Find(3) == dsu.Find(7))
        cout << "Same Component\n";
    else
        cout << "Not Same Component\n";

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
