#include<bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int dp[101][2][101]={0,};
        dp[1][0][0]=dp[1][1][0]=1;

        for(int i =2 ; i<=n;i++)
        {
            dp[i][0][0]=dp[i-1][0][0]+dp[i-1][1][0];
            dp[i][1][0]=dp[i-1][0][0];
            for (int j = 1; j <= k; j++)
            {
                dp[i][0][j]=dp[i-1][0][j]+dp[i-1][1][j];
                dp[i][1][j]=dp[i-1][0][j]+dp[i-1][1][j-1];
            }
        }
        cout<<dp[n][0][k]+dp[n][1][k]<<"\n";
    }
return 0;
}   