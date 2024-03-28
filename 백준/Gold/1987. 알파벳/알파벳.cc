#include <bits/stdc++.h>
using namespace std;
#define MAX 20
bool visited[MAX][MAX];
char graph[MAX][MAX];
int r, c;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int res;
bool alpha[26];
void dfs(int x, int y, int cnt)
{
	res=max(res,cnt);
	for (int j = 0; j < 4; j++)
	{
		int nx = x + dx[j];
		int ny = y + dy[j];
		if(nx<0||nx>=r||ny<0||ny>=c)
		continue;
		if(alpha[graph[nx][ny]-'A'])
		continue;
		alpha[graph[nx][ny]-'A']=true;
		dfs(nx,ny,cnt+1);
		alpha[graph[nx][ny]-'A']=false;
	}
	return;
}
int main()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int q = 0; q < c; q++)
		{
			cin >> graph[i][q];
		}
	}
	alpha[graph[0][0]-'A']=true;
	dfs(0,0,1);
	 cout<<res;
}