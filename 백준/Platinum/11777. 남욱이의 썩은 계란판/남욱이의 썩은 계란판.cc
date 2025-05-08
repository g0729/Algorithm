#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

struct Edge
{
    int next, cost, capacity, flow;
    Edge *rev;
    Edge(int next, int cost, int capacity)
        : next(next), cost(cost), capacity(capacity), flow(0), rev(nullptr) {}
    int residual() const { return capacity - flow; }
    void update(int f)
    {
        flow += f;
        rev->flow -= f;
    }
};

vector<vector<Edge *>> edges;
int source_1, source_2, sink;

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
    int V = edges.size();
    while (true)
    {
        vector<int> dist(V, -INF);
        vector<bool> in_queue(V, false);
        vector<pair<int, Edge *>> parent(V, {-1, nullptr});
        queue<int> q;
        dist[source_1] = 0;
        in_queue[source_1] = true;
        q.push(source_1);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            in_queue[u] = false;
            for (auto e : edges[u])
            {
                int v = e->next;
                if (e->residual() > 0 && dist[v] < dist[u] + e->cost)
                {
                    dist[v] = dist[u] + e->cost;
                    parent[v] = {u, e};
                    if (!in_queue[v])
                    {
                        in_queue[v] = true;
                        q.push(v);
                    }
                }
            }
        }
        if (parent[sink].first == -1 || dist[sink] <= 0)
            break;
        // augment along path
        for (int v = sink; v != source_1; v = parent[v].first)
        {
            parent[v].second->update(1);
        }
        res += dist[sink];
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<vector<int>> v(N, vector<int>(N));
    long long total = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> v[i][j];
            total += v[i][j];
        }
    }
    // 상위 T 후보 선정
    const int T = 400;
    struct Cand
    {
        int w, x1, y1, x2, y2;
    };
    auto cmp = [](const Cand &a, const Cand &b)
    { return a.w > b.w; };
    priority_queue<Cand, vector<Cand>, decltype(cmp)> pq(cmp);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (j + 1 < N)
            {
                pq.push({v[i][j] + v[i][j + 1], i, j, i, j + 1});
                if (pq.size() > T)
                    pq.pop();
            }
            if (i + 1 < N)
            {
                pq.push({v[i][j] + v[i + 1][j], i, j, i + 1, j});
                if (pq.size() > T)
                    pq.pop();
            }
        }
    }
    vector<Cand> top;
    while (!pq.empty())
    {
        top.push_back(pq.top());
        pq.pop();
    }
    sort(top.begin(), top.end(), [](const Cand &a, const Cand &b)
         { return a.w > b.w; });
    // 좌표 압축
    vector<int> comp;
    comp.reserve(top.size() * 2);
    for (auto &c : top)
    {
        comp.push_back(c.x1 * N + c.y1);
        comp.push_back(c.x2 * N + c.y2);
    }
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    int M = comp.size();
    source_1 = M + 0;
    source_2 = M + 1;
    sink = M + 2;
    int V = M + 3;
    edges.assign(V, {});
    // source_1 -> source_2 with cap = K
    add_edge(source_1, source_2, 0, K);
    // build bipartite graph: source_2 -> blacks, whites -> sink
    for (int idx = 0; idx < M; ++idx)
    {
        int id = comp[idx];
        int r = id / N, c0 = id % N;
        if ((r + c0) % 2 == 0)
        {
            add_edge(source_2, idx, 0, 1);
        }
        else
        {
            add_edge(idx, sink, 0, 1);
        }
    }
    // add edges for top candidates
    for (auto &c : top)
    {
        int u_id = c.x1 * N + c.y1;
        int v_id = c.x2 * N + c.y2;
        int u = lower_bound(comp.begin(), comp.end(), u_id) - comp.begin();
        int w = lower_bound(comp.begin(), comp.end(), v_id) - comp.begin();
        int ru = u_id / N, cu = u_id % N;
        // ensure u black, w white
        if ((ru + cu) % 2 != 0)
            swap(u, w);
        add_edge(u, w, c.w, 1);
    }
    int best = mcmf();
    cout << total - best;
    return 0;
}
