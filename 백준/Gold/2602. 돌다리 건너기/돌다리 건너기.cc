#include <bits/stdc++.h>
using namespace std;
int dp[101][20][2];
int main()
{
	string duru,a,b;
	cin>>duru>>a>>b;
	int length=a.length();
	int dulength=duru.length();
	int res=0;
	for(int i = 1 ; i<=length;i++)
	{
		for(int j= 0 ; j<dulength;j++)
		{
			if(a[i-1]==duru[j])
			{
				if(j==0)
				{
					dp[i][j][0]=dp[i-1][j][0]+1;
				}
				else
				{
					dp[i][j][0]=dp[i-1][j-1][1]+dp[i-1][j][0];
				}
			}
			else
			{
				dp[i][j][0]=dp[i-1][j][0];
			}
		}
		for(int j= 0 ; j<dulength;j++)
		{
			if(b[i-1]==duru[j])
			{
				if(j==0)
				{
					dp[i][j][1]=dp[i-1][j][1]+1;
				}
				else
				{
					dp[i][j][1]=dp[i-1][j-1][0]+dp[i-1][j][1];
				}
			}
			else
			{
				dp[i][j][1]=dp[i-1][j][1];
			}
		}
	}
	
	res=dp[length][dulength-1][0]+dp[length][dulength-1][1];
	cout<<res;
}