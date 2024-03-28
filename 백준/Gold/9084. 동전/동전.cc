#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		vector<int> v;
		int n;
		cin >> n;
		int dp[10001];
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			v.push_back(a);
		}
		dp[0]=1;
		sort(v.begin(),v.end());
		int m;
		cin >> m;
		for (int i = 0; i < v.size(); i++)
		{
			for (int j = v[i]; j <= m; j++)
			{
				dp[j]+=dp[j-v[i]];
			}
			
		}
		
		cout<<dp[m]<<endl;
	}
}