	#include <bits/stdc++.h>
	using namespace std;
	#define MAX 51
	char MAP[MAX][MAX];
	int visited[MAX][MAX][4];
	int dx[] = {-1, 0, 1, 0};
	int dy[] = {0, 1, 0, -1};
	pair<int, int> door[2];
	int n;

	void bfs()
	{
		queue<tuple<int,int,int>>q;
		for(int i = 0 ; i<4;i++)
		{
			q.push({door[0].first,door[0].second,i});
			visited[door[0].first][door[0].second][i]=0;
		}
		while(!q.empty())
		{
			int x=get<0>(q.front());
			int y=get<1>(q.front());
			int dir=get<2>(q.front());
			q.pop();
			int nx=x+dx[dir];
			int ny=y+dy[dir];
			if(nx<1||nx>n||ny<1||ny>n)
			continue;
			if(MAP[nx][ny]=='*')
			continue;
			if(MAP[nx][ny]=='.')
			{
				if(visited[nx][ny][dir]>visited[x][y][dir])
				{
					visited[nx][ny][dir]=visited[x][y][dir];
					q.push({nx,ny,dir});
				}
			}
			else if(MAP[nx][ny]=='!')
			{
				if(visited[nx][ny][dir]>visited[x][y][dir])
				{
					visited[nx][ny][dir]=visited[x][y][dir];
					q.push({nx,ny,dir});
				}
				int tempdir[2];
				if(dir==0||dir==2)
				{
					tempdir[0]=3;
					tempdir[1]=1;
				}
				else if(dir==1||dir==3)
				{
					tempdir[0]=0;
					tempdir[1]=2;
				}
				if(visited[nx][ny][tempdir[0]]>visited[x][y][dir]+1)
				{
					visited[nx][ny][tempdir[0]]=visited[x][y][dir]+1;
					q.push({nx,ny,tempdir[0]});
				}
			
				if(visited[nx][ny][tempdir[1]]>visited[x][y][dir]+1)
				{
					visited[nx][ny][tempdir[1]]=visited[x][y][dir]+1;
					q.push({nx,ny,tempdir[1]});
				}
			}
			else if(MAP[nx][ny]='#')
			{
				if(visited[nx][ny][dir]>visited[x][y][dir])
				{
					visited[nx][ny][dir]=visited[x][y][dir];
				}
			}
		}
	}
	int main()
	{
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin >> n;
		bool doorcheck = false;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin>>MAP[i][j];
				if (MAP[i][j] == '#')
				{
					if (doorcheck)
					{
						door[1].first = i;
						door[1].second = j;
					}
					else
					{
						door[0].first = i;
						door[0].second = j;
						doorcheck = true;
					}
				}
				visited[i][j][0]=1e5;
				visited[i][j][1]=1e5;
				visited[i][j][2]=1e5;
				visited[i][j][3]=1e5;
			}
		}
		
		bfs();
		int ans=1e6;
		for(int i = 0 ;i<4;i++)
		{
			ans=min(ans,visited[door[1].first][door[1].second][i]);
		}
		cout<<ans;
	}