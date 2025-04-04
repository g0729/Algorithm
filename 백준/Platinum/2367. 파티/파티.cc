#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 303
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, k, d;
vector<vector<int>> edges(MAX, vector<int>()), capacity(MAX, vector<int>(MAX)), flow(MAX, vector<int>(MAX));
int source = 0, sink = 301;

int max_flow()
{
    int res = 0;
    while (true)
    {
        queue<int> q;
        q.push(source);
        vector<int> parent(MAX, -1);
        int min_flow = INF;
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
    cin >> n >> k >> d;

    for (int i = 1; i <= d; i++)
    {
        int a;
        cin >> a;
        edges[i + 200].push_back(sink);
        edges[sink].push_back(i + 200);
        capacity[i + 200][sink] = a;
    }

    for (int i = 1; i <= n; i++)
    {
        int z;
        cin >> z;
        edges[source].push_back(i);
        edges[i].push_back(source);
        capacity[source][i] = k;

        for (int j = 0; j < z; j++)
        {
            int a;
            cin >> a;
            edges[i].push_back(a + 200);
            edges[a + 200].push_back(i);
            capacity[i][a + 200] = 1;
        }
    }

    cout << max_flow();
    return 0;
}