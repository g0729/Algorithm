#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 5050
#define INF 987654321
int dx[] = {1, 0, 0, 0};
int dy[] = {0, 1, 1, -1};

struct Edge
{
    int next, cost, capacity, flow;
    Edge *rev;

    Edge(int next, int cost, int capacity) : next(next), cost(cost), capacity(capacity), flow(0), rev(nullptr) {};
    int residual() { return capacity - flow; };
    void update(int flow)
    {
        this->flow += flow;
        this->rev->flow -= flow;
    }
};

int n, k;
vector<vector<Edge *>> edges(MAX, vector<Edge *>());
int source = 5002, sink;
void add_edge(int from, int to, int cost, int capacity)
{
    Edge *e1 = new Edge(to, cost, capacity);
    Edge *e2 = new Edge(from, -cost, 0);

    e1->rev = e2;
    e2->rev = e1;

    edges[from].push_back(e1);
    edges[to].push_back(e2);
}

int mcmf()
{
    int res = 0;

    while (true)
    {
        queue<int> q;
        q.push(source);
        vector<int> dist(MAX, -INF);
        dist[source] = 0;
        vector<bool> in_queue(MAX, false);
        vector<pair<int, Edge *>> parent(MAX, {-1, nullptr});

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            in_queue[cur] = false;

            for (auto edge : edges[cur])
            {
                int next = edge->next;

                if (edge->residual() && dist[next] < dist[cur] + edge->cost)
                {
                    dist[next] = dist[cur] + edge->cost;
                    parent[next] = {cur, edge};

                    if (!in_queue[next])
                    {
                        in_queue[next] = false;
                        q.push(next);
                    }
                }
            }
        }

        if (parent[sink].first == -1 || dist[sink] <= 0)
            break;

        int min_flow = INF;

        for (int i = sink; i != source; i = parent[i].first)
            min_flow = min(min_flow, parent[i].second->residual());

        for (int i = sink; i != source; i = parent[i].first)
            parent[i].second->update(min_flow);

        res += dist[sink];
    }

    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    vector<vector<int>> v(n, vector<int>(n));

    auto node = [&](int x, int y)
    { return x * n + y; };

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> v[i][j];

    add_edge(source, 0, 0, k);
    sink = node(n - 1, n - 1) * 2 + 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int cur = node(i, j);
            int cur_in = cur * 2, cur_out = cur_in + 1;

            add_edge(cur_in, cur_out, v[i][j], 1);
            add_edge(cur_in, cur_out, 0, INF);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int cur_out = node(i, j) * 2 + 1;
            for (int k = 0; k < 2; k++)
            {
                int x = i + dx[k], y = j + dy[k];

                if (x < 0 || x >= n || y < 0 || y >= n)
                    continue;

                int next_in = node(x, y) * 2;

                add_edge(cur_out, next_in, 0, INF);
            }
        }
    }

    cout << mcmf();
    return 0;
}