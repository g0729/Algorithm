#include <bits/stdc++.h>
using namespace std;
vector<int> v[501];

bool visited[501];
void dfs(int now, int depth)
{
	if (depth == 2)
	{
		return;
	}
	for (int i = 0; i < v[now].size(); i++)
	{
		int temp = v[now][i];
		visited[temp] = true;
		dfs(temp, depth + 1);
	}
}
int main()
{
	int n;
	cin >> n;
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	visited[1] = true;
	dfs(1, 0);
	int res = 0;
	for (int i = 0; i < 501; i++)
	{
		if (visited[i])
			res++;
	}
	cout << res-1;
}