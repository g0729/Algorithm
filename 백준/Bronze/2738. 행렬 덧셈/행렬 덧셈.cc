#include <bits/stdc++.h>
using namespace std;

int MAP[100][100];
int main()
{
	int n, m;

	cin >> n>>m;

	for (int t = 0; t < 2; t++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int a;

				cin >> a;

				MAP[i][j] += a;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << MAP[i][j] << " ";
		}
		cout << "\n";
	}
}