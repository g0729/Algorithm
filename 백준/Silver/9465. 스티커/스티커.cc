#include <bits/stdc++.h>
using namespace std;
int dp[100000][2];
int arr[100000][2];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i][0];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i][1];
		}
		dp[0][0] = arr[0][0];
		dp[0][1] = arr[0][1];
		dp[1][0] = dp[0][1] + arr[1][0];
		dp[1][1] = dp[0][0] + arr[1][1];
		for (int i = 2; i < n; i++)
		{
			dp[i][0] = max(dp[i - 1][1], dp[i - 2][1]) + arr[i][0];
			dp[i][1] = max(dp[i - 1][0], dp[i-2][0]) + arr[i][1];
		}
		int res = max(dp[n - 1][0], dp[n - 1][1]);
		cout << res<<"\n";
	}
}