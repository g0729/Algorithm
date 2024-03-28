#include <bits/stdc++.h>
using namespace std;
long long dp[100][21];
int arr[100];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	dp[0][arr[0]] = 1;

	for (int i = 1; i < n - 1; i++)
	{
		for (int q = 0; q <= 20; q++)
		{
			if (dp[i - 1][q])
			{
				if (q - arr[i] >= 0)
				{
					dp[i][q - arr[i]] += dp[i - 1][q];
				}
				if (q + arr[i] <= 20)
				{
					dp[i][q + arr[i]] += dp[i - 1][q];
				}
			}
		}
	}
	cout<<dp[n-2][arr[n-1]];
}