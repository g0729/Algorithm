#include <bits/stdc++.h>
using namespace std;
int dp[100000][2];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<int> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	int res = v[0];
	dp[0][0] = v[0];
	
	for (int i = 1; i < n; i++)
	{
		dp[i][0]=max(v[i],dp[i-1][0]+v[i]);
		dp[i][1]=max(dp[i-1][0],dp[i-1][1]+v[i]);
		res=max(res,dp[i][0]);
		res=max(res,dp[i][1]);
	}
	
	cout << res;
}