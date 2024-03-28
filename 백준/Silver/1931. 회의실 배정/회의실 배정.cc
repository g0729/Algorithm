	#include<iostream>
	#include<algorithm>
	#include<vector>
	using namespace std;


	bool cmp(const pair<long long, long long>& first, const pair<long long, long long>& second)
	{
		if (first.second == second.second)
		{
			return first.first < second.first;
		}
		else return first.second < second.second;
	}
	int main()
	{
		int n;
		cin >> n;
		vector<pair<long long, long long>>v;
		for (int i = 0; i < n; i++)
		{
			long long a, b;
			cin >> a >> b;
			v.push_back({ a,b });
		}
		sort(v.begin(), v.end(), cmp);
		int cnt = 1;
		long long end = v[0].second;
		for(int i = 1 ; i < n; i++)
		{
			if (v[i].first < end)
				continue;
			end = v[i].second;
			cnt++;
		}
		cout << cnt;
	}