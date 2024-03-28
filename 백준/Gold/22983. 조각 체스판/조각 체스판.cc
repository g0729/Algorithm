#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

char MAP[3001][3001];
lint dp[3001][3001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	lint res = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> MAP[i][j];
			dp[i][j] = 1;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (MAP[i][j] == MAP[i - 1][j - 1] && MAP[i][j] != MAP[i - 1][j] && MAP[i][j] != MAP[i][j - 1])
			{
				lint temp = min(dp[i - 1][j], dp[i][j - 1]);
				temp = min(dp[i - 1][j - 1], temp);
				dp[i][j] = temp + 1;
			}
			res += dp[i][j];
		}
	}

	cout << res;
	return 0;
}