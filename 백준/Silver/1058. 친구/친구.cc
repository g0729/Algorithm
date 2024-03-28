#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 51

vector<int> v[MAX];

int bfs(int now)
{
	vector<bool> visited(MAX);

	visited[now] = true;

	queue<int> q;
	q.push(now);

	for (int i = 0; i < 2; i++)
	{
		int size = q.size();

		while (size--)
		{
			int now = q.front();
			q.pop();
			for (int j = 0; j < v[now].size(); j++)
			{
				int next = v[now][j];

				if (visited[next])
					continue;

				q.push(next);
				visited[next] = true;
			}
		}
	}

	int res = -1;

	for (int i = 1; i < MAX; i++)
	{
		if (visited[i])
			res++;
	}

	return res;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < s.length(); j++)
		{
			if(s[j]=='Y')
				v[i].push_back(j+1);
		}
		
	}

	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		res = max(res, bfs(i));
	}

	cout << res;

	return 0;
}