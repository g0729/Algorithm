#include <bits/stdc++.h>
using namespace std;
#define MAX 20001
vector<int> v[MAX];
int visited[MAX];
int n, k, res;
vector<int> ans;
void bfs()
{
	queue<int> q;
	q.push(1);
	visited[1] = 1;
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (int i = 0; i < v[now].size(); i++)
		{
			int next = v[now][i];
			if (visited[next] == 0)
			{
				visited[next] = visited[now] + 1;
				q.push(next);
				res = max(res, visited[next]);
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	bfs();
	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == res)
		{
			ans.push_back(i);
		}
	}
	cout << ans[0] << " " << res-1 << " " << ans.size();
}