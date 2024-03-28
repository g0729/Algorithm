#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long
vector<pair<int, int>> node[1001];
bool visited[1001];
int n, m;
int res;
void dfs(int now, int weight, int target)
{
	if (visited[now])
		return;
	
	visited[now]=true;
	if (now == target)
	{
		res = weight;
		return;
	}

	for (int i = 0; i < node[now].size(); i++)
	{
		int next=node[now][i].first;
		int nextWeight=weight+node[now][i].second;

		dfs(next,nextWeight,target);
	}
	
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n - 1; i++)
	{
		int a, b, c;

		cin >> a >> b >> c;

		node[a].push_back({b, c});
		node[b].push_back({a, c});
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		
		dfs(a,0,b);
		cout<<res<<"\n";

		memset(visited,false,sizeof(visited));
		res=0;
	}

	return 0;
}