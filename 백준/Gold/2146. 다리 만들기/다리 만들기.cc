#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int MAP[MAX][MAX];
bool visited[MAX][MAX];
int n;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
void landbfs(int x, int y, int num)
{
	MAP[x][y]=num;
	queue<pair<int, int>> q;
	q.push({x, y});
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;
			if (MAP[nx][ny] != 1)
				continue;
			MAP[nx][ny] = num;
			q.push({nx, ny});
		}
	}
}
int bfs(int num)
{
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (MAP[i][j] == num)
			{
				q.push({i, j});
				visited[i][j] = true;
			}
		}
	}
	int res = 0;
	while (!q.empty())
	{
		int temp = q.size();
		for(int j = 0 ; j<temp;j++)
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n)
					continue;
				if (visited[nx][ny])
					continue;
				if (MAP[nx][ny] != num && MAP[nx][ny] != 0)
				{
					return res;
				}
				q.push({nx, ny});
				visited[nx][ny] = true;
			}
		}
		res++;
	}
	return 1000000000;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{	
			cin >> MAP[i][j];
		}
	}
	int cnt = 2;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (MAP[i][j] == 1)
			{
				landbfs(i, j, cnt);
				cnt++;
			}
		}
	}
	int ans = 1000000000;
	for (int i = 2; i < cnt; i++)
	{
		int temp = bfs(i);
		ans = min(ans, temp);
		memset(visited, 0, sizeof(visited));
	}
	cout << ans;
}