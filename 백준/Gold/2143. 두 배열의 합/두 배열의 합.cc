	#include <bits/stdc++.h>
	using namespace std;
	int aarr[1000];
	int barr[1000];
	vector<int> asum;
	vector<int> bsum;
	int main()
	{
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		int t, n, m;
		cin >> t >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> aarr[i];
		}
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> barr[i];
		}

		for (int i = 0; i < n; i++)
		{
			int sum = 0;
			for (int q = i; q < n; q++)
			{
				sum += aarr[q];
				asum.push_back(sum);
			}
		}
		for (int i = 0; i < m; i++)
		{
			int sum = 0;
			for (int q = i; q < m; q++)
			{
				sum += barr[q];
				bsum.push_back(sum);
			}
		}
		sort(bsum.begin(),bsum.end());
		long long res=0;
		for (int i = 0; i < asum.size(); i++)
		{
			auto start=lower_bound(bsum.begin(),bsum.end(),t-asum[i]);
			auto end=upper_bound(bsum.begin(),bsum.end(),t-asum[i]);
			res+=end-start;
		}
		cout<<res;
	}