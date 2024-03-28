#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 1000000

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> sum(MAX + 1);

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		sum[b] = a;
	}

	
	for (int i = 1; i <= MAX; i++)
	{
		sum[i] = sum[i - 1] + sum[i];
	}

	int res = sum[min(2 * k, MAX)];

	for (int i = 2 * k + 1; i <= MAX; i++)
	{
		res = max(res, sum[i] - sum[i - 2 * k - 1]);
	}

	cout << res;
	return 0;
}