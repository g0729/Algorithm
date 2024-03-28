#include<bits/stdc++.h>
using namespace std;
#define MAX 101
int n;
int graph[MAX];
int visited[MAX];
int cycle[MAX];
int cnt;
bool dfs(int start,int next)
{
	if(visited[next])
		return false;
	visited[next]=true;
	if(start==next||dfs(start,graph[next]))
	{
		cnt++;
		cycle[next]=true;
		return true;
	}
	return false;
	
}
int main()
{
	cin>>n;
	for (int i = 1; i <= n; i++)
	{
		cin>>graph[i];
	}
	for(int i = 1 ; i<=n;i++)
	{
		for(int q = 1 ; q<=n;q++)
		{
			visited[q]=cycle[q];
		}
		dfs(i,graph[i]);
	}
	cout<<cnt<<endl;
	for(int i = 1 ; i<=n;i++)
	{
		if(cycle[i])
			cout<<i<<" ";
	}
}