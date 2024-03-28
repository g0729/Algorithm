#include <bits/stdc++.h>
using namespace std;
#define MAX 101
int MAP[MAX][MAX];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int n,m;
int bfs(int x,int y)
{
	MAP[x][y]=0;
	queue<pair<int,int>>q;
	q.push({x,y});
	int cnt=0;
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		cnt++;
		for(int i =0;i<4;i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx<=0||nx>n||ny<=0||ny>m)
			continue;
			if(MAP[nx][ny]==0)
			continue;
			MAP[nx][ny]=0;
			q.push({nx,ny});
		}
	}
	return cnt;
}
int main()
{
	int k;
	cin>>n>>m>>k;

	for (int i = 0; i < k; i++)
	{
		int a,b;
		cin>>a>>b;
		MAP[a][b]=1;
	}
	int res=0;

	for(int i = 1;i<=n;i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if(MAP[i][j]==1)
			{
				int temp=bfs(i,j);
				res=max(res,temp);
			}
		}
	}
	cout<<res;
}
