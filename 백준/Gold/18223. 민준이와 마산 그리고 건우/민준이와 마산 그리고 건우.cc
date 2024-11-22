#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int v, e, p;
vector<pair<int, int>> edges[5001];

vector<int> dij(int start)
{
    priority_queue<pair<int, int>> pq;
    vector<int> dist(v + 1);

    for (int i = 0; i < v + 1; i++)
        dist[i] = INF;

    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if (dist[cur] < cost)
            continue;

        for (int i = 0; i < edges[cur].size(); i++)
        {
            int next = edges[cur][i].first;
            int ncost = edges[cur][i].second + cost;

            if (dist[next] > ncost)
            {
                dist[next] = ncost;
                pq.push({-ncost, next});
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

    cin >> v >> e >> p;

    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }
    vector<int> minjun = dij(1);
    vector<int> gunwoo = dij(p);

    if (minjun[v] == minjun[p] + gunwoo[v])
        cout << "SAVE HIM";
    else
        cout << "GOOD BYE";

    return 0;
}