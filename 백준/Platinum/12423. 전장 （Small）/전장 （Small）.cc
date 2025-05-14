#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 202
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, a, b, c, d, e, f;
vector<vector<int>> edges(8, vector<int>()), weights(8, vector<int>(8)), capacity, flow;
int source = 0, sink = 7;

int mcmf()
{
    int res = 0;

    while (true)
    {
        queue<int> q;
        q.push(source);
        vector<int> dist(8, -INF), parent(8, -1);
        vector<bool> in_queue(8, false);
        dist[source] = 0;

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            in_queue[cur] = false;

            for (auto next : edges[cur])
            {
                if (capacity[cur][next] - flow[cur][next] > 0 && dist[next] < dist[cur] + weights[cur][next])
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
            res += min_flow * weights[parent[i]][i];
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

    int t;
    cin >> t;
    for (int i = 0; i < 3; i++)
    {
        edges[source].push_back(i + 1);
        edges[i + 1].push_back(source);

        edges[i + 4].push_back(sink);
        edges[sink].push_back(i + 4);

        for (int j = 4; j <= 6; j++)
        {
            edges[i + 1].push_back(j);
            edges[j].push_back(i + 1);
        }
    }

    for (int test = 1; test <= t; test++)
    {
        cin >> n >> a >> b >> c >> d >> e >> f;

        capacity = vector<vector<int>>(8, vector<int>(8));
        flow = vector<vector<int>>(8, vector<int>(8));

        capacity[source][1] = a;
        capacity[source][2] = b;
        capacity[source][3] = c;

        capacity[4][sink] = d;
        capacity[5][sink] = e;
        capacity[6][sink] = f;

        for (int j = 4; j <= 7; j++)
        {
            capacity[1][j] = a;
            capacity[2][j] = b;
            capacity[3][j] = c;
        }

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cin >> weights[i + 1][j + 4];
                weights[j + 4][i + 1] = -weights[i + 1][j + 4];
            }
        }
        cout << "Case #" << test << ": " << mcmf() << "\n";
    }
    return 0;
}