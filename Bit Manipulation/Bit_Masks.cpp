#include <bits/stdc++.h>
using namespace std;
void PrintBinary(int nums){
    for(int i = 8;i>=0;--i){
        cout<<((nums >> i) & 1);
    }
    cout<<'\n';
}
int main()
{
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    int n;
    cin>>n;
    vector<int> masks(n,0);
    for(int i = 0;i < n;++i){
        int num_workers;
        cin>> num_workers;
        int mask = 0;
        for(int j = 0;j<num_workers; ++j){
            int day;
            cin>> day;
            mask = (mask | (1 << day));
        }
        masks[i] = mask;
    }
    // for(auto &i: masks){
    //     cout<<i<<endl;
    //     PrintBinary(i);
    // }
    int max_days = 0;
    for(int i = 0;i < n;++i){
        for(int j = i + 1;j < n;j++){
            int intSec =(masks[i] & masks[j]);
            int comDays =  __builtin_popcount(intSec);
            max_days = max(max_days,comDays);
            cout<<i<<" "<<j<<" "<<comDays<<endl;
        }
    }
    cout<<max_days<<endl;
    cout<< __builtin_clz(0)<<endl;

    return 0;
}