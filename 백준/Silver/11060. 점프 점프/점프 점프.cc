#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
int n;
int arr[MAX];
int visited[MAX];
void bfs()
{
	queue<int>q;
	q.push(0);
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		for (int i = 1; i <= arr[now]; i++)
		{
			if(now+i>=n)
			continue;
			if(visited[now+i]>visited[now]+1)
			{
				q.push(now+i);
				visited[now+i]=visited[now]+1;
			}
		}
	}
}
int main()
{
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		cin>>arr[i];
	}
	for (int i = 1; i < n; i++)
	{
		visited[i]=1e5;
	}
	bfs();
	int res=visited[n-1];
	if(res==1e5)
	{
		cout<<"-1";
	}	
	else
	{
		cout<<res;
	}
}