#include <bits/stdc++.h>
using namespace std;
int n, m;
long long dp[100][10001];

int main()
{
    cin >> n >> m;
    vector<pair<long long, int>> v(n);
    int maxval = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].second;
        maxval += v[i].second;
    }
    dp[0][v[0].second] = v[0].first;
    for (int i = 1; i < n; i++)
    {
      for (int q = 0; q <= maxval; q++)
      {
          if(q-v[i].second<0)
          {
              dp[i][q]=dp[i-1][q];
          }
          else
          {
              dp[i][q]=max(dp[i-1][q-v[i].second]+v[i].first,dp[i-1][q]);
          }
      }
      
    }
    for (int i = 0; i <= maxval; i++)
    {
        if(dp[n-1][i]>=m)
        {
            cout<<i;
            return 0;
        }
    }
}