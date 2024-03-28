#include<bits/stdc++.h>
using namespace std;

int dp[501][501];
int sum[501];
int file[501];
int main()
{
	int  t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		for (int q = 1; q <= n; q++)
		{
			cin >> file[q];
			sum[q] = sum[q - 1] + file[q];
		}
		for (int d = 1; d <= n; d++)
		{
			for (int dx = 1; dx + d <= n; dx++)
			{
				int dy = dx + d;
				dp[dx][dy] = 10000000000;
				for (int middle = dx; middle < dy; middle++)
				{
					dp[dx][dy] = min(dp[dx][dy], dp[dx][middle] + dp[middle + 1][dy] + sum[dy] - sum[dx - 1]);
				}
			}
		}
		cout << dp[1][n] << endl;
	}
}