#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, long long> a, pair<int, long long> b)
{
	if (a.second == b.second)
	{
		return a.first > b.first;
	}
	return a.second < b.second;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	long long m;
	cin >> n >> m;
	vector<pair<int, long long>> v;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({a, b});
	}

	sort(v.begin(), v.end(), cmp);
	bool check = false;
	int temp;
	long long sum = 0;
	long long	 res = 0;
	for (int i = 0; i < n; i++)
	{
		sum += v[i].first;
		if (sum >= m)
		{
			if (!check)
			{
				temp = v[i].second;
				for (int j = i;; j--)
				{
					if (v[j].second != temp)
						break;
					res += v[j].second;
				}
				check=true;
				continue;
			}
			if(v[i].second==temp)
			continue;
			res=min(v[i].second,res);
		}
	}
	if(sum<m)
	{
		cout<<"-1";
		return 0;
	}
	cout<<res;
}