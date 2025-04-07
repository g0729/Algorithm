#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 302
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;
vector<vector<int>> edges(MAX), capacity(MAX, vector<int>(MAX)), flow(MAX, vector<int>(MAX));

int max_flow()
{
    int res = 0;

    while (true)
    {
        queue<int> q;
        vector<int> parent(n + 1, -1);
        q.push(1);
        while (!q.empty() && parent[n] == -1)
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

        if (parent[n] == -1)
            break;

        int min_flow = INF;

        for (int i = n; i != 1; i = parent[i])
            min_flow = min(min_flow, capacity[parent[i]][i] - flow[parent[i]][i]);

        for (int i = n; i != 1; i = parent[i])
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

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        edges[a].push_back(b);
        edges[b].push_back(a);

        capacity[a][b] += c;
        capacity[b][a] += c;
    }

    cout << max_flow();
    return 0;
}