#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;

	int MAP[50][50];

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &MAP[i][j]);
		}
	}

	int res = 1;

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < m - 1; j++)
		{
			for (int dis = 1; i + dis < n && j + dis < m; dis++)
			{
				if(MAP[i][j]==MAP[i][j+dis]&&MAP[i][j+dis]==MAP[i+dis][j+dis]&&MAP[i+dis][j+dis]==MAP[i+dis][j])
				res=max(res,(dis+1)*(dis+1));
			}
		}
	}

	cout << res;
}
