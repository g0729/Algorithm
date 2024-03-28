#include<bits/stdc++.h>
using namespace std;
#define lint unsigned long long
lint dp[62][62][62];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n=0;
    while(1)
    {
        cin>>n;
        if(n==0)
        return 0;

        dp[n][0][0]=1;

    for(int k =1;k<=2*n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j =0;j<n;j++)
            {
                dp[i][j][k]=dp[i+1][j-1][k-1]+dp[i][j+1][k-1];
            }
        }
    }
    cout<<dp[0][0][2*n]+1<<"\n";
    memset(dp,0,sizeof(dp));
    }
}