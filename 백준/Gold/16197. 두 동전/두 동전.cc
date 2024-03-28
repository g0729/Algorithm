#include <bits/stdc++.h>
using namespace std;
#define MAX 22
int n, m;
int res = 1e5;
char MAP[MAX][MAX];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
void dfs(int x1, int y1, int x2, int y2, int depth)
{

	if (x1 == x2 && y1 == y2)
		return;
	if (depth > 10)
	{
		res = min(res, depth);
		return;
	}
	if (x1 == 0 || x1 == n + 1 || y1 == 0 || y1 == m + 1)
	{
		if (x2 == 0 || x2 == n + 1 || y2 == 0 || y2 == m + 1)
		{
			return;
		}
		else
		{
			res = min(res, depth);
			return;
		}
	}
	else
	{
		if (x2 == 0 || x2 == n + 1 || y2 == 0 || y2 == m + 1)
		{
			res = min(res, depth);
			return;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		int nx1 = x1 + dx[i];
		int ny1 = y1 + dy[i];
		int nx2 = x2 + dx[i];
		int ny2 = y2 + dy[i];
		if (MAP[nx1][ny1] == '#')
		{
			if (MAP[nx2][ny2] == '#')
			{
				continue;
			}
			else
			{
				dfs(x1, y1, nx2, ny2, depth + 1);
			}
		}
		else
		{
			if (MAP[nx2][ny2] == '#')
			{
				dfs(nx1, ny1, x2, y2, depth + 1);
			}
			else
			{
				dfs(nx1, ny1, nx2, ny2, depth + 1);
			}
		}
	}
}

int main()
{
	pair<int, int> coin1;
	pair<int, int> coin2;
	cin >> n >> m;
	bool check = false;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> MAP[i][j];
			if (MAP[i][j] == 'o')
			{
				if (!check)
				{
					coin1.first = i;
					coin1.second = j;
					check = true;
				}
				else
				{
					coin2.first = i;
					coin2.second = j;
				}
			}
		}
	}

	dfs(coin1.first, coin1.second, coin2.first, coin2.second, 0);

	if (res == 1e5 || res > 10)
		cout << "-1";
	else
		cout << res;
}