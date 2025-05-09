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
    int next, cost, capacity, flow;
    Edge *rev;

    Edge(int next, int cost, int capacity) : next(next), capacity(capacity), cost(cost), flow(0), rev(nullptr) {};

    int residual() { return capacity - flow; };
    void update(int flow)
    {
        this->flow += flow;
        this->rev->flow -= flow;
    }
};

int n;
vector<vector<Edge *>> edges(MAX, vector<Edge *>());
int source = 504, sink = 505;

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
    int total_flow = 0, total_cost = 0;

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
                        in_queue[next] = true;
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
        {
            parent[i].second->update(min_flow);
            total_cost += parent[i].second->cost;
        }

        total_flow += min_flow;
    }

    return total_cost;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= 3; i++)
    {
        int a;
        cin >> a;
        add_edge(source, 500 + i, 0, a - 1);
        add_edge(source, 500 + i, 1e7, 1);
    }

    for (int i = 1; i <= n; i++)
    {
        add_edge(i, sink, 0, 1);
        for (int j = 1; j <= 3; j++)
        {
            int a;
            cin >> a;
            add_edge(j + 500, i, a, 1);
        }
    }

    cout << mcmf() - (int)3e7;
    return 0;
}