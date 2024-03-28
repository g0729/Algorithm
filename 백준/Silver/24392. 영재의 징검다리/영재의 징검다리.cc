#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
#define MOD 1000000007
#define lint unsigned long long
lint dp[MAX][MAX];
int arr[MAX][MAX];
int n,m;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i = 0 ;i<n;i++)
    {
        for(int q = 0 ; q<m;q++)
        {
            cin>>arr[i][q];
        }
    }
    for(int  i= 0 ; i<m;i++)
    {
        dp[0][i]=arr[0][i];
    }
     for(int i = 1 ;i<n;i++)
    {
        for(int q = 0 ; q<m;q++)
        {
           if(arr[i][q]==1)
           {
               if(q==0)
               {
                   dp[i][q]=(dp[i-1][q]+dp[i-1][q+1])%MOD;
               }
               else if(q==m-1)
               {
                   dp[i][q]=(dp[i-1][m-1]+dp[i-1][m-2])%MOD;
               }
               else
               {
                   dp[i][q]=(dp[i-1][q-1]+dp[i-1][q]+dp[i-1][q+1])%MOD;
               }
               
           }
        }
    }
    lint res=0;
    for(int i = 0 ; i<m;i++)
    {
        res= (res+dp[n-1][i])%MOD;
    }
    cout<<res;
}