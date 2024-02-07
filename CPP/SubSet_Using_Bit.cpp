#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// using namespace chrono;
// using namespace __gnu_pbds;

// def
// #define DinIslam 1

// Speed
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Din cout.tie(NULL);

// Aliases
using ll = long long;
using lld = long double;
using ull = unsigned long long;

// Constants
const lld PI = 3.141592653589793238;
const ll INF = LONG_LONG_MAX;
const ll mod = 1e9 + 7;

// TypeDEf
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef unordered_map<ll, ll> umll;
typedef map<ll, ll> mll;

// Macros
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define fl(i, n) for (int i = 0; i < n; i++)
#define rfl(i, m, n) for (int i = n; i >= m; i--)
#define py cout << "YES\n";
#define pm cout << "-1\n";
#define pn cout << "NO\n";
#define pf cout << "FIRST\n";
#define nn cout << "\n";
#define all(v) v.begin(), v.end()
#define rall(v) v.end(), v.begin()

// Debug
#ifdef DinIslam
#define debug(x)       \
    cerr << #x << " "; \
    cerr << x << " ";  \
    cerr << endl;
#else
#define debug(x) ;
#endif

void subset(vector<vi> &ans) {
    for (auto &x : ans) {
        for (auto &sub : x) {
            cout << sub << " ";
        }
        cout << '\n';
    }
}
void solve()
{
    int n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int subCnt = 1 << n;
    // cout<<subCnt;nn
    vector<vector<int>> ans;
    for (int i = 0; i < subCnt; ++i) {
        vi temp;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                temp.push_back(v[j]);
                // cout<<temp[i]<<" "
                ;
            }
        }
        ans.push_back(temp);
    }
    subset(ans);
}
// Main
int main()
{
    Code By Din
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    clock_t z = clock();
    //     ll t;
    // cin >> t;
    // fl(i, t)
    // {
    //     solve();
    // }
    solve();
    // fl(i,t) //Kickstart
    // {
    //     cout<<"Case #"<<i+1<<": ";
    //     solve();
    //     cout<<"\n";
    // }
    cerr << "Run Time : " << (((double)(clock() - z)) / CLOCKS_PER_SEC);
    return 0;
}