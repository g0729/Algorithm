#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 202
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;
vector<vector<int>> edges(MAX, vector<int>()), weights(MAX, vector<int>(MAX)), capacity(MAX, vector<int>(MAX)), flow(MAX, vector<int>(MAX));
int source = 0, sink = 201;

pair<int, int> mcmf()
{
    int total_flow = 0, total_cost = 0;

    while (true)
    {
        queue<int> q;
        q.push(source);
        vector<int> dist(MAX, INF);
        vector<int> parent(MAX, -1);
        vector<bool> in_queue(MAX, false);
        dist[source] = 0;
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            in_queue[cur] = false;

            for (auto next : edges[cur])
            {
                if (capacity[cur][next] - flow[cur][next] > 0 && dist[next] > dist[cur] + weights[cur][next])
                {
                    dist[next] = dist[cur] + weights[cur][next];
                    parent[next] = cur;
                    if (!in_queue[next])
                    {
                        q.push(next);
                        in_queue[next] = true;
                    }
                }
            }
        }

        if (parent[sink] == -1)
            break;

        int min_flow = INF;

        for (int i = sink; i != source; i = parent[i])
            min_flow = min(min_flow, capacity[parent[i]][i] - flow[parent[i]][i]);

        for (int i = sink; i != source; i = parent[i])
        {
            total_cost += weights[parent[i]][i] * min_flow;
            flow[parent[i]][i] += min_flow;
            flow[i][parent[i]] -= min_flow;
        }

        total_flow += min_flow;
    }

    return {total_flow, total_cost};
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;

        edges[source].push_back(i);
        edges[i].push_back(source);
        capacity[source][i] = a;
    }

    for (int i = 1; i <= m; i++)
    {
        int a;
        cin >> a;

        edges[i + 100].push_back(sink);
        edges[sink].push_back(i + 100);
        capacity[i + 100][sink] = a;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int a;
            cin >> a;

            if (a == 0)
                continue;

            edges[i + 100].push_back(j);
            edges[j].push_back(i + 100);
            capacity[j][i + 100] = a;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int a;
            cin >> a;
            weights[j][i + 100] = a;
            weights[i + 100][j] = -a;
        }
    }

    pair<int, int> res = mcmf();

    cout << res.first << "\n"
         << res.second;
    return 0;
}