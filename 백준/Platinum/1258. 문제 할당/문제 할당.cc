#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 202
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n;
vector<vector<int>> edges(MAX, vector<int>()), weights(MAX, vector<int>(MAX)), capacity(MAX, vector<int>(MAX)), flow(MAX, vector<int>(MAX));
int source = 0, sink = 201;

int mcmf()
{
    int res = 0;

    while (true)
    {
        queue<int> q;
        q.push(source);
        vector<int> dist(MAX, INF), parent(MAX, -1);
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
            res += weights[parent[i]][i];
            flow[parent[i]][i] += min_flow;
            flow[i][parent[i]] -= min_flow;
        }
    }

    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        edges[source].push_back(i);
        edges[i].push_back(source);

        edges[i + 100].push_back(sink);
        edges[sink].push_back(i + 100);

        capacity[source][i] = 1;
        capacity[i + 100][sink] = 1;

        for (int j = 1; j <= n; j++)
        {
            int a;
            cin >> a;

            edges[i].push_back(j + 100);
            edges[j + 100].push_back(i);
            capacity[i][j + 100] = 1;
            weights[i][j + 100] = a;
            weights[j + 100][i] = -a;
        }
    }

    cout << mcmf();
    return 0;
}