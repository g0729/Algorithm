#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
char MAP[MAX][MAX];
int fireMAP[MAX][MAX];
int visited[MAX][MAX];
int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
queue<pair<int, int>> fireq;
queue<pair<int, int>> q;
void firebfs()
{
	while (!fireq.empty())
	{
		int x = fireq.front().first;
		int y = fireq.front().second;
		fireq.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (MAP[nx][ny] == '#')
				continue;
			if (fireMAP[nx][ny] != 0)
				continue;
			fireq.push({nx, ny});
			fireMAP[nx][ny] = fireMAP[x][y] + 1;
		}
	}
}
int bfs()
{
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if(x==n-1||x==0||y==0||y==m-1)
		return visited[x][y];
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (MAP[nx][ny] == '#')
				continue;
			if (visited[nx][ny] != 0)
				continue;
			if (fireMAP[nx][ny] <= visited[x][y] + 1 && fireMAP[nx][ny] != 0)
				continue;
			q.push({nx, ny});
			visited[nx][ny] = visited[x][y] + 1;
		}
	}
	return -1;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> m >> n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> MAP[i][j];
				if (MAP[i][j] == '@')
				{
					q.push({i, j});
					visited[i][j] = 1;
				}
				else if (MAP[i][j] == '*')
				{
					fireq.push({i, j});
					fireMAP[i][j] = 1;
				}
			}
		}
		firebfs();
		int res = bfs();
		if (res == -1)
			cout << "IMPOSSIBLE\n";
		else
			cout << res << "\n";
			
		memset(fireMAP, 0, sizeof(fireMAP));
		memset(visited, 0, sizeof(visited));
		while (!q.empty())
			q.pop();
	}
}
