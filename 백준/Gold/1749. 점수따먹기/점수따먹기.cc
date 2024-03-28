#include <bits/stdc++.h>
using namespace std;
long long sum[201][201];
int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int q = 1; q <= m; q++)
		{
			int a;
			cin >> a;
			sum[i][q] = sum[i - 1][q] + sum[i][q - 1] - sum[i - 1][q - 1] + a;
		}
	}
	long long res = -1e10;
	for (int x1 = 1; x1 <= n; x1++)
	{
		for (int y1 = 1; y1 <= m; y1++)
		{
			for (int x2 = x1; x2 <= n; x2++)
			{
				for (int y2 = y1; y2 <= m; y2++)
				{
					long long temp = sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
					if (temp > res)
						res = temp;
				}
			}
		}
	}
	cout<<res;
}