#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
bool visited[MAX+1][MAX];
int s;
int res;
int bfs()
{
	queue<tuple<int,int,int>>q;
	q.push({1,0,0});
	while(!q.empty())
	{
		int now = get<0>(q.front());
		int clip = get<1>(q.front());
		int time = get<2>(q.front());
		q.pop();
		visited[now][clip]=true;
		if(now==s&&!res)
		{
			res=time;
			cout<<res;
			exit(0);
		}
		if(now!=clip)
		{
			q.push({now,now,time+1});
		}
		if(now+clip<=MAX&&visited[now+clip][clip]==false)
		{
			q.push({now+clip,clip,time+1});
			visited[now+clip][clip]=true;
		}
		if(now-1>1)
		{
			q.push({now-1,clip,time+1});
			visited[now-1][clip]=true;
		}
	}
}
int main()
{
	cin>>s;
	bfs();
	cout<<res;
}