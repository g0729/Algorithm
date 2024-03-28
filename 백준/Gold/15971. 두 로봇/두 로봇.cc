#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100001
ll MAPA[MAX];
ll MAPB[MAX];
vector<pair<ll, ll>> v[MAX];
ll n, a, b;

void bfs()
{
	queue<ll> q;

	q.push(a);

	while (!q.empty())
	{
		ll now = q.front();
		q.pop();

		for (ll i = 0; i < v[now].size(); i++)
		{
			ll next = v[now][i].first;
			ll cost = v[now][i].second;
			if (MAPA[next] == 0)
			{
				MAPA[next] = MAPA[now] + cost;
				q.push(next);
			}
		}
	}

	q.push(b);

	while (!q.empty())
	{
		ll now = q.front();
		q.pop();

		for (ll i = 0; i < v[now].size(); i++)
		{
			ll next = v[now][i].first;
			ll cost = v[now][i].second;
			if (MAPB[next] == 0)
			{
				MAPB[next] = MAPB[now] + cost;
				q.push(next);
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> a >> b;

	for (ll i = 0; i < n - 1; i++)
	{
		ll c, d, e;
		cin >> c >> d >> e;

		v[c].push_back({d, e});
		v[d].push_back({c, e});
	}

	if(n==1||a==b)
	{
		cout<<"0";
		return 0;
	}
	bfs();
	MAPA[a]=0;
	MAPB[b]=0;
	ll res = 1e9;
	for (ll i = 1; i < MAX; i++)
	{
		for (ll j = 0; j < v[i].size(); j++)
		{
			ll next = v[i][j].first;
			res = min(res, MAPA[i] + MAPB[next]);
		}
	}

	cout << res;

	return 0;
}