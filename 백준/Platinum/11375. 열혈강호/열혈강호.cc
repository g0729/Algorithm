#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 2002
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;
int source = 0, sink = 2001;
vector<vector<int>> edges(MAX), capacity(MAX, vector<int>(MAX)), flow(MAX, vector<int>(MAX));

int max_flow()
{
    int res = 0;

    while (true)
    {
        queue<int> q;
        q.push(source);
        vector<int> parent(MAX, -1);

        while (!q.empty() && parent[sink] == -1)
        {
            int cur = q.front();
            q.pop();

            for (auto next : edges[cur])
            {
                if (capacity[cur][next] - flow[cur][next] > 0 && parent[next] == -1)
                {
                    parent[next] = cur;
                    q.push(next);
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
    {
        int k;
        cin >> k;
        edges[source].push_back(i);
        edges[i].push_back(source);
        capacity[source][i] = 1;
        for (int j = 0; j < k; j++)
        {
            int a;
            cin >> a;
            edges[i].push_back(a + 1000);
            edges[a + 1000].push_back(i);
            capacity[i][a + 1000] = 1;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        edges[i + 1000].push_back(sink);
        edges[sink].push_back(i + 1000);
        capacity[i + 1000][sink] = 1;
    }

    cout << max_flow();
    return 0;
}