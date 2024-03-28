#include <bits/stdc++.h>
using namespace std;
int dp[100001][2];
int cal(int n, string s)
{
	if (s[0] == '*')
		return n * (s[1] - '0');
	if (s[0] == '/')
		return n / (s[1] - '0');
	if (s[0] == '+')
		return n + (s[1] - '0');
	if (s[0] == '-')
		return n - (s[1] - '0');
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	dp[0][0] = 1;
	dp[0][1] = 1;
	bool check = false;
	for (int i = 1; i <= n; i++)
	{
		string a, b;
		cin >> a >> b;
		int temp1 = cal(dp[i - 1][0], a);
		int temp2 = cal(dp[i - 1][0], b);
		dp[i][0] = max(temp1, temp2);
		if (check)
			dp[i][0] = 0;
		temp1 = cal(dp[i - 1][1], a);
		temp2 = cal(dp[i - 1][1], b);
		temp1 = max(temp1, temp2);
		dp[i][1] = max(temp1, dp[i - 1][0]);
		if (dp[i][0] <= 0)
		{
			check = true;
			dp[i][0] = 0;
		}
		if (dp[i][1] <= 0)
		{
			cout << "ddong game";
			return 0;
		}
	}
	int res = max(dp[n][1], dp[n][0]);
	cout << res;
}