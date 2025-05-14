#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 605
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

int n, m;
vector<vector<Edge *>> edges;
int source_1 = 0, source_2 = 601, sink = 602;
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
        q.push(source_1);
        vector<int> dist(MAX, -INF);
        vector<bool> in_queue(MAX, false);
        vector<pair<int, Edge *>> parent(MAX, {-1, nullptr});
        dist[source_1] = 0;

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

        if (parent[sink].first == -1)
            break;

        int min_flow = INF;

        for (int i = sink; i != source_1; i = parent[i].first)
            min_flow = min(min_flow, parent[i].second->residual());

        for (int i = sink; i != source_1; i = parent[i].first)
        {
            res += parent[i].second->cost;
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

    int t;
    cin >> t;
    while (t--)
    {
        edges = vector<vector<Edge *>>(MAX, vector<Edge *>());
        cin >> n >> m;

        for (int i = 1; i <= n; i++)
        {
            int in = i * 2 - 1, out = in + 1;
            add_edge(in, out, 1, 1);
        }
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            add_edge(a * 2, b * 2 - 1, 0, INF);
        }
        add_edge(source_1, source_2, 0, 2);

        for (int i = 1; i <= n; i++)
        {
            add_edge(source_2, i * 2 - 1, 0, INF);
            add_edge(i * 2, sink, 0, 1);
        }

        cout << mcmf() << "\n";
    }
    return 0;
}