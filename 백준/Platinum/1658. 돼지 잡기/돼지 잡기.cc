#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100200
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

int n, m;
vector<vector<Edge *>> edges(MAX, vector<Edge *>());
int source = 0, sink = 100101;

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
                    q.push(next);
                    parent[next] = {cur, edge};
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

    cin >> m >> n;

    for (int i = 1; i <= m; i++)
    {
        int a;
        cin >> a;
        add_edge(source, i, a);
    }

    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a;
        vector<int> v(a);
        for (int j = 0; j < a; j++)
            cin >> v[j];
        cin >> b;

        add_edge(i + 100000, sink, b);

        int cur = (i - 1) * m;
        int next = i * m;
        for (int j = 1; j <= m; j++)
            add_edge(cur + j, next + j, INF);

        for (int j = 0; j < a; j++)
        {
            add_edge(cur + v[j], i + 100000, INF);
            for (int k = 0; k < a; k++)
            {
                if (j == k)
                    continue;
                add_edge(cur + v[j], next + v[k], INF);
            }
        }
    }

    int a;
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        int k;
        cin >> k;
        add_edge((n - 1) * m + k, n + 100000, INF);
    }
    int b;
    cin >> b;

    add_edge(n + 100000, sink, b);

    cout << mcmf();
    return 0;
}