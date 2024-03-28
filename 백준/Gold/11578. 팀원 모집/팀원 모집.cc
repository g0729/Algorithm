#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

vector<int> v(10);
int n, m;
int res = 1e9;
void dfs(int now, int visit, int cnt)
{
	if (visit == (1 << n) - 1)
		res = min(res, cnt);
	if (now == m)
		return;
	dfs(now + 1, visit | v[now], cnt + 1);
	dfs(now + 1, visit, cnt);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;

		int temp = 0;
		for (int j = 0; j < a; j++)
		{
			int k;
			cin >> k;

			temp = temp | (1 << (k - 1));
		}
		v[i] = temp;
	}

	dfs(0, 0, 0);
	if (res == 1e9)
		cout << "-1";
	else
		cout << res;
	return 0;
}