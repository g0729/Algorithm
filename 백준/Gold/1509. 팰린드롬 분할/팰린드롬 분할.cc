#include <bits/stdc++.h>
using namespace std;

bool isPalin[2500][2500];
int dp[2500];

int main()
{
	string s;

	cin>>s;

	for(int i = 0 ; i<s.length();i++)
	{
		for(int j=i;j<s.length();j++)
		{
			int left=i;
			int right=j;
			bool flag=true;
			while(left<=right)
			{
				if(s[left]!=s[right])
				{
					flag=false;
					break;
				}
				left++;
				right--;
			}
			if(flag)
			{
				isPalin[i][j]=true;
			}
		}
	}

	
	dp[0]=1;

	for (int i = 1; i < s.length(); i++)
	{
		if(isPalin[0][i])
		{
			dp[i]=1;
			continue;
		}
		int MIN=20000;
		for(int j=1;j<i;j++)
		{
			if(isPalin[j][i])
			{
				if(dp[j]==0)
				continue;
				else
				{
					MIN=min(MIN,dp[j-1]);
				}
			}
		}
		if(dp[i-1]!=0)
		{
			MIN=min(MIN,dp[i-1]);
		}
		dp[i]=MIN+1;	
	}
	
	cout<<dp[s.length()-1];
	
}