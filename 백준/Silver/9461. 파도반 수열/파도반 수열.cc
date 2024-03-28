#include <bits/stdc++.h>
using namespace std;

long long dp[101];

int main()
{
	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		dp[0] = dp[1] = dp[2] = 1;
		dp[3] = dp[4] = 2;
		for (int i = 5; i <= n; i++)
			dp[i] = dp[i - 1] + dp[i - 5];
		cout << dp[n-1] << '\n';
	}
}