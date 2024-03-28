#include<bits/stdc++.h>
using namespace std;
#define MAX 4000
short dp[MAX][MAX];
int main()
{
	string a,b;
	short res=0;
	cin>>a>>b;
	for (int i = 0; i < b.length(); i++)
	{
		for (int q = 0; q < a.length(); q++)
		{
			if(a[q]==b[i])
			{
				if(q==0||i==0)
				{
					dp[i][q]=1;
				}
				else
				dp[i][q]=dp[i-1][q-1]+1;
				res=max(res,dp[i][q]);
			}
		}
		
	}
	cout<<res;
}