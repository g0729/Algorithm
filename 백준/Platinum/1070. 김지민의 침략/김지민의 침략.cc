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

    Edge(int next, int capacity) : next(next), capacity(capacity), flow(0), rev(nullptr) {};

    int residual() { return capacity - flow; };
    void update(int flow)
    {
        this->flow += flow;
        this->rev->flow -= flow;
    }
};

int n, m;
int source, sink;
int vertex_num;
vector<vector<Edge *>> edges;

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
        vector<pair<int, Edge *>> parent(vertex_num, {-1, nullptr});

        while (!q.empty())
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

    cin >> n >> m;
    vertex_num = n * m * 2 + 3;
    sink = n * m * 2 + 2;

    vector<string> MAP(n);
    vector<int> v(26);
    edges.assign(vertex_num, vector<Edge *>());

    auto node = [&](int x, int y)
    {
        return x * m + y;
    };

    for (int i = 0; i < n; i++)
        cin >> MAP[i];

    for (int i = 0; i < 26; i++)
        cin >> v[i];

    int offset = 1e8;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int cur = node(i, j);
            int cur_in = cur * 2, cur_out = cur_in + 1;

            if (MAP[i][j] == '-')
                continue;
            if (i == 0 || i == (n - 1) || j == 0 || j == (m - 1))
                add_edge(cur_out, sink, INF);

            if (MAP[i][j] == '*')
            {
                source = node(i, j) * 2;
                add_edge(cur_in, cur_out, INF);
            }
            else
                add_edge(cur_in, cur_out, offset + v[MAP[i][j] - 'A']);

            for (int k = 0; k < 4; k++)
            {
                int nx = i + dx[k], ny = j + dy[k];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;
                if (MAP[nx][ny] == '-')
                    continue;
                int next = node(nx, ny);
                int next_in = next * 2, next_out = next_in + 1;

                add_edge(cur_out, next_in, INF);
            }
        }
    }

    cout << mcmf() % offset;
    return 0;
}