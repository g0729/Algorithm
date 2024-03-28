#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int MAP[20][20];
bool visited[20][20];
vector<pair<int, int>> MaxBlocks;
int n;
int MaxRainbows;
int resX, resY;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs(int x, int y)
{
	int color = MAP[x][y];
	vector<pair<int, int>> blocks;
	vector<pair<int, int>> rainbows;

	queue<pair<int, int>> q;
	q.push({x, y});
	blocks.push_back({x, y});
	visited[x][y] = true;

	while (!q.empty())
	{
		int X = q.front().first;
		int Y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = X + dx[i];
			int ny = Y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n)
				continue;
			if (visited[nx][ny])
				continue;

			if (MAP[nx][ny] == color || MAP[nx][ny] == 0)
			{
				q.push({nx, ny});
				blocks.push_back({nx, ny});
				visited[nx][ny] = true;
				if (MAP[nx][ny] == 0)
					rainbows.push_back({nx, ny});
			}
		}
	}

	if (blocks.size() > MaxBlocks.size())
	{
		MaxBlocks = blocks;
		MaxRainbows = rainbows.size();
		resX = x;
		resY = y;
	}
	else if (blocks.size() == MaxBlocks.size())
	{
		if (rainbows.size() > MaxRainbows)
		{
			MaxBlocks = blocks;
			MaxRainbows = rainbows.size();
			resX = x;
			resY = y;
		}
		else if (rainbows.size() == MaxRainbows)
		{
			if (resX < x)
			{
				MaxBlocks = blocks;
				MaxRainbows = rainbows.size();
				resX = x;
				resY = y;
			}
			else if (resX == x)
			{
				if (resY < y)
				{
					MaxBlocks = blocks;
					MaxRainbows = rainbows.size();
					resX = x;
					resY = y;
				}
			}
		}
	}

	for (int i = 0; i < rainbows.size(); i++)
	{
		int x = rainbows[i].first;
		int y = rainbows[i].second;

		visited[x][y] = false;
	}
}
void findBlock()
{

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (MAP[i][j] > 0 && !visited[i][j])
			{
				bfs(i, j);
			}
		}
	}
}
void delBlock()
{
	for (int i = 0; i < MaxBlocks.size(); i++)
	{
		int x = MaxBlocks[i].first;
		int y = MaxBlocks[i].second;

		MAP[x][y] = -2;
	}
}
void gravity()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 2; j >= 0; j--)
		{
			if (MAP[j][i] == -2 || MAP[j][i] == -1)
				continue;

			for (int k = j + 1; k < n; k++)
			{
				if (MAP[k][i] == -2)
				{
					MAP[k][i] = MAP[k - 1][i];
					MAP[k - 1][i] = -2;
				}
				else
					break;
			}
		}
	}
}
void rotate()
{
	int CMAP[20][20];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			CMAP[i][j] = MAP[j][n - i - 1];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			MAP[i][j] = CMAP[i][j];
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int m;
	cin >> n>>m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> MAP[i][j];
		}
	}

	int ans = 0;

	while (1)
	{
		findBlock();
		if (MaxBlocks.size() < 2)
			break;
		ans += MaxBlocks.size() * MaxBlocks.size();

		delBlock();
		MaxBlocks.clear();
		resX = resY = MaxRainbows = -1;
		gravity();
		rotate();
		gravity();
		memset(visited,false,sizeof(visited));
	}

	cout<<ans;
	return 0;
}