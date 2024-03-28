#include <bits/stdc++.h>
using namespace std;
char MAP[100][100];
int dx[]={1,1,1,0,0,-1,-1,-1};
int dy[]={1,0,-1,1,-1,1,0,-1};
int main()
{
	while (1)
	{
		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0)
			return 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> MAP[i][j];
			}
		}

		int res = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (MAP[i][j] == '#')
				{
					bool check = true;
					for (int k = 0; k < 8; k++)
					{
						int nx = i + dx[k];
						int ny = j + dy[k];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m)
							continue;
						if (MAP[nx][ny] == '#')
						{
							check = false;
							break;
						}
					}
					if (check)
						res++;
				}
			}
		}
		cout << res << "\n";
	}
}