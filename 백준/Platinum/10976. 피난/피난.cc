#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 300
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;
vector<vector<int>> edges, capacity, flow;

int max_flow()
{
    int res = 0;
    while (true)
    {
        queue<int> q;
        q.push(1);
        vector<int> parent(MAX, -1);
        while (!q.empty() && parent[n] == -1)
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

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        edges = vector<vector<int>>(MAX, vector<int>());
        capacity = vector<vector<int>>(MAX, vector<int>(MAX));
        flow = vector<vector<int>>(MAX, vector<int>(MAX));

        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            edges[a].push_back(b);
            edges[b].push_back(a);
            if (a == 1 || b == n)
                capacity[a][b] = 1;
            else
                capacity[a][b] = MAX;
        }
        cout << max_flow() << "\n";
    }
    return 0;
}