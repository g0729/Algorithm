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
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		vector<int> b(m);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < m; i++)
		{
			cin >> b[i];
		}

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		int res = 0;
		for (int i = 0; i < n; i++)
		{
			int start = 0;
			int end = m;

			while (start + 1 < end)
			{
				int mid = (start + end) / 2;

				if (a[i] > b[mid])
					start = mid;
				else
					end = mid;
			}
			res += start;
			if (a[i] > b[start])
				res++;
		}
		cout<<res<<"\n";
	}
	return 0;
}