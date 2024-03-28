#include<bits/stdc++.h>
using namespace std;

#define MAX 101

int graph[MAX][MAX][MAX];
int dx[] = { 1,-1,0,0,0,0 };
int dy[] = { 0,0,1,-1,0,0 };
int dz[] = { 0,0,0,0,1,-1 };
int n, m, h;
queue<tuple<int, int, int>>v;
int bfs()
{
	int res = 0;
	while (!v.empty())
	{
		int x = get<0>(v.front());
		int y = get<1>(v.front());
		int z = get<2>(v.front());
		v.pop();
		for (int i = 0; i < 6; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h)
				continue;
			if (graph[nx][ny][nz] == -1)
				continue;
			if (graph[nx][ny][nz] == 0)
			{
				v.push({ nx,ny,nz });
				graph[nx][ny][nz] = graph[x][y][z] + 1;
				res = max(res, graph[nx][ny][nz]);
			}
		}
	}
	return res;
}
int main()
{
	cin >> n >> m >> h;
	for (int i = 0; i < h; i++)
	{
		for (int q = 0; q < m; q++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &graph[q][j][i]);
				if (graph[q][j][i] == 1)
				{
					v.push({ q,j,i });
				}
			}
		}
	}
	int res = bfs();
	for (int i = 0; i < h; i++)
	{
		for (int q = 0; q < m; q++)
		{
			for (int j = 0; j < n; j++)
			{
				if (graph[q][j][i] == 0)
				{
					cout << "-1";
					return 0;
				}
			}
		}
	}
	
	if (res == 0)
	{
		cout << "0";
	}
	else
		cout << res - 1;

}