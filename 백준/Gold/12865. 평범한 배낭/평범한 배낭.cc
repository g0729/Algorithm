#include<iostream>
#include<vector>
using namespace std;
int dp[101][100001];
int main()
{

	int n, k;
	cin >> n >> k;
	vector<pair<int, int>>v;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			if (j - v[i].first < 0)
			{
				dp[i + 1][j] = dp[i][j];
			}
			else
			{
				dp[i + 1][j] = max(dp[i][j], dp[i][j - v[i].first] + v[i].second);
			}
		}
	}


	cout << dp[n][k];
	
}