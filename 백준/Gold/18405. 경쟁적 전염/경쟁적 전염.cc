#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 201

int MAP[1001][MAX][MAX];
int n, k;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
void bfs(int idx)
{
	queue<pair<int, int>> q;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (MAP[idx][i][j] != 0)
				q.push({i, j});
		}
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

			if (MAP[idx][nx][ny] != 0)
				continue;
			if (nx <= 0 || ny <= 0 || nx > n || ny > n)
				continue;
			q.push({nx, ny});
			MAP[idx][nx][ny] = MAP[idx][x][y] + 1;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int a;
			cin >> a;

			if (a != 0)
				MAP[a][i][j] = 1;
		}
	}

	for (int i = 1; i <= k; i++)
	{
		bfs(i);
	}

	int a, b, c;
	cin >> a >> b >> c;

	int res = 0;
	int resT=0;
	for (int i = 1; i <= k; i++)
	{
		if(MAP[i][b][c]-1>a)
			continue;
		if(MAP[i][b][c]==0)
		continue;
		if(resT==0)
		{
			resT=MAP[i][b][c];
			res=i;
			continue;
		}
		if(resT>MAP[i][b][c])
		{
			resT=MAP[i][b][c];
			res=i;
		}
	}

	cout<<res;
	return 0;
}