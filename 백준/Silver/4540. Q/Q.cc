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
		vector<string> v(n + 1);

		for (int i = 1; i <= n; i++)
		{
			cin >> v[i];
		}
		vector<string> res(n + 1);
		vector<bool> visited(n + 1);
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			visited[a] = true;
			res[b] = v[a];
		}

		for (int i = 1; i <= n; i++)
		{
			if (visited[i])
				continue;
			int idx = 1;
			while (!res[idx].empty() && idx <= n)
			{
				idx++;
			}
			res[idx] = v[i];
		}
		for (int i = 1; i <= n; i++)
		{
			cout << res[i] << " ";
		}

		cout << "\n";
	}
	return 0;
}