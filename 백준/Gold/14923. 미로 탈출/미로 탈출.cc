#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
int visited[MAX][MAX][2];
int MAP[MAX][MAX];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;
pair<int, int> escloc;
int bfs(int x, int y)
{
	queue<tuple<int, int, bool>> q;
	q.push({x, y, true});
	while (!q.empty())
	{
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		bool wall = get<2>(q.front());
		q.pop();
		if(x==escloc.first&&y==escloc.second)
		return visited[x][y][wall];
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx <=0 || nx > n || ny <= 0 || ny > m)
				continue;
			if (MAP[nx][ny] == 1 && wall)
			{
				q.push({nx, ny, false});
				visited[nx][ny][0] = visited[x][y][1] + 1;
			}
			if (MAP[nx][ny] == 0 && visited[nx][ny][wall] == 0)
			{
				q.push({nx, ny, wall});
				visited[nx][ny][wall] = visited[x][y][wall] + 1;
			}
		}
	}
	return -1;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int x, y;
	cin >> n >> m;
		cin >> x >> y;
	cin >> escloc.first >> escloc.second;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> MAP[i][j];
		}
	}

	
	int res=bfs(x,y);
	cout<<res;

}