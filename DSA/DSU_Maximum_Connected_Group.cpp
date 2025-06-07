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
#define dg(x...)
#endif

// Constants
const lld PI = 3.141592653589793238;
const ll INF = 1e18 + 9;
const ll mod = 1e9 + 7;

// R, D, L, U......
// int dx[4] = {0, 1, 0, -1};
// int dy[4] = {1, 0, -1, 0};

int di[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int dj[8] = {1, -1, 0, 1, -1, 0, 1, -1};

int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

class DSU {
private:
    vector<int> par, sizes;
public:
    DSU (int n) {
        sizes.resize(n, 1);
        par.resize(n);
        iota(par.begin(), par.end(), 0);
    }

    int Find(int node) {
        if (node == par[node]) {
            return node;
        }
        return par[node] = Find(par[node]);
    }

    void Union(int x, int y) {
        int par_x = Find(x);
        int par_y = Find(y);
        if (par_x == par_y) return;
        if (sizes[par_x] < sizes[par_y]) {
            par[par_x] = par_y;
            sizes[par_y] += sizes[par_x];
        }
        else {
            par[par_y] = par_x;
            sizes[par_x] += sizes[par_y];
        }
    }

    void print() {
        dg(par);
        dg(sizes);
    }

    int getSize(int node) {
        return sizes[node];
    }
};

class Solution {
public:
    bool isValid(int i, int j, int n, vector<vector<int>> &grid) {
        return (i >= 0 && j >= 0 && i < n && j < n && grid[i][j] == 1);
    }

    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        // int m = grid[0].size();
        DSU t(n * n);
        vector<vector<bool>> vis(n, vector<bool> (n, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    vis[i][j] = 1;
                    int node = i * n + j;
                    for (int k = 0; k < 4; ++k) {
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        if (isValid(ni, nj, n, grid) && !vis[ni][nj]) {
                            t.Union(node, ni * n + nj);
                        }
                    }
                }
            }
        }

        int ans = 0;
        bool ok = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    ok = 1;
                    set<int> parents;
                    int curr_ans = 0;
                    for (int k = 0; k < 4; ++k) {
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        int node = ni * n + nj;
                        if (isValid(ni, nj, n, grid)) {
                            parents.insert(t.Find(node));
                        }
                    }
                    for (auto &x : parents) {
                        curr_ans += t.getSize(x);
                    }
                    ans = max(ans, curr_ans + 1);
                }
            }
        }

        // t.print()
        if (!ok) ans = n * n;
        return ans;
    }
};

void Din() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int> (n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    cout << obj.MaxConnection(grid) << '\n';

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