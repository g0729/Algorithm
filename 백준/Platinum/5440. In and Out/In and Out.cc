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

int n, r;
int vertex_num;
int source = 1, sink;
vector<vector<Edge *>> edges;

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

        for (int i = sink; i != source; i = parent[i].first)
            parent[i].second->update(1);

        total_flow++;
        total_cost += dist[sink];
    }

    return {total_flow, total_cost};
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
        int n, r;
        cin >> n >> r;
        vertex_num = n * 2 + 3;
        sink = n * 2;
        edges.assign(vertex_num, vector<Edge *>());

        for (int i = 0; i < r; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            int u_in = a * 2 - 1, u_out = u_in + 1, v_in = b * 2 - 1, v_out = v_in + 1;

            add_edge(u_out, v_in, c, INF);
            add_edge(v_out, u_in, c, INF);
        }
        vector<bool> v(n + 1, false);

        int s;
        cin >> s;
        for (int i = 0; i < s; i++)
        {
            int a;
            cin >> a;
            v[a] = true;
            add_edge(a * 2 - 1, a * 2, 0, 1);
        }
        for (int i = 1; i <= n; i++)
        {
            if (v[i])
                continue;
            if (i == 1 || i == n)
                add_edge(i * 2 - 1, i * 2, 0, 2);
            else
                add_edge(i * 2 - 1, i * 2, 0, INF);
        }

        auto res = mcmf();

        if (res.first <= 1)
            cout << "No safe route";
        else
            cout << res.second;
        cout << "\n";
    }
    return 0;
}