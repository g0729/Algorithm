#include<bits/stdc++.h>
using namespace std;
#define MAX 100
int graph[MAX][MAX];
bool visited[MAX][MAX];
int check[MAX][MAX];
int n, m;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,-1,1 };
void reset()
{
	for (int i = 0; i < n; i++)
	{
		for (int q = 0; q < m; q++)
		{
			check[i][q] = 0;
			visited[i][q] = false;
		}
	}
}
bool bfs()
{
	queue<pair<int, int>>q;
	q.push({ 0,0 });
	visited[0][0] = true;
	int cnt = 0;
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
			if (visited[nx][ny] == true)
				continue;
			visited[nx][ny] = true;
			if (graph[nx][ny] == 0)
			{
				q.push({ nx,ny });
			}
			else if (graph[nx][ny] == 1)
			{
				visited[nx][ny] = false;
				check[nx][ny]++;
				if (check[nx][ny] > 1)
				{
					visited[nx][ny] = true;
					graph[nx][ny] = 0;
					cnt++;
				}
			}
		}
	}
	if (cnt == 0)
		return false;
	else
		return true;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int q = 0; q < m; q++)
		{
			cin >> graph[i][q];
		}
	}
	int time = 0;
	while (bfs())
	{
		time++;
		reset();
	}
	cout << time;
}