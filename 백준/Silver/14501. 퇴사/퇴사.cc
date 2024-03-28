#include <bits/stdc++.h>
using namespace std;

int dp[16];

int main()
{
	int n;

	cin >> n;

	vector<pair<int, int>> v(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> v[i].first >> v[i].second;
	}

	dp[1] = v[1].second;

	if(v[1].first>n)
	{
		dp[1]=0;
	}
	for (int i = 2; i <= n; i++)
	{
		int MAX = 0;
		for (int j = 1; j < i; j++)
		{
			if(i>=j+v[j].first)
			{
				MAX=max(MAX,dp[j]);
			}
		}
		if(i+v[i].first-1>n)
		{
			dp[i]=MAX;
		}
		else
		{
			dp[i]=MAX+v[i].second;
		}
	}

	int res=0;
	for (int i = 1; i <= n; i++)
	{
		res=max(res,dp[i]);
	}
	
	
	cout<<res;
}