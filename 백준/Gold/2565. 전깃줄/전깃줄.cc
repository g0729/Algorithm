#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

vector < pair<int, int>> v;

int main()
{
	int n;
	cin >> n;
	int* dp = new int[n];
	for (int i = 0;i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int q = 0; q < i; q++)
		{
			if (v[i].second > v[q].second)
			{
				dp[i] = max(dp[i], dp[q] + 1);
			}
		}	
		ans = max(dp[i], ans);
	}

	cout << n-ans;
}