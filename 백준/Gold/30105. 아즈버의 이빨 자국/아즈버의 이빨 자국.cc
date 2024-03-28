#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	set<int> dis;
	set<int> points;

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		points.insert(v[i]);
	}

	for (int i = 1; i < n; i++)
	{
		dis.insert(v[i]-v[0]);
	}

	vector<int> res;
	for (auto d : dis)
	{
		bool flag = true;

		for (auto p : points)
		{
			if (points.find(p - d) != points.end() || points.find(p + d) != points.end())
				continue;
			else
			{
				flag = false;
				break;
			}
		}
		if (flag)
			res.push_back(d);
	}

	sort(res.begin(), res.end());
	cout << res.size() << "\n";
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}

	return 0;
}