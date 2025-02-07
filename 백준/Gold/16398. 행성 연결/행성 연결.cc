#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
ll dx[] = {1, -1, 0, 0};
ll dy[] = {0, 0, 1, -1};
vector<ll> parent;
vector<pair<pair<ll, ll>, ll>> edges;

ll find(ll x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}
bool isUnion(ll x, ll y)
{
    x = find(x);
    y = find(y);
    return x == y;
}

void merge(ll x, ll y)
{
    x = find(x);
    y = find(y);
    parent[x] = y;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;

    for (ll i = 0; i < n + 1; i++)
        parent.push_back(i);
    for (ll i = 1; i < n + 1; i++)
    {
        for (ll j = 1; j < n + 1; j++)
        {
            ll a;
            cin >> a;
            if (i == j)
                continue;
            edges.push_back({{i, j}, a});
        }
    }
    sort(edges.begin(), edges.end(), [](pair<pair<ll, ll>, ll> a, pair<pair<ll, ll>, ll> b) -> bool
         { return a.second < b.second; });

    ll res = 0;
    for (ll i = 0; i < edges.size(); i++)
    {
        ll src = edges[i].first.first, dst = edges[i].first.second, cost = edges[i].second;

        if (isUnion(src, dst))
            continue;
        res += cost;
        merge(src, dst);
    }

    cout << res;
    return 0;
}