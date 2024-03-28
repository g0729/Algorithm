#include<bits/stdc++.h>
using namespace std;
#define MAX 1001
#define INF 99999
int dp[MAX][3][3];
int arr[MAX][3];
int n;
int res=INF;
int main()
{
    cin>>n;
    for(int i = 1 ; i<=n;i++)
    {
        for(int q= 0 ; q<3;q++)
        {
            cin>>arr[i][q];
        }
    }
    dp[1][0][0]=arr[1][0];
    dp[1][1][1]=arr[1][1];
    dp[1][2][2]=arr[1][2];
    for (int i = 0; i < 3; i++)
    {
        for(int q =0; q<3;q++)
        {
            if(q==i)
            dp[2][q][i]=INF;
            else
            dp[2][q][i]=arr[1][i]+arr[2][q];
        }
        for(int q =3; q<=n;q++)
        {
            dp[q][0][i]=min(dp[q-1][1][i],dp[q-1][2][i])+arr[q][0];
            dp[q][1][i]=min(dp[q-1][0][i],dp[q-1][2][i])+arr[q][1];
            dp[q][2][i]=min(dp[q-1][1][i],dp[q-1][0][i])+arr[q][2];
        }
        for(int q= 0 ;q<3;q++)
        {
            if(q==i)
            continue;
            res=min(res,dp[n][q][i]);
        }
    }
    cout<<res;
}