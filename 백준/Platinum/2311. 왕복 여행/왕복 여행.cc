#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 1002
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;
int source = 0, sink = 1001;

struct Edge
{
    int to, cost, capacity, flow;
    Edge *rev;
    Edge() : Edge(-1, 0, 0) {};
    Edge(int to, int cost, int capacity) : to(to), cost(cost), capacity(capacity), flow(0), rev(nullptr) {};

    int residual() { return capacity - flow; };
    void update(int flow)
    {
        this->flow += flow;
        this->rev->flow -= flow;
    }
};
vector<vector<Edge *>> edges(MAX, vector<Edge *>());
vector<vector<int>> capacity(MAX, vector<int>(MAX)), flow(MAX, vector<int>(MAX));

void add_Edge(int from, int to, int cost, int capacity)
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
        vector<int> dist(MAX, INF);
        vector<bool> in_queue(MAX, false);
        dist[source] = 0;
        vector<pair<int, Edge *>> parent(MAX, make_pair(-1, nullptr));

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            in_queue[cur] = false;

            for (const auto &edge : edges[cur])
            {
                int next = edge->to;
                if (edge->residual() > 0 && dist[next] > dist[cur] + edge->cost)
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
            parent[i].second->update(min_flow);
            res += parent[i].second->cost;
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
    add_Edge(source, 1, 0, 2);
    add_Edge(n, sink, 0, 2);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        add_Edge(a, b, c, 1);
        add_Edge(b, a, c, 1);
    }

    cout << mcmf();
    return 0;
}