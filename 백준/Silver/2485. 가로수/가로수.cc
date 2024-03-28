#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

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
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	vector<int> intervals;

	for (int i = 1; i < v.size(); i++)
		intervals.push_back(v[i] - v[i - 1]);

	int resInterval = intervals[0];

	for (int i = 1; i < intervals.size(); i++)
		resInterval = gcd(resInterval, intervals[i]);

	int ans = 0;

	for (int i = 0; i < intervals.size(); i++)
		ans += intervals[i] / resInterval-1;

	cout << ans;
	return 0;
}