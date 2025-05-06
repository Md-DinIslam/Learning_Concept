#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    int j, target;
    for (int i = 1; i < n; i++)
    {
        target = ar[i];
        j = i - 1;
        for (j; j >= 0 && ar[j] > target; j--)
        {
            ar[j + 1] = ar[j];
        }
        ar[j + 1] = target;
        // while (j >= 0 && ar[j] > target)
        // {
        //     ar[j + 1] = ar[j];
        //     j--;
        // }
        // ar[j + 1] = target;
    }
    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }
    return 0;
}