#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m, a, b, c;
vector<pair<int, int>> dist[11];
int res = 1e9;
void f(int cur, int sum, int min_cost, vector<bool> &visited)
{
    if (cur == b)
    {
        res = min(res, min_cost);
        return;
    }

    for (int i = 0; i < dist[cur].size(); i++)
    {
        int next = dist[cur][i].first;
        int cost = dist[cur][i].second;

        if (sum + cost > c || visited[next])
            continue;
        visited[next] = true;
        f(next, (sum + cost), max(min_cost, cost), visited);
        visited[next] = false;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> a >> b >> c;

    for (int i = 0; i < m; i++)
    {
        int dst, src, cost;
        cin >> dst >> src >> cost;

        dist[dst].push_back({src, cost});
        dist[src].push_back({dst, cost});
    }
    vector<bool> visited(n + 1);
    visited[a] = true;
    f(a, 0, 0, visited);

    if (res == 1e9)
        cout << "-1";
    else
        cout << res;
    return 0;
}