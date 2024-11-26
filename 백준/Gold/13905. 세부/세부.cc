#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int parent[1000001];
vector<pair<int, int>> mst_edges[100001];
vector<pair<int, pair<int, int>>> edges;
int n, m;
int s, e;

bool cmp(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b)
{
    return a.first > b.first;
}
int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}
bool isUnion(int x, int y)
{
    x = find(x);
    y = find(y);
    return x == y;
}
void merge(int x, int y)
{
    x = find(x);
    y = find(y);

    if (x > y)
        swap(x, y);
    parent[x] = y;
}

void MST()
{
    for (int i = 0; i < edges.size(); i++)
    {
        int a = edges[i].second.first, b = edges[i].second.second;

        if (!isUnion(a, b))
        {
            merge(a, b);
            mst_edges[a].push_back({b, edges[i].first});
            mst_edges[b].push_back({a, edges[i].first});
        }
    }
}
int bfs()
{
    queue<int> q;
    vector<int> visited(n + 1, INF);

    q.push(s);
    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int i = 0; i < mst_edges[now].size(); i++)
        {
            int next = mst_edges[now][i].first;
            int cost = mst_edges[now][i].second;

            if (visited[next] != INF)
                continue;
            visited[next] = min(cost, visited[now]);
            q.push(next);
        }
    }
    return visited[e];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> s >> e;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
    }

    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
    }

    sort(edges.begin(), edges.end(), cmp);
    MST();
    int ans = bfs();
    if (ans == INF)
        cout << "0";
    else
        cout << ans;
    return 0;
}