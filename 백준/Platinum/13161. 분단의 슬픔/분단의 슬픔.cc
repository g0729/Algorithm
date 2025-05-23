#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 600
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

struct Edge
{
    int next, capacity, flow;
    Edge *rev;

    Edge(int next, int capacity) : next(next), capacity(capacity), flow(0), rev(nullptr) {};
    int residual() { return capacity - flow; };
    void update(int flow)
    {
        this->flow += flow;
        this->rev->flow -= flow;
    }
};

int n;
vector<vector<Edge *>> edges(MAX, vector<Edge *>());
int source = 0, sink = 502;
int level[MAX], w[MAX];
void add_edge(int from, int to, int capacity)
{
    Edge *e1 = new Edge(to, capacity);
    Edge *e2 = new Edge(from, 0);

    e1->rev = e2;
    e2->rev = e1;

    edges[from].push_back(e1);
    edges[to].push_back(e2);
}

bool bfs()
{
    memset(level, -1, sizeof level);
    level[source] = 0;

    queue<int> q;
    q.push(source);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (auto edge : edges[cur])
        {
            int next = edge->next;

            if (level[next] == -1 && edge->residual())
            {
                level[next] = level[cur] + 1;
                q.push(next);
            }
        }
    }

    return level[sink] != -1;
}

int dfs(int cur, int flow)
{
    if (cur == sink)
        return flow;

    for (; w[cur] < edges[cur].size(); w[cur]++)
    {
        Edge *edge = edges[cur][w[cur]];

        int next = edge->next;

        if (level[next] == level[cur] + 1 && edge->residual())
        {
            int min_flow = dfs(next, min(flow, edge->residual()));

            if (min_flow > 0)
            {
                edge->update(min_flow);

                return min_flow;
            }
        }
    }

    return 0;
}

void bfs(vector<bool> &reachable)
{
    queue<int> q;
    q.push(source);
    reachable[source] = true;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (auto edge : edges[cur])
        {
            int next = edge->next;

            if (!reachable[next] && edge->residual())
            {
                q.push(next);
                reachable[next] = true;
            }
        }
    }
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
        if (a == 1)
            add_edge(source, i, INF);
        else if (a == 2)
            add_edge(i, sink, INF);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int a;
            cin >> a;
            if (a == 0)
                continue;

            add_edge(i, j, a);
        }
    }

    int res = 0;
    while (bfs())
    {
        memset(w, 0, sizeof w);

        while (int flow = dfs(source, INF))
            res += flow;
    }

    vector<bool> reachable(MAX, false);

    bfs(reachable);

    cout << res << "\n";

    for (int i = 1; i <= n; i++)
    {
        if (reachable[i])
            cout << i << " ";
    }

    cout << "\n";
    for (int i = 1; i <= n; i++)
    {
        if (!reachable[i])
            cout << i << " ";
    }
    cout << "\n";
    return 0;
}