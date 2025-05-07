#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 2505
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
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

int n, m;
vector<vector<Edge *>> edges(MAX, vector<Edge *>());
vector<vector<int>> v = {
    {10, 8, 7, 5, 1}, // A
    {8, 6, 4, 3, 1},  // B
    {7, 4, 3, 2, 1},  // C
    {5, 3, 2, 2, 1},  // D
    {1, 1, 1, 1, 0}   // F
};
int source = 2501, sink = 2502;
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
        vector<bool> in_queue(MAX, false);
        vector<pair<int, Edge *>> parent(MAX, {-1, nullptr});
        dist[source] = 0;

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
                        in_queue[next] = true;
                        q.push(next);
                    }
                }
            }
        }

        if (parent[sink].first == -1 || dist[sink] <= 0)
            break;

        for (int i = sink; i != source; i = parent[i].first)
        {
            res += parent[i].second->cost;
            parent[i].second->update(1);
        }
    }

    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    vector<string> MAP(n);

    auto node = [&](int x, int y)
    { return x * m + y; };

    auto idx = [&](char c)
    { return c == 'F' ? 4 : (c - 'A'); };

    for (int i = 0; i < n; i++)
        cin >> MAP[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = i % 2 ? 1 : 0; j < m; j += 2)
        {
            int cur = node(i, j);

            add_edge(source, cur, 0, 1);
            for (int k = 0; k < 4; k++)
            {
                int nx = i + dx[k], ny = j + dy[k];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;

                int next = node(nx, ny);

                int cost = v[idx(MAP[i][j])][idx(MAP[nx][ny])];

                add_edge(cur, next, cost, 1);
            }
        }
        for (int j = i % 2 ? 0 : 1; j < m; j += 2)
        {
            int next = node(i, j);

            add_edge(next, sink, 0, 1);
        }
    }

    cout << mcmf();
    return 0;
}