#include<bits/stdc++.h>
using namespace std;
#define MAX 1001

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int arr[MAX][MAX];
int n, m;
int tom_cnt;
int day_cnt;
int next_tom;
int cnt;
queue<pair<int, int>>q;


void bfs()
{
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		cnt++;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= m || ny<0 || ny>=n)
				continue;
			if (arr[nx][ny] == 1 || arr[nx][ny] == -1)
				continue;
			if (arr[nx][ny] == 0)
			{
				arr[nx][ny] = 1;
				q.push({ nx,ny });
				next_tom++;
			}
		}
		if (tom_cnt == cnt)
		{
			tom_cnt = next_tom;
			cnt = 0;
			next_tom = 0;
			day_cnt++;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
			{
				tom_cnt++;
				q.push({ i,j });
			}
		}
	}
	bfs();
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 0)
			{
				cout << "-1";
				return 0;
			}
		}
	}
	cout << day_cnt-1;
}