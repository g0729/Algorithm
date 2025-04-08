#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 202
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, m;
vector<vector<int>> edges(MAX), capacity(MAX, vector<int>(MAX)), flow(MAX, vector<int>(MAX));
vector<int> v(MAX);
int source = 0, sink = 201;

int max_flow()
{
    int res = 0;

    while (true)
    {
        queue<int> q;
        vector<int> parent(MAX, -1);
        q.push(source);

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

        int min_flow = INF;

        for (int i = sink; i != source; i = parent[i])
            min_flow = min(min_flow, capacity[parent[i]][i] - flow[parent[i]][i]);

        for (int i = sink; i != source; i = parent[i])
        {
            flow[parent[i]][i] += min_flow;
            flow[i][parent[i]] -= min_flow;
        }

        res += min_flow;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= m; i++)
        cin >> v[i + n];

    for (int i = 1; i <= m; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int a;
            cin >> a;

            edges[i + n].push_back(a);
            edges[a].push_back(i + n);

            capacity[i + n][a] += v[a];
            capacity[a][i] += v[i];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        edges[sink].push_back(i);
        edges[i].push_back(sink);

        capacity[i][sink] = INF;
    }

    for (int i = 1; i <= m; i++)
    {
        edges[source].push_back(i + n);
        edges[i + n].push_back(source);

        capacity[source][i + n] = v[i + n];
    }

    cout << max_flow();

    return 0;
}