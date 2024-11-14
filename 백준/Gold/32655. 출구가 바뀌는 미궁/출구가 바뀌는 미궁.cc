#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
ll dx[] = {1, -1, 0, 0};
ll dy[] = {0, 0, 1, -1};

ll n, m, k;
vector<pair<ll, ll>> edges[200001];
vector<ll> exits;

ll dij()
{
    priority_queue<pair<ll, ll>> pq;
    pq.push({0, 1});
    vector<ll> dist(n + 1, 1e16);
    dist[1] = 0;
    while (!pq.empty())
    {
        ll cost = -pq.top().first;
        ll cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cost)
            continue;
        for (ll i = 0; i < edges[cur].size(); i++)
        {
            ll next = edges[cur][i].first;
            ll ncost = edges[cur][i].second + cost;

            if (dist[next] > ncost)
            {
                dist[next] = ncost;
                pq.push({-ncost, next});
            }
        }
    }

    ll res = 1e16;

    for (ll i = 0; i < exits.size(); i++)
    {
        ll time = dist[exits[i]];
        ll cycle_time = exits.size() * k;
        ll cycle_count = time / cycle_time;
        ll cycle_num = (time % cycle_time) / k;
        if (cycle_num == i)
            res = min(res, time);
        else if (cycle_num < i)
            res = min(res, cycle_count * cycle_time + k * i);
        else if (cycle_num > i)
            res = min(res, (cycle_count + 1) * cycle_time + k * i);
    }

    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }
    ll x;
    cin >> x;
    while (x--)
    {
        ll a;
        cin >> a;
        exits.push_back(a);
    }

    cout << dij();
    return 0;
}