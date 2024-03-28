#include <bits/stdc++.h>
using namespace std;

int dp[10001][1000];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> v(k);
	for (int i = 0; i < k; i++)
	{
		cin >> v[i].first >> v[i].second;
	}
	if(k==1)
	{
		if(v[0].second<=n)
		cout<<v[0].first;
		else
		cout<<"0";
		return 0;
	}
	int ans=0;
	dp[v[0].second][0] = v[0].first;
	for (int i = 1; i < k; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (j - v[i].second < 0)
			{
				dp[j][i] = dp[j][i - 1];
			}
			else
			{
				dp[j][i] = max(dp[j][i - 1], dp[j - v[i].second][i - 1] + v[i].first);
			}
			ans=max(dp[j][i],ans);
		}
	}
	cout << ans;
}