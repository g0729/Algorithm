	#include <bits/stdc++.h>
	using namespace std;
	#define MAX 1024
	int MAP[MAX][MAX];
	int n;
	int f(int x, int y)
	{
		vector<int> a;
		for (int i = x; i < x + 2; i++)
		{
			for (int q = y; q < y + 2; q++)
			{
				a.push_back(MAP[i][q]);
			}
		}
		sort(a.begin(), a.end());
		return a[2];
	}
	int main()
	{
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			for (int q = 0; q < n; q++)
			{
				cin >> MAP[i][q];
			}
		}
		while (n > 1)
		{
			for (int i = 0; i < n; i += 2)
			{
				for (int q = 0; q < n; q += 2)
				{
					MAP[i/2][q/2] = f(i, q);
				}
			}
			n=n/2;
		}
		cout<<MAP[0][0];
	}