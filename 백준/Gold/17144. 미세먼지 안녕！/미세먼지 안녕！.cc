#include <bits/stdc++.h>
using namespace std;

int MAP[50][50];
int CMAP[50][50];
int r, c, t;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int up;
int down;
void dust()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (MAP[i][j] > 0)
			{
				int cnt = 0;
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || nx >= r || ny < 0 || ny >= c)
						continue;
					if (MAP[nx][ny] == -1)
						continue;
					CMAP[nx][ny] += MAP[i][j] / 5;
					cnt++;
				}
				CMAP[i][j] += MAP[i][j] - (MAP[i][j] / 5) * cnt;
			}
		}
	}
}
void upcycle()
{
	for(int i = up-1;i>=1;i--)
	{
		CMAP[i][0]=CMAP[i-1][0];
	}
	for(int i = 0 ; i<=c-2;i++)
	{
		CMAP[0][i]=CMAP[0][i+1];
	}
	for(int i =0;i<=up-1;i++)
	{
		CMAP[i][c-1]=CMAP[i+1][c-1];
	}
	for(int i = c-1;i>=2;i--)
	{
		CMAP[up][i]=CMAP[up][i-1];
	}
	CMAP[up][1]=0;
}
void downcylce()
{
	for(int i =down+1;i<r-1;i++)
	{
		CMAP[i][0]=CMAP[i+1][0];
	}
	for(int i=0;i<c-1;i++)
	{
		CMAP[r-1][i]=CMAP[r-1][i+1];
	}
	for(int i =r-1;i>down;i--)
	{
		CMAP[i][c-1]=CMAP[i-1][c-1];
	}
	for(int i =c-1;i>1;i--)
	{
		CMAP[down][i]=CMAP[down][i-1];
	}
	CMAP[down][1]=0;
}
void reset()
{
	for(int i = 0 ; i<r;i++)
	{
		for (int j = 0; j < c; j++)
		{
			MAP[i][j]=CMAP[i][j];
		}
	}
	MAP[up][0]=MAP[down][0]=-1;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> MAP[i][j];
			if (MAP[i][j] == -1)
			{
				if (up == 0)
					up = i;
				else
					down = i;
			}
		}
	}

	for (int i = 0; i < t; i++)
	{
		dust();
		upcycle();
		downcylce();
		reset();
		memset(CMAP,0,sizeof(CMAP));
	}

	int sum=0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			sum+=MAP[i][j];
		}
	}
	sum+=2;
	cout<<sum;
}