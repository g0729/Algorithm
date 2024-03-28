#include <bits/stdc++.h>
using namespace std;
#define MAX 251
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char MAP[MAX][MAX];
bool visited[MAX][MAX];
int r, c;
int v_res, k_res;

void bfs(int x, int y)
{
	int v_cnt, k_cnt;
	v_cnt = k_cnt = 0;

	queue<pair<int, int>> q;
	q.push({x,y});
	visited[x][y] = true;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		if (MAP[x][y] == 'v')
		{
			v_cnt++;
		}
		else if (MAP[x][y] == 'k')
		{
			k_cnt++;
		}
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c)
				continue;
			if (MAP[nx][ny] == '#')
				continue;
			if (visited[nx][ny])
				continue;
			visited[nx][ny] = true;
			q.push({nx, ny});
		}
	}
	if(v_cnt>=k_cnt)
	{
		v_res+=v_cnt;
	}
	else
	{
		k_res+=k_cnt;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> MAP[i][j];
		}
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (visited[i][j] == false && MAP[i][j] != '#')
			{
				bfs(i, j);
			}
		}
	}
	cout<<k_res<<" "<<v_res;
}