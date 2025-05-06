#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 3005
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
int n, m, t, k;
vector<vector<Edge *>> edges(MAX, vector<Edge *>());
int source = 0, sink = 3001;
void add_edge(int from, int to, int capacity, int cost)
{
    Edge *e1 = new Edge(to, cost, capacity);
    Edge *e2 = new Edge(from, cost, 0);

    e1->rev = e2;
    e2->rev = e1;

    edges[from].push_back(e1);
    edges[to].push_back(e2);
}

int mcmf(int target)
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

                if (edge->residual() && parent[next].first == -1 && edge->cost <= target)
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

bool check(int target)
{
    for (auto temp : edges)
        for (auto edge : temp)
            edge->flow = 0;

    return mcmf(target) >= k;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> t >> k;

    add_edge(source, 1, k, 0);

    for (int i = 1; i <= n; i++)
    {
        int cur = (i - 1) * (t + 1);
        for (int j = 1; j < t + 1; j++)
        {
            add_edge(cur + j, cur + j + 1, k, 0);
        }
    }

    for (int i = 1; i <= t + 1; i++)
    {
        int cur = (n - 1) * (t + 1);
        add_edge(cur + i, sink, k, 0);
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        int cur_a = (a - 1) * (t + 1);
        int cur_b = (b - 1) * (t + 1);

        for (int j = 1; j < t + 1; j++)
        {
            add_edge(cur_a + j, cur_b + j + 1, 1, c);
            add_edge(cur_b + j, cur_a + j + 1, 1, c);
        }
    }

    int lo = 0, hi = 1e5 + 10;

    while (lo + 1 < hi)
    {
        int mid = (lo + hi) / 2;

        if (check(mid))
            hi = mid;
        else
            lo = mid;
    }

    if (hi == 1e5 + 10)
        cout << "-1";
    else
        cout << hi;
    return 0;
}