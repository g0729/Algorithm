#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

int comb(int n, int r)
{
	if (n == r || r == 0)
		return 1;
	return comb(n - 1, r - 1) + comb(n - 1, r);
}
int fact(int n)
{
	int res = 1;

	for (int i = 1; i <= n; i++)
	{
		res *= i;
	}
	return res;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	int x, y;
	cin >> x >> y;
	int knowPos;
	knowPos = 0;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a != 0)
			knowPos++;
	}

	int temp = comb(9 - m, n - m) * fact(n - knowPos);

	int res = temp * x;

	if (temp % 3 == 0)
		res += (temp / 3 - 1) * y;
	else
		res += (temp / 3) * y;
	cout << res;
	return 0;
}