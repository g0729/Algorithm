#include <bits/stdc++.h>
using namespace std;
char MAP[200][200];
char CMAP[200][200];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m, t;
void reset()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			MAP[i][j] = CMAP[i][j];
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> t;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> MAP[i][j];
		}
	}
	if (t == 1)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << MAP[i][j];
			}
			cout << "\n";
		}
		return 0;
	}
	
	for (int w = 2; w <= t; w++)
	{
		if (w % 2 == 0)
		{
			memset(CMAP, 'O', sizeof(CMAP));
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (MAP[i][j] == 'O')
					{
						CMAP[i][j] = '.';
						for (int k = 0; k < 4; k++)
						{
							int nx = i + dx[k];
							int ny = j + dy[k];
							if (nx < 0 || nx >= n || ny < 0 || ny >= m)
								continue;
							CMAP[nx][ny] = '.';
						}
					}
				}
			}
			reset();
		}
	}
	reset();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << MAP[i][j];
		}
		cout << "\n";
	}
}