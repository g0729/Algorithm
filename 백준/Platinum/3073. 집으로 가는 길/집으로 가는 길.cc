#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 202
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

vector<vector<int>> edges, weights, capacity, flow;
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

    while (true)
    {
        int n, m;
        cin >> n >> m;

        edges = vector<vector<int>>(MAX, vector<int>());
        weights = vector<vector<int>>(MAX, vector<int>(MAX));
        capacity = vector<vector<int>>(MAX, vector<int>(MAX));
        flow = vector<vector<int>>(MAX, vector<int>(MAX));

        if (n == 0 && m == 0)
            break;

        vector<pair<int, int>> kids, houses;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++)
            {
                if (s[j] == 'm')
                    kids.push_back({i, j});
                else if (s[j] == 'H')
                    houses.push_back({i, j});
            }
        }
        for (int i = 0; i < kids.size(); i++)
        {
            edges[source].push_back(i + 1);
            edges[i + 1].push_back(source);

            edges[i + 101].push_back(sink);
            edges[sink].push_back(i + 101);

            capacity[source][i + 1] = 1;
            capacity[i + 101][sink] = 1;

            for (int j = 0; j < houses.size(); j++)
            {
                int weight = abs(kids[i].first - houses[j].first) + abs(kids[i].second - houses[j].second);

                edges[i + 1].push_back(j + 101);
                edges[j + 101].push_back(i + 1);

                capacity[i + 1][j + 101] = 1;

                weights[i + 1][j + 101] = weight;
                weights[j + 101][i + 1] = -weight;
            }
        }

        cout << mcmf() << "\n";
    }
    return 0;
}