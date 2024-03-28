#include <bits/stdc++.h>
using namespace std;
#define MAX 987654321

int dp[1000001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,a,b;

    
    cin>>n>>a>>b;


    for (int i = 0; i < n; i++)
    {
        dp[i]=n+1;
    }
    
    for (int i = n-1; i >= 0; i--)
    {
        dp[i]=dp[i+1]+1;
        if(i+a+1<=n)
        {
            dp[i]=min(dp[i+a+1]+1,dp[i]);
        }
        if(i+b+1<=n)
        {
            dp[i]=min(dp[i+b+1]+1,dp[i]);
        }
    }
    
    cout<<dp[0];
    return 0;
}
