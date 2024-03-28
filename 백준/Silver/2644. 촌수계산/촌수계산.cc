#include <bits/stdc++.h>
using namespace std;
vector<int> v[101];
bool visited[101];
int n, m;
int start, last;
int res=-1;
void dfs(int now, int cnt)
{
	if (now == last)
	{
		res = cnt;
		return;
	}
	for (int i = 0; i < v[now].size(); i++)
	{
		if(visited[v[now][i]])
		continue;
		visited[v[now][i]] = true;
		dfs(v[now][i], cnt + 1);
		visited[v[now][i]] = false;
	}
}
int main()
{
	cin >> n;
	cin >> start >> last;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	visited[start]=true;
	dfs(start,0);
	
	cout<<res;
}