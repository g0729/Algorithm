#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(const pair<int, int>&first, const pair<int, int> & second)
{
	return first.second < second.second;
}

int main()
{
	int t;
	int cnt = 0;
	cin >> t;
	vector<pair<int, int>>v;
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			v.push_back({ a,b });
		}
		sort(v.begin(), v.end());
		int large = v[0].second;
		for (int i = 1; i < n; i++)
		{
			if (v[i].second > large)
				cnt++;
			large = min(large, v[i].second);
		}

		cout << n - cnt << endl;
		v.clear();
	}
}