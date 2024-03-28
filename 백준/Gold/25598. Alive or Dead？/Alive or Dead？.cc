#include <bits/stdc++.h>
using namespace std;

int MAP[26][26];
int n;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
struct zombie
{
	int x, y;
	int speed;
	int dir;
	int level;
};
bool bound(int x, int y)
{
	if (x <= 0 || y <= 0 || x > n || y > n)
		return false;
	else
		return true;
}
void move(zombie &z)
{
	int dir = z.dir;
	for (int i = 0; i < z.speed; i++)
	{
		int x = z.x + dx[dir];
		int y = z.y + dy[dir];
		if (!bound(x, y) || MAP[x][y] == 1)
		{
			if (z.level == 0)
			{
				dir = (dir + 2) % 4;
				z.dir = dir;
				return;
			}
			else
			{
				if (MAP[x][y] == 1)
				{
					MAP[x][y] = 0;
				}
				int dir_cnt[4] = {0};

				for (int j = z.x; j > 0; j--)
					if (MAP[j][z.y] == 1)
						dir_cnt[0]++;
				for (int j = z.y; j <= n; j++)
					if (MAP[z.x][j] == 1)
						dir_cnt[1]++;
				for (int j = z.x; j <= n; j++)
					if (MAP[j][z.y] == 1)
						dir_cnt[2]++;
				for (int j = z.y; j > 0; j--)
					if (MAP[z.x][j] == 1)
						dir_cnt[3]++;
				int MAX = 0;
				for (int j = 0; j < 4; j++)
					if (dir_cnt[j] > MAX)
						MAX = dir_cnt[j];
				for (int j = 0; j < 4; j++)
					if (dir_cnt[j] == MAX)
					{
						z.dir = j;
						return;
					}
			}
		}
		z.x = x;
		z.y = y;
	}
	if (z.level == 1)
	{
		int dir_cnt[4] = {0};

		for (int j = z.x; j > 0; j--)
			if (MAP[j][z.y] == 1)
				dir_cnt[0]++;
		for (int j = z.y; j <= n; j++)
			if (MAP[z.x][j] == 1)
				dir_cnt[1]++;
		for (int j = z.x; j <= n; j++)
			if (MAP[j][z.y] == 1)
				dir_cnt[2]++;
		for (int j = z.y; j > 0; j--)
			if (MAP[z.x][j] == 1)
				dir_cnt[3]++;
		int MAX = 0;
		for (int j = 0; j < 4; j++)
			if (dir_cnt[j] > MAX)
				MAX = dir_cnt[j];
		for (int j = 0; j < 4; j++)
			if (dir_cnt[j] == MAX)
			{
				z.dir = j;
				return;
			}
	}
}
int main()
{
	string command;
	pair<int, int> player;
	vector<zombie> zombies;

	cin >> n;
	cin >> command;
	cin >> player.first >> player.second;
	int w;

	cin >> w;

	for (int i = 0; i < w; i++)
	{
		int a, b;

		cin >> a >> b;

		MAP[a][b] = 1;
	}
	cin >> w;

	for (int i = 0; i < w; i++)
	{
		zombie temp;
		cin >> temp.x >> temp.y >> temp.level;
		char a;

		cin >> a;
		int dir;
		if (a == 'U')
			dir = 0;
		else if (a == 'R')
			dir = 1;
		else if (a == 'D')
			dir = 2;
		else
			dir = 3;
		temp.dir = dir;
		cin >> temp.speed;
		zombies.push_back(temp);
	}
	int d;

	cin >> d;
	for (int i = 1; i <= d; i++)
	{
		int nx, ny;
		nx = player.first;
		ny = player.second;
		if (command[i - 1] == 'U')
		{
			nx = player.first - 1;
		}
		else if (command[i - 1] == 'R')
		{
			ny = player.second + 1;
		}
		else if (command[i - 1] == 'D')
		{
			nx = player.first + 1;
		}
		else if (command[i - 1] == 'L')
		{
			ny = player.second - 1;
		}
		if (!bound(nx,ny)||MAP[nx][ny]==1)
		{

		}
		else
		{
			player.first=nx;
			player.second=ny;
		}
		for(int j=0;j<zombies.size();j++)
		{
			move(zombies[j]);
		}
		for(int j = 0 ; j<zombies.size();j++)
		{
			if(zombies[j].x==player.first&&zombies[j].y==player.second)
			{
				cout<<i<<"\nDEAD...";
				return 0;
			}
		}
	}
	cout<<"ALIVE!";
}