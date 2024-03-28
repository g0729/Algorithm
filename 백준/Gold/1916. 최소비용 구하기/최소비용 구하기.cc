#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

int n, m;
vector<pair<int, int>> v[1001];
int s, e;
int dist[1001];
void dij()
{
	priority_queue<pair<int, int>> pq;
	dist[s] = 0;
	pq.push({0, s});

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (cost > dist[cur])
			continue;
		for (int i = 0; i < v[cur].size(); i++)
		{
			int next = v[cur][i].first;
			int nCost = v[cur][i].second;

			if (dist[next] > cost + nCost)
			{
				dist[next] = cost + nCost;
				pq.push({-dist[next], next});
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		v[a].push_back({b, c});
	}
	cin >> s >> e;

	for (int i = 0; i <= n; i++)
	{
		dist[i] = INF;
	}

	dij();

	cout << dist[e];
	return 0;
}