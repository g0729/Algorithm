#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cout.precision(6);
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	int x;
	vector<int> res;
	cin >> x;

	for (int i = 0; i < v.size(); i++)
	{
		if (gcd(v[i], x) == 1)
			res.push_back(v[i]);
	}
	long long sum = 0;
	for (int i = 0; i < res.size(); i++)
	{
		sum += res[i];
	}

	double ans = (double)sum / res.size();
	cout << ans;
}