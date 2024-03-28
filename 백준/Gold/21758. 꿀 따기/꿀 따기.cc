#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long
#define MOD 1000000007

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> v(n + 1);
	vector<int> sum(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
		sum[i] = sum[i - 1] + v[i];
	}

	int res = 0;

	for (int i = 2; i < n; i++)
	{
		int temp = sum[i] - v[1] + sum[n - 1] - sum[i - 1];
		res = max(res, temp);
	}

	for (int i = 2; i < n; i++)
	{
		int temp = sum[n] - v[1] - v[i] + sum[n] - sum[i];
		res = max(res, temp);
	}

	for (int i = 2; i < n; i++)
	{
		int temp = sum[n] - v[n] - v[i] + sum[i] - v[i];
		res = max(res, temp);
	}

	cout << res;
	return 0;
}