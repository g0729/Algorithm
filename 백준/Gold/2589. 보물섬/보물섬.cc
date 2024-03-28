#include<bits/stdc++.h>
using namespace std;
#define MAX 50
int n, m;
int graph[MAX][MAX];
int cgraph[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int bfs(int a, int b)
{
	if (cgraph[a][b] == 0)
		return -1;
	int res = 0;
	queue<pair<int, int>>q;
	q.push({ a,b });
	visited[a][b] = true;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (cgraph[nx][ny] == 0||visited[nx][ny]==true)
				continue;
			if (cgraph[nx][ny] !=0 &&visited[nx][ny]==false)
			{
				q.push({ nx,ny });
				visited[nx][ny] = true;
				cgraph[nx][ny] = cgraph[x][y] + 1;
				res = max(res, cgraph[nx][ny]);
			}
		}
	}
	return res;
}
void mapcopy()
{
	for (int i = 0; i < n; i++)
	{
		for (int q = 0; q < m; q++)
		{
			cgraph[i][q] = graph[i][q];
			visited[i][q] = false;
		}
	}
}
int main()
{
	int ans = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int q = 0; q < m; q++)
		{
			char a;
			cin >> a;
			if (a == 'W')
				graph[i][q] = 0;
			else
				graph[i][q] = 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int q = 0; q < m; q++)
		{
			if (graph[i][q]==1)
			{
				ans = max(ans, bfs(i, q));
				mapcopy();
			}
		}
	}
	if (ans == 0 || ans == 1)
	{
		cout << "1";
	}
	else
		cout << ans - 1;
}