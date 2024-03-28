#include <bits/stdc++.h>
using namespace std;
#define lint long long
lint dp[300];
lint Left[300];
lint Right[300];
int main()
{
	vector<pair<lint, lint>> v;

	lint n;

	cin >> n;

	for (lint i = 0; i < n; i++)
	{
		lint a, b;
		cin >> a >> b;

		v.push_back({a, b});
	}
	sort(v.begin(), v.end());

	for (lint i = 1; i < n; i++)
	{
		lint temp = i;
		for (lint j = i - 1; j >= 0; j--)
		{
			if (v[i].first - v[i].second <= v[j].first)
			{
				temp = min(temp, Left[j]);
			}
			else
				break;
		}
		Left[i]=temp;
	}
	Right[n - 1] = n - 1;
	for (lint i = n - 2; i >= 0; i--)
	{
		lint temp=i;
		for (lint j = i + 1; j < n; j++)
		{
			if (v[i].first + v[i].second >= v[j].first)
			{
				temp=max(temp,Right[j]);
			}
			else
				break;
		}
		Right[i]=temp;
	}

	fill(dp, dp + n, 400);
	dp[0] = 1;

	for (lint i = 1; i < n; i++)
	{
		for (lint j = 0; j < i; j++)
		{
			if (Right[j] >= i)
			{
				if (j == 0)
					dp[i] = 1;
				else
				{
					dp[i] = min(dp[i], dp[j - 1] + 1);
				}
			}
		}

		if (Left[i] == 0)
		{
			dp[i] = 1;
		}
		else
		{
			dp[i] = min(dp[i], dp[Left[i] - 1] + 1);
		}
	}

	cout << dp[n - 1];
}