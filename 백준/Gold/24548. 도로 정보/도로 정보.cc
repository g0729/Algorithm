#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long
#define MAX 100001

lint dp[MAX][3][3][3][3];
map<char, int> ma = {{'T', 0}, {'G', 1}, {'F', 2}, {'P', 3}};
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	string s;
	cin >> n >> s;

	int res=0;

	for (int i = 1; i <= n; i++)
	{
		int now = ma[s[i - 1]];

		if (now == 0)
			dp[i][1][0][0][0]++;
		else if (now == 1)
			dp[i][0][1][0][0]++;
		else if (now == 2)
			dp[i][0][0][1][0]++;
		else
			dp[i][0][0][0][1]++;

		if (i == 1)
			continue;

		for (int j = 0; j < 3; j++)
		{
			for (int p = 0; p < 3; p++)
			{
				for (int q = 0; q < 3; q++)
				{
					for (int k = 0; k < 3; k++)
					{
						if (now == 0)
							dp[i][(j + 1) % 3][p][q][k] += dp[i - 1][j][p][q][k];
						else if (now == 1)
							dp[i][j][(p + 1) % 3][q][k] += dp[i - 1][j][p][q][k];
						else if (now == 2)
							dp[i][j][p][(q + 1) % 3][k] += dp[i - 1][j][p][q][k];
						else
							dp[i][j][p][q][(k + 1) % 3] += dp[i - 1][j][p][q][k];
					}
				}
			}
		}
		res+=dp[i][0][0][0][0];
	}

	cout<<res;
	return 0;
}