#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

vector<int> v[100001];
int res[100001];
bool visited[100001];
int n, m, r;
int cnt=1;
void dfs(int now)
{
	res[now]=cnt;
	visited[now]=true;
	cnt++;
	for (int i = 0; i < v[now].size(); i++)
	{
		int next=v[now][i];
		if(visited[next])
		continue;
		dfs(next);
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> r;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		sort(v[i].begin(),v[i].end());
	}
	
	dfs(r);

	for (int i = 1; i <= n; i++)
	{
		cout<<res[i]<<"\n";
	}
	
	return 0;
}