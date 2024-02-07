#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int store[N][26];
int main()
{
    int t;
    cin >> t;
    int n, q;
    cin >> n >> q;
    while (t--)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                store[i][j] = 0;
            }
        }
        string s;
        cin >> s;
        for (int i = 0; i < n; i++)
        {
            store[i][s[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                store[j][i] += store[j - 1][i];
            }
        }
        while (q--)
        {
            int f, l;
            cin >> f >> l;
            int oddco = 0;
            for (int i = 0; i < 26; i++)
            {
                int chcount = store[f-1][i] - store[l - 2][i];
                if (chcount % 2 != 0)
                {
                    oddco++;
                }
            }
            if (oddco > 1)
            {
                cout << "No" << endl;
            }
            else
            {
                cout << "Yes" << endl;
            }
        }
    }
    return 0;
}
 /*#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t; 
  cin>>t;
  while(t--)
  {
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    while(q--)
    {
      int f,l;
      cin>>f>>l;
      int lcount[26];
      for(int i=0;i<26;i++)
      {
        lcount[i]=0;
      }
      f--; l--;
      for(int i=f;i<=l;i++)
      {
        lcount[s[i]-'a']++;
      }
      int oddco=0;
      for(int i=0;i<26;i++)
      {
        if(lcount[i]%2 != 0)
        {
          oddco++;
        }
      }
      if(oddco>1)
      {
        cout<<"No"<<endl;
      }
      else
      {
        cout<<"Yes"<<endl;
      }
    }
  }
  return 0;
}*/