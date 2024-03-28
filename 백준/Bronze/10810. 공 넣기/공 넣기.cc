	#include <bits/stdc++.h>
	using namespace std;
	#define INF 987654321
	#define lint long long

	int main()
	{
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		int n, m;

		cin >> n >> m;
		vector<int> v(n + 1);

		for (int i = 0; i < m; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;

			for (int j = a; j <= b; j++)
			{
				v[j] = c;
			}
		}

		for (int i = 1; i <= n; i++)
		{
			cout << v[i] << " ";
		}
		return 0;
	}