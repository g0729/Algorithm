#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<long long> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		long long a, b;
		cin >> a >> b;
		v.push_back(a - b);
	}
	sort(v.begin(), v.end());

	if (n % 2 == 1)
	{
		cout << "1";
	}
	else
	{
		cout << v[n / 2] - v[n / 2 - 1] + 1;
	}
}