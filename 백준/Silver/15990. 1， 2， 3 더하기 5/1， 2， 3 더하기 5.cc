#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000009
#define MAX 100001
#define lint long long
lint dp[MAX][4];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	dp[1][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;
	int t;
	cin >> t;
	for (int i = 4; i < MAX; i++)
	{
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % MOD;
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % MOD;
	}

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		lint res;
		res = (dp[n][1] + dp[n][2] + dp[n][3]) % MOD;
		cout << res << "\n";
	}
}