#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int dp[N];
vector<int> v(N);
int LIS(int indx){
    if(dp[indx] != -1) return dp[indx];
    int ans = 1;
    for(int i = 0;i < indx; ++i){
        if(v[indx] > v[i]){
            ans = max(ans, LIS(i) + 1);
        }
    }
    return dp[indx] = ans;
}
int main()
{
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    memset(dp, -1, sizeof(dp));
    int n;
    cin>>n;
    for(int i = 0; i < n; ++i){
        cin>>v[i];
    }
    int ans = 0;
    for(int i = 0;i < n; ++i){
        ans = max(ans, LIS(i));
    }
    cout<<ans<<endl;
    return 0;
}