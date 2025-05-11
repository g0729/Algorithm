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
    int next, capacity, flow;
    Edge *rev;

    Edge(int next, int capacity) : next(next), capacity(capacity), flow(0), rev(nullptr) {};

    int residual() { return capacity - flow; };
    void update(int flow)
    {
        this->flow += flow;
        this->rev->flow -= flow;
    };
};

int n, m, k;
vector<vector<Edge *>> edges(MAX, vector<Edge *>());
int source = 1, sink;

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
        vector<pair<int, Edge *>> parent(MAX, {-1, nullptr});

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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    sink = n * 2;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        add_edge(i * 2 - 1, i * 2, (i == 1 || i == n) ? INF : a);
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        int u_in = a * 2 - 1, u_out = u_in + 1, v_in = b * 2 - 1, v_out = b * 2;

        add_edge(u_out, v_in, INF);
        add_edge(v_out, u_in, INF);
    }

    cout << (mcmf() <= k ? "YES" : "NO");
    return 0;
}