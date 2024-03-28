#include <bits/stdc++.h>
using namespace std;
#define MAX 50001
int sum[MAX];
int dp[MAX][4];
vector<int> v;
int n, k;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		sum[i] = sum[i - 1] + a;
	}
	cin >> k;

	for (int i = 1; i <= 3; i++)
	{
		for (int j = i*k; j <=n; j++)
		{
			int temp=sum[j]-sum[j-k];
			dp[j][i]=max(dp[j-1][i],dp[j-k][i-1]+temp);
		}
		
	}
	

	cout << dp[n][3];
}