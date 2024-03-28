#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.second - a.first > b.second - b.first;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, x, y;
	cin >> n >> x >> y;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({a, b});
	}

	sort(v.begin(), v.end(), cmp);

	ll res = 0;
	for (int i = 0; i < n; i++)
	{
		if (i < x)
			res = res + v[i].first;
		else
			res = res + v[i].second;
	}

	cout << res;

	return 0;
}