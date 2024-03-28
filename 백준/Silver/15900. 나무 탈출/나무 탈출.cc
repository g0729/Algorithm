#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 500001

vector<int> tree[MAX];
bool visited[MAX];
ll sum;

void dfs(int now, int depth)
{
	visited[now] = true;

	bool flag = false;
	for (int i = 0; i < tree[now].size(); i++)
	{
		int next = tree[now][i];

		if (visited[next])
			continue;

		flag = true;
		dfs(next, depth + 1);
	}

	if (!flag)
		sum += depth;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs(1, 0);

	if (sum % 2 == 1)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}