#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 105
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n;
int source = 0, sink = 101;
int total_flow;
vector<vector<int>> edges(MAX, vector<int>()), capacity(MAX, vector<int>(MAX)), flow(MAX, vector<int>(MAX));

int mcmf()
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

bool check(int target)
{
    flow = vector<vector<int>>(MAX, vector<int>(MAX));

    for (int i = 1; i <= n; i++)
        for (int j = n + 1; j <= 2 * n; j++)
            capacity[i][j] = target;

    return mcmf() == total_flow;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        total_flow += a;
        edges[source].push_back(i);
        edges[i].push_back(source);

        capacity[source][i] = a;
    }

    for (int i = n + 1; i <= 2 * n; i++)
    {
        int a;
        cin >> a;
        edges[i].push_back(sink);
        edges[sink].push_back(i);

        capacity[i][sink] = a;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = n + 1; j <= 2 * n; j++)
        {
            edges[i].push_back(j);
            edges[j].push_back(i);
        }
    }

    int lo = 0, hi = 1e5;

    while (lo + 1 < hi)
    {
        int mid = (lo + hi) / 2;

        if (check(mid))
            hi = mid;
        else
            lo = mid;
    }

    check(hi);
    cout << hi << "\n";

    for (int i = 1; i <= n; i++)
    {
        for (int j = n + 1; j <= 2 * n; j++)
        {
            cout << flow[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}