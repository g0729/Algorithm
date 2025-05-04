#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 202
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
struct Edge
{

    int next, cost, capacity, flow;
    Edge *rev;

    Edge() : Edge(-1, 0, 0) {};
    Edge(int next, int cost, int capacity) : next(next), cost(cost), capacity(capacity), flow(0), rev(nullptr) {};

    int residual() { return capacity - flow; };
    void update(int flow)
    {
        this->flow += flow;
        this->rev->flow -= flow;
    }
};

int n, t, f;
vector<vector<Edge *>> edges(MAX, vector<Edge *>());
int source = 0, sink = 201;
void add_edge(int from, int to, int cost, int capacity)
{
    Edge *e1 = new Edge(to, cost, capacity);
    Edge *e2 = new Edge(from, -cost, 0);

    e1->rev = e2;
    e2->rev = e1;

    edges[from].push_back(e1);
    edges[to].push_back(e2);
}

int min_cost_mf()
{
    int total_flow = 0, total_cost = 0;

    while (true)
    {
        queue<int> q;
        q.push(source);
        vector<int> dist(MAX, INF);
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

        for (int i = sink; i != source; i = parent[i].first)
        {
            parent[i].second->update(1);
            total_cost += parent[i].second->cost;
        }
        total_flow++;
    }

    if (total_flow != n)
    {
        cout << "-1";
        exit(0);
    }
    return total_cost;
}

int max_cost_mf()
{
    int total_cost = 0;

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
                if (edge->residual() > 0 && dist[next] < dist[cur] + edge->cost)
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

        for (int i = sink; i != source; i = parent[i].first)
        {
            parent[i].second->update(1);
            total_cost += parent[i].second->cost;
        }
    }

    return total_cost;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<int> start(n), end(n);

    for (int i = 0; i < n; i++)
        cin >> start[i];

    for (int i = 0; i < n; i++)
        cin >> end[i];

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    cin >> t >> f;
    for (int i = 1; i <= n; i++)
    {
        add_edge(source, i, 0, 1);
        add_edge(i + 100, sink, 0, 1);
        for (int j = 1; j <= n; j++)
        {
            if (start[i - 1] < end[j - 1])
            {
                int diff = end[j - 1] - start[i - 1];
                int cost = diff >= t ? 0 : (min((t - diff) * (t - diff), f));
                add_edge(i, j + 100, cost, 1);
            }
        }
    }

    cout << min_cost_mf() << " ";

    for (int i = 0; i < edges.size(); i++)
    {
        for (auto edge : edges[i])
            edge->flow = 0;
    }

    cout << max_cost_mf();
    return 0;
}