#include<bits/stdc++.h>
using namespace std;
#define MAX 100
int n;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int graph[MAX][MAX];
int cgraph[MAX][MAX];

bool bfs(int a,int b)
{
	if(graph[a][b]==0)
	return false;
	queue<pair<int,int>>q;
	q.push({a,b});
	int color = graph[a][b];
	while(!q.empty())
	{
		int x= q.front().first;
		int y= q.front().second;
		q.pop();
		for(int i = 0 ; i<4;i++)
		{
			int nx = x+dx[i];
			int ny= y +dy[i];
			if(nx<0||nx>=n||ny<0||ny>=n)
				continue;
			if(graph[nx][ny]==0)
				continue;
			if(graph[nx][ny]==color)
			{
				q.push({nx,ny});
				graph[nx][ny]=0;
			}
		}
	}
	return true;
}
int main()
{
	int cnt=0;
	int ccnt=0;
	cin>>n;
	for(int i = 0 ; i<n;i++)
	{
		for(int q= 0 ; q<n;q++)
		{
			char a;
			cin>>a;
			if(a=='R')
			{
				graph[i][q]=1;
				cgraph[i][q]=1;
			}
			if(a=='G')
			{
				graph[i][q]=2;
				cgraph[i][q]=1;
			}
			if(a=='B')
			{
				graph[i][q]=3;
				cgraph[i][q]=3;
			}
		}
	}
	for(int i = 0 ; i<n;i++)
	{
		for(int q = 0 ;q<n;q++)
		{
			if(bfs(i,q))
			{
				cnt++;
			}
		}
	}
		for(int i = 0 ; i<n;i++)
	{
		for(int q = 0 ;q<n;q++)
		{
			graph[i][q]=cgraph[i][q];
		}
	}
	for(int i = 0 ; i<n;i++)
	{
		for(int q = 0 ;q<n;q++)
		{
			if(bfs(i,q))
			{
				ccnt++;
			}
		}
	}
	cout<<cnt<<" "<<ccnt;
}