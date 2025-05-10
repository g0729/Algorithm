#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 205
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, m;
int source = 0, sink = 201;
vector<vector<int>> edges(MAX, vector<int>()), capacity(MAX, vector<int>(MAX)), flow(MAX, vector<int>(MAX));
vector<int> weak;

void add_edge(int from, int to, int cap)
{
    edges[from].push_back(to);
    edges[to].push_back(from);

    capacity[from][to] = cap;
}

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
    for (int i = 0; i < weak.size(); i++)
        capacity[weak[i] + 100][sink] = target;

    flow.assign(MAX, vector<int>(MAX, 0));

    int total_flow = mcmf();

    return total_flow == (int)weak.size() * target;
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
        if (a == 0)
            continue;

        add_edge(source, i, a);
    }

    vector<pair<int, int>> temp(m);

    for (int i = 0; i < m; i++)
        cin >> temp[i].first >> temp[i].second;

    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        weak.push_back(a);
        add_edge(a + 100, sink, 0);
        add_edge(a, a + 100, INF);
    }

    for (int i = 0; i < weak.size(); i++)
    {
        for (int j = 0; j < temp.size(); j++)
        {
            if (temp[j].first == weak[i])
                add_edge(temp[j].second, weak[i] + 100, INF);
            if (temp[j].second == weak[i])
                add_edge(temp[j].first, weak[i] + 100, INF);
        }
    }
    int lo = 0, hi = 1e8;

    while (lo + 1 < hi)
    {
        int mid = (lo + hi) / 2;

        if (check(mid))
            lo = mid;
        else
            hi = mid;
    }

    cout << lo;
    return 0;
}