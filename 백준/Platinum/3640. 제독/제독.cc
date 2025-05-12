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
    int next, capacity, cost, flow;
    Edge *rev;

    Edge(int next, int cost, int capacity) : next(next), cost(cost), capacity(capacity), flow(0), rev(nullptr) {};

    int residual() { return capacity - flow; };
    void update(int flow)
    {
        this->flow += flow;
        this->rev->flow -= flow;
    }
};
int vertex_num;
vector<vector<Edge *>> edges;
int source = 1, sink;
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
        vector<int> dist(vertex_num, INF);
        vector<bool> in_queue(vertex_num, false);
        vector<pair<int, Edge *>> parent(vertex_num, {-1, nullptr});
        dist[source] = 0;

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            in_queue[cur] = false;

            for (auto edge : edges[cur])
            {
                int next = edge->next;

                if (edge->residual() && dist[next] > dist[cur] + edge->cost)
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

        if (parent[sink].first == -1)
            break;

        int min_flow = INF;

        for (int i = sink; i != source; i = parent[i].first)
            min_flow = min(min_flow, parent[i].second->residual());

        for (int i = sink; i != source; i = parent[i].first)
        {
            res += min_flow * parent[i].second->cost;
            parent[i].second->update(min_flow);
        }
    }

    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int v, e;
    while ((cin >> v >> e))
    {
        vertex_num = 2 * v + 1;
        sink = 2 * v;
        edges = vector<vector<Edge *>>(vertex_num, vector<Edge *>());

        add_edge(1, 2, 0, 2);
        for (int i = 2; i < v; i++)
        {
            int in = i * 2 - 1, out = in + 1;
            add_edge(in, out, 0, 1);
        }
        add_edge(sink - 1, sink, 0, 2);

        for (int i = 0; i < e; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            int a_in = a * 2 - 1, a_out = a_in + 1, b_in = b * 2 - 1, b_out = b_in + 1;

            add_edge(a_out, b_in, c, 1);
        }

        cout << mcmf() << "\n";
    }

    return 0;
}