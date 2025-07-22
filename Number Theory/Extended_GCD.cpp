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

int exGCD(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a; // tupple of gcd, x and y
    }
    int x2, y2;
    int curr_gcd = exGCD(b, a % b, x2, y2);
    x = y2;
    y = x2 - y2 * (a / b);
    return curr_gcd;
}

void Din() {
    int a, b, c;
    cin >> a >> b >> c;

    int x = 1, y = 1;
    int gcd = exGCD(abs(a), abs(b), x, y);

    // for checking a.x + b.y = gcd(a, b), finding x and y...
    // cout << gcd << " " << x << " " << y << "\n";


    // for checking a.x + b.y = c, finding x and y....
    if (c % gcd != 0) {
        cout << "No\n";
    }
    else {
        x *= (c / gcd);
        y *= (c / gcd);

        if (a < 0) x *= -1;
        if (b < 0) y *= -1;
        cout << "Yes\n";
        cout << gcd << " " << x << " " << y << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case " << i << ": ";
        Din();
    }
    return 0;
}
