#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int dp[1516][3];

int main()
{
	dp[1][2] = 1;
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % MOD;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
		dp[i][2] = (dp[i - 1][1] + dp[i - 1][0]) % MOD;
	}
	cout << dp[n][0];

}