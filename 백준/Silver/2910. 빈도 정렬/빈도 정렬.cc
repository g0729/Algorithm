#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

map<int, int> order;
bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
	{
		return order[a.first] < order[b.first];
	}
	else
		return a.second > b.second;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, c;
	cin >> n >> c;
	map<int, int> ma;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		ma[a]++;
		if (order[a] == 0)
			order[a] = i + 1;
	}

	vector<pair<int, int>> v;

	for (auto it : ma)
	{
		v.push_back({it.first, it.second});
	}

	sort(v.begin(), v.end(),cmp);

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].second; j++)
		{
			cout << v[i].first << " ";
		}
	}

	return 0;
}