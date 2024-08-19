#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int n, m;
vector<pair<int, int>> edges[1001];
vector<int> dist(1001, INF);
vector<int> from_to(1001, -1);
int from, to;

void dij()
{
    priority_queue<pair<int, int>> pq;
    pq.push({0, from});
    dist[from] = 0;
    from_to[from] = 0;

    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (cost > dist[cur])
            continue;
        for (int i = 0; i < edges[cur].size(); i++)
        {
            int next = edges[cur][i].first;
            int ncost = cost + edges[cur][i].second;
            if (dist[next] > ncost)
            {
                dist[next] = ncost;
                from_to[next] = cur;
                pq.push({-ncost, next});
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

        edges[a].push_back({b, c});
    }
    cin >> from >> to;
    dij();

    vector<int> route;

    int cur = to;
    while (from_to[cur] != 0)
    {
        route.push_back(cur);
        cur = from_to[cur];
    }
    route.push_back(from);
    cout << dist[to] << "\n";
    cout << route.size() << "\n";

    for (int i = route.size() - 1; i >= 0; i--)
    {
        cout << route[i] << " ";
    }

    return 0;
}