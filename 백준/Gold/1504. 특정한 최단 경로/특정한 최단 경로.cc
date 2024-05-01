#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

vector<pair<ll, ll>> edges[801];
ll n, e;
ll v1, v2;
vector<ll> dij(ll start)
{
    vector<ll> dist(n + 1, INF);
    priority_queue<pair<ll, ll>> pq;

    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty())
    {
        ll cost = -pq.top().first;
        ll cur = pq.top().second;
        pq.pop();

        if (cost > dist[cur])
            continue;
        for (ll i = 0; i < edges[cur].size(); i++)
        {
            ll next = edges[cur][i].first;
            ll ncost = edges[cur][i].second;

            if (dist[next] > cost + ncost)
            {
                dist[next] = cost + ncost;
                pq.push({-dist[next], next});
            }
        }
    }
    return dist;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> e;

    for (ll i = 0; i < e; i++)
    {
        ll a, b, c;

        cin >> a >> b >> c;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }
    cin >> v1 >> v2;

    vector<ll> dist1, dist2, dist3;
    dist1 = dij(1);
    dist2 = dij(v1);
    dist3 = dij(v2);

    ll res = min(min((dist1[v1] + dist2[v2] + dist3[n]), (dist1[v2] + dist3[v1] + dist2[n])), min((dist1[v1] + dist2[v2] + dist3[v1] + dist2[n]), (dist1[v2] + dist3[v1] + dist2[v2] + dist3[n])));
    if (res >= INF)
        cout << "-1";
    else
        cout << res;
    return 0;
}