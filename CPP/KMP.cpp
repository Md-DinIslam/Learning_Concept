#include <bits/stdc++.h>
using namespace std;

// Speed
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Din cout.tie(NULL);

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

// Macros
#define prf(x) printf("%d\n", x)
#define pfl(x) printf("%lld\n", x)
#define sc(x) scanf("%d", &x)
#define scl(x) scanf("%lld", &x)
#define scf(x) scanf("%lf", &x)
#define ff first
#define ss second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define fl(i, n) for (int i = 0; i < n; i++)
#define rep(i,a, n) for (int i = a; i <= n; i++)
#define rfl(i, m, n) for (int i = n; i >= m; i--)
#define py cout << "YES\n";
#define pm cout << "-1\n";
#define pn cout << "NO\n";
#define pf cout << "FIRST\n";
#define nn cout << '\n';
#define bitcount __builtin_popcountll
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.end(), v.begin()

//DEBUG
void __print(int x) {cerr << x << " ";}
void __print(long x) {cerr << x << " ";}
void __print(long long x) {cerr << x << " ";}
void __print(unsigned x) {cerr << x << " ";}
void __print(unsigned long x) {cerr << x << " ";}
void __print(unsigned long long x) {cerr << x << " ";}
void __print(float x) {cerr << x << " ";}
void __print(double x) {cerr << x << " ";}
void __print(long double x) {cerr << x << " ";}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

// Constants
const lld PI = 3.141592653589793238;
const ll INF = 1e18 + 9;
const ll mod = 1e9 + 7;

vll prefix(string &s) {
    int n = s.size();
    vll ans(n, 0);
    int len = 0, i = 1;
    while (i < n) {
        if (s[len] == s[i]) ++len, ans[i] = len, ++i;
        else if (len == 0) ans[i] = 0, ++i;
        else len = ans[len - 1];
    }
    return ans;
}
void solve()
{
    int n;
    string pat, s;
    // cin >> n >> pat >> s;
    while (cin >> n >> pat >> s) {
        if (s.size() < n) cout << '\n';
        else {
            s = pat + "&" + s;
            vll ans = prefix(s);
            for (int i = 0; i < s.size(); ++i) {
                if (ans[i] == n) cout << i - 2 * n << '\n';
            }
        }
    }
}
// Main
int main()
{
    Code By Din

    clock_t z = clock();
    ll t = 1;
    // cin >> t;
    while (t--) solve();
    // fl(i, t) { //Kickstart
    //     cout << "Case #" << i + 1 << ": ";
    //     solve();
    // }
    cerr << "\nRun Time : " << (((double)(clock() - z)) / CLOCKS_PER_SEC);
    return 0;
}