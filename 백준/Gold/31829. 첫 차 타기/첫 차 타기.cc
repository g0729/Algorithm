#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 2000000
#define INF 999999999999999

ll n, k, x, y;
vector<pair<pair<ll, ll>, bool>> edges[MAX + 1];

ll dij()
{
    priority_queue<pair<ll, ll>> pq;
    pq.push({0, 1});
    vector<ll> dist(n + 1, INF);
    dist[1] = 0;

    while (!pq.empty())
    {
        ll cost = -pq.top().first;
        ll cur = pq.top().second;
        pq.pop();

        if (cost > dist[cur])
            continue;
        for (ll i = 0; i < edges[cur].size(); i++)
        {
            ll next = edges[cur][i].first.first;
            ll nCost = edges[cur][i].first.second;
            bool isBus = edges[cur][i].second;

            if (isBus && dist[cur] < k)
            {
                if (dist[next] > k + nCost)
                {
                    dist[next] = k + nCost;
                    pq.push({-dist[next], next});
                }
            }
            else
            {
                if (dist[next] > cost + nCost)
                {
                    dist[next] = cost + nCost;
                    pq.push({-dist[next], next});
                }
            }
        }
    }
    return dist[n];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k >> x >> y;

    for (ll i = 0; i < x; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back({{b, c}, false});
        edges[b].push_back({{a, c}, false});
    }

    for (ll i = 0; i < y; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back({{b, c}, true});
        edges[b].push_back({{a, c}, true});
    }
    cout << dij();
    return 0;
}