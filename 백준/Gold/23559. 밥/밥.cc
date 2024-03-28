#include <bits/stdc++.h>
using namespace std;
#define lint long long

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	lint n;
	lint ans, x;
	ans = 0;

	cin >> n >> x;

	x -= n * 1000;

	x /= 4000;

	vector<lint> v;

	for (lint i = 0; i < n; i++)
	{
		lint a, b;

		cin >> a >> b;
		ans += b;
		if (a - b > 0)
			v.push_back(a - b);
	}

	sort(v.begin(), v.end(), greater<lint>());

	for (lint i = 0; i < x && i < v.size(); i++)
	{
		ans += v[i];
	}

	cout << ans;
}