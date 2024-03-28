#include <bits/stdc++.h>
using namespace std;

int dp[100001];
int main()
{
    int n;
    cin >> n;

    dp[2] = dp[5] = 1;
    dp[4] = 2;
    for (int i = 6; i <= n; i++)
    {
        if (dp[i - 2] == 0 && dp[i - 5] == 0)
            dp[i] = 0;
        else if(dp[i-2]==0||dp[i-5]==0)
        {
            dp[i]=max(dp[i-2],dp[i-5])+1;
        }
        else
        {
            dp[i]=min(dp[i-2],dp[i-5])+1;
        }
    }
    if(dp[n]==0)
    cout<<"-1";
    else
    cout<<dp[n];
}