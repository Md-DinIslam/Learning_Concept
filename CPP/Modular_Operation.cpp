/* GREEN UNIVERSITY OF BANGLADESH
    Md DinIslam, Batch-221 (CSE)
*/
#include <bits/stdc++.h>
using namespace std;

// Debug..
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

template <ll Mod>
class modOpt {
    ll val;
public:
    modOpt (ll _val = 0) : val (_val % Mod) {}
    // modOpt (ll _val = 0) { // both are same...
    //     val = _val % Mod;
    // }

    operator ll() const {
        return val;
    }

    // (a ^ b) using binary exponential...
    modOpt binExp (ll b) const {
        modOpt ans = 1;
        modOpt a = val; // the base...

        while (b) {
            if (b & 1ll)
                ans = (ans * a);
            a *= a;
            b >>= 1;
        }

        return ans;
    }
    
    // if x = 5, it return (1/5)....
    modOpt inverse() const {
        static_assert(Mod >= 2);
        assert(val != 0);
        return binExp(Mod - 2);
    }

    // Operator but not assigning value in the result yet....
    modOpt operator+(const modOpt &other) {
        return (val + other.val) % Mod;
    }

    modOpt operator-(const modOpt &other) {
        return (val - other.val + Mod) % Mod;
    }

    modOpt operator*(const modOpt &other) {
        return (val * other.val) % Mod;
    }

    modOpt operator/(const modOpt &other) {
        // return (*this) * other.inverse();
        return val * other.inverse();
    }

    // Operator with assigning....
    modOpt operator+=(const modOpt &other) {
        return *this = *this + other;
    }

    modOpt operator-=(const modOpt &other) {
        return *this = *this - other;
    }

    modOpt operator*=(const modOpt &other) {
        return *this = *this * other;
    }

    modOpt operator/=(const modOpt &other) {
        return *this = *this / other;
    }

    bool operator==(const modOpt &other) {
        return val == other.val;
    }

    // long long with mod value operation....
    friend modOpt operator+(ll a, const modOpt &b) {
        return modOpt(a) + b;
    }

    friend modOpt operator-(ll a, const modOpt &b) {
        return modOpt(a) - b;
    }

    friend modOpt operator*(ll a, const modOpt &b) {
        return modOpt(a) * b;
    }

    friend modOpt operator/(ll a, const modOpt &b) {
        return modOpt(a) / b;
    }

    friend modOpt operator==(ll a, const modOpt &b) {
        return modOpt(a) == b;
    }

    // Input/Output operator...
    friend istream& operator>>(istream& input, modOpt& number) {
        return input >> number.val; // like cin >> a...
    }

    friend ostream& operator<<(ostream& output, modOpt& number) {
        return output << number.val; // like cin >> a...
    }
};

const int mod = 7; // can any prime like 1e9 + 9....

using mint = modOpt <mod>;

void Din() {
    int a, b;
    cin >> a >> b; // 10, 3.. can be any number...

    mint x = a, y = b; // x = mint(a), y = mint(b)....
    cout << x << " " << y << "\n"; // inital value of x % mod....
    cout << x.binExp(y) << '\n'; // like (a ^ b)....
    cout << x.inverse() << '\n'; // like (1/x)...
    cout << x.inverse() * y << '\n'; // like (1/x * y)....
    cout << x * y << "\n";
    cout << x / y << '\n';
    cout << ((x == y) ? "Equal" : "Not Equal") << '\n';
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
