#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

int dp[50000][101];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    dp[0][0] = 0 ? 1 : v[0] % 2 == 0;

    for (int i = 1; i < n; i++)
    {
        if(v[i]%2==0)
            dp[i][0]=dp[i-1][0]+1;
        else
            dp[i][0]=0;
        for (int j = 1; j <= k; j++)
        {
            if(v[i]%2==0)
                dp[i][j]=dp[i-1][j]+1;
            else
            {
                dp[i][j]=dp[i-1][j-1];
            }
        }
    }

    int res=0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            res=max(res,dp[i][j]);
        }
        
    }
    
    
    cout<<res;  
    return 0;
}