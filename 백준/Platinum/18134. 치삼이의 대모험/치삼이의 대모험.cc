#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 2100
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
    };
};

int n, m;
vector<vector<Edge *>> edges(MAX, vector<Edge *>());
int source, sink;
void add_edge(int from, int to, int cost, int capacity)
{
    Edge *e1 = new Edge(to, cost, capacity);
    Edge *e2 = new Edge(from, -cost, 0);

    e1->rev = e2;
    e2->rev = e1;

    edges[from].push_back(e1);
    edges[to].push_back(e2);
}

pair<int, int> mcmf()
{
    int total_flow = 0, total_cost = 0;

    while (true)
    {
        queue<int> q;
        q.push(source);
        vector<bool> in_queue(MAX, false);
        vector<int> dist(MAX, INF);
        dist[source] = 0;
        vector<pair<int, Edge *>> parent(MAX, {-1, nullptr});

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
                    parent[next] = {cur, edge};
                    dist[next] = dist[cur] + edge->cost;

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
            parent[i].second->update(min_flow);
            total_cost += parent[i].second->cost;
        }
        total_flow += min_flow;
    }

    return {total_flow, total_cost};
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
        cin >> c >> a >> b;
        int u_in = a * 2 - 1, u_out = u_in + 1, v_in = b * 2 - 1, v_out = v_in + 1;

        add_edge(u_out, v_in, c, 1);
        add_edge(v_out, u_in, c, 1);
    }

    int h, t;
    cin >> h >> t;

    source = h * 2 - 1;
    sink = t * 2;

    for (int i = 1; i <= n; i++)
        add_edge(i * 2 - 1, i * 2, 0, (i == t || i == h) ? 2 : 1);

    pair<int, int> res = mcmf();

    if (res.first < 2)
        cout << "-1";
    else
        cout << res.second;
    return 0;
}