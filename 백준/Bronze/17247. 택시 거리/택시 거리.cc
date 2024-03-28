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

	int n, m;
	cin >> n >> m;

	pair<int, int> a = {0, 0};

	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int b;
			cin >> b;

			if (b == 1)
			{
				if (a.first == 0 && a.second == 0)
				{
					a.first = i;
					a.second = j;
				}
				else
				{
					res = abs(i - a.first) + abs(j - a.second);
				}
			}
		}
	}

	cout << res;
	return 0;
}