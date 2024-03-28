#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

vector<pair<int, int>> node[10001];
bool visited[10001];
int n;

int res;
int resNode;
void dfs(int now,int weight)
{
	if(visited[now])
	return;

	visited[now]=true;
	if(res<weight)
	{
		res=weight;
		resNode=now;
	}
	for (int i = 0; i < node[now].size(); i++)
	{
		int next=node[now][i].first;
		int nextWeight=weight+node[now][i].second;
		dfs(next,nextWeight);
	}
	
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;

	for (int i = 0; i < n-1; i++)
	{
		int a,b,c;

		cin>>a>>b>>c;
		node[a].push_back({b,c});
		node[b].push_back({a,c});
	}
	
	dfs(1,0);
	memset(visited,false,sizeof(visited));
	res=0;

	dfs(resNode,0);

	cout<<res;
	return 0;
}