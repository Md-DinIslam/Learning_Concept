#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int factorial[N];
int main()
{
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    int num;
    cout << "Enter Factorial Number: ";
    cin >> num;
    factorial[0] = 1;
    int index = 1, carry = 0;
    for (int i = 2; i <= num; i++)
    {
        for (int j = 0; j < index; j++)
        {
            int value = factorial[j] * i + carry;
            factorial[j] = value % 10;
            carry = value / 10;
        }
        while (carry != 0)
        {
            factorial[index] = carry % 10;
            carry /= 10;
            index++;
        }
    }
    long long sum = 0;
    cout << "Factorial: ";
    for (int i = index - 1; i >= 0; i--)
    {
        cout << factorial[i];
        sum += factorial[i];
    }
    cout << endl
         << "Sum: " << sum;
    return 0;
}