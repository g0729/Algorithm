#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>seq;
vector<int>res;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			seq.push_back(a);
		}
		sort(seq.begin(), seq.end());
		res.resize(n);
		for (int i = 0; i < n; i++)
		{
			if (i % 2 == 0)
			{
				res[i / 2] = seq[i];
			}
			else
			{
				res[n - (i / 2) - 1] = seq[i];
			}
		}
		int ans = abs(res.front() - res.back());
		for (int i = 1; i < n; i++)
		{
			ans = max(ans, abs(res[i] - res[i - 1]));
		}
		cout << ans << endl;
		seq.clear();
		res.clear();
	}
}