#include <stdio.h>
#include <stdbool.h>

int x, y;
int arr[50][50];

int dx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

void init();
int count_island();
void dfs(int, int);

int main()
{
	scanf("%d %d", &x, &y);
	while (x != 0 && y != 0)
	{
		init();
		printf("%d\n", count_island());
		scanf("%d %d", &x, &y);
	}
	return 0;
}

int count_island()
{
	int count = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (arr[i][j]==1)
			{
				dfs(i, j);
				count++;
			}
		}
	}
	return count;
}

void dfs(int cy, int cx)
{
	arr[cy][cx] = 0;
	int ny, nx;
	for (int i = 0; i < 8; i++)
	{
		ny = cy + dy[i];
		nx = cx + dx[i];
		if (ny < y && ny >= 0 && nx < x && nx >= 0 && arr[ny][nx] == 1)
			dfs(ny, nx);
	}
	return;
}

void init()
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
			scanf("%d", &arr[i][j]);
	}
	return;
}