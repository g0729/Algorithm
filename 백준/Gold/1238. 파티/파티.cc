#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int n, m, x;
vector<pair<int, int>> edge[1001];

int dij(int start, bool isReturn = false)
{
    priority_queue<pair<int, int>> pq;
    vector<int> dist(n + 1, INF);
    if (isReturn)
    {
        pq.push({0, x});
        dist[x] = 0;
    }
    else
    {
        pq.push({0, start});
        dist[start] = 0;
    }
    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (cost > dist[cur])
            continue;
        for (int i = 0; i < edge[cur].size(); i++)
        {
            int next = edge[cur][i].first;
            int ncost = cost + edge[cur][i].second;

            if (ncost < dist[next])
            {
                dist[next] = ncost;
                pq.push({-ncost, next});
            }
        }
    }
    if (isReturn)
        return dist[start];
    else
        return dist[x];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> x;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
    }

    int res = 0;

    for (int i = 1; i <= n; i++)
    {
        int temp = dij(i) + dij(i, true);
        res = max(res, temp);
    }

    cout << res;
    return 0;
}