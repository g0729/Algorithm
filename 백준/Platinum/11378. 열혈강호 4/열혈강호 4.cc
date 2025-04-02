#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 2003
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
vector<vector<int>> edges(MAX, vector<int>()), capacity(MAX, vector<int>(MAX)), flow(MAX, vector<int>(MAX));
int n, m, k;
int source = 0, sink = 2001, bridge = 2002;

int bfs()
{
    int res = 0;

    while (1)
    {
        queue<int> q;
        q.push(source);
        vector<int> parent(MAX, -1);
        int amount = INF;

        while (!q.empty() && parent[sink] == -1)
        {
            int cur = q.front();
            q.pop();

            for (auto next : edges[cur])
            {
                if (capacity[cur][next] - flow[cur][next] > 0 && parent[next] == -1)
                {
                    q.push(next);
                    parent[next] = cur;
                }
            }
        }

        if (parent[sink] == -1)
            break;

        for (int i = sink; i != source; i = parent[i])
            amount = min(amount, capacity[parent[i]][i] - flow[parent[i]][i]);

        for (int i = sink; i != source; i = parent[i])
        {
            flow[parent[i]][i] += amount;
            flow[i][parent[i]] -= amount;
        }

        res += amount;
    }

    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    edges[source].push_back(bridge);
    edges[bridge].push_back(source);
    capacity[source][bridge] = k;

    for (int i = 1; i <= n; i++)
    {
        capacity[source][i] = 1;
        edges[source].push_back(i);
        edges[i].push_back(source);

        capacity[bridge][i] = k;
        edges[bridge].push_back(i);
        edges[i].push_back(bridge);
        int a;
        cin >> a;
        while (a--)
        {
            int b;
            cin >> b;
            b += 1000;
            edges[i].push_back(b);
            edges[b].push_back(i);
            capacity[i][b] = 1;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        capacity[i + 1000][sink] = 1;
        edges[i + 1000].push_back(sink);
        edges[sink].push_back(i + 1000);
    }

    cout << bfs();

    return 0;
}