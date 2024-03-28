#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> v;
	vector<int> dp;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int j = 1; j <= t; j++)
	{
		int n, k;
		cin >> n >> k;
		while (n--)
		{
			int a;
			cin >> a;
			v.push_back(a);
		}
		dp.push_back(v[0]);
		for (int i = 1; i < v.size(); i++)
		{
			if (dp.back() < v[i])
			{
				dp.push_back(v[i]);
				continue;
			}
			auto temp = lower_bound(dp.begin(), dp.end(), v[i]);
			*temp = v[i];
		}
		cout << "Case #" << j << "\n";
		if (dp.size() < k)
		{
			cout << "0\n";
		}
		else
		{
			cout << "1\n";
		}
		dp.clear();
		v.clear();
	}
}