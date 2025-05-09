#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
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

int n, e, vertex_num;
vector<vector<Edge *>> edges;
int source, sink;

void add_edge(int from, int to, int capacity)
{
    Edge *e1 = new Edge(to, capacity);
    Edge *e2 = new Edge(from, 0);

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
        vector<pair<int, Edge *>> parent(vertex_num, {-1, nullptr});

        while (!q.empty() && parent[sink].first == -1)
        {
            int cur = q.front();
            q.pop();

            for (auto edge : edges[cur])
            {
                int next = edge->next;

                if (edge->residual() && parent[next].first == -1)
                {
                    parent[next] = {cur, edge};
                    q.push(next);
                }
            }
        }

        if (parent[sink].first == -1)
            break;

        int min_flow = INF;

        for (int i = sink; i != source; i = parent[i].first)
            min_flow = min(min_flow, parent[i].second->residual());

        for (int i = sink; i != source; i = parent[i].first)
            parent[i].second->update(min_flow);

        res += min_flow;
    }

    return res;
}

int dij()
{
    vector<int> dist(vertex_num, 0);
    dist[source] = INF;
    priority_queue<pair<int, int>> pq;
    pq.emplace(dist[source], source);

    while (!pq.empty())
    {
        auto [cost, cur] = pq.top();
        pq.pop();

        if (cost < dist[cur])
            continue;

        for (auto edge : edges[cur])
        {
            int next = edge->next;
            int ncost = min(dist[cur], edge->capacity);

            if (ncost > dist[next])
            {
                dist[next] = ncost;
                pq.emplace(dist[next], next);
            }
        }
    }

    return dist[sink];
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
        cin >> n >> e >> source >> sink;
        vertex_num = n + 1;
        edges = vector<vector<Edge *>>(vertex_num, vector<Edge *>());

        for (int i = 0; i < e; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;

            add_edge(u, v, w);
        }

        int nume = mcmf(), deno = dij();

        cout << fixed;
        cout.precision(3);
        cout << (double)nume / deno << "\n";
    }
    return 0;
}