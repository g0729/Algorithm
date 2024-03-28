#include<bits/stdc++.h>
using namespace std;
#define MAX 8
int graph[MAX][MAX];
int n, m;
int cgraph[MAX][MAX];
vector<pair<int, int>>vir;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int res = 0;
void reset()
{
	for (int i = 0; i < n; i++)
	{
		for (int q = 0; q < m;q++)
		{
			cgraph[i][q] = graph[i][q];
		}
	}
}
int check()
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int q = 0; q < m; q++)
		{
			if (cgraph[i][q] == 0)
				cnt++;
		}
	}
	return cnt;
}
void bfs()
{
	queue<pair<int, int>>q;
	for (int i = 0; i < vir.size(); i++)
	{
		q.push({ vir[i].first,vir[i].second });
	}
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
			if (cgraph[nx][ny] == 2 || cgraph[nx][ny] == 1)
				continue;
			if (cgraph[nx][ny] == 0)
			{
				q.push({ nx,ny });
				cgraph[nx][ny] =2;
			}
		}
	}
	res = max(res, check());
}
void wall(int cnt)
{
	if (cnt == 3)
	{
		reset();
		bfs();
		return;
	}
	for (int i = 0; i < n; i++)
	{
		for (int q = 0; q < m; q++)
		{
			if (graph[i][q] == 0)
			{
				graph[i][q] = 1;
				wall(cnt + 1);
				graph[i][q] = 0;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int q= 0; q < m; q++)
		{
			cin >> graph[i][q];
			if (graph[i][q] == 2)
				vir.push_back({ i,q });
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int q = 0; q < m; q++)
		{
			if (graph[i][q] == 0)
			{
				graph[i][q] = 1;
				wall(1);
				graph[i][q] = 0;
			}
		}
	}
	cout << res;
}