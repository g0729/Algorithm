#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 9876543210

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll xs, ys, xe, ye;
    vector<pair<ll, ll>> v;
    cin >> xs >> ys >> xe >> ye;
    v.push_back({xs, ys});

    for (ll i = 0; i < 6; i++)
    {
        ll a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    v.push_back({xe, ye});

    vector<pair<ll, ll>> edge[8];
    for (ll i = 0; i < 8; i++)
    {
        if (!(i == 0 || i == 7))
        {
            if (i % 2 == 1)
                edge[i].push_back({i + 1, 10});
            else
                edge[i].push_back({i - 1, 10});
        }
        for (ll j = 0; j < 8; j++)
        {
            if (i == j)
                continue;
            edge[i].push_back({j, abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second)});
        }
    }

    priority_queue<pair<ll, ll>> pq;
    pq.push({0, 0});
    vector<ll> dist(8);
    for (ll i = 0; i < 8; i++)
    {
        dist[i] = INF;
    }
    dist[0] = 0;

    while (!pq.empty())
    {
        ll cost = -pq.top().first;
        ll cur = pq.top().second;
        pq.pop();

        if (cost > dist[cur])
            continue;
        for (ll i = 0; i < edge[cur].size(); i++)
        {
            ll next = edge[cur][i].first;
            ll ncost = cost + edge[cur][i].second;

            if (dist[next] > ncost)
            {
                dist[next] = ncost;
                pq.push({-ncost, next});
            }
        }
    }

    cout << dist[7];
    return 0;
}