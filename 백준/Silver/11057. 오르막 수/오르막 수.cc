#include<bits/stdc++.h>
using namespace std;
#define MOD 10007
int dp[1001][10];

int main()
{
	for (int i = 0; i < 10; i++)
	{
		dp[1][i]=1;
	}
	int n;
	cin>>n;
	for (int i = 2; i <= n; i++)
	{
		for (int q = 0; q < 10; q++)
		{
			for (int j = 0; j <= q; j++)
			{
				dp[i][q]+=dp[i-1][j];
			}
			dp[i][q]%=MOD;
		}
	}
	int res=0;
	for (int i = 0; i < 10; i++)
	{
		res+=dp[n][i];
	}
	cout<<res%MOD;
	
}