#include<bits/stdc++.h>
using namespace std;
#define MAX 201
#define MOD 1000000000
#define lint long long
lint dp[MAX][MAX];
int n,m;

int main()
{
    cin>>n>>m;
    for(int i = 0 ; i<=n;i++)
    {
        dp[1][i]=1;
    }
    for(int i = 2; i<=m;i++)
    {
        for(int q = 0 ; q<=n;q++)
        {
            for(int j = 0 ; j<=q;j++)
            {
                dp[i][q]+=dp[i-1][j];
            }
            dp[i][q]%=MOD;
        }
    }
    cout<<dp[m][n];
}
