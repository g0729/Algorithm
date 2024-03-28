#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
int dp[MAX][MAX];
int MAP[MAX][MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++)
		{
			MAP[i][j] = s[j - 1] - '0';
			if (MAP[i][j] == 1)
				dp[i][j] = 1;
		}
	}
	int res = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (dp[i][j] == 1)
			{
				int temp = min(dp[i - 1][j], dp[i][j - 1]);
				temp = min(temp, dp[i - 1][j - 1]);
				dp[i][j] = temp + 1;
				res = max(res, dp[i][j]);
			}
		}
	}
	cout << res * res;
}